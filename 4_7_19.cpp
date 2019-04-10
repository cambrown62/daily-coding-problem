#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/numeric/ublas/matrix.hpp>
using namespace boost::numeric::ublas;

/*
Conway's Game of Life takes place on an infinite two-dimensional board of square cells. Each cell is either dead or alive, and at each tick, the following rules apply:

Any live cell with less than two live neighbours dies.
Any live cell with two or three live neighbours remains living.
Any live cell with more than three live neighbours dies.
Any dead cell with exactly three live neighbours becomes a live cell.
A cell neighbours another cell if it is horizontally, vertically, or diagonally adjacent.

Implement Conway's Game of Life. It should be able to be initialized with a starting list of live cell coordinates and the number of steps it should run for. 
Once initialized, it should print out the board state at each step. Since it's an infinite board, print out only the relevant coordinates, i.e. from the top-leftmost live cell to bottom-rightmost live cell.

You can represent a live cell with an asterisk (*) and a dead cell with a dot (.).
*/

/*
struct Cell{
	int row;
	int col;
	bool alive;
};
*/

class Game_of_Life{

public:
	//matrix<Cell> board;
	matrix<char> board;

	Game_of_Life(std::vector<std::vector<int>> init_coords);

	void play(int time_steps);
	void print_board();

};


bool comp(std::vector<int> a, std::vector<int> b){
	return a[1] < b[1];
}

Game_of_Life::Game_of_Life(std::vector<std::vector<int>> init_coords){
	
	int btm_rgt_row = std::max_element(begin(init_coords), end(init_coords));
	int btm_rgt_col = std::max_element(begin(init_coords), end(init_coords), comp);
	
	board.resize(btm_rgt_row+2, btm_rgt_col+2);

	/*
	for (int i = 0; i < init_coords.size(); i++){
		board(init_coords[i][0], init_coords[i][1]).row = init_coords[i][0];
		board(init_coords[i][0], init_coords[i][1]).col = init_coords[i][1];
		board(init_coords[i][0], init_coords[i][1]).alive = true;
	}

	
	for (int i = 0; i < board.size1(); i++){
		for (int j = 0; j < board.size2(); j++){
			if (board(i,j).alive != true){
				board(i,j).row = i;
				board(i,j).col = j;
			}
		}
	}
	*/

	for (int i = 0; i < init_coords.size(); i++){
		board(init_coords[i][0], init_coords[i][1]) = '*';
	}

	for (int i = 0; i < board.size1(); i++){
		for (int j = 0; j < board.size2(); j++){
			if (i == 0 || i == board.size1()-1){
				board(i,j) == 'e';
			}
			else if (j == 0 || j == board.size2()-1){
				board(i,j) == 'e';
			}
			else if (board(i,j) != '*'){
				board(i,j) = '.';
			}
		}
	}
	

	
}

void Game_of_Life::print_board(){
	for (int i = 0; i < board.size1(); i++){
		for (int j = 0; j < board.size2(); j++){
			if (j == board.size2()-1){
				std::cout << board(i,j) << "\n";
			}
			else{
				std::cout << board(i,j);
			}
		}
	}
}

/*
void Game_of_Life::play(int time_steps){
	for (int t = 0; t < time_steps; t++){
		for (int i = 0; i < board.size1(); i++){
			for (int j = 0; j < board.size2(); j++){
				
			}
		}
	}
}
*/

int main() {

	 

	system("Pause");
	return 0;
}
