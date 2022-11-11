#include "Resource.h"

using namespace std;

Resource::Resource() // default constructor
{
    resource_description_ = "";    
    reward_ = 0;
}
Resource::Resource(string name, string resource_description, int reward, int row, int col): MapObject(name, row, col) // paramaterized constructor
{
    resource_description_ = resource_description;
    reward_ = reward;
}

void Resource::setResourceDescription(string resource_description) // sets resource_description_ to resource_description
{
    resource_description_ = resource_description;
}
string Resource::getResourceDescription() // return resource_description_
{
    return resource_description_;
}

void Resource::setReward(int reward) // sets reward_ to reward
{
    reward_ = reward;
}
int Resource::getReward() // returns reward_
{
    return reward_;
}