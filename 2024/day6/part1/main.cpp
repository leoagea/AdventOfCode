#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

enum facing
{
	UP,
	DOWN,
	RIGHT,
	LEFT
};

typedef struct player{
	int x = -1;
	int y = -1;
	int facing = UP;
	int sum = 0;
} player;

void getPlayerPos(vector<string> &vec, player &p){
	int y=0;
	for(auto l : vec){
		int x=0;
		for(auto c : l){
			if(c == '^'){
				p.x = x;
				p.y = y;
				return;
			}
			x++;
		}
		y++;
	}

}

bool isFinished(vector<string> &vec, player &p){
	if(p.facing == UP && !vec[p.y - 1][p.x])
		return true;
	else if(p.facing == DOWN && !vec[p.y + 1][p.x])
		return true;
	else if(p.facing == RIGHT && !vec[p.y][p.x + 1])
		return true;
	else if(p.facing == LEFT && !vec[p.y][p.x - 1])
		return true;
	return false;
}

void playerMooving(vector<string> &vec, player &p){
	vec[p.y][p.x] = 'X';
	if(p.facing == UP){
		if(vec[p.y - 1][p.x] == '#')
			p.facing = RIGHT;
		else
			p.y -= 1;
	}
	else if(p.facing == DOWN){
		if(vec[p.y + 1][p.x] == '#')
			p.facing = LEFT;
		else
			p.y += 1;
	}
	else if(p.facing == RIGHT){
		if(vec[p.y][p.x + 1] == '#')
			p.facing = DOWN;
		else
			p.x += 1;
	}
	else if(p.facing == LEFT){
		if(vec[p.y][p.x - 1] == '#')
			p.facing = UP;
		else
			p.x -= 1;
	}
}

int main()
{
	fstream file("../data.txt");
	string line;
	vector<string> vec;
	player p;

	while(getline(file, line)){
		vec.push_back(line);
	}

	getPlayerPos(vec, p);

	cout << "player x: " << p.x << endl;
	cout << "player y: " << p.y << endl;
	
	while(1){
		if(isFinished(vec, p)){
			p.sum++;
			break;
		}
		playerMooving(vec, p);

	}

	for(auto l : vec){
		for(auto c : l){
			if(c == 'X')
				p.sum++;
			cout << c;
		}
		cout << endl;
	}
	// cout << "bool isFinished: " << isFinished(vec, p) << endl;
	cout << "sum: " << p.sum << endl;
}