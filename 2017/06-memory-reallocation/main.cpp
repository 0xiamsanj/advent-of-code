#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <cstring>
#include <climits>
#include <algorithm>
#include "../../include/advent.h"
#include "helper/helper.cpp"

// Read input from the input files
std::vector<std::string> read_input(const std::string filename){
    std::fstream file_stream;
    std::vector<std::string> input;
    std::string line;
    try {
        file_stream.open(filename);
        while(!file_stream.eof()){
            std::getline(file_stream,line);
            input.push_back(line);
        }
        file_stream.close();
    } catch (std::fstream::failure& e) {
        std::cout << e.what()<< "Error in opening and processing file" ;
        exit;
    }
    return input;
}

// Part-1 code to be executed here
void solve_part1(const std::vector<std::string>& input){
    std::cout << "--------- Part-1 Solution --------- " << std::endl;
    std::vector<int> int_arr = integer_parser(input);
    std::vector<std::string> my_map;
    int size = int_arr.size();
    int count =0;
    int idx;
    bool flag = true;
    while(flag){
        int max_number = *std::max_element(int_arr.begin(),int_arr.end());
        int index = (std::find(int_arr.begin(),int_arr.end(),max_number)-int_arr.begin());
        int blocks = int_arr[index];

        int_arr[index++] = 0;
        while(blocks > 0){
            if(index>=int_arr.size()){
                index =0;
            }
            int_arr[index++]++;
            blocks--;
        }
        std::string str = stringify(int_arr);
        if(std::find(my_map.begin(),my_map.end(),str)== my_map.end()){
            my_map.push_back(str);
        } else{
            flag = false;
        }
        count++;
    }
    std::cout << "Count: " << count;
}

// Part-2 code to be executed here
void solve_part2(const std::vector<std::string>& input){
    std::cout << "--------- Part-2 Solution --------- " << std::endl;
    std::vector<int> int_arr = integer_parser(input);
    std::vector<std::string> my_map;
    int size = int_arr.size();
    int count =0;
    int idx;
    bool flag = true;
    while(flag){
        int max_number = *std::max_element(int_arr.begin(),int_arr.end());
        int index = (std::find(int_arr.begin(),int_arr.end(),max_number)-int_arr.begin());
        int blocks = int_arr[index];

        int_arr[index++] = 0;
        while(blocks > 0){
            if(index>=int_arr.size()){
                index =0;
            }
            int_arr[index++]++;
            blocks--;
        }
        std::string str = stringify(int_arr);
        if(std::find(my_map.begin(),my_map.end(),str)== my_map.end()){
            my_map.push_back(str);
        } else{
            for(int i=0;i<my_map.size();i++){
                if(my_map[i] == str){
                    idx = i;
                    break;
                }
            }
            flag = false;
        }
        count++;
    }
    std::cout << "Cycle Count: " << count-idx-1;
}
int main(int argc, char **argv){
    std::string input_file = "input/input.txt";
    std::string test_file = "input/test.txt";

    std::vector<std::string> input = read_input(input_file);

    if(!strcmp(argv[1],"part1")){

        // Solving part-1
        solve_part1(input);

    } else if(!strcmp(argv[1],"part2")){

        // Solving part-2
        solve_part2(input);
    }
}
