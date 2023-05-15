
#ifndef PHOTO_H
#define PHOTO_H

#include <iostream>
#include <string.h>
#include <stdio.h>
#include "Date.h"
#include <iomanip>

using namespace std;

class Photo{
    private:
        string photoContent;
        string photoTitle;
        Date photoDate;
    public:
        //constructors
        Photo(const string& titile, const Date& date, const string& content);
        Photo();
        Photo(const Photo& photo1);

        void print() const;
        void display() const;
        bool equals(const string& title);


};

#endif