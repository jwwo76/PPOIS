#pragma once
#include "../pch.h"

class Zone;

class City{
    private:
        int cityId_;
        string name_;
        string state_;
        string country_;
        vector<Zone*> zones_;
    public:
        City(int cityId, const string& name, const string& state, const string& country);
        ~City();

        int getCityId() const { return cityId_; }
        string getName() const { return name_; }
        string getState() const { return state_; }
        string getCountry() const { return country_; }
        vector<Zone*> getZones() const { return zones_; }

        void setCityId(int id) { cityId_ = id; }
        void setName(const string& name) { name_ = name; }
        void setState(const string& state) { state_ = state; }
        void setCountry(const string& country) { country_ = country; }
        void addZone(Zone* zone);
        void removeZone(Zone* zone);

        void print() const;
};


