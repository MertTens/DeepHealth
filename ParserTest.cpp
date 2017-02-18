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
	ifstream testData;
	testData.open ("test_data.txt");
	string line;

	// frequency of data points in each num section
	double zeroTimes[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	int oneTimes[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,1};
	int twoTimes[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,2};
	int threeTimes[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,3};
	int fourTimes[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,4};

	// an array with the sum of everything in it
	double averageZero[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	double averageOne[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,1};
	double averageTwo[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,2};
	double averageThree[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,3};
	double averageFour[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,4};

	double caton;
	getline (testData, line);
	while(getline (testData, line))	{

		int countNumber[] = {0,0,0,0,0,0,0,0,0,0,0,0,0};
		
		string temp[] = {"","","","","","","","","","","","","",""};
		string ID = parser(line);
		for(int i = 0; i < 13; i++)	{
			temp[i] = parser(line);
			if(temp[i] == "?" || temp[i] == "-9")
				temp[i] = "9999";
			else	
				countNumber[i] = 1;
		}

		temp[13] = line;
		string place = temp[13];

		
		cout<<endl;

		for(int i = 0; i < 13; i++)	{


			if(place == "0")	{
				zeroTimes[i] += countNumber[i];
				double tempVal;
				stringstream(temp[i]) >> tempVal;
				//cout<<"Value from temp: "<<tempVal<<" ";
				if(tempVal != 9999)	{
					averageZero[i] += tempVal;
					//if(i == 0)
						//cout<<averageZero[i]<<endl;
				}
			}

			if(place == "1")	{
				oneTimes[i] += countNumber[i];
				double tempVal;
				stringstream(temp[i]) >> tempVal;
				//cout<<"Value from temp: "<<tempVal<<" ";
				if(tempVal != 9999)	{
					averageOne[i] += tempVal;
					if(i == 0)
						cout<<averageOne[i]<<" "<<place<<endl;
				}
			}

			if(place == "2")	{
				twoTimes[i] += countNumber[i];
				double tempVal;
				stringstream(temp[i]) >> tempVal;
				//cout<<"Value from temp: "<<tempVal<<" ";
				if(tempVal != 9999)	{
					averageTwo[i] += tempVal;
					if(i == 0)
						cout<<averageTwo[i]<<" "<<place<<endl;
				}
			}

			if(place == "3")	{
				threeTimes[i] += countNumber[i];
				double tempVal;
				stringstream(temp[i]) >> tempVal;
				//cout<<"Value from temp: "<<tempVal<<" ";
				if(tempVal != 9999)	{
					averageThree[i] += tempVal;
					if(i == 0)
						cout<<averageThree[i]<<" "<<place<<endl;
				}
			}

			if(place == "4")	{
				fourTimes[i] += countNumber[i];
				double tempVal;
				stringstream(temp[i]) >> tempVal;
				//cout<<"Value from temp: "<<tempVal<<" ";
				if(tempVal != 9999)	{
					averageFour[i] += tempVal;
					if(i == 0)
						cout<<averageFour[i]<<" "<<place<<endl;
				}
			}

		}


		
		//cout<<averageZero[0];
	}
	for(int i = 0; i < 13; i++)	{
			double sum = averageZero[i];
			double times = zeroTimes[i];
			double result = sum/times;
			averageZero[i] = result;
			cout<<"average: "<<averageZero[i]<<endl;
		}
		cout<<endl;
	for(int i = 0; i < 13; i++)	{
			double sum = averageOne[i];
			double times = oneTimes[i];
			double result = sum/times;
			averageOne[i] = result;
			cout<<"average: "<<averageOne[i]<<endl;
		}
		cout<<endl;
	for(int i = 0; i < 13; i++)	{
			double sum = averageTwo[i];
			double times = twoTimes[i];
			double result = sum/times;
			averageTwo[i] = result;
			cout<<"average: "<<averageTwo[i]<<endl;
		}
		cout<<endl;
	for(int i = 0; i < 13; i++)	{
			double sum = averageThree[i];
			double times = threeTimes[i];
			double result = sum/times;
			averageThree[i] = result;
			cout<<"average: "<<averageThree[i]<<endl;
		}
		cout<<endl;
	for(int i = 0; i < 13; i++)	{
			double sum = averageFour[i];
			double times = fourTimes[i];
			double result = sum/times;
			averageFour[i] = result;
			cout<<"average: "<<averageFour[i]<<endl;
		}
	
	return 0;
}