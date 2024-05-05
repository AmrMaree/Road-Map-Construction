#include "Graph.h"

string Graph::getGraphName()
{
    return graphName;
}

void Graph::setGraphName(string graphName)
{
    this->graphName = graphName;
}

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

    string reqDest;
    /* string Des = cities[cityName].getEdgeList().getDestinationCity();*/
    vector<Edge> edgeList = cities[cityName].getEdgeList();
    for (Edge edge : edgeList)
    {
        reqDest = edge.getDestinationCity();
        deleteEdge(reqDest, cityName);
    }
    cities.erase(cityName);
    cout << cityName << "city is deleted successfully" << endl;

}

void Graph::addEdge(string sourceCity, string destinationCity, int weight)
{
    vector <Edge> edgeListSource;
    vector <Edge> edgeListDestination;

    /* if (!CityExist(sourceCity))
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
     */
    if (EdgeExist(sourceCity, destinationCity)) {
        //cout << "edge from '" << sourcecity << "' to '" << destinationcity << "' already exists.\n";
        return;
    }

    edgeListSource = cities[sourceCity].getEdgeList();
    edgeListSource.push_back(Edge(sourceCity, destinationCity, weight));
    cities[sourceCity].setEdgeList(edgeListSource);

    edgeListDestination = cities[destinationCity].getEdgeList();
    edgeListDestination.push_back(Edge(destinationCity, sourceCity, weight));
    cities[destinationCity].setEdgeList(edgeListDestination);

    //cout << "Edge successfully added from '" << sourceCity << "' to '" << destinationCity << "' with weight " << weight << ".\n";
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

bool Graph :: isClose(float x1, float y1, float x2, float y2, float minDistance)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    return (dx * dx + dy * dy) < (minDistance * minDistance);
}

void Graph::displayGraph()
{
    RenderWindow window(sf::VideoMode(900, 700), "");
    window.setFramerateLimit(60);

    Texture map1;
    map1.loadFromFile("Textures/map1.png");
    Sprite map1S(map1);
    map1S.setTexture(map1);

    Texture LocationIcon;
    LocationIcon.loadFromFile("Textures/LocationIcon.png");

    Font font;
    font.loadFromFile("Fonts/font.otf");

    // Generate random positions for each city
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> disX(100, 700);// Random x coordinate between 50 and 750
    uniform_int_distribution<> disY(100, 500); // Random y coordinate between 50 and 550

    for (auto pair : cities) {
        City city = pair.second;
        float x = static_cast<float>(disX(gen));
        float y = static_cast<float>(disY(gen));
        // Check if the city is too close to any other city
        for (auto& pair : cities) {
            City& city = pair.second;
            float x = static_cast<float>(disX(gen));
            float y = static_cast<float>(disY(gen));
            // Check if the city is too close to any other city
            bool tooClose;
            do {
                tooClose = false;
                for (auto otherPair : cities) {
                    City otherCity = otherPair.second;
                    if (&city != &otherCity && isClose(x, y, otherCity.getX(), otherCity.getY(), 200.f)) {
                        // Adjust the position if too close
                        x = static_cast<float>(disX(gen));
                        y = static_cast<float>(disY(gen));
                        tooClose = true;
                        break; // Exit the loop to check again
                    }
                }
            } while (tooClose);
            city.setX(x);
            city.setY(y);
        }
    }

    // Calculate offset to center the graph
    float offsetX = 450.f; // Half the width of the window
    float offsetY = 350.f; // Half the height of the window
    float graphCenterX = 0.f;
    float graphCenterY = 0.f;
    for (auto pair : cities) {
        graphCenterX += pair.second.getX();
        graphCenterY += pair.second.getY();
    }
    graphCenterX /= cities.size();
    graphCenterY /= cities.size();
    offsetX -= graphCenterX;
    offsetY -= graphCenterY;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(sf::Color::White);
        window.draw(map1S);

            // Draw cities
        for (auto pair : cities) {
            City city = pair.second;
            Sprite LocationIconS(LocationIcon);
            LocationIconS.setTexture(LocationIcon);
            LocationIconS.setScale(0.1, 0.1);
            LocationIconS.setPosition(city.getX() + offsetX, city.getY() + offsetY);
            window.draw(LocationIconS);

            // Draw city name
            Text text;
            text.setString(city.getCityName());
            text.setFont(font);
            text.setCharacterSize(25);
            text.setOutlineThickness(1.1);
            text.setFillColor(Color::Black);
            text.setPosition(city.getX() + offsetX + 45, city.getY() + offsetY - 5);
            window.draw(text);

            // Draw edges
            for (Edge edge : city.getEdgeList()) {
                City destinationCity = cities[edge.getDestinationCity()];
                VertexArray line(sf::Lines, 2);
                line[0].position = Vector2f(city.getX() + offsetX + 25, city.getY() + offsetY + 20);
                line[1].position = Vector2f(destinationCity.getX()+ offsetX + 25, destinationCity.getY() + offsetY + 20);
                line[0].color = sf::Color::Black;
                line[1].color = sf::Color::Black;
                window.draw(line);
            } 
        }
        window.display();
    }
}


unordered_map<string, City> Graph::getCities()
{
    return cities;
}

void Graph::clearGraph() {
    cities.clear();
}

void Graph::setCities(string cityName)
{
    cities[cityName] = City(cityName);
}

void Graph::DFS(string startCity) {
    if (!CityExist(startCity)) {
        cout << "Starting city not found.\n";
        return;
    }

    unordered_map<string, bool> visited;
    stack<City> stack;
    stack.push(getCity(startCity));
    while (!stack.empty()) {
        City currentCity = stack.top();
        stack.pop();
        if (!visited[currentCity.getCityName()]) {
            cout << currentCity.getCityName() << " ";
            visited[currentCity.getCityName()] = true;
            for (Edge edge : currentCity.getEdgeList()) {
                if (!visited[edge.getDestinationCity()]) {
                    stack.push(getCity(edge.getDestinationCity()));
                }
            }
        }
    }
    cout << endl;
}

void Graph::BFS(string cityName) {
    unordered_map<string, bool> visited;
    queue<City> queue;
    if (cities.find(cityName) != cities.end()) {
        queue.push(getCity(cityName));
        visited[cityName] = true;
        while (!queue.empty()) {
            City current = queue.front();
            queue.pop();
            cout << current.getCityName() << ' ';
            for (Edge edge : current.getEdgeList()) {
                if (!visited[edge.getDestinationCity()]) {
                    queue.push(getCity(edge.getDestinationCity()));
                    visited[edge.getDestinationCity()] = true;
                }
            }
        }
        cout << endl;
    }
}

void Graph::Prim(string startCity) {
    if (!CityExist(startCity)) {
        cout << "Starting city not found.\n";
        return;
    }

    unordered_map<string, bool> visited;
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    vector<pair<string, int>> MST; // Store MST edges

    // Mark all cities as unvisited
    for (auto pair : cities) {
        visited[pair.first] = false;
    }

    // Start with the given city
    pq.push({ 0, startCity });

    while (!pq.empty()) {
        string currentCity = pq.top().second;
        int currentWeight = pq.top().first;
        pq.pop();

        if (!visited[currentCity]) {
            visited[currentCity] = true;

            // Add edge to MST
            if (currentCity != startCity) {
                MST.push_back({ currentCity, currentWeight });
            }

            // Visit neighbors and update priority queue
            for (Edge edge : cities[currentCity].getEdgeList()) {
                if (!visited[edge.getDestinationCity()]) {
                    pq.push({ edge.getWeight(), edge.getDestinationCity() });
                }
            }
        }
    }

    // Print MST edges
    cout << "Minimum Spanning Tree (MST) Edges:\n";
    for (auto edge : MST) {
        cout << edge.first << " - " << edge.second << endl;
    }
}