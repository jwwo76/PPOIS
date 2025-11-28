#pragma once
#include "Person.h"

class Employee: public Person{
    private:
        int id_;
        double salary_;
    public:
        Employee(const string& fName, int age, int id, double salary);
        virtual ~Employee() = default;
        virtual void work() = 0;
        int getId() const { return id_; }
        double getSalary() const { return salary_; }

        void setId(int newId) { id_ = newId; }
        void setSalary(double newSalary);

        virtual void print() const override;
};


