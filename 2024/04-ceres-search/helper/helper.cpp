#include <vector>
#include <string>


bool check(std::string str1, std::string str2){
    if((str1 == "MS"|| str1=="SM") && (str2=="SM" && str2=="MS")){
        return true;
    }
    return false;
}
bool is_safe_N(int pos_row, std::vector<std::string> matrix ){
    if(pos_row>=0){
        return true;
    }
    return false;
}

bool is_safe_S(int pos_row, std::vector<std::string> matrix ){
    if(pos_row<matrix.size()){
        return true;
    }
    return false;
}

bool is_safe_E(int pos_col, std::vector<std::string> matrix ){
    if(pos_col+3<matrix.size()){
        return true;
    }
    return false;
}

bool is_safe_W(int pos_col, std::vector<std::string> matrix ){
    if(pos_col-3>=0){
        return true;
    }
    return false;
}

bool is_safe_diag_NE(int pos_row,int pos_col, std::vector<std::string> matrix){
    if(pos_row >=0 && pos_col<matrix.size()){
        return true;
    }
    return false;
}
bool is_safe_diag_NW(int pos_row,int pos_col, std::vector<std::string> matrix){
    if(pos_col >=0  && pos_row>=0){
        return true;
    }
    return false;
}

bool is_safe_diag_SE(int pos_row,int pos_col, std::vector<std::string> matrix){
    if(pos_row<matrix.size()  && pos_col<matrix.size()){
        return true;
    }
    return false;
}

bool is_safe_diag_SW(int pos_row,int pos_col, std::vector<std::string> matrix){
    if(pos_row<matrix.size()  && pos_col>=0){
        return true;
    }
    return false;
}
bool left_to_right(int pos_row, int pos_col,std::vector<std::string> matrix){
    std::string str = "";
    for(int i=0;i<4;i++){

        if (is_safe_E(pos_col,matrix )){
            str+=matrix[pos_row][pos_col+i];
        }
    }
    if(str == "XMAS"){
        return true;
    }
    return false;
}

bool right_to_left(int pos_row, int pos_col,std::vector<std::string> matrix){
    std::string str = "";
    if (is_safe_W(pos_col,matrix )){
        for(int i=0;i<4;i++){
            str+=matrix[pos_row][pos_col-i];
        }
    }
    if(str == "XMAS"){
        return true;
    }
    return false;
}

bool up_to_down(int pos_row, int pos_col,std::vector<std::string> matrix){
    std::string str="";
    for(size_t i=0;i<4;i++){
        if(is_safe_S(pos_row+i,matrix)){
            str+=matrix[pos_row+i][pos_col];
        }
    }
    return str== "XMAS"?true: false;
}

bool down_to_up(int pos_row, int pos_col,std::vector<std::string> matrix){
    std::string str="";
    for(size_t i=0;i<4;i++){
        if(is_safe_N(pos_row-i,matrix)){
            str+=matrix[pos_row-i][pos_col];
        }else{
            return false;
        }
    }
    return str== "XMAS"?true: false;
}

bool diagonal_right_up(int pos_row, int pos_col, std::vector<std::string> matrix){
    std::string str="";
    for(size_t i=0;i<4;i++){
        if(is_safe_diag_NE(pos_row-i,pos_col+i,matrix)){
            str+=matrix[pos_row-i][pos_col+i];
        }
    }
    return str== "XMAS"?true: false;
}

bool diagonal_left_up(int pos_row, int pos_col, std::vector<std::string> matrix){
    std::string str="";
    for(size_t i=0;i<4;i++){
        if(is_safe_diag_NW(pos_row-i,pos_col-i,matrix)){
            str+=matrix[pos_row-i][pos_col-i];
        }
    }
    return str== "XMAS"?true: false;
}

bool diagonal_right_down(int pos_row, int pos_col, std::vector<std::string> matrix){
    std::string str="";
    for(size_t i=0;i<4;i++){
        if(is_safe_diag_SE(pos_row+i,pos_col+i,matrix)){
            str+=matrix[pos_row+i][pos_col+i];
        }
    }
    return str== "XMAS"?true: false;
}

bool diagonal_left_down(int pos_row, int pos_col, std::vector<std::string> matrix){
    std::string str="";
    for(size_t i=0;i<4;i++){
        if(is_safe_diag_SW(pos_row+i,pos_col-i,matrix)){
            str+=matrix[pos_row+i][pos_col-i];
        }
    }
    return str=="XMAS"?true: false;
}
