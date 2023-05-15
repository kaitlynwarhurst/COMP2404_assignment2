#ifndef PHOTOGRAM_H
#define PHOTOGRAM_H

#include "AlbumArray.h"

class PhotoGram{
    public:
        //constructors and destructors
        PhotoGram();
        ~PhotoGram();
        //add and remove
        bool addAlbum(const string& title, const string& description);
        bool addPhoto(const string& albumTitle, const Photo& photo);
        bool removeAlbum(const string& title);
        bool removePhoto(const string& albumTitle, const string& photoTitle);

        //Client 
        Album* downloadAlbum(const string& albumTitle) const;
        Photo* downloadPhoto(const string& albumTitle, const string& photoTitle) const;

        //print
        void printAlbums() const;
        void displayAlbums() const;
    private:
        AlbumArray* photogram;
};

#endif