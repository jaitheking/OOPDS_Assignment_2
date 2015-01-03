#ifndef XSTACK_HPP
#define XSTACK_HPP
#include <iostream>

using namespace std;
template <typename T>
struct Node{

    T info;
    Node<T> *next;
};

template <typename T>
class Xstack
{
    Node<T> *start;
    public:
         Xstack(){

            start = NULL;

        }

        ~Xstack(){

            makeEmpty();

        }

        void push(T& newEl){


            Node<T> *newNode = new Node<T>;
            newNode->info = newEl;
            newNode->next = start;
            start = newNode;


        }

        void peek(){
            T element;
            if (start == NULL)
                cout<<"No first item to peek";

            element = start->info;
                cout<<"The first item is "<<element<<endl;

        }

        void pop(){

                Node<T> *ptr=start;
                if ( start == NULL )
                    cout<<"List is empty"<<endl;
                else{
                    start = start->next;
                    delete ptr;
                }


        }

        bool isEmpty(){

            return start ==NULL;

        }

        void makeEmpty(){

            while(start !=NULL){

                pop();
                cout<<"List is emptied."<<endl;

            }

            if(start == NULL){

                cout<<"List is empty."<<endl;

            }

        }

        void duplicate(){


            Node<T> *newNode = new Node<T>;
            newNode->info = start->info;
            newNode->next = start;
            start = newNode;

        }
        void swapTop(){

         if (start ==NULL)
            cout<<"Nothing to swap with."<<endl;

         else if (start->next==NULL)
            cout<<"Nothing to swap with."<<endl;


         else{

                Node<T> *tempptr = start;
                Node<T> *tempptr2 = start->next;
                start=start->next->next;
                tempptr->next=start;
                tempptr2->next=tempptr;
                start=tempptr2;

                cout<<"Swap Top successfully"<<endl;
            }

        }
        void roll(){

        if (start ==NULL)
            cout<<"Nothing to roll with."<<endl;

         else if (start->next==NULL)
            cout<<"Nothing to roll with."<<endl;


         else{

                Node<T> *tempptr = start;
                Node<T> *tempptr2 = start->next;
                Node<T> *tempptr3 = start->next->next;
                if (start->next->next->next == NULL)
                    start=NULL;
                else {
                    start=start->next->next->next;
                    }
                tempptr->next=start;
                tempptr3->next=tempptr;
                tempptr2->next=tempptr3;

                start =tempptr2;
                cout<<"Roll (n=3) is successful."<<endl;
                }

            }






        friend ostream& operator<< (ostream& os, Xstack<T> &list){
            cout<<"Displaying..."<<endl;
            Node<T> *ptr =list.start;
            if (ptr == NULL){
                os << "List is empty."<<endl;
            }
            else{
                os<<"START --> ";


                while ( ptr != NULL ) {

                     os<< ptr->info << " --> ";
                    ptr = ptr->next;
                }

                    os<<" NULL";
            }

            return os;


            }
};

#endif //X_STACK HPP
