#ifndef XSTACK_HPP
#define XSTACK_HPP
#include <iostream>
#include "Node.hpp"

using namespace std;

template <typename T>
class Xstack
{
    Node<T> *top;
    public:
        Xstack(){ top = NULL; }


~Xstack(){ makeEmpty(); }


void push(T& newEl){

            Node<T> *newNode = new Node<T>;
            newNode->info = newEl;
            newNode->next = top;
            top = newNode;
            }


bool peek(T& element){

            if (top == NULL){
                cout<<"No first item to peek";
                return false;
            }
            element = top->info;
            cout<<element<<" is on top of the stack."<<endl;
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



        friend ostream& operator<< (ostream& os, Xstack<T> &list){
            cout<<"Displaying..."<<endl;
            Node<T> *ptr =list.top;
            if (ptr == NULL){
                os << "List is empty."<<endl;
            }
            else{
                os<<"top --> ";


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
