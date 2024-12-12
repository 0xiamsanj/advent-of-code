#include <vector>
#include <string>

bool is_safe_hor(int pos, std::vector<std::string> matrix ){
    if(pos+4<matrix[pos].size() || pos-4>=0){
        return true;
    }
    return false;
}

bool is_safe_ver(int pos, std::vector<std::string> matrix ){
    if(pos<matrix.size() ){
        return true;
    }
    return false;
}

bool is_safe_vert(int pos, std::vector<std::string> matrix ){
    if(pos>=0){
        return true;
    }
    return false;
}

bool is_safe_diag_NE(int pos_x,int pos_y, std::vector<std::string> matrix){
    if((pos_x+1 < matrix.size() && pos_y+1 < matrix[pos_x].size())){

        return true;
    }
    return false;
}
bool is_safe_diag_NW(int pos_x,int pos_y, std::vector<std::string> matrix){
    if((pos_x-1 >=0  && pos_y+1<matrix[pos_x].size())){

        return true;
    }
    return false;
}

bool is_safe_diag_SE(int pos_x,int pos_y, std::vector<std::string> matrix){
    if((pos_x >=0  && pos_y<matrix[pos_x].size())){
        return true;
    }
    return false;
}

bool is_safe_diag_SW(int pos_x,int pos_y, std::vector<std::string> matrix){
    if((pos_x-1 >=0  && pos_y-1>=0)){

        return true;
    }
    return false;
}
bool left_to_right(int pos_x, int pos_y,std::vector<std::string> matrix){
    std::string sub_str = "XMAS";
    if (is_safe_hor(pos_y,matrix )){
        if(sub_str == matrix[pos_x].substr(pos_y, pos_y+3)){
            return true;
        }
    }
    return false;
}

bool right_to_left(int pos_x, int pos_y,std::vector<std::string> matrix){
    std::string sub_str = "SAMX";
    if (is_safe_hor(pos_y,matrix )){
        if(sub_str == matrix[pos_x].substr(pos_y, pos_y-4)){
            return true;
        }
    }
    return false;
}

bool up_to_down(int pos_x, int pos_y,std::vector<std::string> matrix){
    std::string str="";

    for(size_t i=0;i<4;i++){
        if(is_safe_ver(pos_x+i,matrix)){
            str+=matrix[pos_x+i][pos_y];
        }
    }
    return str== "XMAS"?true: false;
}

bool down_to_up(int pos_x, int pos_y,std::vector<std::string> matrix){
    std::string str="";
    for(size_t i=0;i<4;i++){
        if(is_safe_vert(pos_x-i,matrix)){
            str+=matrix[pos_x-i][pos_y];
        }
    }
    return str== "XMAS"?true: false;
}

bool diagonal_right_up(int pos_x, int pos_y, std::vector<std::string> matrix){
    std::string str="";
    for(size_t i=0;i<4;i++){
        if(is_safe_diag_NE(pos_x+i,pos_y+i,matrix)){
            str+=matrix[pos_x+i][pos_y+i];
        }
    }
    return str== "XMAS"?true: false;
}

bool diagonal_left_up(int pos_x, int pos_y, std::vector<std::string> matrix){
    std::string str="";
    for(size_t i=0;i<4;i++){
        if(is_safe_diag_NW(pos_x-i,pos_y+i,matrix)){
            str+=matrix[pos_x-i][pos_y+i];
        }
    }
    return str== "XMAS"?true: false;
}

bool diagonal_right_down(int pos_x, int pos_y, std::vector<std::string> matrix){
    std::string str="";
    for(size_t i=0;i<4;i++){
        if(is_safe_diag_SE(pos_x+i,pos_y-i,matrix)){
            str+=matrix[pos_x+i][pos_y-i];
        }
    }
    return str== "XMAS"?true: false;
}

bool diagonal_left_down(int pos_x, int pos_y, std::vector<std::string> matrix){
    std::string str="";
    for(size_t i=0;i<4;i++){
        if(is_safe_diag_SW(pos_x-i,pos_y-i,matrix)){
            str+=matrix[pos_x-i][pos_y-i];
        }
    }
    return str== "XMAS"?true: false;
}
