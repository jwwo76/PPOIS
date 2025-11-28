#pragma once
#include "../pch.h"

class Employee;

class Performance{
    private:
        int performanceId_;
        Employee* employee_;
        string evaluationDate_;
        int rating_;
        string comments_;
        vector<string> achievements_;
    public:
        Performance(int performanceId, Employee* employee, const string& evaluationDate, int rating, const string& comments);
        ~Performance();

        int getPerformanceId() const { return performanceId_; }
        Employee* getEmployee() const { return employee_; }
        int getRating() const { return rating_; }
        vector<string> getAchievements() const { return achievements_; }

        void setRating(int rating);
        void addAchievement(const string& achievement);

        void print() const;
};


