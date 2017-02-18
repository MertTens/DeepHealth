#include <iostream>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

string parser(string &line)	{
	string word = "";
	int count = 0;
	for(int  i = 0; line[i] != ','; i++)	{
		word += line[i];
		//cout<<word<<endl;
		count = i + 2;
	}
	line = &(line[count]);
	//cout<<word<<endl;
	return word;
}

int main()
{
	stringstream newLine;
	ifstream testData;
	testData.open ("test_data.txt");
	string line;

	

	double caton;
	getline (testData, line);
	while(getline (testData, line))	{
		string temp[] = {"","","","","","","","","","","","","",""}
		string ID = parser(line);
		for(int i < 15; )
		
	}
	
	return 0;
}