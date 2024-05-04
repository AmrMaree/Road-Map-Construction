#include <iostream>
#include "Graph.h"
#include"MainMenu.h"
#include<string>
#include <fstream>
#include <iomanip>
#include <nlohmann/json.hpp>
#include "SFML/Graphics.hpp"

using namespace sf;
using namespace std;
using json = nlohmann::json;
        
void saveGraph(unordered_map<string, Graph> graphs, string filename) {
    try {
        json data = json::array(); 

        for (auto graphEntry : graphs) {
            string graphName = graphEntry.first;
            Graph graph = graphEntry.second;

            json graphData;
            graphData["graphName"] = graphName;

            json citiesArray = json::array();
            for (auto cityEntry : graph.getCities()) {
                string cityName = cityEntry.first;
                City city = cityEntry.second;

                json cityData;
                cityData["cityName"] = cityName;

                json edgesArray = json::array();
                for (Edge edge : city.getEdgeList()) {
                    json edgeData;
                    edgeData["sourceCity"] = edge.getSourceCity();
                    edgeData["destinationCity"] = edge.getDestinationCity();
                    edgeData["weight"] = edge.getWeight();
                    edgesArray.push_back(edgeData);
                }

                cityData["edges"] = edgesArray;

                citiesArray.push_back(cityData);
            }

            graphData["cities"] = citiesArray;

            data.push_back(graphData);
        }

        ofstream file(filename);
        if (file.is_open()) {
            file << std::setw(4) << data << std::endl;
            std::cout << "Graphs saved to file " << filename << std::endl;
        }
        else {
            std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
        }
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }
}
unordered_map<string, Graph> loadGraph(string filename) {
    unordered_map<string, Graph> graphs;

    try {
        ifstream file(filename);
        if (!file.is_open()) {
            cerr << "Error: Unable to open file " << filename << " for reading." << std::endl;
            return graphs;
        }

        json data;
        file >> data;

        for (auto graphData : data) {
            string graphName = graphData["graphName"];
            Graph graph;

            for (auto cityData : graphData["cities"]) {
                string cityName = cityData["cityName"];
                /*if (!graph.CityExist(cityName)) {
                    graph.addCity(City(cityName));
                }*/
                graph.setCities(cityName);
                for (auto edge : cityData["edges"]) {
                    string destination = edge["destinationCity"];
                    int weight = edge["weight"];
                    graph.addEdge(cityName, destination, weight);
                }
            }
            graphs[graphName] = graph;
        }
        
        file.close();
    }
    catch (const json::parse_error& e) {
        cerr << "Parse error while loading JSON file: " << e.what() << std::endl;
    }
    catch (const json::exception& e) {
        cerr << "JSON exception while loading JSON file: " << e.what() << std::endl;
    }
    catch (const std::exception& e) {
        cerr << "Exception while loading JSON file: " << e.what() << std::endl;
    }

    return graphs;
}

int main() {
    RenderWindow window(VideoMode(1920, 1080), "RoadMap");
    MainMenu mainMenu;
    Graph graph;
    mainMenu.load();
    unordered_map<string, Graph> graphs = loadGraph("myGraph.json");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        mainMenu.mainMenu(window,graph,graphs);
        window.display();
    }

    int max = 0;
    for (auto it = graphs.begin(); it != graphs.end(); it++)
    {
        if (stoi(it->first) > max)
            max = stoi(it->first);
    }

    if(graphs.find(graph.getGraphName()) != graphs.end())
        graphs[graph.getGraphName()] = graph;
    else if(graphs[to_string(max)].getGraphName() != graph.getGraphName())
        graphs[to_string(max+1)] = graph;

    saveGraph(graphs, "myGraph.json");
    return 0;
}