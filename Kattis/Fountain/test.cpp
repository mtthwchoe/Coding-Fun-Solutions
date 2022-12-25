#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print_map(std::vector<std::string> all) {
	for(int i = 0; i < all.size(); i++) {
		cout << all[i] + "\n";
	}
}

int main() {
    
    int rows;
	int columns;
	int flag = 0;
	string temp;
	
	cin >> rows;
	cin >> columns;

	std::vector<std::string> all;
	
	for(int i = 0; i < rows; i++) {
		cin >> temp;
		all.push_back(temp);
	}
	for(int i = 0; i < 3; i++) {
		for(int r = 0; r < rows; r++) {
			for(int c = 0; c < columns; c++) {
				if(all[r][c] == 'V') {
					if(r + 1 < rows && all[r+1][c] == '.') {
						all[r+1][c] = 'V';
					}
					else if(r + 1 < rows && all[r+1][c] == '#') {
						if(c - 1 >= 0 && all[r][c-1] == '.') {
							all[r][c-1] = 'V';
							flag++;
						}
						if(c + 1 < columns && all[r][c+1] == '.') {
							all[r][c+1] = 'V';
						}
						if(flag == 1) {
							c = 0;
						}
						flag = 0;
					}
				}
			}
		}
	}
	print_map(all);
    return(0);
}