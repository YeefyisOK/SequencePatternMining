#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;
class EyeMovementTypeTime
{
public:
	int fixationTime = 0;
	int saccadeTime = 0;
	int unclassifiedTime = 0;
	int eyesNotFoundTime = 0;
	//void addSaccadeTime(int time);
	//void addFixationTime(int time);
	//void addEyesNotFoundTime(int time);
	//void addUnclassifiedTime(int time);
	void addTime(std::string type, int time);
	void deleteTime(std::string type, int time);
	vector<double> getPercent();
};


