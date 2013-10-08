#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	long long int n;
	cin >> n;
	long long int sum = 0;
	long long int max = -1;
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		sum = sum + temp;
		if(max < temp){
			max = temp;
		}

	}
	sum = sum - max;
	long long int tot;
	tot = (long long int)max*(n-2);
	if(tot >= sum)
		cout << max << endl;
	else{
		sum = sum - tot;
		// cout << sum << n << endl;
		if(sum%(n-1) == 0)
			max = max + sum/(n-1);
		else
			max = max + sum/(n-1) +1;

		cout << max  << endl; 
	}
	return 0;
}