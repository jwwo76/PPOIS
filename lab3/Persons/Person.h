#pragma once
#include "../pch.h"

class Person{
    private:
        string firstName_;
        int age_;
    public:
        Person(const string& firstName, int age);

        virtual ~Person() = default;

        void setFirstName(const string& firstName);
        string getFirstName() const;
        int getAge() const;

        virtual void print() const;
};


