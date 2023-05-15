#include "Album.h"

Album::Album(const string& title, const string& description){
    albumTitle = title;
    albumDescription = description;
    albumPhotos =  new PhotoArray();
}

Album::Album(const Album& album){
    albumTitle = album.albumTitle;
    albumDescription = album.albumDescription;
    //PhotoArray temp = *album.albumPhotos;
    albumPhotos = new PhotoArray(*(album.albumPhotos));
}

Album::~Album(){
    delete albumPhotos;
}

string Album::titleGetter() const{
    return albumTitle;
}

bool Album::equals(const string& title) const{
    if(albumTitle == title) return true;
    return false;
}

bool Album::lessThan(const Album& alb) const{
    if(albumTitle< alb.albumTitle) return true;
    return false;
}

bool Album::addPhoto(Photo* ptr){
    return albumPhotos->add(ptr);
}

bool Album::addPhoto(int index, Photo* ptr){
    return albumPhotos->add(index, ptr);
}

Photo* Album::getPhoto(const string& title) const{
    return albumPhotos->get(title);
}

Photo* Album::getPhoto(int index) const{
    return albumPhotos->get(index);
}

Photo* Album::removePhoto(const string& title) {
    return albumPhotos->remove(title);
}

Photo* Album::removePhoto(int index){
    return albumPhotos->remove(index);
}

void Album::print() const{
    cout<< "Album Title: " << albumTitle << " Description: " << albumDescription << endl;
}

void Album::display() const{
    print();
    cout<< "Album Photos: " << endl;
    albumPhotos->print();
}

int Album::size() const{
    return albumPhotos->size();
}

string Album::getTitle() const{
    return albumTitle;
}