//
// Created by Thomas Couchoud on 01/02/2018.
//

#include <vector>
#include <iostream>

using namespace std;

void showVect(std::vector<int> v);

int main(int argc, char ** argv)
{
	vector<int> v = vector<int>();
	int input;
	for(int i = 0; i < 5; i++)
	{
		cin >> input;
		v.push_back(input);
	}
	for(int i = 0; i < 5; i++)
	{
		cout << v[i];
	}
	
	showVect(v);
	
	{
		cout << endl;
		cout << "A? ";
		int toDel;
		cin >> toDel;
		if(toDel < 0 || toDel > v.size())
		{
			cout << "NOPE!";
			exit(EXIT_FAILURE);
		}
		v.erase(v.begin() + toDel);
	}
	
	showVect(v);
	
	{
		int A;
		cout << endl;
		cout << "A? ";
		cin >> A;
		
		if(A < 0 || A > v.size() + 1)
		{
			cout << "NOPE!";
			exit(EXIT_FAILURE);
		}
		
		int B;
		cout << endl;
		cout << "B? ";
		cin >> B;
		
		if(B < 0 || B > v.size())
		{
			cout << "NOPE!";
			exit(EXIT_FAILURE);
		}
		
		v.insert(v.begin() + A, v[B]);
	}
	
	showVect(v);
	v.clear();
	showVect(v);
	
	return 0;
}

void showVect(vector<int> v)
{
	cout << endl;
	for(vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << ", ";
	}
	cout << endl;
}
