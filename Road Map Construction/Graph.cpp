#include "Graph.h"

void Graph::addCity(City newCity)
{
}

City Graph::getCity(string cityName)
{
	
}

bool Graph::CityExist(string cityName)
{
	if (cities.find(cityName) == cities.end())
		return false;
	else
		return true;
}

void Graph::deleteCity(string cityName)
{
}

void Graph::addEdge(string destinationCity, string sourceCity, int weight)
{

}

bool Graph::EdgeExist(string destinationCity, string sourceCity)
{
	
}

void Graph::deleteEdge(string destinationCity, string sourceCity)
{

}
