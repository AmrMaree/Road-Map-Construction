#include<string>
#include"Edge.h"
#pragma once
using namespace std;
class City
{
	private:
		string cityName;
		vector <Edge> edgeList;

	public:
		City();
		City(string cityName);
		string getCityName();
		void setCityName(string cityName);
		list<Edge>getEdgeList();
};

