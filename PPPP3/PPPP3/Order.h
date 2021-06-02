#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <map>
#include <tuple>
#include "Car.h"
#include "Train.h"
#include "Plane.h"
#include "Track.h"
#include "OrderBuilder.h"
#include "TransportFactory.h"
class Order
{
	double cost;
	int volume;
	std::string startPoint;
	std::string finishPoint;
	enum::Type type;
	Track track;
	OrderBuilder orderBuilder; 
	TransportFactory transportFactory; 
public:
	Order();
	Order(Type, std::string, std::string, int, OrderBuilder, TransportFactory);
	~Order();
	int decr(std::string);
	int** matrixUpd(Type);
	int* optim(int**, int, int);
	Track best(std::string, std::string, Type, int);
};

