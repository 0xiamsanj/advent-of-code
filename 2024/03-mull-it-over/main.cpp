#include <iostream>
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
    return input;
}


// Part-1 code to be executed here
void solve_part1(const std::vector<std::string>& input){
    std::cout << "--------- Part-1 Solution --------- " << std::endl;
    long int res =0;
    for(auto row:input){
        for (int i=0;i<row.size();i++){
            if(row[i]=='m'){
                int num = possible_parse(row,i);
                if(num!=-1){
                    res+=num;
                }
            }
        }
    }
    std::cout << "Sum: "<< res << std::endl;
}

// Part-2 code to be executed here
void solve_part2(const std::vector<std::string>& input){
    std::cout << "--------- Part-2 Solution --------- " << std::endl;
    long int res =0;
    int num;
    bool is_do = true;
    for(auto row:input){
        for (int i=0;i<row.size();i++){
            if(row[i]=='m'){
                num = possible_parse(row,i);
                if(num!=-1 && is_do){
                    res+=num;
                }
            }
            if(row[i]=='d'){
                is_do = do_dont_parser(row,i) ? true : false;
            }
        }
    }
    std::cout << "Sum: "<< res;
}

int main(int argc, char **argv){
    std::string test_file = "input/test.txt";
    std::string input_file = "input/input.txt";

    std::vector<std::string> input = read_input(input_file);

    // Solving part-1
    // solve_part1(input);

    // Solving part-1
    solve_part2(input);
}
