#include "TransportFactory.h"

Car TransportFactory::createCar(std::tuple<int, int, double> tuple, int dist)
{
	Car car = Car(tuple, dist);
	return car;
}

Plane TransportFactory::createPlane(std::tuple<int, int, double> tuple, int dist)
{
	Plane plane = Plane(tuple, dist);
	return plane;
}

Train TransportFactory::createTrain(std::tuple<int, int, double> tuple, int dist)
{
	Train train = Train(tuple, dist);
	return train;
}
