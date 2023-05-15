#ifndef ALBUM_H
#define ALBUM_H

#include "PhotoArray.h"

class Album{
    public:
        //constructors
        Album(const string& title, const string& description);
        Album(const Album& album);
        //destructors
        ~Album();
        //methods
        string titleGetter() const;
        bool equals(const string& title) const;
        bool lessThan(const Album& alb) const;
        bool addPhoto(Photo* ptr );
        bool addPhoto(int index, Photo* ptr);
        Photo* getPhoto(const string& title) const;
        Photo* getPhoto(int index) const;
        Photo* removePhoto(const string& title);
        Photo* removePhoto(int index);
        void print() const;
        void display() const;
        int size() const;
        string getTitle() const;

    private:
        string albumTitle;
        string albumDescription;
        PhotoArray* albumPhotos;

};

#endif