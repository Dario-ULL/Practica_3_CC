# Práctica 3: Implementación de Funciones Primitivas Recursivas de Números Naturales

* **Asignatura:** Complejidad Computacional
* **Centro:** Escuela Superior de Ingeniería y Tecnología (ESIT)
* **Universidad:** Universidad de La Laguna
* **Curso Académico:** 2026/2027
* **Alumno:** Darío Domínguez González

---

## 1. Descripción General del Proyecto

El objetivo principal de esta práctica es implementar en C++ un simulador para evaluar la función potencia de números naturales, formalizándola estrictamente dentro del marco teórico de las Funciones Primitivas Recursivas (FPR).

En lugar de utilizar operaciones aritméticas directas del procesador (`+`, `*` o funciones de librerías estándar como `std::pow`), el cómputo se construye de forma ascendente a partir de:
1. Las funciones básicas iniciales: Cero, Sucesor y Proyecciones.
2. Los esquemas formales de combinación: Composición y Recursión Primitiva.

Además de obtener el valor numérico exacto de, el programa registra e imprime en pantalla el **número total de llamadas a funciones** que tuvieron lugar a lo largo del proceso evaluativo.

---

## 2. Arquitectura y Clases Principales

El diseño sigue el paradigma de Orientación a Objetos mediante el patrón estructural *Composite*:

### A. Clase Base: `FuncionPrimitivaRecursiva`
* Interfaz abstracta común de la que heredan todos los componentes del sistema.
* **Atributos:**
  * `aridad`: Número de parámetros formales que espera la función.
  * `contador_llamadas`: Variable estática (`static uint64_t`) compartida globalmente por todas las instancias para contabilizar cada invocación.
* **Métodos principales:**
  * `evaluar(argumentos)`: Método público que valida la aridad, incrementa `contador_llamadas` e invoca al método virtual protegido `ejecutar`.
  * `ejecutar(argumentos)`: Método virtual puro (`= 0`) implementado por cada subclase concreta.
  * `obtener_llamadas()` y `reiniciar_llamadas()`: Métodos estáticos de consulta y reinicio de la métrica.

### B. Funciones Básicas (`FuncionesBasicas.hpp`)
* **`FuncionCero`:** Modela . Ignora los argumentos y siempre retorna `0`.
* **`FuncionSucesor`:** Modela . Tiene aridad 1 y suma 1 a la entrada.
* **`FuncionProyeccion`:** Modela a extraer y la aridad total .

### C. Esquemas de Combinación
* **`Composicion`:**  
  Encapsula una función exterior y una lista de funciones interiores. Evalúa primero cada función interior con el vector de argumentos original y pasa la lista de resultados intermedios como entrada a la función exterior
* **`RecursionPrimitiva`:**  
  Encapsula la función base y la función de paso inductivo. Si el último argumento es `0`, ejecuta, evalúa recursivamente el estado anterior y suministra la tupla a la función de paso.

### D. Clases de Alto Nivel (`FuncionesAltoNivel.hpp`)
* **`FuncionSuma`:** Ensambla en su constructor el esquema de recursión para la suma a partir de y .
* **`FuncionMultiplicacion`:** Ensambla el esquema de recursión para el producto utilizando `FuncionCero`, `FuncionSuma` y proyecciones.
* **`FuncionPotencia`:** Ensambla el esquema de recursión para la potencia utilizando la composición , `FuncionMultiplicacion` y proyecciones.

### E. Programa Principal: `Simulador.cc` (o `main.cpp`)
* Gestiona las opciones de consola `-x <base>` e `-y <exponente>` mediante la función de biblioteca `getopt`.
* Valida que ambos valores pertenezcan a los números naturales ().
* Reinicia el contador de llamadas, ejecuta la función potencia y muestra el formato de salida requerido.

---

## 4. Estructura del Directorio

```text
.
├── Makefile
├── README.md
├── builds/
├── include/
│   ├── composicion.h
│   ├── funcionBasicaProyeccion.h
│   ├── funcionBasicaSucesor.h
│   ├── funcionBasicaZero.h
│   ├── funcionMultiplicacion.h
│   ├── funcionPotencia.h
│   ├── funcionPrimitivaRecursiva.h
│   ├── funcionSuma.h
│   └── recursionPrimitiva.h
├── src/
│   ├── composicion.cc
│   ├── funcionMultiplicacion.cc
│   ├── funcionPotencia.cc
│   ├── funcionPrimitivaRecursiva.cc
│   ├── funcionSuma.cc
│   ├── recursionPrimitiva.cc
│   └── simulador.cc
└── Simulador.cc
```

---

## 5. Compilación y Ejecución

### Compilación con `make`:
Para compilar el proyecto asegurando el estándar C++17 y directivas de advertencia estrictas:
```bash
make clean
make
```

Esto generará el ejecutable `simulador` en la raíz del proyecto.

### Parámetros de Ejecución:
* `-x <n>`: Base de la potencia ().
* `-y <n>`: Exponente de la potencia ().
* `-h`: Muestra el mensaje de ayuda.

### Ejemplos de uso:

1. **Caso base ():**
   ```bash
   ./simulador -x 2 -y 0
   ```
   *Salida esperada:*
   ```text
   ========================================
   Operación: 2^0
   Resultado: 1
   Número de llamadas a funciones: 5
   ========================================
   ```

2. **Cálculo de :**
   ```bash
   ./simulador -x 2 -y 3
   ```
   *Salida esperada:*
   ```text
   ========================================
   Operación: 2^3
   Resultado: 8
   Número de llamadas a funciones: 124
   ========================================
   ```

3. **Cálculo de :**
   ```bash
   ./simulador -x 2 -y 5
   ```
   *Salida esperada:*
   ```text
   ========================================
   Operación: 2^5
   Resultado: 32
   Número de llamadas a funciones: 358
   ========================================
   ```

---

## 6. Interpretación del Número de Llamadas

El número elevado de llamadas observadas en entradas medianas (por ejemplo, 358 llamadas para ) refleja la fidelidad al modelo teórico:
* No se realizan saltos aritméticos en hardware.
* Cada multiplicación y cada suma se descomponen hasta llegar a la aplicación atómica del sucesor y las proyecciones correspondientes.
* Cada nivel (`FuncionPotencia`, `FuncionMultiplicacion`, `FuncionSuma`, `RecursionPrimitiva` y `Composicion`) registra adecuadamente sus accesos a través del despachador central `evaluar()`, evidenciando el árbol de computabilidad completo.
