#ifndef MAIN_CPP
#define MAIN_CPP
#include <fstream>
#include <iostream>
#include <string>
#include <stack>
#include <cstdlib>
#include "BookItem.hpp"
#include "BookItem.cpp"
using namespace std;

/* DO NOT MODIFY THIS FUNCTION IF YOU ARE NOT FAMILIAR! */
void readData(const char* filename, stack<BookItem>*&stBooks) {
    string line;
    ifstream ifs(filename);
    if (ifs.is_open()) {
        cout << "Reading data...\n";
        int c = 0;
        while ( getline (ifs,line) && (*line.c_str() != '\0') )  {
            string delimiter = ",";
            size_t
            pos = 0;
            string* token = new string[5];
            int f = -1;
            while ((pos = line.find(delimiter)) != string::npos) {
                token[++f] = line.substr(0, pos);
                cout << " " << token[f] << " | " ;
                line.erase(0, pos + delimiter.length());
            }
            token[++f] = line;
            cout << token[f] << endl;       // last item in string
            c++;

            // push to stack (numerical data converted to int)
            BookItem b(atoi(token[0].c_str()), token[1], token[2], atoi(token[3].c_str()), atoi(token[4].c_str()));
            stBooks->push(b);
        }
        cout << c << " row(s) read." << endl;
        ifs.close();
    }
    else
        cout << "Unable to open file";
}
/* ************************************************ */

ostream& operator<<(ostream& os, const BookItem& s)
{
    os << "<" << s.serialNum << "> " << s.title << " : "
       << s.author << " (" << s.yearPublished << ") - "
       << s.copiesSold << " copies sold";
    return os;
}

int main()
{
    // You are to replace the STL Stack with XStack that you have created
    stack<BookItem>* stBooks = new stack<BookItem>();

    // read database from text file, and store in the stack
    readData("db_small.txt", stBooks);

    // Sample code goes after here. Feel free to modify
    // Extra note: the top() method in STL Stack class is similar to peek() that we learnt
    cout << "\nFrom top of stack:\n" << stBooks->top() << endl;
    stBooks->pop();
    cout << stBooks->top();

	return 0;
}
#endif
