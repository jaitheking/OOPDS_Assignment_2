#include <string.h>
#include <iostream>

using namespace std;

class book{

    string title;
    long int isbn;

    public:
    book(string title="Book",long int isbn=0):title(title),isbn(isbn){}
    string getTitle(){ return title; }
    long int getIsbn(){ return isbn; }
    void setTitle() { this->title=title; }
    void setIsbn() { this->isbn=isbn; }
    friend ostream& operator<< (ostream& os,book& book){
        os<<book.getTitle() << book.getIsbn();
        return os;
    }

    friend istream& operator>> (istream& is, book& b){
        return is;
    }





};
