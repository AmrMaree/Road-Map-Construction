#include<string>
#pragma once
using namespace std;
class Edge
{
	int destinationCity;
	int weight;
	Edge();
	Edge(int destCity, int w);
	void setEdgeValue(string destCity, int w);
};

