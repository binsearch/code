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
	string a[n];
	for(int i = 0; i < n; i++)
		cin >> a[i];

	string tex;
	cin >> tex;
	int pos = 0;
	string love = "<3";

	for(int i = 0; i < n; i++){
		int flag = 0;
		int j = 0;
		while(pos < tex.size()){
			if(tex[pos] == love[j]){
				j++;
			}
			pos++;
			if(j == 2){
				break;
			}
		}

		if(pos >= tex.size()-1){
			cout << "no" << endl;
			return 0;
		}
		j = 0;
		while(pos < tex.size() && j < a[i].size()) {
			// cout << a[i][j] << " " << tex[pos] << endl;
			if(a[i][j] == tex[pos])
				j++;
			pos++;
		}

		if(pos == tex.size()){
			cout << "no" << endl;
			return 0;
		}

	}

	int j = 0;
	while(pos < tex.size()){
		if(tex[pos] == love[j]){
			j++;
		}
		if(j == 2){
			break;
		}

		pos++;
		
	}

	if(pos >= tex.size()){
		cout << "no" << endl;
		return 0;
	}

	cout << "yes" << endl;


	return 0;	
}