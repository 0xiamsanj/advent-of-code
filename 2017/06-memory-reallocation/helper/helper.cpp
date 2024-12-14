#include <vector>
#include <string>
#include <sstream>
#include <iostream>

std::string stringify(std::vector<int> arr){
    std::stringstream ss;
    for(auto num:arr){
        ss << num;
    }
    return ss.str();
}
