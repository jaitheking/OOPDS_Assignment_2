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

//        T peek(){
//            T *element = new T;
//            if (start == NULL)
//                return element == NULL;
//
//            element = start->info;
//                return element;
//
//        }

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
