#ifndef _MYVECTOR_H
#define _MYVECTOR_H
#include <iostream>
#include <cassert>
#include "MyIterator.h"

template<class T>
class MyVector {
private:
    int m_length;
    int m_size;
    T* m_data;

public:
    MyVector() : m_length(0),m_size(0), m_data(nullptr){}
    MyVector(int length) : m_length(length), m_size(0){
        assert(length >= 0);

        if(length > 0){
            m_data = new T[length];
        }
        else{
            m_data = nullptr;
        }
    }

    ~MyVector(){ delete[] m_data; }

    void erase(){
        delete[] m_data;

        m_data = nullptr;
        m_size = 0;
        m_length = 0;
    }

    int getSize() const { return m_size; }
    int getLength() const { return m_length; }

    MyIterator<T> begin() const{
        return MyIterator(&m_data[0]);
    }

    MyIterator<T> end() const{
        return MyIterator(&m_data[m_size]);
    }

    int& operator[](int index){
        assert(index >= 0 && index < m_size);

        return m_data[index];
    }

    void resize(int newSize){
        if(newSize == m_size) {

            return;
        }
        if(newSize <= 0){
            erase();

            return;
        }

        int *data;
        if(newSize > m_length){
            m_length = newSize + 5;
            data = new int[m_length];
        }
        else{
            data = new int[m_length];
        }

        if(m_size > 0){
            int elementsToCopy = (newSize > m_size) ? m_size : newSize;

            for(int index = 0; index < elementsToCopy; index++){
                data[index] = m_data[index];
            }
        }

        delete[] m_data;
        m_data = data;
        m_size = newSize;
    }

    void resize(int newSize, T& value){
        if(newSize == m_size) {

            return;
        }
        if(newSize <= 0){
            erase();

            return;
        }

        int *data;
        if(newSize > m_length){
            m_length = newSize + 5;
            data = new int[m_length];
        }
        else{
            data = new int[m_length];
        }

        if(m_size > 0){
            int elementsToCopy = (newSize > m_size) ? m_size : newSize;

            for(int index = 0; index < elementsToCopy; index++){
                data[index] = m_data[index];
            }
            for(int index = elementsToCopy; index < newSize; index++){
                data[index] = value;
            }
        }

        delete[] m_data;
        m_data = data;
        m_size = newSize;
    }

    void reserve(int newLength){
        if(newLength <= m_length) {
            return;
        }

        int *data = new int[m_length];

        if(m_size > 0){
            int elementsToCopy = (newLength > m_size) ? m_size : newLength;

            for(int index = 0; index < elementsToCopy; index++){
                data[index] = m_data[index];
            }
        }

        delete[] m_data;
        m_data = data;
        m_length = newLength;
    }

    void shrink(){
        if(m_size == m_length) {
            return;
        }

        int *data = new int[m_size];

        if(m_size > 0){
            for(int index = 0; index < m_size; index++){
                data[index] = m_data[index];
            }
        }

        delete[] m_data;
        m_data = data;
        m_length = m_size;
    }

    void insertBefore(T& value, int index){
        assert(index >= 0 && index <= m_size);

        if(index > m_length){
            m_length += 5;
        }
        T* data = new T[m_length];

        for(int before = 0; before < index; ++before){
            data[before] = m_data[before];
        }

        data[index] = value;

        for(int after = index; after < m_length; ++after){
            if(index == m_size){
                break;
            }
            data[after + 1] = m_data[after];
        }

        delete[] m_data;
        m_data = data;
        m_size++;
    }

    void push_back(T value){
        insertBefore(value, m_size);
    }

    T& pop_back(){
        T data = m_data[m_size - 1];
        m_size--;

        return data;
    }

    void swap(int* a, int* b){
        int temp;
        temp = *a;
        *a = *b;
        *b = temp;
    }

};


#endif //_MYVECTOR_H
