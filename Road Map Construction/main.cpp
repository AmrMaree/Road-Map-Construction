#include <iostream>
#include "Graph.h"
#include<string>
#include <fstream>
#include <iomanip>
#include <nlohmann/json.hpp> 

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
            std::string graphName = graphData["graphName"];
            Graph graph;

            for (auto cityData : graphData["cities"]) {
                string cityName = cityData["cityName"];
                if (!graph.CityExist(cityName)) {
                    graph.addCity(City(cityName));
                }
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



//void save_to_file(unordered_map<string, Graph> graphs, string filename) {
//    json data;
//    for (auto [graph_name, graph] : graphs) {
//        json graph_data = {
//            {"graphName", graph_name},
//            {"cities", json::array()}
//        };
//
//        for (auto [city_name, city] : graph.getCities()) {
//            json city_data = {
//                {"cityName", city_name},
//                {"edges", json::array()}
//            };
//
//            for (const auto& [destination, weight] : city.getEdges()) {
//                city_data["edges"].push_back({ {"destinationCity", destination}, {"weight", weight} });
//            }
//
//            graph_data["cities"].push_back(city_data);
//        }
//
//        data.push_back(graph_data);
//    }
//
//    try {
//        std::ofstream file(filename);
//        file << data.dump(4); // Indent for better readability
//    }
//    catch (const std::exception& e) {
//        std::cerr << "Error saving graph data: " << e.what() << std::endl;
//    }
//}
//unordered_map<string, Graph> loadGraph(string filename) {
//    unordered_map<string, Graph> graphs;
//
//    try {
//        ifstream file(filename);
//        if (!file.is_open()) {
//            cerr << "Error: Unable to open file " << filename << " for reading." << std::endl;
//            return graphs;
//        }
//
//        json data;
//        file >> data;
//
//        for (auto graphData : data) {
//            string graphName = graphData["graphName"];
//            graphs[graphName] = Graph(); 
//
//            for (auto cityData : graphData["cities"]) {
//                string cityName = cityData["cityName"];
//                if (!graphs[graphName].CityExist(cityName)) {
//                    graphs[graphName].addCity(City(cityName));
//                }
//                for (auto edge : cityData["edges"]) {
//                    string destination = edge["destinationCity"];
//                    int weight = edge["weight"];
//                    graphs[graphName].addEdge(cityName, destination, weight);
//                }
//            }
//        }
//
//        file.close();
//    }
//    catch (const json::parse_error& e) {
//        std::cerr << "Parse error while loading JSON file: " << e.what() << std::endl;
//    }
//    catch (const json::exception& e) {
//        std::cerr << "JSON exception while loading JSON file: " << e.what() << std::endl;
//    }
//    catch (const std::exception& e) {
//        std::cerr << "Exception while loading JSON file: " << e.what() << std::endl;
//    }
//
//    return graphs;
//}

int main() {
    unordered_map<string, Graph> graphs = loadGraph("myGraph.json");
    Graph graph;
    int choice;
    string cityName, sourceCity, destinationCity;
    int weight;

    do {
        cout << "Menu:\n";
        cout << "1. Add city\n";
        cout << "2. Check if city exists\n";
        cout << "3. Add edge\n";
        cout << "4. Check if edge exists\n";
        cout << "5. Delete city\n";
        cout << "6. Delete edge\n";
        cout << "7. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter city name: ";
            cin >> cityName;
            graph.addCity(City(cityName));
            break;
        case 2:
            cout << "Enter city name: ";
            cin >> cityName;
            cout << "City exists? " << (graph.CityExist(cityName) ? "Yes" : "No") << endl;
            break;
        case 3:
            cout << "Enter source city: ";
            cin >> sourceCity;
            cout << "Enter destination city: ";
            cin >> destinationCity;
            cout << "Enter weight: ";
            cin >> weight;
            graph.addEdge(sourceCity, destinationCity, weight);
            break;
        case 4:
            cout << "Enter source city: ";
            cin >> sourceCity;
            cout << "Enter destination city: ";
            cin >> destinationCity;
            cout << "Edge exists? " << (graph.EdgeExist(sourceCity, destinationCity) ? "Yes" : "No") << endl;
            break;
        case 5:
            cout << "Enter city name to delete: ";
            cin >> cityName;
            graph.deleteCity(cityName);
            break;
        case 6:
            cout << "Enter source city: ";
            cin >> sourceCity;
            cout << "Enter destination city: ";
            cin >> destinationCity;
            graph.deleteEdge(sourceCity, destinationCity);
            break;
        case 7:
            cout << "Exiting program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
        }

    } while (choice != 7);
    graphs["2"] = graph;
    saveGraph(graphs, "myGraph.json");

    return 0;
}