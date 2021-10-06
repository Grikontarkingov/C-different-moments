#include <iostream>
#include <list>
#include "Matrix.h"
#include "MyVector.h"

void PushBackArithmeticMean(std::list<double>& list){
    double temp = 0.0f;
    for(auto& num : list){
        temp += num;
    }

    temp /= list.size();
    list.push_back(temp);
}

void PrintList(std::list<double>& list){
    std::cout << "Your list is:" << std::endl;
    for(auto& num : list){
        std:: cout << num << " ";
    }
    std::cout << std::endl;
}

void TaskOne(){
    std::list<double> list;
    list.push_back(3.56f);
    list.push_back(4.5f);
    list.push_back(1.07f);
    list.push_front(7.4f);
    list.push_front(5.0f);
    list.push_front(2.57f);
    list.insert(std::next(list.begin(), 3), 9.35);
    list.insert(std::next(list.begin(), 5), 2.46);
    list.insert(std::next(list.begin(), 2), 4.13);

    PrintList(list);
    PushBackArithmeticMean(list);
    PrintList(list);
}

void TaskTwo(){
    int dimension = 4;
    Matrix matrix(dimension, dimension);
    matrix.PrintMatrix();
    matrix.GetDeterminant();
}

void TaskThree(){
    MyVector<int> vec;
    vec.push_back(7);
    vec.push_back(16);
    vec.push_back(5);
    vec.push_back(43);
    vec.push_back(1);
    vec.push_back(22);
    vec.push_back(31);

    for(const auto& val : vec){
        std::cout << val << " ";
    }

    std::cout << std::endl;

}

int main() {
    //TaskOne();
    TaskTwo();
    //TaskThree();


    return 0;
}
