#include <iostream>
#include <vector>
#include <algorithm>
#include <boost/numeric/ublas/matrix.hpp>
#include <boost/numeric/ublas/io.hpp>
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

class Game_of_Life {

public:
	matrix<char> board;
	matrix<char> next_board;

	Game_of_Life(std::vector<std::vector<int>> init_coords);

	void play(int time_steps);
	void print_board();
	int check_neighbors(int i, int j);
};


bool comp(std::vector<int> a, std::vector<int> b) {
	return a[1] < b[1];
}

Game_of_Life::Game_of_Life(std::vector<std::vector<int>> init_coords) {

	auto btm_rgt_row_it = std::max_element(init_coords.begin(), init_coords.end() );
	auto btm_rgt_col_it = std::max_element(init_coords.begin(), init_coords.end(), comp);

	int btm_rgt_row = (*btm_rgt_row_it)[0];
	int btm_rgt_col = (*btm_rgt_col_it)[1];

	board.resize(btm_rgt_row + 2, btm_rgt_col + 2);

	for (int i = 0; i < init_coords.size(); i++) {
		board(init_coords[i][0], init_coords[i][1]) = '*';
	}

	for (int i = 0; i < board.size1(); i++) {
		for (int j = 0; j < board.size2(); j++) {
			if (i == 0 || i == board.size1() - 1) {
				board(i, j) = 'e';
			}
			else if (j == 0 || j == board.size2() - 1) {
				board(i, j) = 'e';
			}
			else if (board(i, j) != '*') {
				board(i, j) = '.';
			}
		}
	}

	next_board = board;

}

int Game_of_Life::check_neighbors(int i, int j) {
	int living_neighbors = 0;
	for (int dx = -1; dx <= 1; dx++) {
		for (int dy = -1; dy <= 1; dy++) {
			if (i + dy < 0 || i + dy > board.size1()-1 || j + dx < 0 || j + dx > board.size2()-1){
				continue;
			}
			else if (board(i + dy, j + dx) == '*') {
				living_neighbors += 1;
			}

		}
	}
	if (board(i, j) == '*') {
		return living_neighbors-1;
	}
	else {
		return living_neighbors;
	}
}

void Game_of_Life::print_board() {
	for (int i = 0; i < board.size1(); i++) {
		for (int j = 0; j < board.size2(); j++) {
			if (j == board.size2() - 1) {
				std::cout << board(i, j) << "\n";
			}
			else if (i == board.size1() - 1 && j == board.size2() - 1 ) {
				std::cout << board(i, j) << "\n" << "\n";
			}
			else {
				std::cout << board(i, j);
			}
		}
	}
}


void Game_of_Life::play(int time_steps){
	int living_neighbors;
	print_board();
	for (int t = 0; t < time_steps; t++){
		for (int i = 0; i < board.size1(); i++){
			for (int j = 0; j < board.size2(); j++){
				living_neighbors = check_neighbors(i, j);
				if (board(i, j) == '*') {
					if (living_neighbors > 3 || living_neighbors < 2) {
						next_board(i, j) = '.';
					}
				}
				else if (board(i, j) = '.') {
					if (living_neighbors == 3) {
						next_board(i, j) = '*';
					}
				}
			}
		}
		board = next_board;
		print_board();
	}

	
	
}


int main() {

	std::vector<std::vector<int>> init_coords;
	std::vector<int> coords1(2, 1);
	std::vector<int> coords2(2, 2);
	std::vector<int> coords3(2, 3);
	std::vector<int> coords4(2, 4);
	//std::vector<int> coords5;
	//coords5.push_back(2);
	//coords5.push_back(1);
	/*
	std::vector<int> coords6;
	coords6.push_back(3);
	coords6.push_back(1);
	*/

	init_coords.push_back(coords1);
	init_coords.push_back(coords2);
	init_coords.push_back(coords3);
	init_coords.push_back(coords4);
	//init_coords.push_back(coords5);
	//init_coords.push_back(coords6);
	

	Game_of_Life myGame(init_coords);

	myGame.play(3);

	//myGame.print_board();

	system("Pause");
	return 0;
}