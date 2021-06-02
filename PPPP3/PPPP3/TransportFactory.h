#include "Source.cpp"
#pragma once
class TransportFactory:ITransport
{
public:
	Car createCar(std::tuple<int, int, double> tuple, int dist);
	Train createTrain(std::tuple<int, int, double> tuple, int dist);
	Plane createPlane(std::tuple<int, int, double> tuple, int dist);
};

