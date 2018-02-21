//
// Created by Thomas Couchoud on 01/02/2018.
//

#include <set>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

typedef struct _coord
{
	double x;
	double y;
} coord;

bool operator<(const coord &s1, const coord &s2)
{
	return s1.x < s2.x;
}

void cs(const _coord &c)
{
	cout << "(" << c.x << "," << c.y << ")";
}

void show(set<coord> & s)
{
	cout << endl;
	for(set<coord>::iterator it = s.begin(); it != s.end(); it++)
	{
		cs(*it);
		cout << ", ";
	}
	cout << endl;
}

double distt(const _coord &c1, const _coord &c2)
{
	return sqrt(pow(c1.x - c2.x, 2) + pow(c1.y - c2.y, 2));
}

int main(int argc, char ** argv)
{
	set<coord> s = set<coord>();
	s.insert(coord{.x = 1, .y = 2});
	s.insert(coord{.x = 3, .y = 4});
	s.insert(coord{.x = 5, .y = 6});
	s.insert(coord{.x = 7, .y = 8});
	s.insert(coord{.x = 9, .y = 10});
	s.insert(coord{.x = 11, .y = 12});
	s.insert(coord{.x = 13, .y = 14});
	s.insert(coord{.x = 15, .y = 16});
	s.insert(coord{.x = 17, .y = 18});
	s.insert(coord{.x = 19, .y = 20});
	
	show(s);
	
	vector<vector<double>> dist(s.size(), vector<double>(s.size(), 0));
	for(int i = 0; i < s.size(); i++)
		for(int j = 0; j < s.size(); j++)
		{
			try
			{
				auto it = s.begin();
				for(int ii = 0; ii < i; ii++)
					it++;
				coord a = *it;
				
				it = s.begin();
				for(int ii = 0; ii < j; ii++)
					it++;
				coord b = *it;
				
				dist[i][j] = distt(a, b);
			}
			catch(string & e)
			{
				cout << e << endl;
			}
		}
	
	{
		int A;
		cout << endl;
		cout << "A? ";
		cin >> A;
		
		if(A < 0 || A > dist.size() + 1)
		{
			cout << "NOPE!";
			exit(EXIT_FAILURE);
		}
		
		int B;
		cout << endl;
		cout << "B? ";
		cin >> B;
		
		if(B < 0 || B > dist.size())
		{
			cout << "NOPE!";
			exit(EXIT_FAILURE);
		}
		
		cout << dist[A][B] << endl;
	}
	
	return 0;
}