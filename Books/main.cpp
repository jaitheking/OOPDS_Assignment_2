#ifndef MAIN_CPP
#define MAIN_CPP
#include <fstream>
#include <iostream>
#include <string>
#include "Xstack.hpp"
#include <cstdlib>
#include "BookItem.hpp"

using namespace std;

/* DO NOT MODIFY THIS FUNCTION IF YOU ARE NOT FAMILIAR! */
void readData(const char* filename, Xstack<BookItem>*& stBooks)
{
    string line;
    ifstream ifs(filename);
    if (ifs.is_open())
{
    cout << "Reading data...\n";
    int c = 0;
    while ( getline (ifs,line) && (*line.c_str() != '\0') )
        {
            string delimiter = ",";
            size_t pos = 0;
            string* token = new string[5];
            int f = -1;
            while ((pos = line.find(delimiter)) != string::npos)
                {
                token[++f] = line.substr(0, pos);
                cout << " " << token[f] << " | " ;
                line.erase(0, pos + delimiter.length());
                }
            token[++f] = line;
            cout << token[f] << endl; // last item in string
            c++;
            // push to stack (numerical data converted to int)
            BookItem b(atoi(token[0].c_str()), token[1], token[2], atoi(token[3].c_str()), atoi(token[4].c_str()));
            stBooks->push(b);
        }
    cout << c << " row(s) read." << endl;
    ifs.close();
    }
    else
    cout << "Unable to open file\n" << endl;
}
/* ************************************************ */



int main()
{
    //Initialise a new stack with Book Item class
    Xstack<BookItem>* Books = new Xstack<BookItem>();
    BookItem book1();
    //BookItem book_el(24504,"The Old Man and the Sea,Ernest Hemingway",1951,135);
    // read database from text file, and store in the stack
    readData("db_small.txt", Books);

    // Sample code goes after here. Feel free to modify
    // Extra note: the top() method in STL Stack class is similar to peek() that we learnt
    Books->peek();
    Books->pop();
    Books->peek();
    Books->id_search(24504);

	return 0;
}
#endif
