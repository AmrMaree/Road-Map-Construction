#include<string>
#include<List>
#include"Edge.h"
#pragma once
using namespace std;
class City
{
	private:
		string cityName;
		list <Edge> edgeList;

	public:
		City();
		City(string cityName);
		string getCityName();
		void setCityName(string cityName);
		list<Edge>getEdgeList();
};

