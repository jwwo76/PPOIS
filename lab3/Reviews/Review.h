#pragma once
#include "../pch.h"

class Customer;
class Restaurant;
class Order;

class Review{
    private:
        int reviewId_;
        Customer* customer_;
        Restaurant* restaurant_;
        Order* order_;
        int rating_;
        string comment_;
        string reviewDate_;
    public:
        Review(int reviewId, Customer* customer, Restaurant* restaurant, Order* order, int rating, const string& comment, const string& reviewDate);
        ~Review();

        int getReviewId() const { return reviewId_; }
        Customer* getCustomer() const { return customer_; }
        Restaurant* getRestaurant() const { return restaurant_; }
        int getRating() const { return rating_; }
        string getComment() const { return comment_; }

        void setRating(int rating);
        void setComment(const string& comment) { comment_ = comment; }

        void print() const;
};


