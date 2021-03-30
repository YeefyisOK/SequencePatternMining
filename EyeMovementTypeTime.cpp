#include "EyeMovementTypeTime.h"
//void EyeMovementTypeTime::addSaccadeTime(int time) {
//	saccadeTime += time;
//}
//
//void EyeMovementTypeTime::addFixationTime(int time) {
//	fixationTime += time;
//}
//
//void EyeMovementTypeTime::addEyesNotFoundTime(int time) {
//	eyesNotFoundTime += time;
//}
//
//void EyeMovementTypeTime::addUnclassifiedTime(int time) {
//	unclassifiedTime += time;
//}

void EyeMovementTypeTime::addTime(std::string type, int time) {
	if (type == "Fixation") {
		fixationTime += time;
	}
	else if (type == "Saccade") {
		saccadeTime += time;
	}
	else if (type == "Unclassified") {
		unclassifiedTime += time;
	}
	else if(type == "EyesNotFound") {
		eyesNotFoundTime += time;
	}
}

void EyeMovementTypeTime::deleteTime(std::string type, int time) {
	if (type == "Fixation") {
		fixationTime -= time;
	}
	else if (type == "Saccade") {
		saccadeTime -= time;
	}
	else if (type == "Unclassified") {
		unclassifiedTime -= time;
	}
	else if (type == "EyesNotFound") {
		eyesNotFoundTime -= time;
	}
}
vector<double> EyeMovementTypeTime::getPercent() {
	int totalTime = saccadeTime + fixationTime + unclassifiedTime + eyesNotFoundTime;
	double fixationTimePercentage, saccadeTimePercentage, unclassifiedTimePercentage, eyesNotFoundTimePercentage;
	if (totalTime != 0) {
		fixationTimePercentage = (double)fixationTime / (double)totalTime;
		saccadeTimePercentage = (double)saccadeTime / (double)totalTime;
		unclassifiedTimePercentage = (double)unclassifiedTime / (double)totalTime;
		eyesNotFoundTimePercentage = (double)eyesNotFoundTime / (double)totalTime;
	}
	else {
		fixationTimePercentage = saccadeTimePercentage = unclassifiedTimePercentage = eyesNotFoundTimePercentage = 0;
	}
	//cout << "×ÜÊ±¼ä" << totalTime << endl;
	//cout << "fixationTimePercentage:" << fixationTimePercentage << endl;
	//cout << "saccadeTimePercentage:" << saccadeTimePercentage << endl;
	//cout << "unclassifiedTimePercentage:" << unclassifiedTimePercentage << endl;
	//cout << "eyesNotFoundTimePercentage:" << eyesNotFoundTimePercentage << endl;
	vector<double> res;
	res.push_back(totalTime);
	res.push_back(fixationTimePercentage);
	res.push_back(saccadeTimePercentage);
	res.push_back(unclassifiedTimePercentage);
	res.push_back(eyesNotFoundTimePercentage);
	return res;
}