#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <numeric>

using namespace std;

int solve_part1(const vector<string> input){

    int horizontal = 0, depth = 0;
    
    for_each(input.begin(), input.end(), [&horizontal,&depth](string move){

        int numPos = move.find(" ") + 1;
        int amount = stoi(move.substr(numPos, move.size() - numPos));

        if(move.starts_with("up")){
            depth -= amount;
        }else if(move.starts_with("down")){
            depth += amount;
        }else{
            horizontal += amount;
        }

    });

    return horizontal * depth;
}

int solve_part2(const vector<string> input){

    int horizontal = 0, depth = 0, aim = 0;
    
    for_each(input.begin(), input.end(), [&horizontal,&depth, &aim](string move){

        int numPos = move.find(" ") + 1;
        int amount = stoi(move.substr(numPos, move.size() - numPos));

        if(move.starts_with("up")){
            aim -= amount;
        }else if(move.starts_with("down")){
            aim += amount;
        }else{
            horizontal += amount;
            depth += aim * amount;
        }
        
    });

    return horizontal * depth;
}

int main(){

    fstream file("input.txt");
    string line;
    vector<string> input;

    // Read input.
    while(getline(file, line)){
        input.push_back(line);
    }

    int answer_part1 = solve_part1(input);
    int answer_part2 = solve_part2(input);

    cout << answer_part1 << endl;
    cout << answer_part2 << endl;

    return 0;
}
