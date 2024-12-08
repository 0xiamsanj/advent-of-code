#include<string>
#include<iostream>

int check_digit(std::string line , int pos){
    int num=0;
    while(line[pos]<='9' && line[pos]>='0'){
        num=(line[pos]-'0')+num*10;
        pos++;
    }
    return num;
}

int len_digits(int num){
    int count =0;
    while(num){
        num/=10;
        count++;
    }
    return count;
}

int do_dont_parser(std::string line, int pos){
    std::string do_string = "do()";
    std::string dont_string = "don't()";

    if(do_string == line.substr(pos,4)){
        return 1;
    } else if (dont_string == line.substr(pos,7)){
        return 0;
    }
    return -1;

}
int possible_parse (std::string line, int pos){
    std::string sub_string = "mul(";

    int num_1, num_2,res=0;
    if(sub_string == line.substr(pos,4)){
            num_1= check_digit(line,pos+=4);
        int len = len_digits(num_1);

        if(line.at(pos+=len)==','){
            num_2  = check_digit(line,pos+=1);
        } else{
            return -1;
        }
        int len_2 = len_digits(num_2);

        if(line.at(pos+=len_2)==')'){
            res = num_1 * num_2;
        } else{
            return -1;
        }
    } else{
        return -1;
    }
    return  res;
}
