#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

istream& read(ifstream &is)
{
	int age;
	string name;
	is>>age>>name;
	cout<<age<<"--"<<name<<endl;
	return is;
}

int main(int argc, char **argv)
{
	if(argc < 2)
	{
		cout<<"Argument Error!"<<endl;
		return 1;
	}
	ifstream input(argv[1]);
	cout<<argv[1]<<endl;
	string line;
	while(getline(input, line))
	{
		cout<<line<<endl;
		int age;
		string name;
		istringstream linestream(line);
		linestream>>age>>name;
		cout<<age<<"--"<<name<<endl;
	}
	/*
	while(read(input))
	{
	}
	*/
	return 0;
}
