#ifndef PHOTOARRAY_H
#define PHOTOARRAY_H

#include "defs.h"
#include "Photo.h"

class PhotoArray{
    public:
        //constructors
        PhotoArray();
        PhotoArray(const PhotoArray& photoArray2);

        //destructor
        ~PhotoArray();

        //methods
        bool isFull() const;
        bool add(Photo* photo);
        bool add(int index, Photo* photo);
        Photo* get(const string& title) const;
        Photo* get(int index) const;
        Photo* remove(const string& title);
        Photo* remove(int index);
        int size() const;
        void print() const;

    private:
        Photo** photoArray;
        int numPhotos;
};

#endif