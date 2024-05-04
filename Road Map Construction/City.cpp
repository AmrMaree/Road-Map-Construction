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

void City::setEdgeList(vector<Edge> edgeList)
{
	this->edgeList = edgeList;
}

void City::setX(int X)
{
	this->X = X;
}

void City::setY(int Y)
{
	this->Y = Y;
}

int City::getX()
{
	return X;
}

int City::getY()
{
	return Y;
}
