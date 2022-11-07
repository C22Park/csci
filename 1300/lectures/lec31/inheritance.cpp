#include <iostream>

using namespace std;

class Person
{
    private:
        string name_;
        int age_;
    public:
        Person()
        {
            name_ = "";
            age_ = 0;
        }
        Person(string name, int age)
        {
            name_ = name;
            age_ = age;
        }

        void setName(string name)
        {
            name_ = name;
        }
        string getName()
        {
            return name_;
        }

        void setAge(int age)
        {
            age_ = age;
        }
        int getAge()
        {
            return age_;
        }

        void display()
        {
            cout << "Name: " << name_ << "\nAge: " << age_ << "\n";
        }
};

class Student: public Person
{
    private:
        string major_;
    
    public:
        Student()
        {
            major_ = "";
        }
        Student(string name, int age, string major): Person(name, age)
        {
            major_ = major;
        }

        void setMajor(string major)
        {
            major_ = major;
        }
        string getMajor()
        {
            return major_;
        }

        void display()
        {
            Person::display();
            cout << "Major: " << major_ << "\n";
        }
};

int main()
{
    Student Torin("Torin", 18, "Big Bidness");

    Torin.display();

    return 0;
}