#include "City.h"

City::City()
{
}

City::City(string cityName)
{
	this->cityName = cityName;
}

string City::getCityName()
{
	return cityName;
}

void City::setCityName(string cityName)
{
	this->cityName = cityName;
}

list<Edge> City::getEdgeList()
{
	return list<Edge>();
}
