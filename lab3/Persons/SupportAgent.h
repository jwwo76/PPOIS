#pragma once
#include "Employee.h"

class SupportAgent: public Employee{
    private:
        int ticketsResolved_;
    public:
        SupportAgent(const string& fName, int age, int id, double salary);
        
        int getTicketsResolved() const { return ticketsResolved_; }

        void resolveTicket() { ticketsResolved_++; }

        virtual void work() override;
        virtual void print() const override;
};


