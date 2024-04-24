#include "Graph.h"

void Graph::addCity(City newCity)
{
	if (cities.find(newCity.getCityName()) == cities.end()) {
		cities[newCity.getCityName()] = newCity;
	}
	else {
		cout << "City already exists.\n";
	}
}

City Graph::getCity(string cityName)
{
    return cities[cityName];
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

void Graph::addEdge(string sourceCity, string destinationCity, int weight)
{
	if (cities.find(sourceCity) != cities.end() && cities.find(destinationCity) != cities.end()	) {
		cities[sourceCity].getEdgeList().push_back(Edge(sourceCity, destinationCity, weight));
		cities[destinationCity].getEdgeList().push_back(Edge(destinationCity, sourceCity, weight));
	}
	else {
		cout << "One or both cities do not exist.\n";
	}
}

bool Graph::EdgeExist(string sourceCity, string destinationCity)
{
    City c = getCity(sourceCity);
    vector <Edge> e;
    e = c.getEdgeList();
    bool flag = false;
    for (auto it = e.begin(); it != e.end(); it++) {
        if (it->getDestinationCity() == destinationCity) {
            flag = true;
            return flag;
        }
    }
    return flag;
}

void Graph::deleteEdge(string sourceCity, string destinationCity)
{

}
