#include <iostream>
using namespace std;
int main(){
	int n;
	int no_of_t;
	cin >> no_of_t;
	for(int i = 0; i < no_of_t; i++){
		cin >> n;
		cout << (n/2)*2 << endl;
	}
	
	return 0;
}