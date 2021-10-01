#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
#include "Timer.h"

template<typename T>
void Swap(T* a, T* b){
    T temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

template<typename T>
void QuickSortPointers(std::vector<T*>& vector, const int first, const int last){
    int i = first;
    int j = last;
    int x = *vector[(first + last) / 2];

    do{
        while(*vector[i] < x) ++i;
        while(*vector[j] > x) --j;

        if(i <= j){
            Swap(&vector[i], &vector[j]);
            ++i;
            --j;
        }
    }while(i <= j);

    if(i < last) QuickSortPointers(vector, i, last);
    if(first < j) QuickSortPointers(vector, first, j);
}

template<typename T>
void BubbleSortPointers(std::vector<T*>& vector){
    for(int i = 0; i < vector.size(); ++i){
        for(int j = 0; j < vector.size() - 1; ++j){
            if(*vector[j] > *vector[j + 1]){
                Swap(&vector[j], &vector[j + 1]);
            }
        }
    }
}



template<typename T>
void FillingVector(std::vector<T*> vector){
    for(int i = 0; i < 10; ++i){
        *vector[i] = std::rand() % 10;
    }
}

template<typename T>
void PrintVector(std::vector<T*> vector){
    std::cout << "This is you vector: ";
    for(int i = 0; i < vector.size() ; ++i){
        std::cout << *vector[i] << " ";
    }

    std::cout << std::endl;
}

int main() {
    int aA = 3;
    int bB = 2;
    Swap(&aA, &bB);

    std::cout << "aA = " << aA << " bB = " << bB << std::endl;

    int a = 7, b = 4, c = 15, d = 4, e = 2, f = 5;

    std::vector<int*> numbers;
    numbers.push_back(&a);
    numbers.push_back(&b);
    numbers.push_back(&c);
    numbers.push_back(&d);
    numbers.push_back(&e);
    numbers.push_back(&f);

    PrintVector(numbers);

    //BubbleSortPointers(numbers);
    QuickSortPointers(numbers, 0, numbers.size() - 1);
    PrintVector(numbers);

    std::ifstream file("war_and_peace.txt");
    std::string vowels = "AEIOUYaeiouy";
    std::string text;

    if(file.is_open()){
        while(std::getline(file, text, '\0'));
    }
    file.close();

    Timer timer("Count_if and find");
    int result = std::count_if(text.begin(), text.end(), [&vowels](const char word){
        return vowels.find(word) != std::string::npos;
    });
    timer.Print();
    std::cout << "Count_if and find = " << result << std::endl;

    result = 0;
    timer.Start("Count_if and for");
    result = std::count_if(text.begin(), text.end(), [&vowels](const char word){
        for(int i = 0; i < vowels.size(); ++i){
            if(word == vowels[i]){
                return true;
            }
        }
        return false;
    });
    timer.Print();
    std::cout << "Count_if and for = " << result << std::endl;

    result = 0;
    timer.Start("for and find");
    for(int i = 0; i < text.size() - 1; ++i){
        if(vowels.find(text[i]) != std::string::npos){
            result ++;
        }
    }
    timer.Print();
    std::cout << "for and find = " << result << std::endl;

    result = 0;
    timer.Start("two for");
    for(int i = 0; i < text.size(); ++i){
        for(int j = 0; j < vowels.size(); ++j){
            if(text[i] == vowels[j]){
                result++;
            }
        }
    }
    timer.Print();
    std::cout << "two for = " << result << std::endl;



    return 0;
}
