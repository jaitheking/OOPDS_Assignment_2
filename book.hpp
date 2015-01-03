#include <string.h>
#include <iostream>

using namespace std;

class book{

    string title;
    long int isbn;

    public:
    book(long int isbn=0):title("Book"),isbn(isbn){}
    string getTitle(){ return title; }
    long int getIsbn(){ return isbn; }
    void setTitle() { this->title=title; }
    void setIsbn() { this->isbn=isbn; }
    friend ostream& operator<< (ostream& os,book& book){
        os<<book.getTitle() <<","<< book.getIsbn()<<endl;
        return os;
    }

    friend istream& operator>> (istream& is, book& b){
        return is;
    }





};
