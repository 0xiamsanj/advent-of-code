#include <iostream>
#include <vector>
#include <fstream>
#include <string>

// Read input from the input files
std::string read_input(const std::string filename){

    std::ifstream input_file;
    input_file.open(filename);
    std::string input;
    std::getline(input_file,input);
    input_file.close();
    return input;
}

// Part-1 code to be executed here
void solve_part1(const std::string input){
    std::cout << "--------- Part-1 Solution --------- " << std::endl;
    int i=0,sum=0;
    do{
        int next_pos = (i+1)%input.size();
        if(input[i] == input[next_pos]) {
            sum+=(input[i]-'0');
        }
        i++;
        i=i%input.size();
    }while(i!=0);
    std::cout << "Sum: " << sum ;
}

// Part-2 code to be executed here
void solve_part2(const std::string input){
    std::cout << "--------- Part-2 Solution --------- " << std::endl;
    int i=0, sum=0;
    int jump_pos = input.size()/2;
    while(i<input.size()){
        int next_pos = (i+jump_pos)%input.size();
        if(input[i] == input[next_pos]){
            sum+=(input[i]-'0');
        }
        i++;
    }
    std::cout << "Sum: " << sum ;
}
int main(int argc, char **argv){
    std::string input_filename = "input.txt";
    std::string input_string = read_input(input_filename);

    // Solving part-1
    solve_part1(input_string);

    // Solving part-2
    solve_part2(input_string);
}
