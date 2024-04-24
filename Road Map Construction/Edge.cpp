#include "Edge.h"

Edge::Edge()
{
	sourceCity = "";
	destinationCity = "";
	weight = 0;
}

Edge::Edge(string sourceCity ,string destCity, int w)
{
	this->sourceCity = sourceCity;
	destinationCity = destCity;
	weight = w;
}

string Edge::getSourceCity()
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
