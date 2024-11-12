#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Tablas.h"

class Sector {
public:
    std::vector<char> datos;
    size_t capacidad;
    size_t espacioLibre;
    std::vector<Tablas> tabla;
    Sector(size_t size, std::vector<Tablas> tabla);
    bool insertar_datos(const std::vector<char>& data);
    void espacio_disp();
    void set_datos();
};
