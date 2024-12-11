#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int main()
{
	char nb;
	int id = 0;
	string line;
	vector<int> vec;
	vector<int> compact;
	unsigned long long checkSum = 0;
	ifstream file("../data.txt");

	getline(file, line);

	for(int i=0; i < line.size(); i++){
		nb = line[i] - '0';
		for(int j=0; j < nb; j++){
			if(i % 2)
				vec.push_back(-1);
			else{
				vec.push_back(id);
				if(j == nb - 1)
					id++;
			}
		}
	}

    int maxID = -1;
    for (auto v : vec) {
        if (v >= 0 && v > maxID) 
			maxID = v;
    }

    for (int currentID = maxID; currentID >= 0; currentID--) {
        int start = -1;
        int length = 0;
            
		for (int i = 0; i < (int)vec.size(); i++) {
            if (vec[i] == currentID) {
                start = i;
                break;
            }
        }
        
        if (start == -1)
            continue;
        
        int idx = start;
        while (idx < (int)vec.size() && vec[idx] == currentID) {
            length++;
            idx++;
        }
        
        int bestStart = -1;
        int runStart = -1;
        int runLength = 0;
        for (int i = 0; i < (int)vec.size(); i++) {
            if (vec[i] == -1) {
                if (runStart == -1) {
                    runStart = i;
                    runLength = 1;
                } else {
                    runLength++;
                }
            } else {
                if (runLength >= length) {
                    bestStart = runStart;
                    break;
                }
                runStart = -1;
                runLength = 0;
            }

            if (bestStart == -1 && runStart != -1 && runLength >= length)
                bestStart = runStart;
        }

        if (bestStart != -1 && bestStart < start) {
            for (int i = 0; i < length; i++) {
                vec[bestStart + i] = currentID;
            }
            for (int i = start; i < start + length; i++) {
                vec[i] = -1;
            }
        }
    }

	for(int i=0; i < vec.size(); i++)
		if(vec[i] != -1)
			checkSum += vec[i] * i;

	cout << checkSum << endl; 

    return 0;
}