template <typename T>
struct Node{

    T info;
    Node<T> *next;
};

template <typename T>
class Xstack
{
Node<T>* start;
Node<T>* current;
public:
Xstack(){}
~Xstack(){}
void push (T &newEl){}
T peek(){}
void pop (){}
bool isEmpty(){}
void makeEmpty(){}
void duplicate(){}
void swapTop(){}
void roll(){}
friend ostream& operator<< (ostream& os,Xstack<T>& list){}
};
