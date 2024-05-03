#include "MainMenu.h"
#include"Graph.h"
#include<iostream>
using namespace std;
using namespace sf;

MainMenu::MainMenu()
{
}

void MainMenu::load()
{
    home.loadFromFile("Textures/map.png");
    selectionMenu.loadFromFile("Textures/map.png");
    addGraphPage.loadFromFile("Textures/map.png");
    loadGraphPage.loadFromFile("Textures/map.png");
    addGraphButton.loadFromFile("Textures/Button.png");
    loadGraphButton.loadFromFile("Textures/Button.png");
    addIcon.loadFromFile("Textures/addIcon.png");
    fileIcon.loadFromFile("Textures/fileIcon.png");
    mapIcon.loadFromFile("Textures/mapIcon.png");
    backIcon.loadFromFile("Textures/backIcon.png");
    font.loadFromFile("Fonts/font.otf");
    popUpBox.loadFromFile("Textures/popUp.png");
    border.loadFromFile("Textures/border.png");
}

void MainMenu::mainMenu(RenderWindow& window, Graph& graph, unordered_map<string, Graph>& graphs)
{
    load();
    Sprite homeS(home);

    int max = 0;
    bool addCityOpen = false;
    bool deleteCityOpen = false;
    bool addEdgeOpen = false;
    bool deleteEdgeOpen = false;
    bool loadGraphOpen = false;
    bool addGraphOpen = false;
    bool displayGraphOpen = false;
    bool loadGraphDataOpen = false;
    bool startOpen = true;
    bool backIconLoadGraphOpen = false;
    bool backIconAddGraphOpen = false;
    bool backIconLoadGraphDataOpen = false;
    bool ProceedToEditGraphOpen = false;
    bool DFSOpen = false;
    bool BFSOpen = false;
    bool PrimOpen = false;


    Sprite selectionMenuS(selectionMenu);
    selectionMenuS.setPosition(1920, 0);

    Sprite addGraphPageS(addGraphPage);
    addGraphPageS.setPosition(3840, 0);

    Sprite loadGraphPageS(loadGraphPage);
    loadGraphPageS.setPosition(5760, 0);

    Sprite displayGraphS(loadGraphPage);
    displayGraphS.setPosition(7680, 0);

    Sprite graphDataS(loadGraphPage);
    graphDataS.setPosition(9600, 0);

    Sprite addGraphButtonS(addGraphButton);
    addGraphButtonS.setScale(0.35, 0.35);
    addGraphButtonS.setPosition(2260, 550);

    Sprite loadGraphButtonS(addGraphButton);
    loadGraphButtonS.setScale(0.35, 0.35);
    loadGraphButtonS.setPosition(3160, 550);

    Sprite Start(addGraphButton);
    Start.setScale(0.35, 0.35);
    Start.setPosition(820, 670);

    Sprite addIconS(addIcon);
    addIconS.setScale(0.11, 0.11);
    addIconS.setPosition(2275, 505);

    Sprite fileIconS(fileIcon);
    fileIconS.setScale(0.1, 0.1);
    fileIconS.setPosition(3340, 510);

    Sprite addMapIconS(mapIcon);
    addMapIconS.setScale(0.6, 0.6);
    addMapIconS.setPosition(2235, 210);

    Sprite loadMapIconS(mapIcon);
    loadMapIconS.setScale(0.6f, 0.6f);
    loadMapIconS.setPosition(3120, 210);

    Sprite popUpBoxS(popUpBox);
    popUpBoxS.setPosition(4500, 200);
    popUpBoxS.setScale(0.7, 0.7);

    Sprite backIconAddGraphS(backIcon);
    backIconAddGraphS.setPosition(3980, 900);
    backIconAddGraphS.setScale(0.16, 0.16);

    Sprite backIconLoadGraphS(backIcon);
    backIconLoadGraphS.setPosition(5900, 900);
    backIconLoadGraphS.setScale(0.16, 0.16);

    Sprite backIconDisplayGraphS(backIcon);
    backIconDisplayGraphS.setPosition(7820, 900);
    backIconDisplayGraphS.setScale(0.16, 0.16);

    Sprite backIconLoadGraphDataS(backIcon);
    backIconLoadGraphDataS.setPosition(9740, 900);
    backIconLoadGraphDataS.setScale(0.16, 0.16);

    RectangleShape closePopUp(sf::Vector2f(40, 40));
    closePopUp.setPosition(popUpBoxS.getPosition().x + 512, popUpBoxS.getPosition().y + 19);

    Sprite borderS[30];
    //for (auto i = 0; i < graphs.size(); i++)
    //{
    //    borderS[i].setTexture(border);
    //    borderS[i].setScale(0.55f, 0.6f);
    //    borderS[i].setPosition(6530, (125 * i) + 238);
    //}

    Sprite ProceedToEditGraphS(addGraphButton);
    ProceedToEditGraphS.setScale(0.42, 0.42);
    ProceedToEditGraphS.setPosition(10400,588);

    Sprite BFSs(addGraphButton);
    BFSs.setScale(0.42, 0.42);
    BFSs.setPosition(7980, 688);

    Sprite DFSs(addGraphButton);
    DFSs.setScale(0.42, 0.42);
    DFSs.setPosition(8480, 688);

    Sprite PRIMs(addGraphButton);
    PRIMs.setScale(0.42, 0.42);
    PRIMs.setPosition(8980, 688);

    addGraphButtonText.setString("Add Graph");
    addGraphButtonText.setFont(font);
    addGraphButtonText.setOutlineThickness(2);
    addGraphButtonText.setPosition(addGraphButtonS.getPosition().x + 55, addGraphButtonS.getPosition().y + 40);

    loadGraphButtonText.setString("Load Graph");
    loadGraphButtonText.setFont(font);
    loadGraphButtonText.setOutlineThickness(2);
    loadGraphButtonText.setPosition(loadGraphButtonS.getPosition().x + 55, loadGraphButtonS.getPosition().y + 40);

    StartText.setString("Start");
    StartText.setFont(font);
    StartText.setScale(1.3, 1.3);
    StartText.setOutlineThickness(2);
    StartText.setPosition(Start.getPosition().x + 82, Start.getPosition().y + 35);

    addCityText.setString("Add City");
    addCityText.setFont(font);
    addCityText.setScale(1.5, 1.5);
    addCityText.setOutlineThickness(1.5);
    addCityText.setPosition(3990, 200);

    addEdgeText.setString("Add Edge");
    addEdgeText.setFont(font);
    addEdgeText.setScale(1.5, 1.5);
    addEdgeText.setOutlineThickness(1.5);
    addEdgeText.setPosition(3990, 350);

    deleteCityText.setString("Delete City");
    deleteCityText.setFont(font);
    deleteCityText.setScale(1.5, 1.5);
    deleteCityText.setOutlineThickness(1.5);
    deleteCityText.setPosition(3990, 500);

    deleteEdgeText.setString("Delete Edge");
    deleteEdgeText.setFont(font);
    deleteEdgeText.setScale(1.5, 1.5);
    deleteEdgeText.setOutlineThickness(1.5);
    deleteEdgeText.setPosition(3990, 650);

    displayGraphText.setString("Display Graph");
    displayGraphText.setFont(font);
    displayGraphText.setScale(1.5, 1.5);
    displayGraphText.setOutlineThickness(1.5);
    displayGraphText.setPosition(3990, 800);

    saveInfoPopUpAddCity.setString("Add City");
    saveInfoPopUpAddCity.setFont(font);
    saveInfoPopUpAddCity.setScale(1.17, 1.17);
    saveInfoPopUpAddCity.setOutlineThickness(1.5);
    saveInfoPopUpAddCity.setPosition(popUpBoxS.getPosition().x + 365, popUpBoxS.getPosition().y + 300);

    saveInfoPopUpAddEdge.setString("Add Edge");
    saveInfoPopUpAddEdge.setFont(font);
    saveInfoPopUpAddEdge.setScale(1.17, 1.17);
    saveInfoPopUpAddEdge.setOutlineThickness(1.5);
    saveInfoPopUpAddEdge.setPosition(popUpBoxS.getPosition().x + 360, popUpBoxS.getPosition().y + 300);

    saveInfoPopUpDeleteCity.setString("Delete City");
    saveInfoPopUpDeleteCity.setFont(font);
    saveInfoPopUpDeleteCity.setScale(1.17, 1.17);
    saveInfoPopUpDeleteCity.setOutlineThickness(1.5);
    saveInfoPopUpDeleteCity.setPosition(popUpBoxS.getPosition().x + 352, popUpBoxS.getPosition().y + 300);

    saveInfoPopUpDeleteEdge.setString("Delete Edge");
    saveInfoPopUpDeleteEdge.setFont(font);
    saveInfoPopUpDeleteEdge.setScale(1.17, 1.17);
    saveInfoPopUpDeleteEdge.setOutlineThickness(1.5);
    saveInfoPopUpDeleteEdge.setPosition(popUpBoxS.getPosition().x + 345, popUpBoxS.getPosition().y + 300);

    cancelInfoPopUp.setString("Cancel");
    cancelInfoPopUp.setFont(font);
    cancelInfoPopUp.setScale(1.17, 1.17);
    cancelInfoPopUp.setOutlineThickness(1.5);
    cancelInfoPopUp.setPosition(popUpBoxS.getPosition().x + 108, popUpBoxS.getPosition().y + 300);

    EnterCityName.setString("Enter City Name : ");
    EnterCityName.setFont(font);
    EnterCityName.setScale(1, 1);
    EnterCityName.setOutlineThickness(1.2);
    EnterCityName.setPosition(popUpBoxS.getPosition().x + 48, popUpBoxS.getPosition().y + 150);

    cityName.setFont(font);
    cityName.setScale(1, 1);
    cityName.setOutlineThickness(1.2);
    cityName.setPosition(popUpBoxS.getPosition().x + 295, popUpBoxS.getPosition().y + 150);

    EnterCityNameDelete.setString("Enter City Name : ");
    EnterCityNameDelete.setFont(font);
    EnterCityNameDelete.setScale(1, 1);
    EnterCityNameDelete.setOutlineThickness(1.2);
    EnterCityNameDelete.setPosition(popUpBoxS.getPosition().x + 48, popUpBoxS.getPosition().y + 150);

    cityNameDelete.setFont(font);
    cityNameDelete.setScale(1, 1);
    cityNameDelete.setOutlineThickness(1.2);
    cityNameDelete.setPosition(popUpBoxS.getPosition().x + 295, popUpBoxS.getPosition().y + 150);

    EnterSourceCityName.setString("Enter SourceCity Name : ");
    EnterSourceCityName.setFont(font);
    EnterSourceCityName.setScale(1, 1);
    EnterSourceCityName.setOutlineThickness(1.2);
    EnterSourceCityName.setPosition(popUpBoxS.getPosition().x + 35, popUpBoxS.getPosition().y + 110);

    EnterDestinationCityName.setString("Enter DestinaitonCity Name : ");
    EnterDestinationCityName.setFont(font);
    EnterDestinationCityName.setScale(1, 1);
    EnterDestinationCityName.setOutlineThickness(1.2);
    EnterDestinationCityName.setPosition(popUpBoxS.getPosition().x + 35, popUpBoxS.getPosition().y + 170);

    EnterEdgeWeight.setString("Enter Distance : ");
    EnterEdgeWeight.setFont(font);
    EnterEdgeWeight.setScale(1, 1);
    EnterEdgeWeight.setOutlineThickness(1.2);
    EnterEdgeWeight.setPosition(popUpBoxS.getPosition().x + 35, popUpBoxS.getPosition().y + 230);

    addEdgeInfo[0].setFont(font);
    addEdgeInfo[0].setScale(1, 1);
    addEdgeInfo[0].setOutlineThickness(1.2);;
    addEdgeInfo[0].setPosition(popUpBoxS.getPosition().x + 360, popUpBoxS.getPosition().y + 110);

    addEdgeInfo[1].setFont(font);
    addEdgeInfo[1].setScale(1, 1);
    addEdgeInfo[1].setOutlineThickness(1.2);;
    addEdgeInfo[1].setPosition(popUpBoxS.getPosition().x + 415, popUpBoxS.getPosition().y + 170);

    addEdgeInfo[2].setFont(font);
    addEdgeInfo[2].setScale(1, 1);
    addEdgeInfo[2].setOutlineThickness(1.2);;
    addEdgeInfo[2].setPosition(popUpBoxS.getPosition().x + 250, popUpBoxS.getPosition().y + 230);

    EnterSourceCityNameDeleteEdge.setString("Enter SourceCity Name : ");
    EnterSourceCityNameDeleteEdge.setFont(font);
    EnterSourceCityNameDeleteEdge.setScale(1, 1);
    EnterSourceCityNameDeleteEdge.setOutlineThickness(1.2);
    EnterSourceCityNameDeleteEdge.setPosition(popUpBoxS.getPosition().x + 35, popUpBoxS.getPosition().y + 110);

    EnterDestinationCityNameDeleteEdge.setString("Enter DestinaitonCity Name : ");
    EnterDestinationCityNameDeleteEdge.setFont(font);
    EnterDestinationCityNameDeleteEdge.setScale(1, 1);
    EnterDestinationCityNameDeleteEdge.setOutlineThickness(1.2);
    EnterDestinationCityNameDeleteEdge.setPosition(popUpBoxS.getPosition().x + 35, popUpBoxS.getPosition().y + 170);

    deleteEdgeInfo[0].setFont(font);
    deleteEdgeInfo[0].setScale(1, 1);
    deleteEdgeInfo[0].setOutlineThickness(1.2);;
    deleteEdgeInfo[0].setPosition(popUpBoxS.getPosition().x + 360, popUpBoxS.getPosition().y + 110);

    deleteEdgeInfo[1].setFont(font);
    deleteEdgeInfo[1].setScale(1, 1);
    deleteEdgeInfo[1].setOutlineThickness(1.2);;
    deleteEdgeInfo[1].setPosition(popUpBoxS.getPosition().x + 415, popUpBoxS.getPosition().y + 170);

    selectGraphName.setString("Select A Graph");
    selectGraphName.setFont(font);
    selectGraphName.setScale(2, 2);
    selectGraphName.setOutlineThickness(1.5);
    selectGraphName.setPosition(6519, 100);

    CitiesIngraph.setString("Cities in Graph");
    CitiesIngraph.setFont(font);
    CitiesIngraph.setScale(2, 2);
    CitiesIngraph.setOutlineThickness(1.5);
    CitiesIngraph.setPosition(9750, 80);

    ProceedToEditGraph.setString("Edit Graph");
    ProceedToEditGraph.setFont(font);
    ProceedToEditGraph.setScale(1.5, 1.5);
    ProceedToEditGraph.setOutlineThickness(1.2);
    ProceedToEditGraph.setPosition(10450, 630);

    BFS.setString("BFS");
    BFS.setFont(font);
    BFS.setScale(1.5, 1.5);
    BFS.setOutlineThickness(1.2);
    BFS.setPosition(8085, 730);

    DFS.setString("DFS");
    DFS.setFont(font);
    DFS.setScale(1.5, 1.5);
    DFS.setOutlineThickness(1.2);
    DFS.setPosition(8585, 730);

    PRIM.setString("Prim's");
    PRIM.setFont(font);
    PRIM.setScale(1.5, 1.5);
    PRIM.setOutlineThickness(1.2);
    PRIM.setPosition(9076, 730);

    //Text selectedGraphCityT;

    int activeFieldAddCity = 0;
    int activeFieldDeleteCity = 0;
    int activeFieldAddEdge = 0;
    int activeFieldDeleteEdge = 0;

    string userInputCityName;
    string userInputCityNameDelete;
    string userInputaddEdgeInfo[3];
    string userInputDeleteEdgeInfo[2];

    View pane2(FloatRect(1920, 0, 1920, 1080));//selection page
    View pane3(FloatRect(3840, 0, 1920, 1080));//addGraph page
    View pane4(FloatRect(5760, 0, 1920, 1080));//loadGraph page
    View pane5(FloatRect(7680, 0, 1920, 1080));//DisplayGraph page 
    View pane6(FloatRect(9600, 0, 1920, 1080));//GraphData page
    while (window.isOpen())
    {
        window.setPosition(Vector2i(-8, -8));
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
            {
                window.close();
            }
            else if (event.type == Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == Mouse::Left)
                {
                    if (Start.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y) && startOpen) {
                        startOpen = false;
                        loadGraphOpen = true;
                        addGraphOpen = true;
                        window.setView(pane2);
                    }
                    if (addGraphButtonS.getGlobalBounds().contains(event.mouseButton.x + 1920, event.mouseButton.y) && addGraphOpen)
                    {
                        graph.setGraphName(to_string(max + 1));
                        graph.clearGraph();
                        for (auto it = graphs.begin(); it != graphs.end(); it++)
                        {
                            if (stoi(it->first) >= max)
                                max = stoi(it->first);
                        }
                        loadGraphOpen = false;
                        addGraphOpen = false;
                        backIconAddGraphOpen = true;
                        window.setView(pane3);
                    }
                    if (loadGraphButtonS.getGlobalBounds().contains(event.mouseButton.x + 1920, event.mouseButton.y) && loadGraphOpen)
                    {
                        for (auto i = 1; i < graphs.size(); i++)
                        {
                            borderS[i].setTexture(border);
                            borderS[i].setScale(0.55f, 0.6f);
                            borderS[i].setPosition(6530, (125 * i) + 138);
                        }
                        loadGraphOpen = false;
                        addGraphOpen = false;
                        backIconLoadGraphOpen = true;
                        loadGraphDataOpen = true;
                        window.setView(pane4);
                        for (auto graphsIt = graphs.begin(); graphsIt != graphs.end(); graphsIt++)
                        {
                            Text graphNameT(to_string(stoi(graphsIt->first) - 1), font, 24);
                            graphNameT.setScale(2, 2);
                            graphNameT.setOutlineThickness(1.2);
                            graphName.push_back(graphNameT);
                        }
                    }
                    if (ProceedToEditGraphS.getGlobalBounds().contains(event.mouseButton.x + 9600, event.mouseButton.y)&& ProceedToEditGraphOpen)
                    {
                        //graph.Prim("A");
                        ProceedToEditGraphOpen = false;
                        DFSOpen = true;
                        window.setView(pane3);
                    }
                    if (DFSs.getGlobalBounds().contains(event.mouseButton.x + 7680, event.mouseButton.y) && DFSOpen)
                    {
                        graph.DFS("A");
                        DFSOpen = false;
                    }
                    if (BFSs.getGlobalBounds().contains(event.mouseButton.x + 7680, event.mouseButton.y) && BFSOpen)
                    {
                        graph.BFS("A");
                        BFSOpen = false;
                    }
                    if (PRIMs.getGlobalBounds().contains(event.mouseButton.x + 7680, event.mouseButton.y) && PrimOpen)
                    {
                        graph.Prim("A");
                        PrimOpen = false;
                    }
                    for (int i = 1; i < graphs.size(); ++i)
                    {
                        if (borderS[i].getGlobalBounds().contains(event.mouseButton.x + 5760, event.mouseButton.y) && loadGraphDataOpen)
                        {
                            ProceedToEditGraphOpen = true;
                            loadGraphDataOpen = false;
                            loadGraphOpen = false;
                            addGraphOpen = false;
                            backIconLoadGraphDataOpen = true;
                            backIconLoadGraphOpen = false;
                            DFSOpen = true;
                            BFSOpen = true;
                            PrimOpen = true;
                            window.setView(pane6);

                            Graph selectedGraph = graphs[to_string(i + 1)];
                            graph = selectedGraph;
                            graph.setGraphName(to_string(i + 1));
                            for (auto cityPair : selectedGraph.getCities()) {
                                cout << cityPair.second.getCityName() << endl;
                                Text selectedGraphCityT(cityPair.second.getCityName(), font, 24);
                                selectedGraphCityT.setScale(2, 2);
                                selectedGraphCityT.setOutlineThickness(1.2);
                                selectedGraphCity.push_back(selectedGraphCityT);
                            }
                        }
                    }

                    if (addCityText.getGlobalBounds().contains(event.mouseButton.x + 3840, event.mouseButton.y))
                    {
                        addCityOpen = true;
                        loadGraphOpen = false;

                    }
                    if (deleteCityText.getGlobalBounds().contains(event.mouseButton.x + 3840, event.mouseButton.y))
                    {
                        deleteCityOpen = true;
                        loadGraphOpen = false;
                    }
                    if (addEdgeText.getGlobalBounds().contains(event.mouseButton.x + 3840, event.mouseButton.y))
                    {
                        addEdgeOpen = true;
                        loadGraphOpen = false;
                    }
                    if (deleteEdgeText.getGlobalBounds().contains(event.mouseButton.x + 3840, event.mouseButton.y))
                    {
                        deleteEdgeOpen = true;
                        loadGraphOpen = false;
                    }
                    if (displayGraphText.getGlobalBounds().contains(event.mouseButton.x + 3840, event.mouseButton.y))
                    {
                        displayGraphOpen = true;
                        loadGraphOpen = false;
                        window.setView(pane5);
                    }
                    if (closePopUp.getGlobalBounds().contains(event.mouseButton.x + 3840, event.mouseButton.y))
                    {
                        userInputCityNameDelete.clear();
                        cityNameDelete.setString("");

                        userInputCityName.clear();
                        cityName.setString("");

                        for (int i = 0; i < 2; i++)
                        {
                            userInputDeleteEdgeInfo[i].clear();
                            deleteEdgeInfo[i].setString("");
                        }

                        for (int i = 0; i < 3; i++)
                        {
                            userInputaddEdgeInfo[i].clear();
                            addEdgeInfo[i].setString("");
                        }

                        addCityOpen = false;
                        deleteCityOpen = false;
                        addEdgeOpen = false;
                        deleteEdgeOpen = false;
                        loadGraphDataOpen = false;

                    }
                    if (saveInfoPopUpAddCity.getGlobalBounds().contains(event.mouseButton.x + 3840, event.mouseButton.y))     //save hena el info men el user 
                    {
                        if (!userInputCityName.empty()) {
                            graph.addCity(City(userInputCityName));
                            cout << graph.getCities()[userInputCityName].getCityName() << endl;
                            userInputCityName.clear();
                            cityName.setString("");
                            addCityOpen = false;
                        }
                    }
                    if (saveInfoPopUpAddEdge.getGlobalBounds().contains(event.mouseButton.x + 3840, event.mouseButton.y))     //save hena el info men el user 
                    {
                        if (!userInputaddEdgeInfo[0].empty() && !userInputaddEdgeInfo[1].empty() && !userInputaddEdgeInfo[2].empty()) {
                            int edgeWeight = stoi(userInputaddEdgeInfo[2]);
                            graph.addEdge(userInputaddEdgeInfo[0], userInputaddEdgeInfo[1], edgeWeight);
                            for (int i = 0; i < 3; i++)
                            {
                                userInputaddEdgeInfo[i].clear();
                                addEdgeInfo[i].setString("");
                            }
                            addEdgeOpen = false;
                        }
                    }
                    if (saveInfoPopUpDeleteEdge.getGlobalBounds().contains(event.mouseButton.x + 3840, event.mouseButton.y))     //save hena el info men el user 
                    {
                        if (!userInputDeleteEdgeInfo[0].empty() && !userInputDeleteEdgeInfo[1].empty()) {
                            graph.deleteEdge(userInputDeleteEdgeInfo[0], userInputDeleteEdgeInfo[1]);
                            for (int i = 0; i < 2; i++)
                            {
                                userInputDeleteEdgeInfo[i].clear();
                                deleteEdgeInfo[i].setString("");
                            }
                            deleteEdgeOpen = false;
                        }
                    }
                    if (saveInfoPopUpDeleteCity.getGlobalBounds().contains(event.mouseButton.x + 3840, event.mouseButton.y))     //save hena el info men el user 
                    {
                        if (!userInputCityNameDelete.empty()) {
                            graph.deleteCity(userInputCityNameDelete);
                            userInputCityNameDelete.clear();
                            cityNameDelete.setString("");
                            deleteCityOpen = false;
                        }
                    }
                    if (cancelInfoPopUp.getGlobalBounds().contains(event.mouseButton.x + 3840, event.mouseButton.y))
                    {
                        for (int i = 0; i < 2; i++)
                        {
                            userInputDeleteEdgeInfo[i].clear();
                            deleteEdgeInfo[i].setString("");
                        }
                        userInputCityNameDelete.clear();
                        cityNameDelete.setString("");

                        userInputCityName.clear();
                        cityName.setString("");

                        for (int i = 0; i < 3; i++)
                        {
                            userInputaddEdgeInfo[i].clear();
                            addEdgeInfo[i].setString("");
                        }
                        addCityOpen = false;
                        deleteCityOpen = false;
                        addEdgeOpen = false;
                        deleteEdgeOpen = false;
                        loadGraphDataOpen = false;

                    }
                    if (backIconAddGraphS.getGlobalBounds().contains(event.mouseButton.x + 3840, event.mouseButton.y) && backIconAddGraphOpen) {
                        graphs[to_string(max + 1)] = graph;
                        window.setView(pane2);
                        backIconAddGraphOpen = false;
                        loadGraphOpen = true;
                        addGraphOpen = true;
                    }
                    if (backIconLoadGraphS.getGlobalBounds().contains(event.mouseButton.x + 5760, event.mouseButton.y) && backIconLoadGraphOpen) {
                        window.setView(pane2);
                        backIconLoadGraphOpen = false;
                        loadGraphOpen = true;
                        addGraphOpen = true;
                        loadGraphDataOpen = false;
                        graphName.clear();
                    }
                    if (backIconDisplayGraphS.getGlobalBounds().contains(event.mouseButton.x + 7680, event.mouseButton.y) && displayGraphOpen) {
                        window.setView(pane2);
                        displayGraphOpen = false;
                        DFSOpen = false;
                        BFSOpen = false;
                        PrimOpen = false;
                    }
                    if (backIconLoadGraphDataS.getGlobalBounds().contains(event.mouseButton.x + 9600, event.mouseButton.y) && backIconLoadGraphDataOpen) {
                        graphs[graph.getGraphName()] = graph;
                        window.setView(pane4);
                        loadGraphDataOpen = true;
                        loadGraphOpen = false;
                        addGraphOpen = false;
                        backIconLoadGraphDataOpen = false;
                        backIconLoadGraphOpen = true;
                        selectedGraphCity.clear();
                    }
                }
            }
            else if (event.type == Event::MouseMoved)
            {
                Vector2f mousePos = window.mapPixelToCoords(Mouse::getPosition(window));
                if (addCityText.getGlobalBounds().contains(mousePos))
                {
                    addCityText.setScale(1.7, 1.7);
                }
                else
                {
                    addCityText.setScale(1.5, 1.5);
                }
                if (deleteCityText.getGlobalBounds().contains(mousePos))
                {
                    deleteCityText.setScale(1.7, 1.7);
                }
                else
                {
                    deleteCityText.setScale(1.5, 1.5);
                }
                if (addEdgeText.getGlobalBounds().contains(mousePos))
                {
                    addEdgeText.setScale(1.7, 1.7);
                }
                else
                {
                    addEdgeText.setScale(1.5, 1.5);
                }
                if (deleteEdgeText.getGlobalBounds().contains(mousePos))
                {
                    deleteEdgeText.setScale(1.7, 1.7);
                }
                else
                {
                    deleteEdgeText.setScale(1.5, 1.5);
                }
                if (displayGraphText.getGlobalBounds().contains(mousePos))
                {
                    displayGraphText.setScale(1.7, 1.7);
                }
                else
                {
                    displayGraphText.setScale(1.5, 1.5);
                }
            }
            else if (event.type == sf::Event::TextEntered) {
                //activeFieldAddEdge = 0;
                //activeFieldDeleteEdge = 0;

                if (event.text.unicode < 128 && addCityOpen) {
                    if (event.text.unicode == '\b' && !userInputCityName.empty()) { // Backspace
                        userInputCityName.pop_back();
                        cityName.setString(userInputCityName);
                    }
                    else {
                        userInputCityName += static_cast<char>(event.text.unicode);
                        cityName.setString(userInputCityName);
                    }
                }

                if (event.text.unicode < 128 && addEdgeOpen) {
                    if (event.text.unicode == '\b' && !userInputaddEdgeInfo[activeFieldAddEdge].empty()) { // Backspace
                        userInputaddEdgeInfo[activeFieldAddEdge].pop_back();
                        addEdgeInfo[activeFieldAddEdge].setString(userInputaddEdgeInfo[activeFieldAddEdge]);
                    }
                    else if (event.text.unicode == '\r' || event.text.unicode == '\n') { // Enter
                        activeFieldAddEdge = (activeFieldAddEdge + 1) % 3; // Move to the next field
                    }
                    else {
                        userInputaddEdgeInfo[activeFieldAddEdge] += static_cast<char>(event.text.unicode);
                        addEdgeInfo[activeFieldAddEdge].setString(userInputaddEdgeInfo[activeFieldAddEdge]);
                    }
                }

                if (event.text.unicode < 128 && deleteCityOpen) {
                    if (event.text.unicode == '\b' && !userInputCityNameDelete.empty()) { // Backspace
                        userInputCityNameDelete.pop_back();
                        cityNameDelete.setString(userInputCityNameDelete);
                    }
                    else {
                        userInputCityNameDelete += static_cast<char>(event.text.unicode);
                        cityNameDelete.setString(userInputCityNameDelete);
                    }
                }
                if (event.text.unicode < 128 && deleteEdgeOpen) {
                    if (event.text.unicode == '\b' && !userInputDeleteEdgeInfo[activeFieldDeleteEdge].empty()) { // Backspace
                        userInputDeleteEdgeInfo[activeFieldDeleteEdge].pop_back();
                        deleteEdgeInfo[activeFieldDeleteEdge].setString(userInputDeleteEdgeInfo[activeFieldDeleteEdge]);
                    }
                    else if (event.text.unicode == '\r' || event.text.unicode == '\n') { // Enter
                        activeFieldDeleteEdge = (activeFieldDeleteEdge + 1) % 2; // Move to the next field
                    }
                    else {
                        userInputDeleteEdgeInfo[activeFieldDeleteEdge] += static_cast<char>(event.text.unicode);
                        deleteEdgeInfo[activeFieldDeleteEdge].setString(userInputDeleteEdgeInfo[activeFieldDeleteEdge]);
                    }
                }
            }

            window.draw(homeS);
            window.draw(selectionMenuS);
            window.draw(addGraphPageS);
            window.draw(loadGraphPageS);
            window.draw(displayGraphS);
            window.draw(graphDataS);
            window.draw(Start);
            window.draw(addGraphButtonS);
            window.draw(loadGraphButtonS);
            window.draw(addMapIconS);
            window.draw(loadMapIconS);
            window.draw(fileIconS);
            window.draw(addIconS);
            window.draw(backIconAddGraphS);
            window.draw(backIconLoadGraphS);
            window.draw(backIconDisplayGraphS);
            window.draw(backIconLoadGraphDataS);
            window.draw(StartText);
            window.draw(addGraphButtonText);
            window.draw(loadGraphButtonText);
            window.draw(addCityText);
            window.draw(deleteCityText);
            window.draw(addEdgeText);
            window.draw(deleteEdgeText);
            window.draw(displayGraphText);
            window.draw(selectGraphName);
            if (addCityOpen) {
                window.draw(popUpBoxS);
                window.draw(saveInfoPopUpAddCity);
                window.draw(cancelInfoPopUp);
                window.draw(EnterCityName);
                window.draw(cityName);
            }
            if (addEdgeOpen) {
                window.draw(popUpBoxS);
                window.draw(saveInfoPopUpAddEdge);
                window.draw(cancelInfoPopUp);
                window.draw(EnterSourceCityName);
                window.draw(EnterDestinationCityName);
                window.draw(EnterEdgeWeight);
                for (int i = 0; i < 3; i++)
                {
                    window.draw(addEdgeInfo[i]);
                }
            }
            if (deleteCityOpen) {
                window.draw(popUpBoxS);
                window.draw(saveInfoPopUpDeleteCity);
                window.draw(cancelInfoPopUp);
                window.draw(EnterCityNameDelete);
                window.draw(cityNameDelete);
            }
            if (deleteEdgeOpen) {
                window.draw(popUpBoxS);
                window.draw(saveInfoPopUpDeleteEdge);
                window.draw(cancelInfoPopUp);
                window.draw(EnterSourceCityNameDeleteEdge);
                window.draw(EnterDestinationCityNameDeleteEdge);
                for (int i = 0; i < 2; i++)
                {
                    window.draw(deleteEdgeInfo[i]);
                }
            }
            for (auto i = 1; i < graphs.size(); i++)
            {
                window.draw(borderS[i]);
            }
            for (auto i = 1; i < graphName.size(); ++i)
            {
                graphName[i].setPosition(6700, 145 + (125 * i));
                window.draw(graphName[i]);
            }
            for (auto i = 0; i < selectedGraphCity.size(); ++i)
            {
                selectedGraphCity[i].setPosition(9860, 220 + (100 * i));
                window.draw(selectedGraphCity[i]);
            }
            window.draw(CitiesIngraph);
            window.draw(ProceedToEditGraphS);
            window.draw(ProceedToEditGraph);
            window.draw(DFSs);
            window.draw(BFSs);
            window.draw(PRIMs);
            window.draw(DFS); 
            window.draw(BFS); 
            window.draw(PRIM);
            window.display();
        }
    }
}