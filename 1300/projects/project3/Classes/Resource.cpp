#include "Resource.h"

using namespace std;

Resource::Resource()
{
    resource_description_ = "";    
    reward_ = 0;
}
Resource::Resource(string name, string resource_description, int reward, int row, int col): MapObject(name, row, col)
{
    resource_description_ = resource_description;
    reward_ = reward;
}

void Resource::setResourceDescription(string resource_description)
{
    resource_description_ = resource_description;
}
string Resource::getResourceDescription()
{
    return resource_description_;
}

void Resource::setReward(int reward)
{
    reward_ = reward;
}
int Resource::getReward()
{
    return reward_;
}