#include "Photo.h"

using namespace std; 


Photo::Photo(){
    photoTitle = "unknown";
    photoContent = "unknown";
    photoDate = Date();
}

Photo::Photo(const string& title, const Date& date, const string& content){
    photoTitle = title;
    photoDate = date;
    photoContent = content;
}

Photo::Photo(const Photo& photo1){
    photoTitle = photo1.photoTitle;
    photoDate = Date(photo1.photoDate);
    photoContent = photo1.photoContent;
}

bool Photo::equals(const string& title){
    if(title == photoTitle) return true;
    return false;
}

void Photo::print() const{
    cout<< "Photo title: "<< photoTitle << " Date: " << endl;
    photoDate.print();

}

void Photo::display() const{
    cout<< "Photo title: "<< photoTitle << " Date: " << endl;
    photoDate.print();
    cout<< endl << "Content: " << photoContent << endl; 
}





