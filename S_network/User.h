#pragma once
#include "DeviceList.h"
#include "string.h"

class User
{
private:
	unsigned int uID;
	unsigned int age;
	std::string uName;
	DevicesList devices;

public:
	void init(unsigned int id, std::string username, unsigned int age);//sets the user's info

	void clear();//delete the user's info

	unsigned int getID() const;//get the user's id not the device id

	std::string getUserName() const;//get the user's username

	unsigned int getAge() const;//get the user's age

	DevicesList& getDevices();// get the refrence to the first device on the the device list

	void addDevice(Device newDevice);//adding device to the list

	bool checkIfDevicesAreOn() const;//chackes if akk the devices are on



};