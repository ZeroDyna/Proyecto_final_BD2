
## **1. Propósito del Programa**
El programa simula el funcionamiento de una base de datos relacional, donde:
- Se pueden definir tablas con columnas de diferentes tipos de datos.
- Los datos se almacenan en una estructura física representada por discos (platos, superficies, pistas y sectores).
- Se calcula y asigna el espacio necesario para cada dato, respetando las restricciones físicas de la base de datos.

Además, se extiende con **SFML** para proporcionar una interfaz gráfica que permita visualizar:
- Las consultas realizadas.
- La representación física de los datos asignados.

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
- **Métodos**:
  - `columna(string nombre_columna, tipo* tipo_dato)`: Constructor para inicializar la columna con un nombre y un tipo de dato.
  - `insertar(const vector<char>& valor, const vector<int>& ubicacion)`: Inserta un valor y su ubicación física en la columna.

---

### **Clase `BD` (Base de Datos)**
- **Propósito**: Representar el almacenamiento físico de datos en discos.
- **Atributos**:
  - `platos, superficies, pistas, sectores, bytes`: Configuración física del disco.
  - `ocupado`: Espacio ocupado actualmente en el disco.
  - `plato, superficie, pista, sector`: Indicadores de la posición actual de escritura.
  - `bytes_ocupados_sector`: Bytes usados en el sector actual.
- **Métodos**:
  - `BD(int p, int s, int pi, int sec, int b)`: Constructor para inicializar la estructura física de la base de datos.
  - `espacio_disponible() const`: Calcula el espacio total disponible.
  - `asignar_espacio(int tamaño, vector<int>& ubicacion)`: Asigna espacio físico para almacenar un dato. Actualiza los indicadores de posición.

---

### **Clase `tabla`**
- **Propósito**: Representar una tabla dentro de la base de datos.
- **Atributos**:
  - `nombre`: Nombre de la tabla.
  - `columnas`: Vector de objetos `columna`, que representan las columnas de la tabla.
- **Métodos**:
  - `tabla(string nombre_tabla)`: Constructor para inicializar la tabla.
  - `agregar_columna(string nombre_columna, tipo* tipos)`: Agrega una columna a la tabla con un tipo de dato específico.
  - `insertar(const vector<vector<char>>& valores, BD& base)`: Inserta datos en las columnas de la tabla, asignando espacio en la base de datos.
  - `mostrar() const`: Imprime el contenido de la tabla, incluyendo los valores y sus ubicaciones físicas.

---

## **3. Funcionamiento del Programa**
### **Inicialización**:
1. Se crea un objeto `BD` para representar el almacenamiento físico de la base de datos.
2. Se crean objetos de los tipos `integer` y `varchar`.

### **Creación de Tablas y Columnas**:
1. Se define una tabla y se agregan columnas con tipos específicos.

### **Inserción de Datos**:
1. Los datos se insertan en la tabla. Cada valor se almacena físicamente en la base de datos, y su ubicación se guarda junto con el valor.

### **Visualización**:
1. Los datos almacenados en la tabla se imprimen en la consola, mostrando también su ubicación física.

---

## **4. Ejecución**
### **Código Principal (Sin SFML)**:
```cpp
int main() {
    BD base(1, 2, 3, 4, 512);

    integer int_type;
    varchar varchar_type;

    tabla t("MiTabla");
    t.agregar_columna("ID", &int_type);
    t.agregar_columna("Nombre", &varchar_type);

    t.insertar({{'1'}, {'A', 'n', 'a'}}, base);
    t.insertar({{'2'}, {'B', 'o', 'b'}}, base);

    t.mostrar();

    return 0;
}
