#pragma once
#include <iostream>
#include<List>
#include<queue>
#include<stack>
#include<vector>
#include<unordered_map>
#include "SFML/Graphics.hpp"
#include "City.h"
#include "Edge.h"
using namespace std;
using namespace sf;

class Graph
{
private:
		unordered_map<string, City> cities;
		string graphName;
public:
		string getGraphName();
		void setGraphName(string graphName);
		void addCity(City newCity);
		City getCity(string cityName);
		bool CityExist(string cityName);
		void deleteCity(string cityName);
		void addEdge(string sourceCity, string destinationCity, int weight);
		bool EdgeExist(string sourceCity, string destinationCity);
		void deleteEdge(string sourceCity, string destinationCity);
		void displayGraph();
		unordered_map<string, City> getCities();
		void BFS(string cityName);
		void DFS(string cityName);
		void Prim(string startCity);
		void clearGraph();
};

