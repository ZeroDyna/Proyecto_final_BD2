#pragma once
#include <iostream>
#include<string>
#include <vector>
#include"Tablas.h"
class Sector
{
public:
	std::vector<char> datos;
	std::vector<Tablas> tabla;
	Sector(size_t size, std::vector<Tablas> tabla);//ac� asigno el tama�o del sector, supongo que sera un cin o en sql
	bool insertar_datos(std::vector<char> data);//al principio queria meterle una tabla pero mejor lo pongo como tupla
	void espacio_disp();
	void set_datos();
};

