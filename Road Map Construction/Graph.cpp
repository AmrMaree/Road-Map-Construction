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
        return;
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
    cout << cityName << " city is deleted successfully" << endl;

}

void Graph::addEdge(string sourceCity, string destinationCity, int weight)
{
    vector <Edge> edgeListSource;
    vector <Edge> edgeListDestination;

     if (!CityExist(sourceCity))
     {
         return;
     }

     if (!CityExist(destinationCity)) 
     {
         return;
     }
    
     if (EdgeExist(sourceCity, destinationCity)) 
     {
         return;
     }

    edgeListSource = cities[sourceCity].getEdgeList();
    edgeListSource.push_back(Edge(sourceCity, destinationCity, weight));
    cities[sourceCity].setEdgeList(edgeListSource);

    edgeListDestination = cities[destinationCity].getEdgeList();
    edgeListDestination.push_back(Edge(destinationCity, sourceCity, weight));
    cities[destinationCity].setEdgeList(edgeListDestination);
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

bool Graph::isClose(float x1, float y1, float x2, float y2, float minDistance)
{
    float dx = x2 - x1;
    float dy = y2 - y1;
    return (dx * dx + dy * dy) < (minDistance * minDistance);
}

void Graph::displayGraph()
{
    RenderWindow window(sf::VideoMode(900, 700), "Graph Drawing");
    window.setFramerateLimit(60);

    Texture bg;
    bg.loadFromFile("Textures/bgColor.png");
    Sprite bgS(bg);

    Texture locationIcon;
    locationIcon.loadFromFile("Textures/LocationIcon.png");

    Font font;
    font.loadFromFile("Fonts/font.otf");

    // Generate random positions for each city
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> disX(100, 700);// Random x coordinate between 50 and 750
    uniform_int_distribution<> disY(100, 500); // Random y coordinate between 50 and 550
 
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
    
    // Calculate offset to center the graph
    float offsetX = 400.f; // Half the width of the window
    float offsetY = 300.f; // Half the height of the window
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
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(Color::White);
        window.draw(bgS);
        // Draw cities
        for (auto pair : cities) {
            City city = pair.second;
            Sprite locationIconS(locationIcon);
            locationIconS.setScale(0.1, 0.1);
            locationIconS.setPosition(city.getX() + offsetX, city.getY() + offsetY);
            window.draw(locationIconS);

            // Draw city name
            Text text;
            text.setString(city.getCityName());
            text.setFont(font);
            text.setCharacterSize(25);
            text.setOutlineThickness(1.07);
            text.setFillColor(sf::Color::Black);
            text.setPosition(city.getX() + offsetX + 45, city.getY() + offsetY - 5);
            window.draw(text);

            // Draw edges
            for (Edge edge : city.getEdgeList()) {
                City destinationCity = cities[edge.getDestinationCity()];
                VertexArray line(sf::Lines, 2);
                line[0].position = Vector2f(city.getX() + offsetX + 25, city.getY() + offsetY + 20);
                line[1].position = Vector2f(destinationCity.getX() + offsetX + 25, destinationCity.getY() + offsetY + 20);
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

void Graph::BFS(string startCity, string& bfsOrder) {
    if (!CityExist(startCity)) {
        bfsOrder = "Starting city not found.\n";
        return;
    }
    unordered_map<string, bool> visited;
    queue<City> queue;
    queue.push(getCity(startCity));
    visited[startCity] = true;
    while (!queue.empty()) {
        City current = queue.front();
        queue.pop();
        bfsOrder += current.getCityName() + "  --> ";
        for (Edge edge : current.getEdgeList()) {
            if (!visited[edge.getDestinationCity()]) {
                queue.push(getCity(edge.getDestinationCity()));
                visited[edge.getDestinationCity()] = true;
            }
        }
    }

    bfsOrder = bfsOrder.substr(0, bfsOrder.length() - 4);
}

void Graph::DFS(string startCity, string& dfsOrder) {
    if (!CityExist(startCity)) {
        dfsOrder = "Starting city not found.\n";
        return;
    }
    unordered_map<string, bool> visited;
    stack<City> stack;
    stack.push(getCity(startCity));
    while (!stack.empty()) {
        City currentCity = stack.top();
        stack.pop();
        if (!visited[currentCity.getCityName()]) {
            dfsOrder += currentCity.getCityName() + "  --> ";
            visited[currentCity.getCityName()] = true;
            for (Edge edge : currentCity.getEdgeList()) {
                if (!visited[edge.getDestinationCity()]) {
                    stack.push(getCity(edge.getDestinationCity()));
                }
            }
        }
    }
    dfsOrder = dfsOrder.substr(0, dfsOrder.length() - 4);
}

vector<pair<int, pair<string, string>>> Graph::Prim(string startCity) {

    unordered_map<string, bool> visited;
    priority_queue<pair<int, pair<string, string>>, vector<pair<int, pair<string, string>>>, greater<pair<int, pair<string, string>>>> pq;
    vector<pair<int, pair<string, string>>> MST; // Store MST edges (weight, (sourceCity, destinationCity))

    if (!CityExist(startCity)) {
        cout << "Starting city not found.\n";
        return MST;
    }


    // Mark all cities as unvisited
    for (auto pair : cities) {
        visited[pair.first] = false;
    }

    // Start with the given city
    pq.push({ 0, {startCity, startCity} }); // Source city is the same as destination city for the start

    while (!pq.empty()) {
        string sourceCity = pq.top().second.first;
        string destinationCity = pq.top().second.second;
        int currentWeight = pq.top().first;
        pq.pop();

        if (!visited[destinationCity]) {
            visited[destinationCity] = true;

            // Add edge to MST
            if (destinationCity != startCity) {
                MST.push_back({ currentWeight, {sourceCity, destinationCity} });
            }

            // Visit neighbors and update priority queue
            for (Edge edge : cities[destinationCity].getEdgeList()) {
                if (!visited[edge.getDestinationCity()]) {
                    pq.push({ edge.getWeight(), {destinationCity, edge.getDestinationCity()} });
                }
            }
        }
    }

    // Print MST edges
    cout << "Minimum Spanning Tree (MST) Edges:\n";
    for (auto edge : MST) {
        cout << "Edge: " << edge.second.first << " - " << edge.second.second << ", Weight: " << edge.first << endl;
    }
    return MST;
}

void Graph::drawMST(vector<pair<int, pair<string, string>>> MST) {
    RenderWindow window(sf::VideoMode(900, 700), "Graph Drawing");
    window.setFramerateLimit(60);

    Texture bg;
    bg.loadFromFile("Textures/bgColor.png");
    Sprite bgS(bg);

    Texture locationIcon;
    locationIcon.loadFromFile("Textures/LocationIcon.png");

    Font font;
    font.loadFromFile("Fonts/font.otf");

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear(Color::White);
        window.draw(bgS);
        // Draw cities
        for (auto pair : cities) {
            City city = pair.second;
            Sprite locationIconS(locationIcon);
            locationIconS.setScale(0.1, 0.1);
            locationIconS.setPosition(city.getX(), city.getY());
            window.draw(locationIconS);

            // Draw city name
            Text text;
            text.setString(city.getCityName());
            text.setFont(font);
            text.setCharacterSize(25);
            text.setOutlineThickness(1.07);
            text.setFillColor(Color::Black);
            text.setPosition(city.getX() + 45, city.getY() - 5);
            window.draw(text);
        }

        // Draw MST edges
        for (auto edge : MST) {
            string sourceCityName = edge.second.first;
            string destinationCityName = edge.second.second;
            int weight = edge.first;

            if (cities.find(sourceCityName) != cities.end() && cities.find(destinationCityName) != cities.end()) {
                City sourceCity = cities[sourceCityName];
                City destinationCity = cities[destinationCityName];

                VertexArray line(Lines, 2);
                line[0].position = Vector2f(sourceCity.getX() + 25, sourceCity.getY() + 20);
                line[1].position = Vector2f(destinationCity.getX() + 25, destinationCity.getY() + 20);
                line[0].color = Color::Red; // You can choose any color you want for MST edges
                line[1].color = Color::Red;
                window.draw(line);

                // Draw weight of the edge
                Text weightText;
                weightText.setString(to_string(weight));
                weightText.setFont(font);
                weightText.setCharacterSize(25);
                weightText.setOutlineThickness(1.07);
                weightText.setFillColor(Color::Black);
                float textX = (sourceCity.getX() + destinationCity.getX()) / 2.0f;
                float textY = (sourceCity.getY() + destinationCity.getY()) / 2.0f;
                weightText.setPosition(textX, textY);
                window.draw(weightText);
            }
        }

        window.display();
    }
}
void Graph::Dijkstra(string sourceCity) {
    // Initialize distances for all cities as infinite
    unordered_map<string, int> distances;
    for (auto const& city : cities) {
        distances[city.first] = numeric_limits<int>::max();
    }

    // Priority queue to store cities with minimum distance
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

    // Set source city distance to 0 and mark it visited
    distances[sourceCity] = 0;
    pq.push({ 0, sourceCity });

    while (!pq.empty()) {
        // Get the city with the minimum distance from the priority queue
        string cityName = pq.top().second;
        int currentDistance = pq.top().first;
        pq.pop();

        // Process neighbors of the current city
        for (Edge edge : cities[cityName].getEdgeList()) {
            string neighbor = edge.getDestinationCity();
            int newDistance = currentDistance + edge.getWeight();

            // Update distance if the new path is shorter
            if (distances[neighbor] > newDistance) {
                distances[neighbor] = newDistance;
                pq.push({ newDistance, neighbor }); // Update priority queue with new distance and city
            }
        }
    }

    // Print the results with (distance, city) pairs
    cout << "Shortest distances from source city " << sourceCity << ":" << endl;
    for (auto const& city : cities) {
        if (distances[city.first] != numeric_limits<int>::max()) {
            cout << city.first << " - " << distances[city.first] << endl;
        }
        else {
            cout << city.first << " - Unreachable" << endl; // Unreachable city marked with "Unreachable"
        }
    }
}
void Graph::drawDijkstra(string sourceCity) {
    // Calculate shortest distances using Dijkstra's algorithm
    unordered_map<string, int> distances;
    for (auto const& city : cities) {
        distances[city.first] = numeric_limits<int>::max();
    }
    priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;
    distances[sourceCity] = 0;
    pq.push({ 0, sourceCity });

    while (!pq.empty()) {
        string cityName = pq.top().second;
        int currentDistance = pq.top().first;
        pq.pop();

        for (Edge edge : cities[cityName].getEdgeList()) {
            string neighbor = edge.getDestinationCity();
            int newDistance = currentDistance + edge.getWeight();
            if (distances[neighbor] > newDistance) {
                distances[neighbor] = newDistance;
                pq.push({ newDistance, neighbor });
            }
        }
    }

    // Create window
    RenderWindow window(sf::VideoMode(900, 700), "Dijkstra Graph Drawing");
    window.setFramerateLimit(60);

    // Load textures and font
    Texture bg;
    bg.loadFromFile("Textures/bgColor.png");
    Sprite bgS(bg);

    Texture locationIcon;
    locationIcon.loadFromFile("Textures/LocationIcon.png");

    Font font;
    font.loadFromFile("Fonts/font.otf");

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(Color::White);
        window.draw(bgS);
        // Draw cities
        for (auto pair : cities) {
            City city = pair.second;
            Sprite locationIconS(locationIcon);
            locationIconS.setScale(0.1, 0.1);
            locationIconS.setPosition(city.getX(), city.getY());
            window.draw(locationIconS);

            // Draw city name
            Text text;
            text.setString(city.getCityName());
            text.setFont(font);
            text.setCharacterSize(25);
            text.setOutlineThickness(1.07);
            text.setFillColor(Color::Black);
            text.setPosition(city.getX() + 45, city.getY() - 5);
            window.draw(text);

            

            // Draw edges
            for (Edge edge : cities[city.getCityName()].getEdgeList()) {
                City destinationCity = cities[edge.getDestinationCity()];
                VertexArray line(Lines, 2);
                line[0].position = Vector2f(city.getX() + 25, city.getY() + 20);
                line[1].position = Vector2f(destinationCity.getX() + 25, destinationCity.getY() + 20);
                line[0].color = Color::Red;
                line[1].color = Color::Red;
                window.draw(line);
                // Calculate midpoint of the line
                float midX = (city.getX() + destinationCity.getX()) / 2.0f;
                float midY = (city.getY() + destinationCity.getY()) / 2.0f;

                // Draw distance as text
                Text distanceText;
                distanceText.setString(to_string(edge.getWeight())); // Assuming edge weight is the distance
                distanceText.setFont(font);
                distanceText.setCharacterSize(25);
                distanceText.setOutlineThickness(0.55);
                distanceText.setFillColor(Color::Black);
                distanceText.setPosition(midX, midY);
                window.draw(distanceText);
            }
        }

        window.display();
    }
}


