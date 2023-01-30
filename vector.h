#ifndef VECTOR_H
#define VECTOR_H

#include<iostream>
using namespace std;
template <typename T>
class Vector{
    private:
        T *data;
        int number;
        typedef T * iterator;
    public:
        //Constructor
        Vector(){
            data = new T[1];
            number = 0;
            cout << "Call default constructor" << endl;
        };

        //Overload constructor
        Vector(const unsigned int index) {
            number = index;
            this->data = new T[number];
            cout << "Call overloading constructor" << endl;
        };

        Vector(Vector &rhs);                    //Copy constructor
        Vector &operator=(const Vector &rhs);   //Assigmnet copy constructor

        Vector(const Vector &&rhs);             //Move constructor
        Vector &operator=(const Vector &&rhs);  //Move assignment constructor

        T operator[](const int i);   //Access element by [] operator
        T & at(const unsigned int);   //Access element by method at()

        void push_back(T);  //Push_back element(insert element)
        void pop_back();    //Pop_back element(delete element)

        int size();     //Size of vector
        bool empty();   //IsEmpty

        T & front();  //Return frist element
        T & back();   //Return last element

        void insert(iterator, T);    //Insert element by position

        iterator begin();   //Return an iterator pointing to the frist element of vector
        iterator end();     //Return an iterator pointing to the last element of vector

        T max_size(){
            return sizeof(data);
        };
};

//=======================================
//=========Operator Overloading==========
template <typename T>
Vector<T>::Vector(Vector &rhs)
{
    this->number = rhs.number;
    data = new T[number];
    *data = *rhs.data;
    cout << "Call copy constructor" << endl;
}

template <typename T>
Vector<T> & Vector<T>::operator=(const Vector &rhs)
{
    this->number = rhs.number;
    data = new T[number];
    *data = *rhs.data;
    cout << "Call assignment copy constructor " << endl;
    return *this;
};

template <typename T>
Vector<T>::Vector(const Vector &&rhs)
{
    *data = rhs.data;
    rhs.data = nullptr;
    cout << "Call move constructor" << endl;
};

template <typename T>
Vector<T> & Vector<T>::operator=(const Vector &&rhs)
{
    *data = rhs.data;
    rhs.data = nullptr;
    cout << "Call move constructor" << endl;
}

template <typename T>
T Vector<T>::operator[](const int i){
    return data[i];
}

//=============== End ====================

template <typename T>
void Vector<T>::push_back(T d){
    T *temp = new T[number++];
    for(int i = 0;i < number - 1; i++){
        temp[i] = data[i];
    }
    delete [] data;
    data = temp;
    data[number - 1] = d;
};

template <typename T>
void Vector<T>::pop_back(){
    number--;
}

template <typename T>
int Vector<T>::size(){
    return this->number;
}

template <typename T>
bool Vector<T>::empty(){
    return (number == 0) ? true : false;
}

template <typename T>
T & Vector<T>::front(){
    return data[0];
}

template <typename T>
T & Vector<T>::back(){
    return data[number - 1];
}

template <typename T>
T & Vector<T>::at(const unsigned int i){
    if(i >= number){  
        throw runtime_error("out of range exception");
    }
    return data[i];
}

template <typename T>
void Vector<T>::insert(const iterator index, T val){
    int j;
    T * temp = new T[number++];

    if(&data[number - 1] == index)
        j = number - 1;

    for(int i = 0; i < number - 1; i++){
        temp[i] = data[i];
        if(&data[i] == index)
            j = i;
    }

    delete [] data;
    data = temp;
    for(int i = number - 1; i > j; i--){
        data[i] = data[i - 1];
    }
    data[j] = val;
}

template <typename T>
typename Vector<T>::iterator Vector<T>::begin(){
    return iterator(&data[0]);
}

template <typename T>
typename Vector<T>::iterator Vector<T>::end(){
    return iterator(&data[number]);
}

#endif 