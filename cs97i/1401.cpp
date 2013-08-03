#include <iostream>
#include <math.h>
using namespace std;
int main(){
	int no_of_t;
	cin >> no_of_t;
	for(int i = 0; i < no_of_t; i++){
		int sum = 0;
		int in;
		cin >> in;
		long long int p = 1; 
		for(int j = 1; (in/(p = p*5)) != 0; j++){
			sum = sum + in/p;
		}
		cout << sum << endl;
	}
	return 0;
}