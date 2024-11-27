
## **1. Propósito del Programa**
El programa simula el funcionamiento de una base de datos relacional, donde:
- Se pueden definir tablas con columnas de diferentes tipos de datos.
- Los datos se almacenan en una estructura física representada por discos (platos, superficies, pistas y sectores).
- Se calcula y asigna el espacio necesario para cada dato, respetando las restricciones físicas de la base de datos.

---

## **2. Explicación de las Clases**

### **Clase `tipo` (Abstracta)**
- **Propósito**: Representar tipos genéricos de datos para columnas.
- **Métodos abstractos**:
  - `tamaño(int x)`: Calcula el espacio que ocupa un dato, basado en su tipo.
  - `nombre()`: Devuelve el nombre del tipo de dato.

### **Clases Derivadas de `tipo`**
1. **`integer`**:
   - Representa datos enteros.
   - Cada entero ocupa 4 bytes.
2. **`floating`**:
   - Representa números flotantes.
   - Cada número ocupa 4 bytes menos 1 byte de overhead.
3. **`varchar`**:
   - Representa cadenas de caracteres.
   - Cada carácter ocupa 1 byte, y se añade un byte extra para el terminador.

---

### **Estructura `columna`**
- **Propósito**: Representar una columna en una tabla.
- **Atributos**:
  - `nombre`: Nombre de la columna.
  - `tipos`: Tipo de datos que acepta (por ejemplo, `integer` o `varchar`).
  - `datos`: Almacena valores de la columna junto con sus ubicaciones físicas.
-
