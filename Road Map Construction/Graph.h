#include<List>
#include<unordered_map>
#include"City.h"
#pragma once
class Graph
{
	unordered_map<string, City> cities;

	void addCity(City newCity);
	City getCity(string cityName);
	bool CityExist(string cityName);
	void deleteCity(string cityName);
	void addEdge(string sourceCity,string destinationCity,int weight);
	bool EdgeExist(string sourceCity, string destinationCity);
	void deleteEdge(string sourceCity, string destinationCity);
};

