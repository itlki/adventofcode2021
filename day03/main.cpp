#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <numeric>
#include <list>


using namespace std;

int findEpsilon(const vector<string> report){
    int epsilon = 0;
    int size = report.size();
    int digits = report.at(0).size();

    for(int i = 0; i < digits; i++){
        int amount = count_if(report.begin(), report.end(), [i](const string line){
            return line.at(i) == '1';
        });

        epsilon <<= 1;
        if(amount < (size+1) / 2){
            epsilon |= 1;
        }
    }

    return epsilon;
}

int findGamma(const vector<string> report){
    int gamma = 0;
    int size = report.size();
    int digits = report.at(0).size();

    for(int i = 0; i < digits; i++){
        int amount = count_if(report.begin(), report.end(), [i](const string line){
            return line.at(i) == '1';
        });

        gamma <<= 1;
        if(amount >= (size+1) / 2){
            gamma |= 1;
        }
    }

    return gamma;
}

int solve_part1(const vector<string> input){
    return findGamma(input) * findEpsilon(input);
}

int solve_part2(const vector<string> input){
    int oxygenRating = 0;
    int co2Rating = 0;
    int size = input.at(0).size();

    vector<string> report = input;

    while(oxygenRating == 0){

        for(int i = 0; i < size; i++){
            int gamma = findGamma(report);
            int bitVal =  (gamma >> (size - 1 - i)) & 0x01;

            erase_if(report, [i, bitVal](const string line){
                return line.at(i) != ('0' + bitVal);
            });

            if(report.size() == 1){
                oxygenRating = stoi(report.at(0), 0, 2);
                break;
            }
        }
    }
    
    report = input;
    while(co2Rating == 0){

        for(int i = 0; i < size; i++){
            int epsilon = findEpsilon(report);
            int bitVal =  (epsilon >> (size - 1 - i)) & 0x01;

            erase_if(report, [i, bitVal](const string line){
                return line.at(i) != ('0' + bitVal);
            });

            if(report.size() == 1){
                co2Rating = stoi(report.at(0), 0, 2);
                break;
            }
        }
    }

    return oxygenRating * co2Rating;
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
