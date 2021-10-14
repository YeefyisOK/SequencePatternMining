#pragma once
#include "point.h"
class AAOI {
public:
	AAOI(point a, point b) :LU(a),RB(b){

	}
	point LU;
	point RB;
};
class AOILoc
{
public:
	AOILoc(AAOI diagram, AAOI optionA, AAOI optionB, AAOI optionC, AAOI optionD, AAOI option, AAOI stament, AAOI time) 
		:diagram(diagram), optionA(optionA), optionB(optionB), optionC(optionC), optionD(optionD), option(option), stament(stament), time(time) {
	}

	AAOI diagram;

	AAOI optionA;
	AAOI optionB;
	AAOI optionC;
	AAOI optionD;

	AAOI option;

	AAOI stament;

	AAOI time;
};

