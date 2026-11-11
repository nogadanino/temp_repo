#include "SocialNetwork.h"

void SocialNetwork::init(std::string networkName, int minAge)
{
    this->networkName = networkName;
    this->minAge = minAge;
    this->profilesList.init();
}



void SocialNetwork::clear()
{
    this->profilesList.clear();
}



std::string SocialNetwork::getNetworkName() const
{
    return this->networkName;
}



int SocialNetwork::getMinAge() const
{
    return this->minAge;
}




bool SocialNetwork::addProfile(Profile profile_to_add)
{
    if (profile_to_add.getOwner().getAge() < this->minAge)
    {
        return false;
    }
    this->profilesList.add(profile_to_add);
    return true;
}




std::string SocialNetwork::getWindowsDevices() const
{
    std::string result = "";
    ProfileNode* currentProfile = this->profilesList.get_first();

    while (currentProfile != nullptr)
    {
        DevicesList devList = currentProfile->get_data().getOwner().getDevices();
        DeviceNode* currentDevice = devList.get_first();

        while (currentDevice != nullptr)
        {
            std::string os = currentDevice->get_data().getOS();

            if (os.find("Windows") == 0)
            {
                if (!result.empty())
                {
                    result += ", ";
                }
                result += "[" + std::to_string(currentDevice->get_data().getID()) + ", " + os + "]";
            }
            currentDevice = currentDevice->get_next();
        }
        currentProfile = currentProfile->get_next();
    }
    return result;
}