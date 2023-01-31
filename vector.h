#ifndef VECTOR_H
#define VECTOR_H

#include<iostream>
#include<math.h>

using namespace std;

template <typename T>
class Vector{
    private:
        T *data;
        int number;
        int capacity;
        typedef T * iterator;
    public:
        //Constructor
        Vector(){
            capacity = 1;
            number = 0;
            data = new T[capacity];
            cout << "Call default constructor" << endl;
        };

        //Overload constructor
        Vector(const unsigned int index) {
            number = capacity = index;
            this->data = new T[capacity];
            // for(int i = 0; i < index; i++){
            //     data[i] = NULL;
            // }
            cout << "Call overloading constructor" << endl;
        };

        Vector(Vector &rhs);                    //Copy constructor
        Vector &operator=(const Vector &rhs);   //Assigmnet copy constructor

        Vector(Vector &&rhs);             //Move constructor
        Vector &operator=(Vector &&rhs);  //Move assignment constructor

        T operator[](const int i);   //Access element by [] operator
        T & at(const unsigned int);   //Access element by method at()

        T & front();  //Return frist element
        T & back();   //Return last element

        int size();     //Return count of element in vector
        size_t max_size();   //Return maximum element that vector can store 
        bool empty();   //IsEmpty

        void clear(){number = 0;}
        void insert(iterator, T);    //Insert element by position
        void erase(iterator);

        void push_back(T);  //Push_back element(insert element)
        void pop_back();    //Pop_back element(delete element)

        void push_front(T val);
        void pop_front();

        iterator begin();   //Return an iterator pointing to the frist element of vector
        iterator end();     //Return an iterator pointing to the last element of vector


        // Cout data's vector
        friend ostream& operator<<(ostream &os,Vector &v){
            os << "Size's vector: " << v.number << endl;
            os << "Capacity's vector: " << v.capacity << endl;
            os << "Elements in vector: " << endl;
            for(int i = 0; i < v.size(); i++){
                os << v.data[i] << " "; 
            }
            os << endl;
            os << "The element front of vector is : " << v.front() << endl;
            os << "The element back of vector is : " << v.back() << endl;
            return os;
        }
};

//=======================================
//=========Operator Overloading==========
template <typename T>
Vector<T>::Vector(Vector &rhs)
{
    this->capacity = rhs.capacity;
    this->number = rhs.number;
    data = new T[capacity];
    for(int i = 0; i < this->number; i++){
        data[i] = rhs.data[i];
    }
    cout << "Call copy constructor" << endl;
}

template <typename T>
Vector<T> & Vector<T>::operator=(const Vector &rhs)
{
    this->capacity = rhs.capacity;
    this->number = rhs.number;
    data = new T[capacity];
    for(int i = 0; i < this->number; i++){
        data[i] = rhs.data[i];
    }
    cout << "Call assignment copy constructor " << endl;
    return *this;
};

template <typename T>
Vector<T>::Vector(Vector &&rhs)
{
    this->capacity = rhs.capacity;
    this->number = rhs.number;
    data = new T[capacity];
    for(int i = 0; i < this->number; i++){
        data[i] = rhs.data[i];
    }
    rhs.data = nullptr;
    cout << "Call move constructor" << endl;
};

template <typename T>
Vector<T> & Vector<T>::operator=(Vector &&rhs)
{
    this->capacity = rhs.capacity;
    this->number = rhs.number;
    data = new T[capacity];
    for(int i = 0; i < this->number; i++){
        data[i] = rhs.data[i];
    }
    rhs.data = nullptr;
    cout << "Call assigment move constructor" << endl;
    return *this;
}

template <typename T>
T Vector<T>::operator[](const int i){
    return data[i];
}

//=============== End ====================

template <typename T>
void Vector<T>::push_back(T d){
    if(number == capacity){
        T *temp = new T[capacity * 2];
        for(int i = 0; i < number; i++){
            temp[i] = data[i];
        }
        delete [] data;
        data = temp;
        capacity *= 2;
    }
    data[number] = d;
    number++;
};

template <typename T>
void Vector<T>::pop_back(){
    number--;
}

template <typename T>
void Vector<T>::push_front(T val){
    if(number == capacity){
        T *temp = new T[capacity * 2];
        for(int i = 0; i < number; i++){
            temp[i + 1] = data[i];
        }
        delete [] data;
        data = temp;
        capacity *= 2;
        temp[0] = val;
        number++;
        return;
    }

    for(int i = number; i > 0; i--){
        data[i] = data[i - 1];
    }

    data[0] = val;
    number++;
};

template <typename T>
void Vector<T>::pop_front(){
    for(int i = 0; i < number - 1; i++){
        data[i] = data[i + 1];
    }
    number--;
}



template <typename T>
int Vector<T>::size(){
    return this->number;
}

template <typename T>
size_t Vector<T>::max_size(){
    return pow(2,64) / sizeof(T) / 2;
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
void Vector<T>::erase(iterator index){
    int i;
    for(i = 0; i < number; i++){
        if(&data[i] == index)
            break;
    }
    if(i != number){
        do{
            data[i] = data[i + 1];
        }while(i++ < number);
    }
    else{
        throw runtime_error("double free or corruption (out)");
        return;
    }

    number--;
}

template <typename T>
void Vector<T>::insert(const iterator index, T val){
    int j = -1;

    for(int i = 0; i <= number; i++){
        if(&data[i] == index){
            j = i;
            break;
        }
    }

    if(number == capacity){
        T *temp = new T(capacity * 2);
        for(int i = 0; i < number; i++){
            temp[i] = data[i];
        }
        delete [] data;
        data = temp;
        capacity *= 2;
    }

    for(int i = number; i > j; i--){
        data[i] = data[i - 1];
    }

    data[j] = val;
    number++;
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