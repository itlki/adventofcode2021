#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <numeric>

using namespace std;

int solve_part1(const vector<int> numbers){

    // Count if the current element is greater than the previous element.
    int answer = count_if(numbers.begin() + 1, numbers.end(), [](int const &e){
        return e > (&e)[-1];
    });
    
    return answer;
}

int solve_part2(const vector<int> numbers){

    // Count if the current element is greater than the third previous element.
    int answer = count_if(numbers.begin() + 3, numbers.end(), [](int const &e){
        return e > (&e)[-3];
    });
    
    return answer;
}

int main(){

    fstream file("input.txt");
    string line;
    vector<int> numbers;

    // Read input.
    while(getline(file, line)){
        numbers.push_back(stoi(line));
    }

    int answer_part1 = solve_part1(numbers);
    int answer_part2 = solve_part2(numbers);

    cout << answer_part1 << endl;
    cout << answer_part2 << endl;

    return 0;
}
