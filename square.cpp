#include<iostream>
using namespace std;
int main(){
	long long int m,n,a;
	cin >> m;
	cin >> n;
	cin >> a;
	long long int sum1 = 0;
	long long int sum2 = 0;
	long long int sum = 0;
	if(m%a){
		sum1 = sum1 + m/a + 1; 
	}

	else{
		sum1 = sum1 + m/a;
	}

	if(n%a){
		sum2 = sum2 + n/a + 1;
	}

	else{
		sum2 = sum2 + n/a;
	}

	sum = sum1 * sum2;
	cout << sum << endl;
	return 0;
}