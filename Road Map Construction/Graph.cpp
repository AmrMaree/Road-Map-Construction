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
    cout << "city deleted"<<endl;
}

void Graph::addEdge(string sourceCity, string destinationCity, int weight)
{
	if (cities.find(sourceCity) != cities.end() && cities.find(destinationCity) != cities.end() && !EdgeExist(sourceCity,destinationCity)) {
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
    vector <Edge> e = c.getEdgeList();

    for (Edge edge:e) {
        if (edge.getDestinationCity() == destinationCity) {
            return true;
        }
    }
    return false;
}

void Graph::deleteEdge(string sourceCity, string destinationCity)
{
    cout << "edge deleted" << endl;
    bool check = EdgeExist(sourceCity, destinationCity);
    if (check)
    {
            if (cities.find(sourceCity)!=cities.end())
            {
                for (auto it = cities[sourceCity].getEdgeList().begin(); it != cities[sourceCity].getEdgeList().end(); it++)
                {
                    if (it->getDestinationCity() == destinationCity) {
                        cities[sourceCity].getEdgeList().erase(it);
                        break;
                    }
                }
            }

            if (cities.find(destinationCity) != cities.end())
            {
                for (auto it = cities[destinationCity].getEdgeList().begin(); it != cities[destinationCity].getEdgeList().end(); it++)
                {
                    if (it->getDestinationCity() == sourceCity) {
                        cities[destinationCity].getEdgeList().erase(it);
                        break;
                    }
                }
            }
    }
}
