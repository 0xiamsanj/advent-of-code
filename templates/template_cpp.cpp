#include <cstdlib>
#include <iostream>
#include <vector>
#include <fstream>
#include <string>


// Read input from the input files
std::vector<std::string> read_input(const std::string filename){
    std::fstream file_stream;
    std::vector<std::string> input;
    std::string line;
    try {

    } catch (std::fstream::failure& e) {
        std::cout << e.what()<< "Error in opening and processing file" ;
        exit;
    }

    return input;
}

// Part-1 code to be executed here
void solve_part1(const std::vector<std::string>& input){
    std::cout << "--------- Part-1 Solution --------- " << std::endl;
}

// Part-2 code to be executed here
void solve_part2(const std::vector<std::string>& input){
    std::cout << "--------- Part-2 Solution --------- " << std::endl;
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
