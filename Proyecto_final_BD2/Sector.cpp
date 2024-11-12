#include "Sector.h"

Sector::Sector(size_t size, std::vector<Tablas> tabla)
    : capacidad(size), espacioLibre(size), tabla(tabla) {}

bool Sector::insertar_datos(const std::vector<char>& data) {
    size_t dataSize = data.size();
    size_t offset = 0;

    while (dataSize > 0) {
        size_t fragmentSize = std::min(dataSize, espacioLibre);

        datos.insert(datos.end(), data.begin() + offset, data.begin() + offset + fragmentSize);
        espacioLibre -= fragmentSize;
        dataSize -= fragmentSize;
        offset += fragmentSize;

        if (espacioLibre == 0) {
            std::cout << "Sector lleno, necesita continua en otro sector\n";
            return dataSize == 0; // Si aún quedan datos, los fragmentos deben ir a otro sector
        }
    }
    return true;
}

void Sector::espacio_disp() {
    std::cout << "Espacio disponible: " << espacioLibre << " bytes\n";
}

void Sector::set_datos() {
    datos.clear();
    espacioLibre = capacidad;
}
