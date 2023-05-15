#include "Client.h"

Client::Client(){
    albumArrayPtr = new AlbumArray();
}

Client::~Client(){
    delete albumArrayPtr;
}

bool Client::downloadAlbum(PhotoGram* pg, const string& albumTitle){
    Album* tempAlbum = pg->downloadAlbum(albumTitle);
    if(tempAlbum==NULL) return false;
    Album* newAlbum = new Album(*tempAlbum);
    if(!albumArrayPtr->add(newAlbum)) {
        cout<< "Error: Failed to add album to local AlbumArray"<<endl;
        return false;
    }
    return true;
}

bool Client::displayOnlinePhoto(PhotoGram* pg, const string& albumTitle, const string& photoTitle) const{
    Photo* tempPhoto = pg->downloadPhoto(albumTitle,photoTitle);
    if(tempPhoto== NULL) return false;
    tempPhoto->display();
    return true;
}

bool Client::displayLocalPhoto(const string& albumTitle, const string& photoTitle) const{
    Album* tempAlbum = albumArrayPtr->get(albumTitle);
    if(tempAlbum==NULL){
        cout<< "Error: Album "<< albumTitle<< " does not exist."<<endl;
        return false;
    }
    Photo* tempPhoto= tempAlbum->getPhoto(photoTitle);
    if(tempPhoto==NULL){
        cout<< "Error: Album does not contain photo:  "<< photoTitle<<endl;
        return false;
    }
    tempPhoto->display();
    return true;
}

void Client::printLocalAlbums() const{
    albumArrayPtr->print();
}

void Client::displayLocalAlbums() const{
    albumArrayPtr->display();
}