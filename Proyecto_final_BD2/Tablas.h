#pragma once
#include "columna.h"
#include"Fila.h"
class Tablas
{
	std::string name;
	std::vector<Columna> col;
	std::vector<Fila*> fil;
	Tablas(const std::string n , const std::vector<Columna> c) :name(n), col(c) {}

};

