#include "PhotoGram.h"

PhotoGram::PhotoGram(){
    photogram = new AlbumArray();
}

PhotoGram::~PhotoGram(){
    delete photogram;
}

bool PhotoGram::addAlbum(const string& title, const string& description){
    if(photogram->isFull()){
        cout<< "Error: failed to add Album"<< endl;
        return false;
    }
    Album* newAlbum = new Album(title, description);
    return photogram->add(newAlbum);
}

bool PhotoGram::removeAlbum(const string& title){
    Album* removedAlbum = photogram->remove(title);
    if(removedAlbum == NULL){
        cout<< "Error: failed to find and remove Album " << title <<endl;
        return false;
    }
    delete removedAlbum;
    return true;
}

bool PhotoGram::addPhoto(const string& albumTitle, const Photo& photo){
    Album* tempAlbum = photogram->get(albumTitle); 
    Photo* photoPtr = new Photo(photo);
    bool photoAdded = tempAlbum ->addPhoto(photoPtr);
    if(!photoAdded){
        cout<< "Error: Failed to add Photo" <<endl;
        return false;
    }
    return true;
}

bool PhotoGram::removePhoto(const string& albumTitle, const string& photoTitle){
    Album* tempAlbum = photogram->get(albumTitle);
    Photo* removedPhoto = tempAlbum->removePhoto(photoTitle);
    if(removedPhoto==NULL){
        cout<<"Error: failed to remove Photo"<< photoTitle<<endl;
        return false;
    }
    delete removedPhoto;
    return true;
}

//returns NULL if the download is unsuccessful 
Album* PhotoGram::downloadAlbum(const string& albumTitle) const{
    Album* temp = photogram->get(albumTitle);
    if(temp==NULL){
        cout<< "Error: Album, " << albumTitle << " not found" <<endl;
    }
    return temp;
}

//returns NULL if the download is unsuccsessful 
Photo* PhotoGram::downloadPhoto(const string& albumTitle, const string& photoTitle) const{
    Photo* temp = photogram->get(albumTitle)->getPhoto(photoTitle);
    if(temp==NULL){
        cout<< "Error: Photo, " << photoTitle << " in "<< albumTitle<< " not found" <<endl;
    }
    return temp;
}

void PhotoGram::printAlbums() const{
    photogram->print();
}

void PhotoGram::displayAlbums() const{
    photogram->display();
} 