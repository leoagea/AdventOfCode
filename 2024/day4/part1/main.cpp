#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main(){
    fstream file("../data.txt");
    vector<string> vec;
    string line;

    while(getline(file, line)){
        vec.push_back(line);
    }

    vector<string> tmp = vec;
    int res = 0;
    for(int i=0; i < vec.size(); i++){
        for(int j=0; j < vec[i].size(); j++){
            if(vec[i][j] && vec[i][j] == 'X'){
                if((vec[i][j-1] && vec[i][j-2] && vec[i][j-3]) && (vec[i][j-1] == 'M' && vec[i][j-2] == 'A' && vec[i][j-3] == 'S')) //left
                    res++; 
                if((vec[i][j+1] && vec[i][j+2] && vec[i][j+3]) && (vec[i][j+1] == 'M' && vec[i][j+2] == 'A' && vec[i][j+3] == 'S')) //right
                    res++; 
                if(i + 3 < vec.size() && (vec[i+1][j] && vec[i+2][j] && vec[i+3][j]) && (vec[i+1][j] == 'M' && vec[i+2][j] == 'A' && vec[i+3][j] == 'S')) //up
                    res++; 
                if(i - 3 >= 0 &&(vec[i-1][j] && vec[i-2][j] && vec[i-3][j]) && (vec[i-1][j] == 'M' && vec[i-2][j] == 'A' && vec[i-3][j] == 'S')) //down
                    res++; 
                if((i - 3 >= 0 && j - 3 >= 0) &&(vec[i-1][j-1] && vec[i-2][j-2] && vec[i-3][j-3]) && (vec[i-1][j-1] == 'M' && vec[i-2][j-2] == 'A' && vec[i-3][j-3] == 'S')) //diag up left
                    res++; 
                if((i - 3 >= 0 && j + 3 < vec[i].size()) &&(vec[i-1][j+1] && vec[i-2][j+2] && vec[i-3][j+3]) && (vec[i-1][j+1] == 'M' && vec[i-2][j+2] == 'A' && vec[i-3][j+3] == 'S')) //diag down right
                    res++; 
                if((i + 3 < vec.size() && j + 3 < vec[i].size()) &&(vec[i+1][j+1] && vec[i+2][j+2] && vec[i+3][j+3]) && (vec[i+1][j+1] == 'M' && vec[i+2][j+2] == 'A' && vec[i+3][j+3] == 'S')) //diag down right
                    res++; 
                if((i + 3 < vec.size() && j - 3 >= 0) &&(vec[i+1][j-1] && vec[i+2][j-2] && vec[i+3][j-3]) && (vec[i+1][j-1] == 'M' && vec[i+2][j-2] == 'A' && vec[i+3][j-3] == 'S')) //diag down left
                    res++; 
            }
        }
    }

    cout << res << endl;
}