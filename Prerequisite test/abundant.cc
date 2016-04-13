#include <vector>
#include <iostream>
#include <cstdlib>

std::vector<int> getProperDivisors(int n){
    auto properDivisors = std::vector<int>();
    for(auto i = 1u; i < n; ++i)
        if(n%i == 0)
            properDivisors.push_back(i);
    return properDivisors;    
}

bool isAbundant(int n){
    auto properDivisors = getProperDivisors(n);
    auto sum = 0;
    for(auto& x : properDivisors)
        sum += x;
    if(sum > n)
        return true;
    return false;
}

int main(int argc, char* argv[]){
    
    auto abundantNumbers = std::vector<int>();
    
    for(auto i = 1u; ; ++i){
        if(isAbundant(i))
            abundantNumbers.push_back(i);
        
        if(abundantNumbers.size() == atoi(argv[1]))
            break;
    }
    
    for(auto& x : abundantNumbers)
        std::cout << x << std::endl;
    
    return 0;
}