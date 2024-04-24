#include<string>
#include"Edge.h"
#include <vector>
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
		vector<Edge>getEdgeList();
};

