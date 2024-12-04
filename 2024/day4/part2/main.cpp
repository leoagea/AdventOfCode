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
            if(vec[i][j] && vec[i][j] == 'A'){
                if (j - 1 >= 0 && j + 1 < vec[i].size() && i - 1 >= 0 && i + 1 < vec.size()){
                    if (vec[i-1][j-1] == 'M' && vec[i-1][j+1] == 'M' && vec[i+1][j-1] == 'S' && vec[i+1][j+1] == 'S')
                        res++;
                    if (vec[i-1][j-1] == 'S' && vec[i-1][j+1] == 'S' && vec[i+1][j-1] == 'M' && vec[i+1][j+1] == 'M')
                        res++; 
                    if (vec[i-1][j-1] == 'S' && vec[i-1][j+1] == 'M' && vec[i+1][j-1] == 'S' && vec[i+1][j+1] == 'M')
                        res++;
                    if (vec[i-1][j-1] == 'M' && vec[i-1][j+1] == 'S' && vec[i+1][j-1] == 'M' && vec[i+1][j+1] == 'S')
                        res++;
                }
            }
        }
    }

    cout << res << endl;
}