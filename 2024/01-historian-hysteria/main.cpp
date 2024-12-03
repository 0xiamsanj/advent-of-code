#include <cmath>
#include <cstddef>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>
#include <algorithm>
#include <map>
#include "../../include/advent.h"

// Read input from the input files
std::vector<std::string> read_input(const std::string filename){
    std::fstream file_stream;
    std::vector<std::string> input;
    std::string line;

    file_stream.open(filename);
    while(!file_stream.eof()){
        std::getline(file_stream,line);
        input.push_back(line);
    }
    file_stream.close();
    return input;
}

// Split function
std::vector<std::string> tokenize (std::string numbers){
    std::vector<std::string> nums_pair;
    std::stringstream ss(numbers);
    std::string number;
    while(ss >> number){
        nums_pair.push_back(number);
    }
    // std::cout << nums_pair.size() << " ";
    return nums_pair;
}
void split_input(std::vector<std::string> input, std::vector<int>& vec_1, std::vector<int>& vec_2){
    for(auto itr: input){
        std::vector<std::string> temp = tokenize(itr);
        vec_1.push_back(num_parser(temp[0]));
        vec_2.push_back(num_parser(temp[1]));
    }
}

// Part-1 code to be executed here
void solve_part1(std::vector<int> vec_1, std::vector<int> vec_2){
    std::cout << "--------- Part-1 Solution --------- " << std::endl;
    std::sort(vec_1.begin(),vec_1.end());
    std::sort(vec_2.begin(),vec_2.end());

    int sum=0;
    for(int i=0;i<vec_1.size();i++){
        sum+=std::abs(vec_1[i]-vec_2[i]);
    }
    std::cout<<"Sum: " << sum;
}

// Part-2 code to be executed here
void solve_part2(std::vector<int> vec_1, std::vector<int> vec_2){
    std::cout << "\n--------- Part-2 Solution --------- " << std::endl;
    std::map<int,int> hash_map;
    std::size_t sum =0;
    for(auto itr: vec_2){
        hash_map[itr]++;
    }
    for(auto itr: vec_1){
        sum+= (itr*hash_map[itr]);
    }
    std:: cout << "Sum: "<< sum;

}
int main(int argc, char **argv){
    std::string input_file = "input.txt";

    std::vector<std::string> input = read_input(input_file);
    input.pop_back();
    std::vector<int> vec_1 = {0},vec_2={0};
    split_input(input,vec_1,vec_2);

    // Solving part-1
    solve_part1(vec_1,vec_2);

    // Solving part-2
    solve_part2(vec_1,vec_2);
}
