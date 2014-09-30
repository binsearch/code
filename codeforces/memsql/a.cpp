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
#define rep(i,a,b) for(int i = a; i < b; i++)
int main(){

	string s[8];
	s[0] = "vaporeon";
	s[1] = "jolteon";
	s[2] = "flareon";
	s[3] = "espeon";
	s[4] = "umbreon";
	s[5] = "leafeon";
	s[6] = "glaceon";
	s[7] = "sylveon";
	// Vaporeon, Jolteon, Flareon, Espeon, Umbreon, Leafeon, Glaceon, and Sylveon.

	int n;
	cin >> n;
	string cr;
	cin >> cr;
	int ans;
	for(int j = 0; j < 8; j++){	
		int flag = 1;
		for(int i = 0; i < n; i++){
			if(cr[i] != '.' && cr[i] != s[j][i]){ 
				flag = 0;
				break;
			}
		}
		if(flag){
			ans = j;
			break;
		} 
	}

	cout << s[ans] << endl;
	return 0;	
}