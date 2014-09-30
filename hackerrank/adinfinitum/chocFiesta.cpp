#include <iostream>
using namespace std;
#define lli long long int
#define mod 1000000007
lli recurse(int n){
    if(n == 0) return 1;
    else return (2*recurse(n-1))%mod;
}
int main(){
	int n;
	cin >> n;
	int even = 0;
	int odd = 0;
	for(int i = 0; i < n; i++){
		int temp;
		cin >> temp;
		if(temp%2 == 0) even++;
		else odd++;
	}
	lli evenpow = recurse(even);
    lli oddpow;
    if(odd == 0) oddpow = 1;
    else oddpow = recurse(odd -1);
    lli ans = (oddpow*evenpow-1)%mod;
    cout << ans << endl;
    return 0;
}

