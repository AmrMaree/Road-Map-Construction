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
    bgColor.loadFromFile("Textures/bgColor.png");
    Logo.loadFromFile("Textures/RoadMapLogo.png");
    Noti.loadFromFile("Textures/notification.png");
}

void MainMenu::mainMenu(RenderWindow& window, Graph& graph, unordered_map<string, Graph>& graphs)
{
    window.setFramerateLimit(60); // Limit the frame rate to 60 FPS

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
    bool addCityDFSOpen = false;
    bool addCityBFSOpen = false;
    bool addCityPrimOpen = false;
    bool savedInfoAddCity = false;
    bool savedInfoAddEdge = false;
    bool savedInfoDeleteCity = false;
    bool savedInfoDeleteEdge = false;
    bool bfsResultOpen = false;
    bool dfsResultOpen = false;

    Clock bgClock;

    Sprite bgColorS(bgColor);
    bgColorS.setPosition(0, 0);

    Sprite roadMapLogo(Logo);
    roadMapLogo.setPosition(698, 140);

    Sprite NotiS(Noti);
    NotiS.setPosition(4510, 0);
    NotiS.setScale(0.6, 0.58);

    Sprite NotiAddEdgeS(Noti);
    NotiAddEdgeS.setPosition(4510, 0);
    NotiAddEdgeS.setScale(0.6, 0.58);

    Sprite NotiDeleteCityS(Noti);
    NotiDeleteCityS.setPosition(4510, 0);
    NotiDeleteCityS.setScale(0.6, 0.58);

    Sprite NotiDeleteEdgeS(Noti);
    NotiDeleteEdgeS.setPosition(4510, 0);
    NotiDeleteEdgeS.setScale(0.6, 0.58);

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
    ProceedToEditGraphS.setPosition(10400, 588);

    Sprite BFSs(addGraphButton);
    BFSs.setScale(0.42, 0.42);
    BFSs.setPosition(7980, 688);

    Sprite DFSs(addGraphButton);
    DFSs.setScale(0.42, 0.42);
    DFSs.setPosition(8480, 688);

    Sprite PRIMs(addGraphButton);
    PRIMs.setScale(0.42, 0.42);
    PRIMs.setPosition(8980, 688);

    Sprite popUpBoxAlgoS(popUpBox);
    popUpBoxAlgoS.setPosition(8340, 200);
    popUpBoxAlgoS.setScale(0.7, 0.7);

    RectangleShape closePopUpAlgo(Vector2f(40, 40));
    closePopUpAlgo.setPosition(popUpBoxAlgoS.getPosition().x + 512, popUpBoxAlgoS.getPosition().y + 19);

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
    addCityText.setPosition(3990, 170);

    addEdgeText.setString("Add Edge");
    addEdgeText.setFont(font);
    addEdgeText.setScale(1.5, 1.5);
    addEdgeText.setOutlineThickness(1.5);
    addEdgeText.setPosition(3990, 320);

    deleteCityText.setString("Delete City");
    deleteCityText.setFont(font);
    deleteCityText.setScale(1.5, 1.5);
    deleteCityText.setOutlineThickness(1.5);
    deleteCityText.setPosition(3990, 470);

    deleteEdgeText.setString("Delete Edge");
    deleteEdgeText.setFont(font);
    deleteEdgeText.setScale(1.5, 1.5);
    deleteEdgeText.setOutlineThickness(1.5);
    deleteEdgeText.setPosition(3990, 620);

    displayGraphText.setString("Display Graph");
    displayGraphText.setFont(font);
    displayGraphText.setScale(1.5, 1.5);
    displayGraphText.setOutlineThickness(1.5);
    displayGraphText.setPosition(3990, 770);

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

    EnterCityNameBFS.setString("Enter City Name : ");
    EnterCityNameBFS.setFont(font);
    EnterCityNameBFS.setScale(1, 1);
    EnterCityNameBFS.setOutlineThickness(1.2);
    EnterCityNameBFS.setPosition(popUpBoxAlgoS.getPosition().x + 48, popUpBoxAlgoS.getPosition().y + 150);

    cityNameBFS.setFont(font);
    cityNameBFS.setScale(1, 1);
    cityNameBFS.setOutlineThickness(1.2);
    cityNameBFS.setPosition(popUpBoxAlgoS.getPosition().x + 295, popUpBoxAlgoS.getPosition().y + 150);

    cityNameDFS.setFont(font);
    cityNameDFS.setScale(1, 1);
    cityNameDFS.setOutlineThickness(1.2);
    cityNameDFS.setPosition(popUpBoxAlgoS.getPosition().x + 295, popUpBoxAlgoS.getPosition().y + 150);

    cityNamePRIM.setFont(font);
    cityNamePRIM.setScale(1, 1);
    cityNamePRIM.setOutlineThickness(1.2);
    cityNamePRIM.setPosition(popUpBoxAlgoS.getPosition().x + 295, popUpBoxAlgoS.getPosition().y + 150);

    EnterCityNameDFS.setString("Enter City Name : ");
    EnterCityNameDFS.setFont(font);
    EnterCityNameDFS.setScale(1, 1);
    EnterCityNameDFS.setOutlineThickness(1.2);
    EnterCityNameDFS.setPosition(popUpBoxAlgoS.getPosition().x + 48, popUpBoxAlgoS.getPosition().y + 150);

    EnterCityNamePRIM.setString("Enter City Name : ");
    EnterCityNamePRIM.setFont(font);
    EnterCityNamePRIM.setScale(1, 1);
    EnterCityNamePRIM.setOutlineThickness(1.2);
    EnterCityNamePRIM.setPosition(popUpBoxAlgoS.getPosition().x + 48, popUpBoxAlgoS.getPosition().y + 150);

    saveInfoPopUpBFS.setString("Search");
    saveInfoPopUpBFS.setFont(font);
    saveInfoPopUpBFS.setScale(1.17, 1.17);
    saveInfoPopUpBFS.setOutlineThickness(1.5);
    saveInfoPopUpBFS.setPosition(popUpBoxAlgoS.getPosition().x + 378, popUpBoxAlgoS.getPosition().y + 300);

    saveInfoPopUpDFS.setString("Search");
    saveInfoPopUpDFS.setFont(font);
    saveInfoPopUpDFS.setScale(1.17, 1.17);
    saveInfoPopUpDFS.setOutlineThickness(1.5);
    saveInfoPopUpDFS.setPosition(popUpBoxAlgoS.getPosition().x + 378, popUpBoxAlgoS.getPosition().y + 300);

    saveInfoPopUpPRIM.setString("Search");
    saveInfoPopUpPRIM.setFont(font);
    saveInfoPopUpPRIM.setScale(1.17, 1.17);
    saveInfoPopUpPRIM.setOutlineThickness(1.5);
    saveInfoPopUpPRIM.setPosition(popUpBoxAlgoS.getPosition().x + 378, popUpBoxAlgoS.getPosition().y + 300);

    cancelInfoPopUpAlgo.setString("Cancel");
    cancelInfoPopUpAlgo.setFont(font);
    cancelInfoPopUpAlgo.setScale(1.17, 1.17);
    cancelInfoPopUpAlgo.setOutlineThickness(1.5);
    cancelInfoPopUpAlgo.setPosition(popUpBoxAlgoS.getPosition().x + 108, popUpBoxAlgoS.getPosition().y + 300);

    AddCityConfirmation.setString("City Added Successfully");
    AddCityConfirmation.setFont(font);
    AddCityConfirmation.setScale(1.17, 1.17);
    AddCityConfirmation.setOutlineThickness(1.5);
    AddCityConfirmation.setPosition(4600, 50);

    DeleteCityConfirmation.setString("City Deleted Successfully");
    DeleteCityConfirmation.setFont(font);
    DeleteCityConfirmation.setScale(1.17, 1.17);
    DeleteCityConfirmation.setOutlineThickness(1.5);
    DeleteCityConfirmation.setPosition(4600, 50);

    DeleteEdgeConfirmation.setString("Edge Deleted Successfully");
    DeleteEdgeConfirmation.setFont(font);
    DeleteEdgeConfirmation.setScale(1.17, 1.17);
    DeleteEdgeConfirmation.setOutlineThickness(1.5);
    DeleteEdgeConfirmation.setPosition(4600, 50);

    AddEdgeConfirmation.setString("Edge Added Successfully");
    AddEdgeConfirmation.setFont(font);
    AddEdgeConfirmation.setScale(1.17, 1.17);
    AddEdgeConfirmation.setOutlineThickness(1.5);
    AddEdgeConfirmation.setPosition(4600, 50);
    //Text selectedGraphCityT;


    int activeFieldAddCity = 0;
    int activeFieldDeleteCity = 0;
    int activeFieldAddEdge = 0;
    int activeFieldDeleteEdge = 0;

    string userInputCityName;
    string userInputCityNameDelete;
    string userInputaddEdgeInfo[3];
    string userInputDeleteEdgeInfo[2];
    string userInputCityNameBFS;
    string userInputCityNameDFS;
    string userInputCityNamePRIM;

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
                    if (ProceedToEditGraphS.getGlobalBounds().contains(event.mouseButton.x + 9600, event.mouseButton.y) && ProceedToEditGraphOpen)
                    {
                        ProceedToEditGraphOpen = false;
                        window.setView(pane3);
                    }
                    if (DFSs.getGlobalBounds().contains(event.mouseButton.x + 7680, event.mouseButton.y) && DFSOpen)
                    {
                        DFSOpen = false;
                        BFSOpen = false;
                        PrimOpen = false;
                        bfsResultOpen = false;
                        dfsResultOpen = false;
                        addCityDFSOpen = true;
                    }
                    if (BFSs.getGlobalBounds().contains(event.mouseButton.x + 7680, event.mouseButton.y) && BFSOpen)
                    {
                        DFSOpen = false;
                        BFSOpen = false;
                        PrimOpen = false;
                        bfsResultOpen = false;
                        dfsResultOpen = false;
                        addCityBFSOpen = true;
                    }
                    if (PRIMs.getGlobalBounds().contains(event.mouseButton.x + 7680, event.mouseButton.y) && PrimOpen)
                    {
                        DFSOpen = false;
                        BFSOpen = false;
                        PrimOpen = false;
                        bfsResultOpen = false;
                        dfsResultOpen = false;
                        addCityPrimOpen = true;
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
                        graph.displayGraph();
                        DFSOpen = true;
                        BFSOpen = true;
                        PrimOpen = true;
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
                    if (closePopUpAlgo.getGlobalBounds().contains(event.mouseButton.x + 7680, event.mouseButton.y))
                    {
                        userInputCityNameBFS.clear();
                        cityNameBFS.setString("");
                        userInputCityNameDFS.clear();
                        cityNameDFS.setString("");
                        userInputCityNamePRIM.clear();
                        cityNamePRIM.setString("");
                        BFSOpen = true;
                        DFSOpen = true;
                        PrimOpen = true;

                    }
                    if (closePopUpAlgo.getGlobalBounds().contains(event.mouseButton.x + 7680, event.mouseButton.y))
                    {
                        userInputCityNameBFS.clear();
                        cityNameBFS.setString("");
                        userInputCityNameDFS.clear();
                        cityNameDFS.setString("");
                        userInputCityNamePRIM.clear();
                        cityNamePRIM.setString("");
                        BFSOpen = true;
                        DFSOpen = true;
                        PrimOpen = true;
                        addCityBFSOpen = false;
                        addCityDFSOpen = false;
                        addCityPrimOpen = false;
                    }
                    if (saveInfoPopUpBFS.getGlobalBounds().contains(event.mouseButton.x + 7680, event.mouseButton.y))     //save hena el info men el user 
                    {
                        if (!userInputCityNameBFS.empty() && graph.CityExist(userInputCityNameBFS)) {
                            string bfsResult,strBFS;
                            graph.BFS(userInputCityNameBFS, bfsResult);
                            bfsOrderText.setString(bfsResult);
                            bfsOrderText.setFont(font);
                            bfsOrderText.setScale(1.5, 1.5);
                            bfsOrderText.setOutlineThickness(1.3);
                            bfsOrderText.setPosition(7780, 380);
                            userInputCityNameBFS.clear();
                            cityNameBFS.setString("");
                            addCityBFSOpen = false;
                            dfsResultOpen = false;
                            bfsResultOpen = true;
                            BFSOpen = true;
                            DFSOpen = true;
                            PrimOpen = true;
                        }
                    }
                    if (saveInfoPopUpDFS.getGlobalBounds().contains(event.mouseButton.x + 7680, event.mouseButton.y))     //save hena el info men el user 
                    {
                        if (!userInputCityNameDFS.empty() && graph.CityExist(userInputCityNameDFS)) {
                            string dfsResult;
                            graph.DFS(userInputCityNameDFS, dfsResult);
                            dfsOrderText.setString(dfsResult);
                            dfsOrderText.setFont(font);
                            dfsOrderText.setScale(1.5, 1.5);
                            dfsOrderText.setOutlineThickness(1.3);
                            dfsOrderText.setPosition(7780, 380);
                            userInputCityNameDFS.clear();
                            cityNameDFS.setString("");
                            addCityDFSOpen = false;
                            bfsResultOpen = false;
                            dfsResultOpen = true;
                            BFSOpen = true;
                            DFSOpen = true;
                            PrimOpen = true;
                        }
                    }
                    if (saveInfoPopUpPRIM.getGlobalBounds().contains(event.mouseButton.x + 7680, event.mouseButton.y))     //save hena el info men el user 
                    {
                        if (!userInputCityNamePRIM.empty() && graph.CityExist(userInputCityNamePRIM)) {
                            vector<pair<int, pair<string, string>>> MST = graph.Prim(userInputCityNamePRIM);
                            graph.drawMST(MST);
                            userInputCityNamePRIM.clear();
                            cityNamePRIM.setString("");
                            addCityPrimOpen = false;
                            BFSOpen = true;
                            DFSOpen = true;
                            PrimOpen = true;
                        }
                    }
                    if (saveInfoPopUpAddCity.getGlobalBounds().contains(event.mouseButton.x + 3840, event.mouseButton.y))     //save hena el info men el user 
                    {
                        if (!userInputCityName.empty()) {
                            bgClock.restart();
                            savedInfoAddCity = true;
                            graph.addCity(City(userInputCityName));
                            cout << graph.getCities()[userInputCityName].getCityName() << endl;
                            userInputCityName.clear();
                            cityName.setString("");
                            addCityOpen = false;
                        }
                    }
                    if (saveInfoPopUpAddEdge.getGlobalBounds().contains(event.mouseButton.x + 3840, event.mouseButton.y))     //save hena el info men el user 
                    {

                        if (!userInputaddEdgeInfo[0].empty() && !userInputaddEdgeInfo[1].empty() && !userInputaddEdgeInfo[2].empty() && graph.CityExist(userInputaddEdgeInfo[0]) && graph.CityExist(userInputaddEdgeInfo[1])) {
                            bgClock.restart();
                            savedInfoAddEdge = true;
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
                        if (!userInputDeleteEdgeInfo[0].empty() && !userInputDeleteEdgeInfo[1].empty() && graph.EdgeExist(userInputDeleteEdgeInfo[0], userInputDeleteEdgeInfo[1])) {
                            bgClock.restart();
                            savedInfoDeleteEdge = true;
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
                        if (!userInputCityNameDelete.empty() && graph.CityExist(userInputCityNameDelete)) {
                            savedInfoDeleteCity = true;
                            bgClock.restart();
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
                    if (cancelInfoPopUpAlgo.getGlobalBounds().contains(event.mouseButton.x + 7680, event.mouseButton.y))
                    {
                        userInputCityNameBFS.clear();
                        cityNameBFS.setString("");

                        userInputCityNameDFS.clear();
                        cityNameDFS.setString("");

                        userInputCityNamePRIM.clear();
                        cityNamePRIM.setString("");
                        BFSOpen = true;
                        DFSOpen = true;
                        PrimOpen = true;
                        addCityBFSOpen = false;
                        addCityDFSOpen = false;
                        addCityPrimOpen = false;
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
                        bfsResultOpen = false;
                        dfsResultOpen = false;
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
                if (Start.getGlobalBounds().contains(mousePos)) {
                    Start.setScale(0.34, 0.34);
                }
                else
                {
                    Start.setScale(0.35, 0.35);
                }
                if (addGraphButtonS.getGlobalBounds().contains(mousePos)) {
                    addGraphButtonS.setScale(0.34, 0.34);
                }
                else
                {
                    addGraphButtonS.setScale(0.35, 0.35);
                }
                if (loadGraphButtonS.getGlobalBounds().contains(mousePos)) {
                    loadGraphButtonS.setScale(0.34, 0.34);
                }
                else
                {
                    loadGraphButtonS.setScale(0.35, 0.35);
                }
                if (backIconAddGraphS.getGlobalBounds().contains(mousePos)) {
                    backIconAddGraphS.setScale(0.15, 0.15);
                }
                else
                {
                    backIconAddGraphS.setScale(0.16, 0.16);
                }
                if (backIconLoadGraphS.getGlobalBounds().contains(mousePos)) {
                    backIconLoadGraphS.setScale(0.15, 0.15);
                }
                else
                {
                    backIconLoadGraphS.setScale(0.16, 0.16);
                }
                if (backIconDisplayGraphS.getGlobalBounds().contains(mousePos)) {
                    backIconDisplayGraphS.setScale(0.15, 0.15);
                }
                else
                {
                    backIconDisplayGraphS.setScale(0.16, 0.16);
                }
                if (backIconLoadGraphDataS.getGlobalBounds().contains(mousePos)) {
                    backIconLoadGraphDataS.setScale(0.15, 0.15);
                }
                else
                {
                    backIconLoadGraphDataS.setScale(0.16, 0.16);
                }
                if (ProceedToEditGraphS.getGlobalBounds().contains(mousePos)) {
                    ProceedToEditGraphS.setScale(0.41, 0.41);
                }
                else
                {
                    ProceedToEditGraphS.setScale(0.42, 0.42);
                }
                if (BFSs.getGlobalBounds().contains(mousePos)) {
                    BFSs.setScale(0.41, 0.41);
                }
                else
                {
                    BFSs.setScale(0.42, 0.42);
                }
                if (DFSs.getGlobalBounds().contains(mousePos)) {
                    DFSs.setScale(0.41, 0.41);
                }
                else
                {
                    DFSs.setScale(0.42, 0.42);
                }
                if (PRIMs.getGlobalBounds().contains(mousePos)) {
                    PRIMs.setScale(0.41, 0.41);
                }
                else
                {
                    PRIMs.setScale(0.42, 0.42);
                }
                if (saveInfoPopUpAddCity.getGlobalBounds().contains(mousePos)) {
                    saveInfoPopUpAddCity.setScale(1.15, 1.15);
                }
                else
                {
                    saveInfoPopUpAddCity.setScale(1.17, 1.17);
                }
                if (saveInfoPopUpAddEdge.getGlobalBounds().contains(mousePos)) {
                    saveInfoPopUpAddEdge.setScale(1.15, 1.15);
                }
                else
                {
                    saveInfoPopUpAddEdge.setScale(1.17, 1.17);
                }
                if (saveInfoPopUpDeleteCity.getGlobalBounds().contains(mousePos)) {
                    saveInfoPopUpDeleteCity.setScale(1.15, 1.15);
                }
                else
                {
                    saveInfoPopUpDeleteCity.setScale(1.17, 1.17);
                }
                if (saveInfoPopUpDeleteEdge.getGlobalBounds().contains(mousePos)) {
                    saveInfoPopUpDeleteEdge.setScale(1.15, 1.15);
                }
                else
                {
                    saveInfoPopUpDeleteEdge.setScale(1.17, 1.17);
                }
                if (cancelInfoPopUp.getGlobalBounds().contains(mousePos)) {
                    cancelInfoPopUp.setScale(1.15, 1.15);
                }
                else
                {
                    cancelInfoPopUp.setScale(1.17, 1.17);
                }
                if (saveInfoPopUpBFS.getGlobalBounds().contains(mousePos)) {
                    saveInfoPopUpBFS.setScale(1.15, 1.15);
                }
                else
                {
                    saveInfoPopUpBFS.setScale(1.17, 1.17);
                }
                if (saveInfoPopUpDFS.getGlobalBounds().contains(mousePos)) {
                    saveInfoPopUpDFS.setScale(1.15, 1.15);
                }
                else
                {
                    saveInfoPopUpDFS.setScale(1.17, 1.17);
                }
                if (saveInfoPopUpPRIM.getGlobalBounds().contains(mousePos)) {
                    saveInfoPopUpPRIM.setScale(1.15, 1.15);
                }
                else
                {
                    saveInfoPopUpPRIM.setScale(1.17, 1.17);
                }
                if (cancelInfoPopUpAlgo.getGlobalBounds().contains(mousePos)) {
                    cancelInfoPopUpAlgo.setScale(1.15, 1.15);
                }
                else
                {
                    cancelInfoPopUpAlgo.setScale(1.17, 1.17);
                }
                for (int i = 1; i < graphs.size(); i++)
                {
                    if (borderS[i].getGlobalBounds().contains(mousePos)) {
                        borderS[i].setScale(0.538, 0.588);
                    }
                    else
                    {
                        borderS[i].setScale(0.55, 0.6);
                    }
                }

            }
            else if (event.type == sf::Event::TextEntered) {
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
                if (event.text.unicode < 128 && addCityBFSOpen) {
                    if (event.text.unicode == '\b' && !userInputCityNameBFS.empty()) { // Backspace
                        userInputCityNameBFS.pop_back();
                        cityNameBFS.setString(userInputCityNameBFS);
                    }
                    else {
                        userInputCityNameBFS += static_cast<char>(event.text.unicode);
                        cityNameBFS.setString(userInputCityNameBFS);
                    }
                }
                if (event.text.unicode < 128 && addCityDFSOpen) {
                    if (event.text.unicode == '\b' && !userInputCityNameDFS.empty()) { // Backspace
                        userInputCityNameDFS.pop_back();
                        cityNameDFS.setString(userInputCityNameDFS);
                    }
                    else {
                        userInputCityNameDFS += static_cast<char>(event.text.unicode);
                        cityNameDFS.setString(userInputCityNameDFS);
                    }
                }
                if (event.text.unicode < 128 && addCityPrimOpen) {
                    if (event.text.unicode == '\b' && !userInputCityNamePRIM.empty()) { // Backspace
                        userInputCityNamePRIM.pop_back();
                        cityNamePRIM.setString(userInputCityNamePRIM);
                    }
                    else {
                        userInputCityNamePRIM += static_cast<char>(event.text.unicode);
                        cityNamePRIM.setString(userInputCityNamePRIM);
                    }
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
        if (addCityBFSOpen)
        {
            window.draw(popUpBoxAlgoS);
            window.draw(saveInfoPopUpBFS);
            window.draw(cancelInfoPopUpAlgo);
            window.draw(EnterCityNameBFS);
            window.draw(cityNameBFS);
        }
        if (addCityDFSOpen)
        {
            window.draw(popUpBoxAlgoS);
            window.draw(saveInfoPopUpDFS);
            window.draw(cancelInfoPopUpAlgo);
            window.draw(EnterCityNameDFS);
            window.draw(cityNameDFS);
        }
        if (addCityPrimOpen)
        {
            window.draw(popUpBoxAlgoS);
            window.draw(saveInfoPopUpPRIM);
            window.draw(cancelInfoPopUpAlgo);
            window.draw(EnterCityNamePRIM);
            window.draw(cityNamePRIM);
        }
        if (bfsResultOpen)
        {
            window.draw(bfsOrderText);
        }
        if (dfsResultOpen)
        {
            window.draw(dfsOrderText);
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
        if (savedInfoAddCity && bgClock.getElapsedTime().asSeconds() <= 2.f)
        {
            window.draw(NotiS);
            window.draw(AddCityConfirmation);
        }
        if (savedInfoDeleteCity && bgClock.getElapsedTime().asSeconds() <= 2.f)
        {
            window.draw(NotiDeleteCityS);
            window.draw(DeleteCityConfirmation);
        }
        if (savedInfoDeleteEdge && bgClock.getElapsedTime().asSeconds() <= 2.f)
        {
            window.draw(NotiDeleteEdgeS);
            window.draw(DeleteEdgeConfirmation);
        }
        if (savedInfoAddEdge && bgClock.getElapsedTime().asSeconds() <= 2.f)
        {
            window.draw(NotiAddEdgeS);
            window.draw(AddEdgeConfirmation);
        }
        window.draw(bgColorS);
        window.draw(roadMapLogo);
        if (startOpen && bgClock.getElapsedTime().asSeconds() <= 2.5f)
        {
            float alpha = 255.f * (1.f - (bgClock.getElapsedTime().asSeconds() / 2.5f));
            bgColorS.setColor(Color(255, 255, 255, static_cast<Uint8>(alpha)));
            // roadMapLogo.setColor(Color(255, 255, 255, static_cast<Uint8>(alpha)));
        }

        window.display();
    }
}