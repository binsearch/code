#include <iostream>
#include <math.h>
#include <stdio.h>
using namespace std;
#define PI 3.14159265
int main(){

	int no_of_t;
	cin >> no_of_t;

	for( int i = 0; i < no_of_t; i++){
		double bigr;
		cin >> bigr;
		int n;
		cin >> n;
		double angle;
		angle = PI/n ;
		double sin_a;
		sin_a = sin(angle);
		double small_r;
		small_r = bigr*sin_a/(sin_a+1) ;
		cout << "Scenario #" << i+1 << ":"<<endl;
		printf("%.3f", small_r);
		cout << endl;
		cout << endl;
	}
	return 0;
}