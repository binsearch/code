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
	cin >> n;
	int arr[100010];
	int prev[100010];
	int d[100010];

	memset(d,-1,sizeof d);
	memset(prev, -1, sizeof prev);
	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	for(int i = 0; i < n; i++){
		int val = arr[i];
		if(d[val] == -2){
			continue;
		}
		if(prev[val] == -1){
			prev[val] = i;
			d[val] = 0;
			continue;
		}

		if(d[val] == 0){
			d[val] = i - prev[val];
			prev[val] = i;
			continue;
		}

		else{
			if(i - prev[val] != d[val]){
				d[val] = -2;
			}
			else{
				prev[val] = i;
			}
			continue;
		}


	}
	int count = 0;
	for(int i = 0; i < 100010; i++){
		if(d[i] >= 0){
			count++;
		}
	}
	cout << count << endl;
	for(int i = 0; i < 100010; i++){
		if(d[i] >= 0){
			cout << i << " " << d[i] << endl;
		}
	}

	return 0;
}