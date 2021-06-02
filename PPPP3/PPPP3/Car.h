#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <map>
#include <tuple>
class Car
{
	int carSpeed;
	int carVolume;
	double carPrice;
	int distance;
public:
	Car();
	Car(std::tuple<int, int, double>, int);
	~Car();
	double sumCost(int, int);
	double sumTime(int);
	int getDistance();

};

