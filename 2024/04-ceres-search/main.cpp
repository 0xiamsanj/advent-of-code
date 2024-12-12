#include <iostream>
#include <ostream>
#include <vector>
#include <fstream>
#include <string>
#include "helper/helper.cpp"

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

// Part-1 code to be executed here
void solve_part1(const std::vector<std::string>& input){
    std::cout << "--------- Part-1 Solution --------- " << std::endl;
    int count =0;
    for(int i=0;i<input.size();i++){
        for(int j=0;j<input.size();j++){

            if(input[i][j] == 'X'){

                //Left to right
                if(left_to_right(i,j,input)){
                    count++;
                }

                // Right to left
                if(right_to_left(i,j,input)){
                    count++;
                }

                // Up to down
                if(up_to_down(i,j,input)){
                    count++;
                }
                // Down to up
                if(down_to_up(i,j,input)){
                    count++;
                }

                if(diagonal_right_up(i,j,input)){
                    count++;
                }
                if(diagonal_right_down(i,j,input)){
                    count++;
                }
                if(diagonal_left_up(i,j,input)){
                    count++;
                }
            }
        }
    }
    std::cout << "Count: "<<count;
}

// Part-2 code to be executed here
void solve_part2(const std::vector<std::string>& input){
    std::cout << "--------- Part-2 Solution --------- " << std::endl;
}
int main(int argc, char **argv){
    const std::string input_file = "input/input.txt";
    const std::string test_file = "input/test.txt";

    std::vector<std::string> input = read_input(test_file);
    // Solving part-1
    input.pop_back();
    solve_part1(input);
}
