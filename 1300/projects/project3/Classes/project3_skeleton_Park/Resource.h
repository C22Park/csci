#ifndef RESOURCE_H
#define RESOURCE_H

using namespace std;

class Resource: public MapObject
{
    private:
        string resource_description_; 
        int reward_; // amount of gold user will recieve from resource

    public:
        Resource(); // default constructor
        Resource(string name, string resource_description, int reward, int row, int col); // paramaterized constructor

        void setResourceDescription(string resource_description); // sets resource_description_ to resource_description
        string getResourceDescription(); // returns resource_description_

        void setReward(int reward); // sets reward_ to reward
        int getReward(); // return reward_
};

#endif