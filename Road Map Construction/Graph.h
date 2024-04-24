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
	void addEdge(string destinationCity,string sourceCity,int weight);
	bool EdgeExist(string destinationCity, string sourceCity);
	void deleteEdge(string destinationCity,string sourceCity);
};

