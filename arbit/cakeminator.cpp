#include <iostream>
#include <vector>
using namespace std;

int main(){
	vector <vector<int> > cake;
	int rows;
	int cols;
	vector<int> temp;
	cin >> rows;
	cin >> cols;
	char temp1;
	int sum;
	int ate;
	sum = 0;
	for(int i = 0; i < rows; i++){
		temp.clear();
		for(int j = 0; j< cols; j++){
			cin >> temp1;
			if(temp1 == 'S'){
				temp.push_back(1);
			}
			else{
				temp.push_back(0);
			}
		}
		cake.push_back(temp);
	}
	// for(int i = 0; i < rows; i++){
	// 	for(int j = 0; j < cols; j++){
	// 		cout << cake[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }
	int flag;

	for(int i = 0; i < rows; i++){
		flag = 0;
		for(int j = 0; j < cols; j++){
			if(cake[i][j] == 1){
				flag = 1;
			}

		}
		// cout<< i << flag << endl;
		if(flag == 0){
			sum = sum + cols;
			for(int j = 0; j < cols; j++)cake[i][j] = -1;
		}
	}

	// cout << sum << endl;

	for(int j = 0; j < cols; j++){
		flag = 0;
		ate = 0;
		for(int i = 0; i < rows; i++){
			if(cake[i][j] == 1){
				flag = 1;
			}
			if(cake[i][j] == -1){
				ate++;
			}
		}
		if(flag == 0){
			sum = sum + rows - ate;
		}
	}

	cout << sum << endl;

	return 0;
}