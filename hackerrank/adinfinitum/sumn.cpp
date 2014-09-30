#include <iostream>
using namespace std;
#define mod 1000000007
int main(){
	int t;
	cin >> t;
	while(t--){
		long long int n;
		cin >> n;
		n = n%mod;
		n = (n*n)%mod;
		cout << n << endl;
	}
	return 0;
}