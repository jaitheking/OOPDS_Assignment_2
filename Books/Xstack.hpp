#ifndef XSTACK_HPP
#define XSTACK_HPP
#include <iostream>
#include "Node.hpp"
#include "BookItem.hpp"
using namespace std;

template <typename T>
class Xstack
{
    Node<T> *top;
    public:
        Xstack(){ top = NULL; }
        Xstack(const Xstack<T> &list){}

~Xstack(){ makeEmpty(); }


    void push(T& newEl){

            Node<T> *newNode = new Node<T>;
            newNode->info = newEl;
            newNode->next = top;
            top = newNode;
            }


    bool peek(T& element){

            if (top == NULL)
                return false;
            element = top->info;
                return true;
        }


    bool pop(T& element){


                if ( top == NULL ){
                    return false;
                    cout<<"List is empty"<<endl;
                }
                    element = top->info;
                    Node<T> *ptr=top;
                    top = top->next;
                    delete ptr;
                    return true;

            }


    bool isEmpty(){

            return top ==NULL;

        }


void makeEmpty(){

            T temp;
            while (pop(temp));

        }

    void duplicate(){


            Node<T> *newNode = new Node<T>;
            newNode->info = top->info;
            newNode->next = top;
            top = newNode;

        }

    void swapTop(){

         if (top ==NULL)
            cout<<"Nothing to swap with."<<endl;

         else if (top->next==NULL)
            cout<<"Nothing to swap with."<<endl;


         else{

                Node<T> *tempptr = top;
                Node<T> *tempptr2 = top->next;
                top=top->next->next;
                tempptr->next=top;
                tempptr2->next=tempptr;
                top=tempptr2;

                cout<<"Swap Top successfully"<<endl;
            }

        }

    void roll(int n){
        if (top == NULL)
            cout<<"Nothing to roll with."<<endl;

        else {

            int total = 0;
            Node<T> *ptr =top;
            Node<T> *tempptr= top;
            while(tempptr->next !=NULL && total !=n){
                tempptr=tempptr->next;

                total++;
            }
            if (n>total){
                cout<<"Cannot perform roll at "<<n<<" amount(s)"<<endl;
            }


            else{
                top=top->next;
                ptr->next = tempptr->next;
                tempptr->next = ptr;

            cout<<"Roll ("<<n<<") is successful."<<endl;

                }

            }
        }

    void serial_search(int serial){
        bool found = false;
        Node<T> *ptr = top;
        while(ptr->next != NULL && !found){
            ptr=ptr->next;
            if (ptr->info.fetch_serial() == serial){
                found = true;
                cout<<ptr->info;
            }
            else if(ptr->next == NULL){
            cout<<"There is no book with such serial number,"<<serial<<endl;
            }


        }

    }

        void findtop5sellers(Xstack<T> *& list){

            Xstack<T> list2; //sorted stack
            int loop=0;
            while(!list->isEmpty()){
                T x; // My x(Comparison)
                T y; //
                list->pop(x);
                //y,Peek at S2 to compare with X
                //while (y >x) ,move y to the sorted stack
                list2.peek(y);
                while(!list2.isEmpty() && y.fetch_sold() > x.fetch_sold() ){
                    T temp;
                    list2.pop(temp);
                    list->push(temp);
                    list2.peek(y);

                }
                list2.push(x);

            }
            Node<T> *ptr=list2.top;
            do{

            cout<<ptr->info<<endl;
            loop++;
            ptr=ptr->next;

            }while ( ptr->next!= NULL && loop < 5);
        }

        void findworst5sellers(Xstack<T> *& list){

            Xstack<T> list2; //sorted stack
            int loop=0;
            while(!list->isEmpty()){
                T x; // My x(Comparison)
                T y; //
                list->pop(x);
                //while (y <x) ,move y to the sorted stack because we want bottom 5 sellers in ascending order;
                list2.peek(y);
                while(!list2.isEmpty() && y.fetch_sold() < x.fetch_sold() ){
                    T temp;
                    list2.pop(temp);
                    list->push(temp);
                    list2.peek(y);

                }
                list2.push(x);

            }
            Node<T> *ptr=list2.top;
            do{

            cout<<ptr->info<<endl;
            loop++;
            ptr=ptr->next;

            }while ( ptr->next!= NULL && loop < 5);
        }

        void find_newest(Xstack<T> *& list){

            Xstack<T> list2; //sorted stack
            int loop=0;
            while(!list->isEmpty()){
                T x; // My x(Comparison)
                T y; //
                list->pop(x);
                list2.peek(y);
                if (y.fetch_pubyear() == x.fetch_pubyear()){
                //The published year is the same the object will be
                //arranged by alphabetical order instead
                    while(!list2.isEmpty() && y.fetch_title()<x.fetch_title() ){

                            T temp;
                            list2.pop(temp);
                            list->push(temp);
                            list2.peek(y);
                        }

                }

                else {
                    while(!list2.isEmpty() && y.fetch_pubyear() > x.fetch_pubyear() ){

                            T temp;
                            list2.pop(temp);
                            list->push(temp);
                            list2.peek(y);

                      }
                }
                list2.push(x);

            }
            Node<T> *ptr=list2.top;
            do{

            cout<<ptr->info<<endl;
            loop++;
            ptr=ptr->next;

            }while ( ptr->next!= NULL && loop < 11);
        }

       void top_unique_authors(Xstack<T> *& list,int n){

            Xstack<T> list2;//sorted stack
            Xstack<T> list3; //unique stack
            int loop=1;
            while(!list->isEmpty()){
                T x; // My x(Comparison)
                T y; //
                list->pop(x);
                //y,Peek at S2 to compare with X
                //while (y >x) ,move y to the sorted stack
                list2.peek(y);
                while(!list2.isEmpty() && y.fetch_sold() < x.fetch_sold() ){
                    T temp;
                    list2.pop(temp);
                    list->push(temp);
                    list2.peek(y);

                }
                list2.push(x);

            }

            while(!list2.isEmpty()){
                T x;
                T y;
                list2.pop(x);
                list3.peek(y);
                if (y.fetch_author() == x.fetch_author()){
                    if(x.fetch_sold() > y.fetch_sold()){
                        list3.pop(y);

                    }


                }
               list3.push(x);
            }


            Node<T> *ptr=list3.top;
            cout<<"Top "<<n<<" Authors:"
            <<"\nAuthor: | Copies Sold:"<<endl;
            do{

            cout<<ptr->info.fetch_author()<<"  |  "<<ptr->info.fetch_sold()<<endl;
            loop++;
            ptr=ptr->next;

            }while ( ptr->next!= NULL && loop < n+1);
        }


        friend ostream& operator<< (ostream& os, Xstack<T> *&list){
            cout<<"Displaying..."<<endl;
            Node<T> *ptr =list->top;
            if (list->isEmpty()){
                os << "List is empty."<<endl;
            }
            else{
                os<<"TOP --> ";


                while ( ptr != NULL ) {

                     os<<"\n"<< ptr->info<<endl;
                    ptr = ptr->next;
                }

                    os<<" NULL";
            }

            return os;


            }
};



#endif //X_STACK HPP
