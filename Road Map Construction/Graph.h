#pragma once
#include <iostream>
#include<List>
#include<vector>
#include<unordered_map>
#include "City.h"
#include "Edge.h"
using namespace std;

class Graph
{
		unordered_map<string, City> cities;
	public:
		void addCity(City newCity);
		City getCity(string cityName);
		bool CityExist(string cityName);
		void deleteCity(string cityName);
		void addEdge(string destinationCity, string sourceCity, int weight);
		bool EdgeExist(string sourceCity, string destinationCity);
		void deleteEdge(string sourceCity, string destinationCity);
};

