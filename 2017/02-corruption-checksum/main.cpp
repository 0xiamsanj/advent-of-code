#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <climits>
#include "advent.h"

// Read input from the input files
std::vector<std::string> read_input(const std::string filename){
    std::fstream input_file;
    std::string line;
    std::vector<std::string> input;

    input_file.open(filename);

    while(!input_file.eof()){
        std::getline(input_file,line);
        // std::cout<< line;
        input.push_back(line);
    }
    return input;
}

// Part-1 code to be executed here
void solve_part1(const std::vector<std::string>& input){
    std::cout << "--------- Part-1 Solution --------- " << std::endl;
    std::vector<std::vector<int>> matrix = matrix_parser(input);
    int sum_res =0;
    for(const auto& row:matrix){
        int max=INT_MIN, min=INT_MAX;
        for(const auto& num: row){
            // std::cout << num << " ";
            max = std::max(max,num);
            min = std::min(min,num);
        }
        int diff = max - min;
        sum_res += diff;
    }

        std::cout << "Checksum: "<<sum_res-1;
}

// Part-2 code to be executed here
void solve_part2(const std::vector<std::string>& input){
    std::cout << "--------- Part-2 Solution --------- " << std::endl;
    std::vector<std::vector<int>> matrix = matrix_parser(input);
    int sum_res = 0,res;
    for(auto& row:matrix){
        std::sort(row.begin(),row.end());
        for(int i=0;i<row.size();i++){
            for(int j=i+1;j<row.size();j++){
                if(row[j]%row[i]==0){
                    res = row[j]/row[i];
                    break;
                }
            }
        }
        sum_res+=res;
        res=0;
    }
    std::cout << "Sum: " << sum_res;
}
int main(int argc, char **argv){
    std::string input_file = "input.txt";

    // Solving part-1
    std::vector<std::string> input_string = read_input(input_file);
    // solve_part1(input_string);
    solve_part2(input_string);
}
