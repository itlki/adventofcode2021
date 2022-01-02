#include <iostream>
#include <ranges>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <string_view>

using namespace std;

class Board{
private:
	int board[5][5] = {0};
	int winningNum = -1;
	int winningScore = -1;

public:

	// Construct Board from input file stream.
	// Reads 5 lines from stream.
	Board(ifstream *f){

		string line;

		for(int i = 0; i < 5; i++){

			std::getline(*f, line);
			
			stringstream lineStream(line);

			for(int j = 0; j < 5; j++){
				lineStream >> board[i][j];
			}
		}
	}

	// Mark a number on board
	// Returns true if the supplied number wins the game.
	bool mark(int num){
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++){
				if(board[i][j] == num){
					board[i][j] = -1;
				}
			}
		}
		if(winningNum == -1 && won()){
			winningNum = num;
			winningScore = score();
			return true;
		}
		return false;
	}

	// Returns true if the board has won.
	bool won(){
		// If we have already won, return true.
		if(winningNum >= 0)
			return true;

		// Else, calculate.
		bool won = false;

		// Check columns
		for(int i = 0; i < 5; i++){
			won = true;
			for(int j = 0; j < 5; j++){
				if(board[i][j] != -1){
					won = false;
					break;
				}
			}
			if(won)
				return won;
		}

		// Check rows
		for(int i = 0; i < 5; i++){
			won = true;
			for(int j = 0; j < 5; j++){
				if(board[j][i] != -1){
					won = false;
					break;
				}
			}
			if(won)
				return won;
		}
		
		return won;
	}

	// Calculates the score
	int score(){
		if(winningScore > 0)
			return winningScore;

		int score = 0;
		for(int i = 0; i < 5; i++){
			for(int j = 0; j < 5; j++){
				if(board[i][j] != -1){
					score += board[i][j];
				}
			}
		}
		return score * winningNum;
	}

};

pair<int, int> solve(const string numbers, vector<Board> boards){

	int num;
	int score;
	char dummy;

	Board *firstWinner = nullptr;
	Board *lastWinner = nullptr;

	stringstream draw(numbers);

	// For every number
	while(draw){
		draw >> num; // Draw next number
		draw >> dummy; // Skip delimeter ','

		// Mark drawn number on each board and check for winners.
		for(Board &board : boards){
			if(board.mark(num)){

				lastWinner = &board;

				if(!firstWinner)
					firstWinner = &board;
			}
		}   
	}

	return make_pair(firstWinner->score(),
					lastWinner->score());
}

int main(){
	
	ifstream f("input.txt");
	string line;
	string nums;

	vector<string> input;
	vector<Board> boards;

	std::getline(f, nums);
	
	while(std::getline(f, line)){
		boards.push_back(Board(&f));
	}
	f.close();

	pair<int, int> answers = solve(nums, boards);

	cout << answers.first << endl;
	cout << answers.second << endl;

	return 0;
}
