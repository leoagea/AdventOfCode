#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#define WIDTH 101
#define HEIGHT 103

using namespace std;
typedef struct robot
{
    int x = 0;
    int y = 0;
    int dx = 0;
    int dy = 0;
}robot;

void step(vector<robot> &robots){
    string grid(WIDTH * HEIGHT, '.');
    for(auto &[x, y, dx, dy] : robots){
        x = (x + dx + WIDTH) % WIDTH;
        y = (y + dy + HEIGHT) % HEIGHT;
        grid[x + y * WIDTH] = '#';
    }

    for(int i=0; i < HEIGHT; i++)
        cout << grid.substr(WIDTH * i, WIDTH) << endl;
}

int main(){
    ifstream file("../data.txt");
    vector<robot> vec;
    int q1=0, q2=0, q3=0, q4=0;

    while(!file.eof()){
        robot r;
        file.ignore(2, ' ');
        file >> r.x;
        file.ignore(1, sizeof(char));
        file >> r.y;
        file.ignore(3, sizeof(char));
        file >> r.dx;
        file.ignore(1, sizeof(char));
        file >> r.dy;
        file.ignore();
        vec.push_back(r);
    }
    
    for(int i=1; i < 10000; i++){
        cout << i << endl;
        step(vec);
    }
}