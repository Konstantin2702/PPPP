#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <map>
#include <tuple>
#include "Source.cpp"
class OrderBuilder:IOrder
{
public:
	Track createTrack(Car, int);
	Track createTrack1(Car, Car, Train, int);
	Track createTrack2(Car, Car, Plane, int);
	Track createTrack3(Car, Car, Car, Train, Plane, int);
	Track createTrack4(Car, Car, Car, Car, Train, Train, Plane, int);
};

