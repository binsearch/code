#include <iostream>
using namespace std;
int main(){
	int no_of_t;
	cin >> no_of_t;
	for(int i = 0; i < no_of_t; i++){
		long long int n;
		long long int k;
		cin >> n;
		cin >> k;
		if(k == 0){
			cout << "0" <<" " << n <<  endl;
			continue;
		}
		long long int can = (n/k);
		long long int rem = n%k;
		cout << can << " " << rem << endl;

	}
	return 0;
}
