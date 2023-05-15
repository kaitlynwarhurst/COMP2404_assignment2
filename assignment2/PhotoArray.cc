#include "PhotoArray.h"

PhotoArray::PhotoArray(){
    photoArray = new Photo*[MAX_ARRAY];
    numPhotos=0;
}

PhotoArray::PhotoArray(const PhotoArray& photoArray2){
    numPhotos = photoArray2.numPhotos;
    photoArray = new Photo*[MAX_ARRAY];
    for(int i= 0; i< numPhotos; ++i){
        Photo* temp = new Photo(*photoArray2.get(i));
        photoArray[i] = temp;
    }
}

PhotoArray::~PhotoArray(){
    for(int i =0; i <numPhotos ; ++i){
        Photo* photoPtr = photoArray[i];
        photoArray[i] = NULL;
        delete photoPtr;
    }
    delete[] photoArray;
    photoArray = NULL;
}

bool PhotoArray::isFull() const{
    if(numPhotos>=MAX_ARRAY) return true;
    return false;
}

bool PhotoArray::add(Photo* photo){
    if(isFull()) return false;
    //Photo* newPhoto = new Photo(*photo);
    photoArray[numPhotos] = photo; 
    ++numPhotos;
    return true;
}

bool PhotoArray::add(int index, Photo* photo){
    if(isFull()|| index<0 || index>numPhotos) return false;
    //Photo* newPhoto =  new Photo(*photo);
    for(int i = numPhotos; i> index; --i){
        photoArray[i] = photoArray[i-1];
    }
    photoArray[index] = photo;
    ++numPhotos;
    return true;
}

Photo* PhotoArray::get(const string& title) const{
    for(int i =0; i<numPhotos; ++i){
        if(photoArray[i]->equals(title)) return photoArray[i];
    }
    return NULL;
}

Photo* PhotoArray::get(int index) const{
    if(index<0 ||index>=numPhotos) return NULL;
    return photoArray[index];
}

Photo* PhotoArray::remove(const string& title){
    Photo* photoPtr= NULL;
    bool found = false;
    for(int i= 0; i<numPhotos; ++i){
        if(photoArray[i]->equals(title)){
            photoPtr = photoArray[i];
            found = true;
        }
        if(found){
            if(i== numPhotos -1){
                photoArray[numPhotos-1] = NULL;
                break;
            }
            photoArray[i] = photoArray[i+1];
        }
    }
    if(!found) return NULL;
    --numPhotos;
    return photoPtr;
}

Photo* PhotoArray::remove(int index){
    if(index < 0 || index >= numPhotos) return NULL;
    Photo* photoPtr = photoArray[index];
    for(int i = index; i < numPhotos-1; ++i){
        photoArray[i] = photoArray[i+1];
    }
    photoArray[numPhotos-1] = NULL;
    --numPhotos;
    return photoPtr;

}

int PhotoArray::size() const{
    return numPhotos;
}

void PhotoArray::print()const{
    cout<< "Photo Array: "<< endl;
    for(int i =0; i< numPhotos; i++){
        photoArray[i]->display();
    }
}

