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
    if (!CityExist(cityName))
    {
        cout << "Source city '" << cityName << "' does not exist.\n";
    }

    /* for (int i = 0; i < cities[cityName].getEdgeList().size(); i++)
     {
         string Des = cities[cityName].getEdgeList().getDestinationCity();
         vector<Edge>& edgeList = source.getEdgeList();
     }*/
}

void Graph::addEdge(string sourceCity, string destinationCity, int weight)
{
    vector <Edge> edgeListSource;
    vector <Edge> edgeListDestination;

    if (!CityExist(sourceCity))
    {
        cout << "Source city '" << sourceCity << "' does not exist.\n";
        cout << "To Add it please enter YES or yes  " << endl << "To return to the menu please enter NO or no";
        string answer;
        cin >> answer;
        if (answer == "yes" || answer == "YES")
        {
            addCity(City(sourceCity));
        }
        else
        {
            return;
        }

    }

    if (!CityExist(destinationCity)) {
        cout << "Destination city '" << destinationCity << "' does not exist.\n";
        cout << "To Add it please enter YES or yes  " << endl << "To return to the menu please enter NO or no";
        string answer;
        cin >> answer;
        if (answer == "yes" || answer == "YES")
        {
            addCity(City(destinationCity));
        }
        else
        {
            return;
        }
    }

    if (EdgeExist(sourceCity, destinationCity)) {
        cout << "Edge from '" << sourceCity << "' to '" << destinationCity << "' already exists.\n";
        return;
    }

    edgeListSource = cities[sourceCity].getEdgeList();
    edgeListSource.push_back(Edge(sourceCity, destinationCity, weight));
    cities[sourceCity].setEdgeList(edgeListSource);

    edgeListDestination = cities[destinationCity].getEdgeList();
    edgeListDestination.push_back(Edge(destinationCity, sourceCity, weight));
    cities[destinationCity].setEdgeList(edgeListDestination);

    cout << "Edge successfully added from '" << sourceCity << "' to '" << destinationCity << "' with weight " << weight << ".\n";
}

bool Graph::EdgeExist(string sourceCity, string destinationCity)
{
    if (!CityExist(sourceCity)) {
        return false;
    }
    City c = cities[sourceCity];
    vector <Edge> e = c.getEdgeList();
    for (auto it = e.begin(); it != e.end(); it++) {
        if (it->getDestinationCity() == destinationCity) {
            return true;
        }
    }
    return false;
}

//void Graph::deleteEdge(string sourceCity, string destinationCity)
//{
//    bool check = EdgeExist(sourceCity, destinationCity);
//    if (check)
//    {
//            if (cities.find(sourceCity)!=cities.end())
//            {
//                for (auto it = cities[sourceCity].getEdgeList().begin(); it != cities[sourceCity].getEdgeList().end(); it++)
//                {
//                    if (it->getDestinationCity() == destinationCity) {
//                        cities[sourceCity].getEdgeList().erase(it);
//                        break;
//                    }
//                }
//            }
//
//            if (cities.find(destinationCity) != cities.end())
//            {
//                for (auto it = cities[destinationCity].getEdgeList().begin(); it != cities[destinationCity].getEdgeList().end(); it++)
//                {
//                    if (it->getDestinationCity() == sourceCity) {
//                        cities[destinationCity].getEdgeList().erase(it);
//                        break;
//                    }
//                }
//            }
//    }
//}

void Graph::deleteEdge(string sourceCity, string destinationCity)
{
    if (!CityExist(sourceCity))
    {
        cout << "Source city '" << sourceCity << "' does not exist.\n";
        return;
    }
    if (!CityExist(destinationCity))
    {
        cout << "Destination city '" << destinationCity << "' does not exist.\n";
        return;
    }
    if (!EdgeExist(sourceCity, destinationCity)) {
        cout << "Edge from '" << sourceCity << "' to '" << destinationCity << "' does not exist.\n";
        return;
    }
    else if (EdgeExist(sourceCity, destinationCity))
    {
        // Find the edge to delete
        vector<Edge> newEdgeListSource;
        for (int i = 0; i < cities[sourceCity].getEdgeList().size(); i++)
        {
            if (cities[sourceCity].getEdgeList()[i].getDestinationCity() != destinationCity) {
                // Add edges that don't match the destination city to the new list
                newEdgeListSource.push_back(cities[sourceCity].getEdgeList()[i]);
            }
        }
        cities[sourceCity].setEdgeList(newEdgeListSource);
        vector<Edge> newEdgeListDestination;
        for (int i = 0; i < cities[destinationCity].getEdgeList().size(); i++)
        {
            if (cities[destinationCity].getEdgeList()[i].getDestinationCity() != sourceCity) {
                // Add edges that don't match the destination city to the new list
                newEdgeListSource.push_back(cities[destinationCity].getEdgeList()[i]);
            }
        }
        cities[destinationCity].setEdgeList(newEdgeListDestination);
        cout << "The Edge between " << sourceCity << " and " << destinationCity << " deleted successfully" << endl;
    }
}

unordered_map<string, City> Graph::getCities()
{
    return cities;
}

