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


int main(){

	int n;
	cin >> n;
	int a[n];
	int b[n];
	for(int i = 0; i < n; i++){
		cin >> a[i];
		b[i] = a[i];
	}
	cout << 1 << endl;
	int l = 0;
	int r = 0;

	for(int i = 0; i < n; i++){
		if(a[i] == 0){
			r = i;
			l = r+1;
			sort(a+l, a+r);
		}

	}
	cout << "hai" << endl;
	int cnt = 1;
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
			cnt = 1;
			ops = 0;
			prev = i;
		}

		else{
			if(b[i] == a[prev+ops+1] && ops < 3){
				if(cnt == 1){
					cout << "pushQueue" << endl;
					cnt == 2;
					ops = 1;
					continue;
				}

				if(cnt == 2){
					cout << "pushStack" << endl;
					cnt++;
					ops = 2;
					continue;
				}

				if(cnt == 3){
					cout << "pushBack" << endl;
					cnt++;
					ops = 3;
					continue;
				}
			}

			if(cnt == 1 || cnt == 2){
				cout << "pushStack" << endl;

			}

			if(cnt == 3){
				cout << "pushQueue" << endl;
			}

			if(cnt == 4){
				cout << "pushBack" << endl;
			}


		}
	}

	return 0;	
}