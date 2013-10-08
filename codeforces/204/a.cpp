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
#include <queue>
using namespace std;
int main(){

	int n;
	int f = 0;
	int z = 0;
	cin >> n;
	for(int j = 0; j < n;  j++){
		int temp;
		cin >> temp;
		if(temp == 5) 
			f++;
		if(temp == 0)
			z++;
	}
	if(z == 0){
		cout << -1 << endl;
	}
	else{
		int i;
		for(i = f; i > 0; i--){
			if((i*5) % 9 == 0)
				break;
		}

		if(i == 0){
				cout << 0 << endl;
		}
		else{
			for(int j = 0; j < i; j++)
				cout << 5;
			for(int j = 0; j < z; j++)
				cout << 0;
			cout << endl;
		}
	}
	return 0;
}