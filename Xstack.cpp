#include "Xstack.hpp"

Xstack::Xstack(){

    start = NULL;

}

Xstack::~Xstack(){

    makeEmpty();

}

void Xstack::push(T& newEl){


    Node<T> *newNode = new Node<T>;
    newNode->info = element;
    newNode->next = start;
    start = newNode;


}

bool Xstack::peek(T &element){

    if (start == NULL)
        return false;

    element = start->info;
        return true;

}

void Xstack::pop(){

        Node<T> *ptr=start;
        if ( start == NULL )
            cout<<"List is empty"<<endl;
        else{
            start = start->next;
            delete ptr;
        }


}

T Xstack::peek(){

    if (start == NULL)
        return 1;

    else{
        return start->info;
    }

}

bool Xstack::isEmpty(){

    return start ==NULL;

}

void Xstack::makeEmpty(){

    while(start !=NULL){

        pop();

    }

    else{

        cout<<"List is empty."<<endl;

    }

}

friend ostream& operator<< (ostream& os,Xstack<T>& list){

    if (list.start == NULL){
        os << "List is empty."<<endl;

    }

    else{

        Node<T> *ptr =list.start;

        while ( ptr != NULL ) {

            os<< ptr->info << "";
            ptr = ptr->next;
        }

        cout<<endl;
    }


    return os;
    }

