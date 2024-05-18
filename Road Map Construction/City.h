#include<string>
#include"Edge.h"
#include <vector>
using namespace std;
class City
{
	private:
		string cityName;
		vector <Edge> edgeList;
		int X, Y;
	public:
		City();
		City(string cityName);
		string getCityName();
		void setCityName(string cityName);
		vector<Edge>getEdgeList();
		void setEdgeList(vector<Edge> edgeList);
		void setX(int X);
		void setY(int Y);
		int getX();
		int getY();
};

