#include <iostream>
using namespace std;
int main(){
	int i;
	int x = 1000;
	int sum = 0;
	for(int j = 1; j < 1000; j++){
		if(j%3 == 0){
			sum = sum + j;
		}

		else if(j%5 == 0){
			sum = sum + j;
		}

	}

	cout << sum << endl;
	return 0;
}