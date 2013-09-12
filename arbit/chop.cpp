#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int no_of_t;
	vector<int> len;
	int temp;
	int diff;
	cin >> no_of_t;
	cin >> diff;
	for(int i = 0; i < no_of_t; i++){
		cin >> temp;
		len.push_back(temp);
	}

	sort(len.begin(), len.end());
	// for(int i = 0; i < no_of_t; i++)
	// 	cout << len[i] << endl;
	int pair;
	pair = 0;
	int i = 0;
	while(i < no_of_t){
		if(i == no_of_t - 1){
			break;
		}
		if(len[i+1] <= len[i] + diff){
			pair++;
			i = i + 2;
		}

		else{
			i++;
		}
	}

	cout << pair << endl;
	return 0;


}