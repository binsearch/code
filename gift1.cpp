/*
	ID: rohithk1
	PROG: gift1
	LANG: C++
	*/
	#include <iostream>
	#include <fstream>
	#include <string>
	#include <vector>
	using namespace std;

int main(){
	ofstream fout ("gift1.out");
	ifstream fin ("gift1.in");
	vector<string> names;
	vector<int> money;
	int no_of_friends;
	int mon;
	int num;
	int index;
	fin >> no_of_friends;
	string temp;
	for(int i = 0; i < no_of_friends; i++){
		fin >> temp;
		names.push_back(temp);
		money.push_back(0);
	}

	while(fin.good()){
		fin >> temp;

		for(index = 0; index < no_of_friends; index++){
			if(names[index] == temp)break;
		}
		
		fin >> mon;
		fin >> num;

		if(num == 0){
			money[index] = money[index] + mon;
			continue;
		}

		money[index] = money[index] + mon - (mon % num);
		for(int i = 0; i < num; i++){
			fin >> temp;
			for(int i = 0; i < no_of_friends; i++){
				if(names[i] == temp){
					money[i] = money[i] - (mon/num);
					break;
				}	
			}
		}
	}

	for(int i = 0; i < no_of_friends; i++){
		fout << names[i] << " " << (0 - money[i]) << endl;
	}




}