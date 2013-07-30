#include <iostream>
using namespace std;
int main(){
	int n,k;
	int no_of_t;
	int mod = 1000000007;
	long long int a;
	long long int b;
	long long int pro;
	cin >> no_of_t;
	for(int i = 0; i < no_of_t; i++){
		cin >> n;
		cin >> k;
		pro  = 1; 
		if(k == 1 || k == 0){cout << 0 << endl;continue;}
		a = ((((k-2)*(k-2))%mod) + (k-1))%mod;
		b = (k*(k-1))%mod;
		for(int j = 0; j < n-1; j++){
			pro = (pro*a)%mod;
		}
		pro = (pro * b)%mod;
		cout << pro << endl;
	}
	return 0;
}