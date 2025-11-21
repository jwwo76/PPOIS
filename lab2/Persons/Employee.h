#pragma once
#include "Person.h"

class Employee: public Person{
    private:
        int id_;
        string position_;
        double salary_;
        int experience_;
    public:
        Employee(const string& fName, const string& sName,int age, int id, const string& position, double salary, int experience);
        virtual ~Employee() = default;
        virtual void work() = 0;
        int getId() const { return id_; }
        string getPosition() const { return position_; }
        double getSalary() const { return salary_; }

        void setId(int newId) { id_ = newId; }
        void setPosition(const string& newPosition) { position_ = newPosition; }
        void setSalary(double newSalary);

        virtual void print() const override;

};