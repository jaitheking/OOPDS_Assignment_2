#include "book.hpp"
#include "Xstack.hpp"
#include <iostream>

using namespace std;

int main() {
        long int isbn = 10000000; // Book`s ISBNs for automatic value of x and y.
        Xstack<book> list;
        int choice; // user choice.
        string s; // user input for the roll function
        int n; // user input for the roll function
        book newBook, target;
        do {
        cout << "Choice:\n"
        << "1: Display books\n"
        << "2: Push a new book\n"
        << "3: Pop the topmost book \n"
        << "4: Peek the top\n"
        << "5: Duplicate\n"
        << "6: SwapTop\n"
        << "7: Roll (n=3)\n"
        << "8: Empty the list\n"
        << "Others: Exit\n";
        cin >> choice;
        switch (choice) {
        case 1 : cout << list << endl;
        break;
        case 2 : newBook = book(++isbn);
        list.push(newBook);
        break;
        case 3 :list.pop();
        break;
        case 4:list.peek();
        break;
        case 5 :list.duplicate();
        break;
        case 6: list.swapTop();
        break;
        case 7:
                cout<<"Please enter an amount to perform roll"<<endl;
                cin>>n;
                try {
                if ( n == 0 )
                throw n;
                list.roll(n);
                }
                catch (int n){
                    cout<<"0 is an invalid input.Please try again.\n";
                }



        break;
        case 8: list.makeEmpty();
        cout << "List is emptied\n";
        break;
        }
        } while (choice >= 1 && choice <= 8);
}
