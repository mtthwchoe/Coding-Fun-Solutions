#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    
    int rows;
	int columns;
	string temp;
	
	cin >> rows;
	cin >> columns;

	std::vector<std::string> all;
	
	for(int i = 0; i < rows; i++) {
		cin >> temp;
		all.push_back(temp);
	}
	
	for(string i : all) {
		cout << i;
		cout << "\n";
	}
	

    return(0);
}