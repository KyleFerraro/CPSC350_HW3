#include <iostream>
#include <stdexcept>

using namespace std;

// made into a template class to be changed in furture
template <typename T>
class GenStack{
public:
    //pointer for memory
    T *myArray;
    GenStack(); //default constructor
    GenStack(T maxSize); //overloaded constructor
    ~GenStack(); //destructor
    //functions
    void push(T); //insert
    T pop(); //remove
    T peek();

    //helper functions
    bool isFull();
    bool isEmpty();
private:
    int mSize;
    int top;//variable to keep track of indicies representing the top of our myStack
};

//constructor
template <typename T>
GenStack<T>::GenStack(){
    myArray = new T[128];
    mSize = 128;
    top = -1;
}

//overload constructor
template <typename T>
GenStack<T>::GenStack(T maxSize){
    myArray = new T[maxSize];
    mSize = maxSize;
    top = -1;
}

//destructor that deletes after use
template <typename T>
GenStack<T>::~GenStack(){
    delete myArray;
}

//peek the top of the array
template <typename T>
T GenStack<T>::peek(){
    if(!isEmpty()){
        return myArray[top];
    }
}

//check to see if stack is full
template <typename T>
bool GenStack<T>::isFull(){
    return (top == mSize);
}

//check to see if stack is empty
template <typename T>
bool GenStack<T>::isEmpty(){
    return (top == 0);
}

//pop the top of the stack
template <typename T>
T GenStack<T>::pop(){
    if(isEmpty() == false){
        return myArray[top--];
    }
}

//push element onto stack
template <typename T>
void GenStack<T>::push(T data){
    if(isFull() == false){
        data = myArray[top--];
    }
}
