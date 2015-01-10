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
        Xstack();

        ~Xstack();

        void push(T& newEl);

        void peek();

        void pop();

        bool isEmpty();

        void makeEmpty();

        void duplicate();
        void swapTop();
        void roll(int n);



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
