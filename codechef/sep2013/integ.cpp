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
using namespace std;
int cost;
long long int head;
std::vector<int> array;

long long int recurse (int marker){
	if(marker == 0)
		return 0;
	if(marker > cost){
		long long int newcost;
		newcost = (0 - (lli)array[marker -1] - head)*(lli)cost; 
		head = 0-array[marker-1];
		//cout << newcost << endl;
		return newcost + recurse(marker-1);
	}

	else{
		long long int ans = 0;
		for(int i = 0; i < marker; i++){
			ans = ans - array[i] - head;
		}
		return ans;
	}

}


int main(){

	
	int n;
	cin >> n;

	for(int i =0; i < n; i++){
		int temp;
		cin >> temp;
		array.push_back(temp);
	}
	head = 0;
	cin >> cost;

	sort(array.begin(),array.end());

	int flag = n;
	for(int i = 0; i < n; i++){
		if(array[i] >= 0){
			flag = i;
			break;
		}
	}



	long long int answer = recurse(flag);
	cout << answer << endl;
	return 0; 
	
}