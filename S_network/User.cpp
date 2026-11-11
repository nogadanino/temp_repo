#include "user.h"
#include <iostream>

void User::init(unsigned int id, std::string username, unsigned int age)
{
	this->uID = id;
	this->uName = username;
	this->age = age;
}

void User::clear()
{
	this->devices.clear();
}

unsigned int User::getID() const
{
	return this->uID;
}

std::string User::getUserName() const
{
	return this->uName;
}

unsigned int User::getAge() const
{
	return this->age;
}

DevicesList& User::getDevices()
{
	return this->devices;
}

void User::addDevice(Device newDevice)
{
	this->devices.add(newDevice);
}

bool User::checkIfDevicesAreOn() const
{
	DeviceNode* device1 = this->devices.get_first();

	while (device1 != NULL)
	{
		if (!(device1->get_data().isActive()))
		{
			return false;
		}
		device1 = device1->get_next();
	}

	return true;
}