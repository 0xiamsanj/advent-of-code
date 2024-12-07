#include <iostream>
#include <ostream>
#include <vector>
#include <fstream>
#include <cmath>
#include <string>
#include "../../include/advent.h"
#include "helper/helper.cpp"

// Read input from the input files
std::vector<std::string> read_input(const std::string filename){
    std::fstream file_stream;
    std::vector<std::string> input;
    std::string line;

    file_stream.open(filename);

    while(!file_stream.eof()){
        std::getline(file_stream,line);
        // std::cout << line << std::endl;
        input.push_back(line);
    }
    input.pop_back();
    return input;
}

// Part-1 code to be executed here
void solve_part1(const std::vector<std::string>& input){
    std::cout << "--------- Part-1 Solution --------- " << std::endl;
    std::vector<std::vector<int>> matrix = matrix_parser(input);
    bool res = false,increase=false;
    int sum = 0;
    for(int i=0;i<matrix.size();i++){
        for(int j=0;j<matrix[i].size()-1;j++){
            increase = matrix[i][0] < matrix[i][1] ? true : false;
            if((matrix[i][j] < matrix[i][j+1] && increase) &&
                    std::abs(matrix[i][j] - matrix[i][j+1])<=3){
                res = true;
            }else if((matrix[i][j] > matrix[i][j+1] && !increase) &&
                    std::abs(matrix[i][j] - matrix[i][j+1])<=3){
                res = true;
            } else{
                res = false;
                break;
            }
        }
        if(res){
            sum++;
        }
    }
    std::cout << "Count: " << sum << std::endl;
}

// Part-2 code to be executed here
void solve_part2(const std::vector<std::string>& input){
    std::cout << "--------- Part-2 Solution --------- " << std::endl;
    std::vector<std::vector<int>> matrix = matrix_parser(input);

    int  safe_rows = 0;
    for(auto row: matrix){
        bool check = checkLevels(row);
        if(check){
            safe_rows++;
        }
        else {
            for(int i=0;i<row.size();i++){
                std::vector<int> altered_row = row;
                altered_row.erase(altered_row.begin()+i);

                if(checkLevels(altered_row)){
                    safe_rows++;
                    break;
                }
            }
        }
    }
    std::cout << "Safe rows: "<< safe_rows << std::endl;
}

int main(int argc, char **argv){
    std::string input_file = "input/input.txt";
    std::string test_file = "input/test.txt";

    std::vector<std::string> input = read_input(input_file);

    // Solving part-1
    solve_part1(input);

    // Solving part-2
    solve_part2(input);
}
