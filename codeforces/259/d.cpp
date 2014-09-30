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
#define vvi vector<vector<int> > 
#define vi vector<int>
//intializing ---- vvi res(k, vi(k,0))


int main(){

	int n;
	cin >> n;
	for(int i = 0; i < n/2; i++){
		for(int j = 0; j < n/2-i; j++)
			cout << "*";
		for(int j = 0; j < 2*i + 1; j++)
			cout << "D";
		for(int j = 0; j < n/2-i; j++)
			cout << "*";
		cout << endl;
	}

	for(int i = 0; i < n; i++)
		cout << "D";
	cout << endl;

	for(int i = 0; i < n/2; i++){
		for(int j = 0; j <= i; j++)
			cout << "*";
		for(int j = 0; j < n - 2*(i+1); j++)
			cout << "D";
		for(int j = 0; j <= i; j++)
			cout << "*";
		cout << endl;
	}



	return 0;	
}