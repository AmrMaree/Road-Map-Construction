#include<string>
#pragma once
using namespace std;
class Edge
{
private:
	string destinationCity;
	int weight;
public:
	Edge();
	Edge(string destCity, int w);
	void setEdgeValue(string destCity, int w);
	string getDestinationCity();
	int getWeight();

};

