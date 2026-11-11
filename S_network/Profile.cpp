#include "Profile.h"

void Profile::init(User owner)
{
    this->owner = owner;
    this->profilePage.init();
    this->friendsList.init();
}

void Profile::clear()
{
    this->profilePage.clearPage();
    this->friendsList.clear();
}

User Profile::getOwner() const
{
    return this->owner;
}

void Profile::setStatus(std::string new_status)
{
    this->profilePage.setStatus(new_status);
}

void Profile::addPostToProfilePage(std::string post)
{
    this->profilePage.addLineToPosts(post);
}

void Profile::addFriend(User friend_to_add)
{
    this->friendsList.add(friend_to_add);
}

std::string Profile::getPage() const
{
    return "Status: " + this->profilePage.getStatus() + "\n" +
        "*******************\n*******************\n" +
        this->profilePage.getPosts();
}

std::string Profile::getFriends() const
{
    std::string result = "";
    UserNode* current = this->friendsList.get_first();

    while (current != nullptr)
    {
        result += current->get_data().getUserName();
        current = current->get_next();
        if (current != nullptr)
        {
            result += ",";
        }
    }
    return result;
}

std::string Profile::getFriendsWithSameNameLength() const
{
    std::string result = "";
    int ownerNameLength = this->owner.getUserName().length();
    UserNode* current = this->friendsList.get_first();

    while (current != nullptr)
    {
        if (current->get_data().getUserName().length() == ownerNameLength)
        {
            if (!result.empty())
            {
                result += ",";
            }
            result += current->get_data().getUserName();
        }
        current = current->get_next();
    }
    return result;
}