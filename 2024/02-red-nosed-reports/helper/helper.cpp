#include <vector>
#include <cmath>

bool is_decreasing(std::vector<int>row){
    for(int i=0;i<row.size();i++){
        if(row[i] < row[i+1]){
            return false;
        }
    }
    return true;
}

bool is_increasing(std::vector<int>row){
    for(int i=0;i<row.size();i++){
        if(row[i] > row[i+1]){
            return false;
        }
    }
    return true;
}

bool checkLevels(const std::vector<int> & levels){
    bool increasing = (levels[0] - levels[1]) > 0; // if false then it is decreasing

    for (int i = 0; i < levels.size()-1; i++){
        int difference = levels[i] - levels[i+1];

        if (increasing && (difference < 0)){
            return false;
        }
        if (!increasing && (difference > 0)){
            return false;
        }

        if (std::abs(difference) > 3 || std::abs(difference) < 1)
        {
            return false;
        }
    }

    return true;
}
