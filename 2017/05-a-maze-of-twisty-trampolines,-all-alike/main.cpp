#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "../../include/advent.h"



// Read input from the input files
std::vector<std::string> read_input(const std::string filename){
    std::ifstream input_file;
    input_file.open(filename);
    std::string line;
    std::vector<std::string> input;
    while(!input_file.eof()){
        std::getline(input_file,line);
        input.push_back(line);
    }
    return input;
}
// Part-1 code to be executed here
void solve_part1(const std::vector<std::string>& input){
    std::cout << "--------- Part-1 Solution --------- " << std::endl;
    std::vector<int> arr = integer_parser(input);
    int i=0,count=0;
    while(i<arr.size()){
        if(arr[i]>=3){
            i+=arr[i]--;
        } else{

            i+=arr[i]++;
        }
        count++;
    }
    std::cout << count;
}

// Part-2 code to be executed here
void solve_part2(const std::vector<std::string>& input){
    std::cout << "--------- Part-2 Solution --------- " << std::endl;
}
int main(int argc, char **argv){
    std::string input_file = "input.txt";

    // Solving part-1
    std::vector<std::string> input_string;
    input_string = read_input(input_file);
    solve_part1(input_string);
}
