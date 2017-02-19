#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
//#include "statistics.h"
#include "ap.h"
#include <vector>

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

void obsolete(double *array, int N) {
    int i;
 
    for(i=0; i<N; i++)
        if (array[i]<0)
            array[i] = array[i] * (-1);
 
}

int minFinder(double *array){
    
    int min = 0;
    for(int i = 0; i < 5; i++){
        if (array[i] < array[min]){
            min = i;
        }
    }
    
    return min;
}

int main()
{	int sameCount = 0;
	ifstream testData;
	testData.open ("test_data.txt");
	string line;

	ifstream testData2;
    testData2.open ("try_again.txt");
    string line2;

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
			//cout<<temp[i]<<endl;
			if(temp[i] == "?" || temp[i] == "-9")
				temp[i] = "9999";
			else	
				countNumber[i] = 1;
		}

		temp[13] = line[0];
		string place = temp[13];

		
		//cout<<place<<endl;

		for(int i = 0; i < 13; i++)	{

			cout<<place<<endl;
			if(place == "0")	{
				zeroTimes[i] += countNumber[i];
				double tempVal;
				stringstream(temp[i]) >> tempVal;
				//cout<<"Value from temp: "<<tempVal<<" ";
				if(tempVal != 9999)	{
					averageZero[i] += tempVal;
					//if(i == 0)
						//cout<<averageOne[i]<<" "<<place<<endl;
				}
			}

			if(place == "1")	{
				oneTimes[i] += countNumber[i];
				double tempVal;
				stringstream(temp[i]) >> tempVal;
				//cout<<"Value from temp: "<<tempVal<<" ";
				if(tempVal != 9999)	{
					averageOne[i] += tempVal;
					//if(i == 0)
						//cout<<averageOne[i]<<" "<<place<<endl;
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

	double id = 0;
    double age = 0;
    double sex = 0;
    double cp = 0;
    double trestbps = 0; 
    double chol = 0; 
    double fbs = 0;
    double restecg = 0; 
    double thalach = 0;
    double exang = 0;
    double oldpeak = 0;
    double slope = 0;
    double ca = 0;
    double thal = 0;
    
    getline (testData2, line2);
    while(getline (testData2, line2))	{
    
    string id_ = parser(line2);
    string age_ = parser(line2);
    string sex_ = parser(line2);
    string cp_ = parser(line2);
    string trestbps_ = parser(line2);
    string chol_ = parser(line2);
    string fbs_ = parser(line2);
    string restecg_ = parser(line2);
    string thalach_ = parser(line2);
    string exang_ = parser(line2);
    string oldpeak_ = parser(line2);
    string slope_ = parser(line2);
    string ca_ = parser(line2);
    string thal_ = parser(line2);

    char num = line2[0];
    string ahh = "";
    ahh += num;
    int number;
    stringstream(ahh)>>number;
    
    stringstream(age_) >> age;
    stringstream(sex_) >> sex;
    stringstream(cp_) >> cp;
    stringstream(trestbps_) >> trestbps;
    stringstream(chol_) >> chol;
    stringstream(fbs_) >> fbs;
    stringstream(restecg_) >> restecg;
    stringstream(thalach_) >> thalach;
    stringstream(exang_) >> exang;
    stringstream(oldpeak_) >> oldpeak;
    stringstream(slope_) >> slope;
    stringstream(ca_) >> ca;
    stringstream(thal_) >> thal;
    
    
    double ageDif[5] = {(averageZero[0] - age), (averageOne[0] - age), (averageTwo[0] - age), (averageThree[0] - age),  (averageFour[0] - age)};
    double trestbpsDif[5] = {(averageZero[3] - trestbps), (averageOne[3] - trestbps), (averageTwo[3] - trestbps), (averageThree[3] - trestbps),  (averageFour[3] - trestbps)};
    double cholDif[5] = {(averageZero[4] - chol), (averageOne[4] - chol), (averageTwo[4] - chol), (averageThree[4] - chol),  (averageFour[4] - chol)};
    double fbsDif[5] = {(averageZero[5] - fbs), (averageOne[5] - fbs), (averageTwo[5] - fbs), (averageThree[5] - fbs),  (averageFour[5] - fbs)};
    double thalachDif[5] = {(averageZero[7] - thalach), (averageOne[7] - thalach), (averageTwo[7] - thalach), (averageThree[7] - thalach),  (averageFour[7] - thalach)};
    double exangDif[5] = {(averageZero[8] - exang), (averageOne[8] - exang), (averageTwo[8] - exang), (averageThree[8] - exang),  (averageFour[8] - exang)};
    double oldpeakDif[5] = {(averageZero[9] - oldpeak), (averageOne[9] - oldpeak), (averageTwo[9] - oldpeak), (averageThree[9] - oldpeak),  (averageFour[9] - oldpeak)};
    double caDif[5] = {(averageZero[11] - ca), (averageOne[11] - ca), (averageTwo[11] - ca), (averageThree[11] - ca),  (averageFour[11] - ca)};
    double thalDif[5] = {(averageZero[12] - thal), (averageOne[12] - thal), (averageTwo[12] - thal), (averageThree[12] - thal),  (averageFour[12] - thal)};
    
    
    double sexDif[5] = {(averageZero[1] - sex), (averageOne[1] - sex), (averageTwo[1] - sex), (averageThree[1] - sex),  (averageFour[1] - sex)};
    double cpDif[5] = {(averageZero[2] - cp), (averageOne[2] - cp), (averageTwo[2] - cp), (averageThree[2] - cp),  (averageFour[2] - cp)};
    double restecgDif[5] = {(averageZero[6] - restecg), (averageOne[6] - restecg), (averageTwo[6] - restecg), (averageThree[6] - restecg),  (averageFour[6] - restecg)};
    double slopeDif[5] = {(averageZero[10] - slope), (averageOne[10] - slope), (averageTwo[10] - slope), (averageThree[10] - slope),  (averageFour[10] - slope)};
    double score = 0;

    if (age > 45 || sex == 1){
        score += 5*(age/45);
    }
    if (age > 55 || sex == 0){
        score += 5*(age/55);
    }
    //chest pain, set
    if (cp == 2)
        score += 2;
    if (cp == 3)
        score += 5;
    if (cp == 4)
        score += 9;
    //ca, set
    if (ca == 1)
        score += 1;
    if (ca == 2)
        score += 2;
    if (ca == 3)
        score += 4;
    //oldpeak, set
    //score += minFinder(oldpeakDif) + 2;
    int op = minFinder(oldpeakDif);
    if(op == 0)
    	score +=2;
    if(op == 1)
    	score +=3;
    if(op == 2)
    	score +=4;
    if(op == 3)
    	score +=5;
    if(op == 4)
    	score +=6;
    
    //xang, set
    score += minFinder(exangDif) + 3;
    
    //fps, set
    score += minFinder(fbsDif)-2;
    
    //trestbps
    if (trestbps > 140)
        score += 3;
    
    //SEX, set
    score += minFinder(sexDif)+.5;

    int predict;
    if(score < 25)
    	predict = 0;
    else if(score >= 20 && score < 26)
    	predict = 1;
    else if(score >= 25 && score < 28)
    	predict = 2;
    else if(score >= 28 && score < 31)
    	predict = 3;
    else if(score >= 31)
    	predict = 4;

	cout<<number<<"     "<<predict<<endl;

	if(number == predict)
		sameCount++;

}
alglib::integer_2d_array r2;
r2.setlength(4,3);


	cout<<endl<<sameCount<<endl;
	return 0;
}

