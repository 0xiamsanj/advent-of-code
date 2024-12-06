#include <sstream>
#include <string>
#include <vector>

int num_parser(std::string input){
    int num;
    std::istringstream stream(input);
    while(stream >> num);
    return num;
}
std::vector<int> integer_parser(std::string input){
    std::vector<int> int_arr;

    std::istringstream stream(input);
    for(const auto& str:input){
        int number;
        while(stream >> number){
            int_arr.push_back(number);
        }
    }
    return int_arr;
}

std::vector<int> integer_parser(std::vector<std::string> input){
    std::vector<int> int_arr;

    for(const auto str_num: input){

        std::istringstream stream(str_num);
        for(const auto& str:str_num){
            int number;
            while(stream >> number){
                int_arr.push_back(number);
            }
        }
    }
    return int_arr;
}
std::vector<std::vector<int>> matrix_parser(std::vector<std::string> input_matrix ){

    std::vector<std::vector<int>> int_matrix;
    for(const auto& string_row:input_matrix){

        std::istringstream stream(string_row);
        std::vector<int> int_row;
        int number;

        // Parsing the string to number
        while(stream >> number){
            int_row.push_back(number);
        }
        int_matrix.push_back(int_row);
    }
    return int_matrix;
}
