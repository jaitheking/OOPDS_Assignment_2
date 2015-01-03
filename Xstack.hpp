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

            }

            if(start == NULL){

                cout<<"List is empty."<<endl;

            }

        }

        friend ostream& operator<< (ostream& os,Xstack<T>& list){

            if (list.start == NULL){
                cout << "List is empty."<<endl;

            }

            else{
                cout<<"START-->";
                Node<T> *ptr =list.start;

                while ( ptr != NULL ) {

                     cout<< ptr->info << "-->";
                    ptr = ptr->next;
                }

                cout<<"NULL";
            }



            }
        void duplicate(){}
        void swapTop(){}
        void roll(){}

        };
