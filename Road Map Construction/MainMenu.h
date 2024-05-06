#pragma once
#include <SFML/Graphics.hpp>
#include"Graph.h"
using namespace sf;
class MainMenu
{
private:
    Texture home;
    Texture selectionMenu;
    Texture addGraphPage;
    Texture loadGraphPage;
    Texture addGraphButton;
    Texture loadGraphButton;
    Texture addIcon;
    Texture mapIcon;
    Texture fileIcon;
    Texture backIcon;
    Texture popUpBox;
    Texture border;
    Texture bgColor;
    Texture Logo;
    Texture Noti;

    Text StartText;
    Text addGraphButtonText;
    Text loadGraphButtonText;
    Text addCityText;
    Text addEdgeText;
    Text deleteCityText;
    Text deleteEdgeText;
    Text displayGraphText;
    Text saveInfoPopUpAddCity;
    Text saveInfoPopUpAddEdge;
    Text saveInfoPopUpDeleteCity;
    Text saveInfoPopUpDeleteEdge;
    Text cancelInfoPopUp;
    Text EnterCityName;
    Text cityName;
    Text EnterSourceCityName;
    Text EnterDestinationCityName;
    Text EnterEdgeWeight;
    Text addEdgeInfo[3];
    Text EnterCityNameDelete;
    Text cityNameDelete;
    Text EnterSourceCityNameDeleteEdge;
    Text EnterDestinationCityNameDeleteEdge;
    Text deleteEdgeInfo[2];
    Text selectGraphName;
    Text CitiesIngraph;
    Text ProceedToEditGraph;
    Text BFS;
    Text DFS;
    Text PRIM;
    Text Dijiktra;
    Text EnterCityNameBFS;
    Text EnterCityNameDFS;
    Text EnterCityNamePRIM;
    Text saveInfoPopUpBFS;
    Text saveInfoPopUpDFS;
    Text saveInfoPopUpPRIM;
    Text cancelInfoPopUpAlgo;
    Text cityNameBFS;
    Text cityNameDFS;
    Text cityNamePRIM;
    Text AddCityConfirmation;
    Text DeleteCityConfirmation;
    Text AddEdgeConfirmation;
    Text DeleteEdgeConfirmation;
    vector<Text>graphName;
    vector<Text>selectedGraphCity;
    Text bfsOrderText;
    Text dfsOrderText;

    Font font;

    View pane2;
    View pane3;
    View pane4;
public:
    MainMenu();
    void load();
    void mainMenu(RenderWindow& window, Graph& graph, unordered_map<string, Graph>& graphs);

};