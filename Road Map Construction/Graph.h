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
private:
		unordered_map<string, City> cities;
		string graphName;
public:
		string getGraphName();
		void setGraphName();
		void addCity(City newCity);
		City getCity(string cityName);
		bool CityExist(string cityName);
		void deleteCity(string cityName);
		void addEdge(string sourceCity, string destinationCity, int weight);
		bool EdgeExist(string sourceCity, string destinationCity);
		void deleteEdge(string sourceCity, string destinationCity);
		unordered_map<string, City> getCities();
};

