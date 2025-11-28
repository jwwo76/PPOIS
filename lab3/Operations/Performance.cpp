#include "Performance.h"
#include "../Persons/Employee.h"
#include "../Exceptions/Exceptions.h"

Performance::Performance(int performanceId, Employee* employee, const string& evaluationDate, int rating, const string& comments)
    : performanceId_(performanceId), employee_(employee), evaluationDate_(evaluationDate), rating_(rating), comments_(comments) {}

Performance::~Performance() {
    employee_ = nullptr;
}

void Performance::setRating(int rating) {
    Exceptions::validateRating1to10(rating, "Рейтинг производительности");
    rating_ = rating;
}

void Performance::addAchievement(const string& achievement) {
    achievements_.push_back(achievement);
}

void Performance::print() const {
    cout << "Performance ID: " << performanceId_ << endl;
    cout << "Evaluation Date: " << evaluationDate_ << endl;
    cout << "Rating: " << rating_ << "/10" << endl;
    cout << "Comments: " << comments_ << endl;
    cout << "Achievements: " << achievements_.size() << endl;
}


