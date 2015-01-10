#include "Xstack.hpp"
#include "Node.hpp"
template <class T>
Xstack<T>::Xstack(){ top = NULL; }

template <class T>
Xstack<T>::~Xstack(){ makeEmpty(); }

template <class T>
void Xstack<T>::push(T& newEl){

            Node<T> *newNode = new Node<T>;
            newNode->info = newEl;
            newNode->next = top;
            top = newNode;
            }

template <class T>
void Xstack<T>::peek(){
            T element;
            if (top == NULL)
                cout<<"No first item to peek";

            element = top->info;
                cout<<"The first item is "<<element<<endl;

        }

template <class T>
void Xstack<T>::pop(){

                Node<T> *ptr=top;
                if ( top == NULL )
                    cout<<"List is empty"<<endl;
                else{
                    top = top->next;
                    delete ptr;
                }
            }

template <class T>
bool Xstack<T>::isEmpty(){

            return top ==NULL;

        }

template <class T>
void Xstack<T>::makeEmpty(){

            while(top !=NULL){

                pop();
                cout<<"List is emptied."<<endl;

            }

            if(top == NULL){

                cout<<"List is empty."<<endl;

            }

        }
template <class T>
void Xstack<T>::duplicate(){


            Node<T> *newNode = new Node<T>;
            newNode->info = top->info;
            newNode->next = top;
            top = newNode;

        }
template <class T>
void Xstack<T>::swapTop(){

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
template <class T>
void Xstack<T>::roll(int n){
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



