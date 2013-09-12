#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
vector<vector<char> > grid;
int rows;
int cols;

bool cross(int row, int col){
	vector<int> cont;
	//cont.assign(4,0);
	int l,r,b,t;
	l = 0; r = 0; b = 0; t = 0;

	for(int i = col-1; i >=0 ; i--){
		if(grid[row][i] == '^')
			l++;
		if(grid[row][i] == '#')
			break;
	}

	for(int i = col+1; i < cols ; i++){
		if(grid[row][i] == '^')
			r++;
		if(grid[row][i] == '#')
			break;
	}

	for(int i = row-1; i >=0 ; i--){
		if(grid[i][col] == '^')
			t++;
		if(grid[i][col] == '#')
			break;
	}

	for(int i = row+1; i < rows ; i++){
		if(grid[i][col] == '^')
			b++;
		if(grid[i][col] == '#')
			break;
	}

	cont.push_back(l);
	cont.push_back(r);
	cont.push_back(b);
	cont.push_back(t);

	sort(cont.begin(),cont.end());
	// cout << "i " << row  << "j " << col <<  " cont " << cont[0] << endl;
	if(cont[0] >= 2)
		return true;
 
		return false;




}

int main(){
	int no_of_t;
	cin >> no_of_t;
	for(int i = 0; i < no_of_t; i++){
		
		cin >> rows;
		cin >> cols;
		grid.clear();

		for(int j = 0; j < rows; j++){
			std::vector<char> temp;
			for (int k = 0; k < cols; k++)
			{	
				char in;
				cin >> in;
				temp.push_back(in);

			}
			grid.push_back(temp);
		}

		int count = 0;
		for(int j = 1; j < rows; j++){
			for(int k = 1; k < cols; k++){
				if(grid[j][k] != '#'){
					if(cross(j,k))
						count++;
				}
			}
		}
		cout << count << endl;
	}
	return 0;
}