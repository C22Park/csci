#ifndef RESOURCE_H
#define RESOURCE_H

using namespace std;

class Resource: public MapObject
{
    private:
        string resource_description_;
        int reward_;

    public:
        Resource();
        Resource(string name, string resource_description, int reward, int row, int col);

        void setResourceDescription(string resource_description);
        string getResourceDescription();

        void setReward(int reward);
        int getReward();
};

#endif