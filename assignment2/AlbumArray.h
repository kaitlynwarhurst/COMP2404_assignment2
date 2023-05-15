#ifndef ALBUMARRAY_H
#define ALBUMARRAY_H

#include "Album.h"

class AlbumArray{
    public:
        //constructors
        AlbumArray();
        AlbumArray(const AlbumArray& AlbumArray2);
        //destructor 
        ~AlbumArray();
        //other methods
        bool isFull() const;
        bool add(Album* albumPtr);
        Album* get(const string& title) const;
        Album* get(int index) const;
        Album* remove( const string& title);
        Album* remove(int index);
        int size() const;
        void print() const;
        void display() const;
    private:
        Album** albumPtrArray;
        int numAlbums;
};

#endif