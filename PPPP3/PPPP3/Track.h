#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <map>
#include <tuple>
#include "Source.cpp"
class Track
{
	double cost;
	double time;
	int volume;
public:
	Track();
	Track(Car, int);
	Track(Car, Car, Train, int);
	Track(Car, Car, Plane, int);
	Track(Car, Car, Car, Train, Plane, int);
	Track(Car, Car, Car, Car, Train, Train, Plane, int);
	double getCost();
	~Track();
};

