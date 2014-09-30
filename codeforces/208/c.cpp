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
typedef long long int lli;
typedef pair<int,int> pii;

bool myfunction (int i,int j) { return (i>j); }

int main(){

	int n;
	cin >> n;
	int a[n];
	int b[n];
	int c[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	// cout << 1 << endl;
	int l = 0;
	int r = -1;

	for(int i = 0; i < n; i++){
		if(a[i] == 0){
			l = r+1;
			r = i;
			if(r-l >= 3){
				c[l] = 3;
			}
			else{
				c[l] = r-l;
			}
			sort(a+l, a+r, myfunction);
		}

	}
	// cout << "hai" << endl;
	int ops = 0;
	int prev = -1;
	for(int i = 0; i < n; i++){
		if(b[i] == 0){
			if(ops == 0){
				cout << "0" << endl;
			}
			if(ops == 1){
				cout << "1 popQueue" << endl;
			}
			if(ops == 2){
				cout << "2 popStack popQueue" << endl;
			}

			if(ops == 3){
				cout << "3 popStack popQueue popFront" << endl;
			}
			ops = 0;
			prev = i;
		}

		else{
			if(b[i] >= a[prev+c[prev+1]-ops] && ops < 3){
				if(ops == 0){
					cout << "pushQueue" << endl;
					ops = 1;
					continue;
				}

				if(ops == 1){
					cout << "pushStack" << endl;
					ops = 2;
					continue;
				}

				if(ops == 2){
					cout << "pushBack" << endl;
					ops = 3;
					continue;
				}
			}

			if(ops == 0 || ops == 1){
				cout << "pushStack" << endl;

			}

			if(ops == 2){
				cout << "pushQueue" << endl;
			}

			if(ops == 3){
				cout << "pushBack" << endl;
			}


		}
	}

	return 0;	
}