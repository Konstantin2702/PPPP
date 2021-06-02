#include "OrderBuilder.h"
Track OrderBuilder::createTrack(Car car1, int volume)
{
	Track track = Track(car1, volume);
	return track;
}

Track OrderBuilder::createTrack1(Car car1, Car car2, Train train1, int volume)
{
	Track track = Track(car1, car2, train1, volume);
	return track;
}

Track OrderBuilder::createTrack2(Car car1, Car car2, Plane plane1, int volume)
{
	Track track = Track(car1, car2, plane1, volume);
	return track;
}

Track OrderBuilder::createTrack3(Car car1, Car car2, Car car3, Train train1, Plane plane1, int volume)
{
	Track track = Track(car1, car2, car3, train1, plane1, volume);
	return track;
}

Track OrderBuilder::createTrack4(Car car1, Car car2, Car car3, Car car4, Train train1, Train train2, Plane plane1, int volume)
{
	Track track = Track(car1, car2, car3, car4, train1, train2, plane1, volume);
	return track;
}

