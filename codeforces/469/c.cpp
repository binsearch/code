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

int main(){

	int n;
	cin >> n;
	if(n < 4){
		cout << "NO" << endl;
	}

	else{
		cout << "YES" << endl;
		if(n%2 == 0){
		if(n > 4){
			for(int i = 0; i < (n-4)/2 - 1; i++){
				cout << 2*i+6 << " - " << 2*i + 5 << " = 1\n"; 
				cout << 1 << " * " << 2*i + 7 << " = " << 2* i + 7 << endl;
			}

			cout << n << " - " << n - 1 << " = " << 1 << endl;

		}

		cout << "1 * 2 = 2" <<endl;
		cout << "2 * 3 = 6" << endl;
		cout << "6 * 4 = 24" << endl;
		if(n > 4) cout << "24 * 1  = 24" << endl;

		}

		else {
			if(n > 5){
				for(int i = 0; i < (n-5)/2 - 1; i++){
					cout << 2*i+7 << " - " << 2*i + 6 << " = 1\n"; 
					cout << 1 << " * " << 2*i + 8 << " = " << 2* i + 8 << endl;
				}
				cout << n << " - " << n - 1 << " = " << 1 << endl;				
			}
			cout << "5 - 1 = 4" << endl;
			cout << "4 - 2 = 2" << endl;
			cout << "2 * 3 = 6" << endl;
			cout << "6 * 4 = 24" << endl;
			if(n > 5) cout << "1 * 24 = 24" << endl;
		}
	}
	return 0;	
}