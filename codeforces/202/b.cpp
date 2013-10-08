#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int v;
	cin >> v;
	int p[10];
	int min = 1e7;
	for(int i = 1; i < 10; i++){
		cin >> p[i] ;
		if(p[i]  < min)
			min = p[i];

	}
	
	int max = v/min;
	if(max == 0){
		cout << -1 << endl;
		return 0;
	}
	for(int i = 0; i < max; i++){
		for(int j = 9; j >= 1; j--){
			if(v >= p[j]){
				if((v-p[j])/min == max-i-1){
					v =  v- p[j];
					cout << j;
					break;
				}
			}
		}
	}

	cout << endl;
	return 0;


}