#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <map>
#include <tuple>
class Train
{
	int trainSpeed;
	int trainVolume;
	double trainPrice;
	int distance;
public:
	Train();
	Train(std::tuple<int, int, double>, int);
	~Train();
	double sumCost(int, int);
	double sumTime(int);
	int getDistance();
};


