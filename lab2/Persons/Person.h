#pragma once
#include "../pch.h"

class Person{
    private:
        string firstName_;
        string surname_;
        int age_;
    public:
        Person(const string& firstName, const string& surname, int age);

        virtual ~Person() = default;

        void setFirstName(const string& firstName);
        void setSurname(const string& surname);
        void setAge(int age);

        string getFirstName() const;
        string getSurname() const;
        int getAge() const;

        virtual void print() const;
};