# 🚗 S.A.V.E Sistema de Análisis de Vehiculos Autónomos


## 📄 Descripción del Proyecto

Desarrollamos una aplicación en **C++ moderno (C++20)** capaz de leer una base de datos real de vehículos eléctricos (desde un archivo `.csv`) y analizarlos para tomar decisiones. El objetivo es simular un sistema que ayuda a una empresa a ver qué autos son eficientes y cuáles necesitan mantenimiento urgente.

### 👥 Integrantes del Equipo
* **Aarón Alejandro Escobar Villanueva** - *A01199520*
* **Axel Suarez Román** - *A01199513*
* **Diego Villanueva Fernández** - *A01199495*

---

## 🚀 Características Principales (Lo que pide la rúbrica)
Nos enfocamos en cumplir todos los requisitos técnicos del curso:

1.  **Lectura de Archivos Reales:** El programa no usa datos falsos en el código, lee un archivo `fleet.csv` externo usando librerías modernas.
2.  **C++20:** Implementamos `<filesystem>` para verificar rutas y `<string_view>` para dividir el texto de forma eficiente (sin gastar memoria extra).
3.  **POO y Composición:** Usamos Clases que contienen Vectores de objetos (`FleetManager` tiene `FleetRecord`).
4.  **Algoritmos Propios:**
    * **Ordenamiento:** Programamos una función para ordenar la flota del **más eficiente al menos eficiente** (Km por kWh).
    * **Búsqueda:** Filtramos automáticamente los vehículos que tuvieron accidentes ("Incidentes").

---

## 🛠️ Estructura del Proyecto
Así organizamos nuestros archivos para dividirnos el trabajo:

* `main.cpp`: Es el punto de entrada. Contiene el menú interactivo (ciclo while + switch) para que el usuario elija qué hacer.
* `FleetFrame.h`: Aquí definimos los "planos" (Structs) de nuestros datos (`FleetRecord`) y sobrecargamos el operador `<<` para imprimir bonito.
* `Fleet_Enum.h`: Guardamos los `enum class` para los Tipos de Vehículo y los Estados del viaje, para no usar "magic strings".
* `FileHandler.h`: **(El archivo difícil)**. Se encarga de abrir el CSV, partir las líneas por comas y convertir el texto a números/enums.
* `FleetManager.h`: Es el "cerebro". Recibe los datos y hace los cálculos matemáticos y ordenamientos.
* `fleet.csv`: Nuestra base de datos con +200 registros de prueba.

---

## 💻 Instrucciones de Compilación y Ejecución

Como usamos funcionalidades nuevas de C++, es importante compilar especificando la versión 20.

### Requisitos
* Tener instalado `g++` (versión reciente).
* Asegurarse de que el archivo `fleet.csv` esté en la misma carpeta que el ejecutable.

### Pasos
1.  Abre tu terminal en la carpeta del proyecto.
2.  Compila el código con este comando:
    ```bash
    g++ main.cpp -o SAVE -std=c++20
    ```
    *(Nota: Si usas Windows y no te reconoce el comando, intenta compilarlo desde tu IDE como Visual Studio o CLion asegurándote que el estándar esté en C++20).*

3.  Ejecuta el programa:
    * En Windows:
        ```bash
        ./main.exe
        ```
    * En Mac/Linux:
        ```bash
        ./main
        ```

---

## 📝 Reflexión y Retos
Lo más retador del proyecto fue entender cómo funciona `string_view` y hacer que el `split` funcionara correctamente sin corromper los datos del CSV. También aprendimos a usar `lambda functions` dentro de `std::sort` para ordenar objetos personalizados, lo cual fue muy útil para no escribir tanto código repetido.
