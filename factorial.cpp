#include<iostream>
using namespace std;
int main(){

	long long fac[101];
	int no_of_t,num;
	fac[0] = 1;
	for( int i = 0; i < 100; i++){
		fac[i+1] = fac[i] * (i+1);
	} 
	
	cin >> no_of_t;
	for (int i= 0; i < no_of_t; i++){
		
		cin >> num;
		cout << fac[num] << endl;
	}
	
	
	return 0;
}
