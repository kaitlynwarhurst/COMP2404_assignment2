#include "AlbumArray.h"

AlbumArray::AlbumArray(){
    albumPtrArray = new Album*[MAX_ARRAY];
    numAlbums=0;
}

AlbumArray::AlbumArray(const AlbumArray& AlbumArray2) {
    numAlbums = AlbumArray2.numAlbums;
    albumPtrArray = new Album*[MAX_ARRAY];
    for(int i= 0; i< numAlbums; ++i){
        Album* temp = new Album(*AlbumArray2.get(i));
        albumPtrArray[i] = temp;
    }
}

AlbumArray::~AlbumArray(){
    /*for(int i =0; i <numAlbums ; ++i){
        Album* albumPtr = albumPtrArray[i];
        albumPtrArray[i] = NULL;
        delete albumPtr;
    }*/
    delete[] albumPtrArray;
    albumPtrArray = NULL;
}

bool AlbumArray::isFull() const{
    if(numAlbums>=MAX_ARRAY) return true;
    return false;
}

bool AlbumArray::add(Album* albumPtr){
    if(isFull()) return false;
    for(int i = numAlbums;i>0;--i){
        if(albumPtr->lessThan(*albumPtrArray[i-1])){
            albumPtrArray[i] = albumPtrArray[i-1];
        }
        else{
            albumPtrArray[i] = albumPtr;
            ++numAlbums;
            return true;
        }
    }
    albumPtrArray[0] = albumPtr;
    ++numAlbums;
    return true;
}

Album* AlbumArray::get(const string& title) const{
    for(int i =0; i<numAlbums; ++i){
        if(albumPtrArray[i]->equals(title)) return albumPtrArray[i];
    }
    return NULL;
}

Album* AlbumArray::get(int index) const{
    if(index<0 ||index>=numAlbums) return NULL;
    return albumPtrArray[index];
}

Album* AlbumArray::remove(const string& title){
    Album* albumPtr= NULL;
    bool found = false;
    for(int i= 0; i<numAlbums; ++i){
        if(albumPtrArray[i]->equals(title)){
            albumPtr = albumPtrArray[i];
            found = true;
        }
        if(found){
            if(i== numAlbums -1){
                albumPtrArray[numAlbums-1] = NULL;
                break;
            }
            albumPtrArray[i] = albumPtrArray[i+1];
        }
    }
    if(!found) return NULL;
    --numAlbums;
    return albumPtr;
}

Album* AlbumArray::remove(int index){
    if(index < 0 || index >= numAlbums) return NULL;
    Album* albumPtr = albumPtrArray[index];
    for(int i = index; i < numAlbums-1; ++i){
        albumPtrArray[i] = albumPtrArray[i+1];
    }
    albumPtrArray[numAlbums-1] = NULL;
    --numAlbums;
    return albumPtr;
}

int AlbumArray::size() const{
    return numAlbums;
}

void AlbumArray::print() const{
    for(int i= 0; i< numAlbums; i++){
        albumPtrArray[i]->print();
    }
}

void AlbumArray::display() const{
    for(int i =0; i< numAlbums; i++){
        albumPtrArray[i]->display();
    }
}