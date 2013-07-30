#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int main(){
	int no_of_t;
	cin >> no_of_t;
	int num;
	double sum;
	double temp;
	for(int i = 0; i < no_of_t; i++){
		cin >> num;
		if(num<8)
			temp = pow(0.1,num);
		else
			temp=0.0;
		sum = (double)num/2.0 - (5.0/90)*(1- temp);
		cout << sum << endl;
	} 

	return 0;

}	