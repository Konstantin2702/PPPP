#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <map>
#include <tuple>
class Plane
{
	int planeSpeed;
	int planeVolume;
	double planePrice;
	int distance;
public:
	Plane();
	Plane(std::tuple<int, int, double>, int);
	~Plane();
	double sumCost(int, int);
	double sumTime(int);
	int getDistance();
};

