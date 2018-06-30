#include<iostream>
#include<fstream>
#include<errno.h>
#include<syslog.h>
#include<assert.h>

#include "json.h"

using namespace std;

void cpp()
{
	ifstream ifs;
	ifs.open("test.json");
	assert(ifs.is_open());
	
	Json::Reader reader;
	Json::Value root;
	
	if(!reader.parse(ifs, root, false))
	{
		cerr << "parse failed" << endl;
		return;
	}

	string name = root["name"].asString();
	cout << name <<endl;
	int age = root["age"].asInt();
	cout << age <<endl;

}



int main()
{
	cpp();
	return 0;
}
