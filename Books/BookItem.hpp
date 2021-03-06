#ifndef BOOKITEM_HPP
#define BOOKITEM_HPP
#include <iostream>
#include <string>
using namespace std;

class BookItem
{
    int serialNum;
    string title;
    string author;
    int yearPublished;
    int copiesSold;
public:
    BookItem(int serialNum=0, string title="", string ath="", int year=0, int copiesSold=0)
    : serialNum(serialNum), title(title), author(ath), yearPublished(year), copiesSold(copiesSold) {}
    int fetch_serial();
    int fetch_sold();
    int fetch_pubyear();
    string fetch_title();
    string fetch_author();
	friend ostream& operator<<(ostream& os, const BookItem& s){
    os << "<" << s.serialNum << "> " << s.title << " : "
       << s.author << " (" << s.yearPublished << ") - "
       << s.copiesSold << " copies sold";
    return os;
};
};

#endif // BOOKITEM_HPP
