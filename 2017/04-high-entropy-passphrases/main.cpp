#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>
#include <fstream>
#include <string>
#include "../../include/advent.h"

// Read input from the input files
std::vector<std::vector<std::string>> read_input(const std::string filename){
    std::fstream input_file;
    std::string line;
    std::vector<std::vector<std::string>> input;

    input_file.open(filename);

    while(!input_file.eof()){
        std::getline(input_file,line);
        std::vector<std::string> row;
        std::string word="";

        for(auto chr:line){
            if(chr==' ' && !word.empty()){
                row.push_back(word);
                word.clear();
            }
            else {
                word+=chr;
            }
        }
        if (!word.empty()) {
            row.push_back(word);
        }

        if (!row.empty()) {
            input.push_back(row);
        }
    }
    return input;

}
// Part-1 code to be executed here
void solve_part1(const std::vector<std::vector<std::string>>& input){
    std::cout << "--------- Part-1 Solution --------- " << std::endl;
    int count=0;
    for(const auto& line:input){
    std::unordered_map<std::string, int> map;
        for(const auto& word:line){
            map[word]++;
        }
        bool flag = true;
        for(auto it:map){
            if(it.second != 1){
                flag=false;
                break;
            }
        }
        count  = flag ? count+1:count;
    }
    std::cout << count;
}

// Part-2 code to be executed here
void solve_part2(const std::vector<std::vector<std::string>>& input){
    std::cout << "--------- Part-2 Solution --------- " << std::endl;
    std::unordered_map<std::string, int> map;
    int count =0;
    for( auto line:input){
        for( auto word:line){
            std::sort(word.begin(),word.end());
            map[word]++;

        }
        bool flag = true;
        for(auto it:map){
            if(it.second != 1){
                flag=false;
            }
        }
        map.clear();
        count  = flag ? count+1:count;

    }
    std::cout << count;
}

int main(int argc, char **argv){
    std::string input_file = "input.txt";

    std::vector<std::vector<std::string>> input_string = read_input(input_file);

    // Solving part-1
    // solve_part1(input_string);

    // Solving part-2
    solve_part2(input_string);
}
