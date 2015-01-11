#include "BookItem.hpp"
#include <iostream>
using namespace std;

int BookItem::fetch_serial(){ return serialNum;}
int BookItem::fetch_sold(){ return copiesSold; }
int BookItem::fetch_pubyear(){ return yearPublished;}
string BookItem::fetch_title(){ return title; }
string BookItem::fetch_author(){ return author; }
