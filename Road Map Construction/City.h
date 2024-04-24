#include<string>
#include<List>
#include"Edge.h"
#pragma once
using namespace std;
class City
{
	int cityId;
	string cityName;
	list <Edge> edgeList;
	City();
	City(int id, string cityName);

};

