#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	int min = 1000;
	int max = 0;
	for(int i = 0; i < n ; i++){
		int temp;
		cin >> temp;
		if(temp > max){
			max = temp;
		}
		if(temp < min){
			min = temp;
		}
	}

	int v;
	v = max;
	if(2*min > v){
		v = 2*min;
	}

	for(int i = 0; i < m; i++){
		int temp;
		cin >> temp;
		if(temp <= v){
			v = -1;
		}
	}
	cout << v << endl;
	return 0;
}