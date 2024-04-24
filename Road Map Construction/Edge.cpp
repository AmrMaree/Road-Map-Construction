#include "Edge.h"

Edge::Edge()
{
	destinationCity = "";
	weight = 0;
}

Edge::Edge(string destCity, int w)
{
	destinationCity = destCity;
	weight = w;
}

void Edge::setEdgeValue(string destCity, int w)
{
	destinationCity = destCity;
	weight = w;

}

string Edge::getDestinationCity()
{
	return destinationCity;
}

int Edge::getWeight()
{
	return weight;
}
