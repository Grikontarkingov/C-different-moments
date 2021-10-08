#include <iostream>
#include <set>
#include <unordered_set>
#include <map>
#include <sstream>

template<typename T>
void Uniqueness(T begin, T end){
    for(; begin != end; ++begin){
        std::cout << *begin << " ";
    }
    std::cout << std::endl;
}

int main() {
    std::set<std::string> mySet;
    mySet.insert("word");
    mySet.insert("moon");
    mySet.insert("last");
    mySet.insert("year");
    mySet.insert("before");
    mySet.insert("last");
    mySet.insert("forward");
    mySet.insert("check");
    mySet.insert("yeear");
    Uniqueness(mySet.begin(), mySet.end());

    std::unordered_set<int> mySetTwo{2, 5, 8, 3, 15, 4, 6, 3, 1, 5, 2, 7};
    Uniqueness(mySetTwo.begin(), mySetTwo.end());

    std::string text;
    std::string delimeters = ".!?";
    std::map<int, std::string> sentences;
    std::getline(std::cin, text);
    std::string substring;
    for(auto i = text.begin(); i != text.end(); ++i){
        if(delimeters.find(*i) != std::string::npos){
            substring.push_back(*i);
            sentences.insert(std::make_pair(substring.size(), substring));
            substring.clear();
        }
        else if(substring.empty() && *i == ' '){
            continue;
        }
        else{
            substring.push_back(*i);
        }
    }

    for(auto& a : sentences){
        std::cout << a.second << std::endl;
    }


    return 0;
}
