#include<string>
#pragma once
using namespace std;
class Edge
{
private:
	string sourceCity;
	string destinationCity;
	int weight;
public:
	Edge();
	Edge(string sourceCity,string destCity, int w);
	string getSourceCity();
	string getDestinationCity();
	int getWeight();
};

