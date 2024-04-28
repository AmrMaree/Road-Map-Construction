#include <iostream>
#include "Graph.h"
#include"MainMenu.h"
#include<string>
#include"SFML/Graphics.hpp"
#include <nlohmann/json.hpp>
using namespace std;
using namespace sf;

void printMenu() {
    cout << "Menu:\n";
    cout << "1. Add city\n";
    cout << "2. Check if city exists\n";
    cout << "3. Add edge\n";
    cout << "4. Check if edge exists\n";
    cout << "5. Delete city\n";
    cout << "6. Delete edge\n";
    cout << "7. Exit\n";
    cout << "Enter your choice: ";
}

int main() {
    RenderWindow window(sf::VideoMode(1920, 1080), "RoadMap");
    MainMenu mainMenu;
    mainMenu.load();
    
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        mainMenu.mainMenu(window);
        window.display();
    }
    
    Graph graph;
    int choice;
    string cityName, sourceCity, destinationCity;
    int weight;

    do {
        printMenu();
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

    return 0;
}