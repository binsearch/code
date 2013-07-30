#include <iostream>
using namespace std;
int main(){
	float in;
	double inp;
	float sum;
	sum = 0;
	for(int i = 0; i < 12; i++){
		cin >> in;
		//inp = in*100;
		cout << inp << endl;
		sum = sum + inp;
	}
	int sumip = sum /12;
	float sump;
	sump = sumip /100.0;
	cout << sump << endl;
	return 0;
}