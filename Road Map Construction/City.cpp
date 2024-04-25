#include "City.h"

City::City()
{
	cityName = "";
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

vector <Edge> City::getEdgeList()
{
	return edgeList;
}
