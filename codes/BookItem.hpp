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
    : serialNum(serialNum), title(title), author(ath), yearPublished(year), copiesSold(copiesSold) { }

	friend std::ostream& operator<<(std::ostream& os, const BookItem& s);
};

#endif // BOOKITEM_HPP
