#ifndef MAIN_CPP
#define MAIN_CPP
#include <fstream>
#include <iostream>
#include <string>
#include "Xstack.hpp"
#include <cstdlib>
#include "BookItem.hpp"

using namespace std;
//Initialise a new stack with Book Item class
Xstack<BookItem>* Books = new Xstack<BookItem>();
BookItem book1();
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
                //cout << " " << token[f] << " | " ;
                line.erase(0, pos + delimiter.length());
                }
            token[++f] = line;
            //cout << token[f] << endl; // last item in string
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

void user_interface(){
    int user_choice;
    int serial;
    int rollnum;
    do{
        cout<<"\nWelcome to E-Leisure \n Book List Management System"
        <<"\n1.Duplicate"
        <<"\n2.SwapTop"
        <<"\n3.Roll"
        <<"\n4.Book search via Serial Number"
        <<"\n5.Look for Top 5 best sellers"
        <<"\n6.Look for Bottom 5 worst sellers"
        <<"\n7.Look for 10 newest books"
        <<"\n8.Exit"
        <<"\nPlease enter your choice:";
        cin>>user_choice;

        switch(user_choice){

        case 1: Books->duplicate();
                break;
        case 2: Books->swapTop();
                break;
        case 3: cout<<"Please enter an amount to perform roll"<<endl;
                cin>>rollnum;
                try {
                if ( rollnum == 0 )
                throw rollnum;
                Books->roll(rollnum);
                }
                catch (int rollnum){
                    cout<<"0 is an invalid input.Please try again.\n";
                }
                break;
        case 4: cout<<"Please enter Serial Number of the book you wish to find:"<<endl;
                cin>>serial;
                Books->serial_search(serial);
                break;
        case 5: Xstack<BookItem>* Books2 = new Xstack<BookItem>();
                readData("db_small.txt", Books2);
                Books2->findtop5sellers(Books2);
//        case 6:
//        case 7:

        }
    }while(user_choice >=1 && user_choice <=8);


}


int main()
{

    // read database from text file, and store in the stack
    readData("db_small.txt", Books);
    user_interface();

	return 0;
}
#endif