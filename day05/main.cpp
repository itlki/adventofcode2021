#include <iostream>
#include <ranges>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <string_view>

using namespace std;

constexpr size_t MAP_SIZE = 1000;

int countIntersection(const vector<string> input, bool diagonal = false){
	
	auto map = new int[MAP_SIZE][MAP_SIZE]();

	for(string line : input){

		int x1,y1,x2,y2;
		if(4 != sscanf(line.c_str(), "%d,%d -> %d,%d\n", &x1, &y1, &x2, &y2)){
			// Cannot parse.
			return -1;
		}

        int xinc = x1 == x2 ? 0 : x2 > x1 ? 1 : -1;
        int yinc = y1 == y2 ? 0 : y2 > y1 ? 1 : -1;

		if(!diagonal && x1 != x2 && y1 != y2){
			// Skip diagonal lines if specified.
			continue;
		}

        do{
            map[x1][y1]++;
            x1 += xinc;
            y1 += yinc;
        }while( x1!=x2 || y1!=y2 );
        
		map[x2][y2]++;
	}

    int intersection = 0;
    for(int i = 0; i < MAP_SIZE; i++){
        for(int j = 0; j < MAP_SIZE; j++){
            if(map[i][j] > 1)
                intersection++;
        }
    }

	delete map;

	return intersection;
}

int solve_part1(const vector<string> input){
	return countIntersection(input, false);
}

int solve_part2(const vector<string> input){
	return countIntersection(input, true);
}

int main(){

	ifstream f("input.txt");
	string line;
	string nums;

	vector<string> input;
	
	while(std::getline(f, line)){
		input.push_back(line);
	}
	f.close();

	cout << solve_part1(input) << endl;
	cout << solve_part2(input) << endl;

	return 0;
}
