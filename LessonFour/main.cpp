#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <cmath>
#include <numeric>

template<typename T>
void InsertSorted(std::vector<T>& vec, T a){
    for(int i = 0; i < vec.size(); ++i){
        if(a < vec[i]){
            vec.insert(vec.begin() + i, a);
            return;
        }
    }
}

template<typename T>
void PrintVectorSorted(std::vector<T>& vec) {
    for(auto& it : vec){
        std::cout << it << " ";
    }
    std::cout << std::endl;
}

void TaskOne() {
    std::vector<char> vec{'b', 's', 'm', 'p', 'z', 'k', 'a', 'f', 'n', 'y'};
    std::sort(vec.begin(), vec.end());

    PrintVectorSorted(vec);
    InsertSorted(vec, 'c');
    PrintVectorSorted(vec);
}

void DigitVsAnalog(std::vector<double>& one, std::vector<int>& two){
    if(one.size() != two.size()){
        std::cout << "These massive are different";
        return;
    }

    double result = 0.0f;
    auto func = [](auto& y, auto& x){
        return pow(x - y, 2);
    };
    std::transform(two.begin(), two.end(), one.begin(), one.begin(), func);
    result = std::accumulate(one.begin(), one.end(), 0.0f);

    std::cout << "Your result of DigitVSAnalog is " << result << std::endl;
}

void TaskTwo(){
    std::vector<double> vecOne(10);
    std::generate(vecOne.begin(), vecOne.end(), [](){
        return 10.0f * rand() / RAND_MAX;
    });

    std::vector<int> vecTwo(vecOne.size());
    std::transform(vecOne.begin(), vecOne.end(), vecTwo.begin(), [](double i){
        return static_cast<int>(i);
    });

    std::copy(vecOne.begin(), vecOne.end(), std::ostream_iterator<double> {std::cout, " "});
    std::cout << std::endl;
    std::copy(vecTwo.begin(), vecTwo.end(), std::ostream_iterator<int> {std::cout, " "});
    std::cout << std::endl;

    DigitVsAnalog(vecOne, vecTwo);
}

int main() {
    TaskOne();
    TaskTwo();

    return 0;
}