#include <iostream>
#include <mutex>
#include <iterator>
#include <thread>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

std::mutex mOne, mTwo;

void Pcout(std::string any){
    std::scoped_lock sL{mOne};
    std::cout << any << std::endl;
}

void TaskOne(){
    std::cin.unsetf(std::ios::skipws);
    std::string input{std::istream_iterator<char>{std::cin}, {}};
    input.pop_back();
    std::vector<std::thread> vec;
    for(size_t i = 0; i< 10; ++i){
        vec.push_back(std::thread{Pcout, input});
    }
    for(auto& a : vec){
        a.join();
    }
}

bool CheckPrimeNumber(const int& prime){
    std::scoped_lock sL{mTwo};
    for(int i = 2; i < prime; ++i) {
        if (prime % i == 0) {
            return false;
        }
    }


    std::cout << prime << " ";
    return true;
}

int PrimeNumber(const int& index){
    std::scoped_lock sL{mOne};
    if(index == 1){
        return 1;
    }
    else if(index == 2){
        return 2;
    }

    int prime = 2;
    int count = 2;
    bool isCount = false;

    std::cout << "1 2 ";
    while(count != index){
        ++prime;
        std::thread th([&]() {isCount = CheckPrimeNumber(prime);});
        th.join();

        if(isCount){
            count++;
        }
    }

    std::cout << std::endl;
    return prime;
}

void TaskTwo(){
    int number = 0;
    int index = 0;
    std::cin >> index;

    std::thread th([&]() { number = PrimeNumber(index);});
    th.join();
    std::cout << number << std::endl;
}

std::mt19937 gen;
std::uniform_int_distribution<int> dis(100, 1000);

void MasterGet(int& worth, int& get, std::vector<int>& vec){
    std::scoped_lock sLOne{mOne};
    for(int i = 0; i < get; ++i){
        worth = dis(gen);
        vec.push_back(worth);
        std::cout << "master get is " << worth << std::endl;
    }
}

void ThiefGive(int& steal, std::vector<int>& vec,std::vector<int>& steals){
    std::scoped_lock sLTwo{mOne};
    for(int i = 0; i < steal; ++i){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::sort(vec.begin(), vec.end());
        std::cout << "Thief steals is " << *(vec.end() - 1) << std::endl;
        steals.push_back(*(vec.end() - 1));
        vec.pop_back();
    }
}

void PrintTwoVec(std::vector<int>& vec, std::vector<int>& steals){
    std::cout << "somethings: " << std::endl;
    for(auto& a : vec){
        std::cout << a << " ";
    }
    std::cout << "\nsteals: " << std::endl;
    for(auto& a : steals){
        std::cout << a << " ";
    }
    std::cout << std::endl;
}

void TaskThree(){
    std::vector<int> somethings;
    std::vector<int> stealsWorth;
    int worth = 0;
    int get = 10;
    int steal = 5;
    std::thread thOne(MasterGet, std::ref(worth), std::ref(get), std::ref(somethings));
    std::thread thTwo(ThiefGive, std::ref(steal), std::ref(somethings), std::ref(stealsWorth));
    thOne.join();
    thTwo.join();

    std::thread th(PrintTwoVec, std::ref(somethings), std::ref(stealsWorth));
    th.join();
}

int main() {
    //TaskOne();
    //TaskTwo();
    TaskThree();
    return 0;
}
