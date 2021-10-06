#ifndef _MYITERATOR_H
#define _MYITERATOR_H

template<class T>
class MyIterator {
public:
    MyIterator(T* val = nullptr) : m_data(val){};
    MyIterator(const T* ptr);

    T operator* ();
    MyIterator<T>& operator++();
    MyIterator<T>& operator++(T);
    bool operator!= (MyIterator& iterTwo){
        return m_data != iterTwo.m_data;
    }

private:
    T* m_data;
};


template<typename T>
MyIterator<T>::MyIterator(const T* val) : m_data(val){}

template<typename T>
T MyIterator<T>::operator* (){
    return *m_data;
}

template<typename T>
MyIterator<T>& MyIterator<T>::operator++(){
    ++m_data;
    return *this;
}

template<typename T>
MyIterator<T>& MyIterator<T>::operator++(T){
    MyIterator temp(m_data);
    ++(*this);
    return temp;
}



#endif //_MYITERATOR_H
