//
// Created by Thomas Couchoud on 01/02/2018.
//

#include <string>
#include <istream>
#include <vector>
#include <map>
#include <iostream>

using namespace std;

void show(multimap<int, string> &m)
{
	for(multimap<int, string>::iterator it = m.begin(); it != m.end(); it++)
		cout << it->first << " contains " << it->second << endl;
}

int main(int argc, char ** argv)
{
	multimap<int, string> m = multimap<int, string>();
	while(true)
	{
		int key;
		cout << "Key: ";
		cin >> key;
		
		string val;
		cout << "Value: ";
		cin >> val;
		
		if(strcmp(val.c_str(), "end") == 0)
			break;
		
		m.insert(pair<int, string>(key, val));
	}
	
	cout << "--------------------------------------" << endl;
	show(m);
	cout << "--------------------------------------" << endl;
	
	while(true)
	{
		int key;
		cout << "Key: ";
		cin >> key;
		
		if(key == 0)
			break;
		
		multimap<int, string>::iterator it;
		for(it = m.begin(); it != m.end(); it++)
			if(it->first >= key)
				break;
		
		if(it == m.end())
			cout << "Too big" << endl;
		else
			cout << it->first << " contains " << it->second << endl;
	}
	
	cout << "--------------------------------------" << endl;
	
	while(true)
	{
		string value;
		cout << "Value: ";
		cin >> value;
		
		if(strcmp(value.c_str(), "end") == 0)
			break;
		
		vector<int> keys = vector<int>();
		multimap<int, string>::iterator it;
		for(it = m.begin(); it != m.end(); it++)
			if(it->second == value)
				keys.push_back(it->first);
		
		if(keys.empty())
			cout << "No key for this value";
		else
			for(auto it = keys.begin(); it != keys.end(); it++)
				cout << *it << ",";
		cout << endl;
	}
	
	cout << "--------------------------------------" << endl;
	
	string value;
	cout << "Delete: ";
	cin >> value;
	
	multimap<int, string>::iterator it;
	for(it = m.begin(); it != m.end(); it++)
		if((it->second).find_first_of(value) != string::npos)
			m.erase(it);
	
	show(m);
	
	return 0;
}
