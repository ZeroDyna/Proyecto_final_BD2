#pragma once
#include<string>
#include <vector>
#include"Tablas.h"
class Sector
{
	std::string datos;
	std::vector<Tablas> tablas;
	Sector(std::string dat, std::vector<Tablas> tab): datos(dat), tablas(tab) {}
};

