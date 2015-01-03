#include "book.hpp"
#include "Xstack.hpp"
#include <iostream>
using namespace std;

int main() {
long int isbn = 10000000; // seed for automatic value of x and y.
Xstack<book> list;
int choice; // user choice.
bool found;
book newBook, target;
do {
cout << "Choice:\n"
<< "1: Display books\n"
<< "2: Push new book(Push into stack)\n"
<< "3: Pop the topmost book \n"
<< "4: Blank\n"
<< "5: Empty the list\n"
<< "Others: Exit\n";
cin >> choice;
switch (choice) {
case 1 : cout << list << endl;
break;
case 2 : newBook = book("",++isbn);
list.push(newBook);
break;
case 3 :list.pop();
break;
case 4:
cout<<"Blank Feature."<<endl;
break;
case 5 : list.makeEmpty();
cout << "List is emptied\n\n";
break;
}
} while (choice >= 1 && choice <= 7);
}
