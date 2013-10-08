#include <cstdlib>
#include <ctime>
#include <cstring>
#include <queue>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdio.h>
#define inf 1e8
using namespace std;

double arr[4000];
double dpf[2010][4010];
double dpc[2010][4010];
int n;

double recurse(int d, int ind){

	if(ind == 2*n){
		return 0;
	}	

	if(2*n-ind < abs(d)){
		return 1e6;
	}
	
	if(d >= 0){
		if(abs(dpf[d][ind]-inf) > 1){
			return dpf[d][ind];
		}
		double df = arr[ind] - floor(arr[ind]) + recurse(d+1,ind+1);
		double dc = arr[ind] - ceil(arr[ind]) + recurse(d-1, ind+1);
		if(abs(df) > abs(dc)){
			dpf[d][ind] = dc;
		}
		else{
			dpf[d][ind] = df;
		}
		// cout << d << " " << ind << " f" << dpf[d][ind] << endl;
		return dpf[d][ind];
	}

	if(d < 0){
		d = -d;

		if(abs(dpc[d][ind]-inf) > 1){
			return dpc[d][ind];
		}

		double df = arr[ind] - floor(arr[ind]) + recurse((-d)+1,ind+1);
		double dc = arr[ind] - ceil(arr[ind]) + recurse(-d-1, ind+1);

		if(abs(df) > abs(dc)){
			dpc[d][ind] = dc;
		}
		else{
			dpc[d][ind] = df;
		}
		// cout << d << " " << ind << " c" << dpc[d][ind] << endl;
		return dpc[d][ind];
	}

}


int main(){

	cin  >> n;
	for(int i = 0; i < 2*n; i++)
		cin >> arr[i];
	for(int i = 0; i < 2009; i++){
		for(int j = 0; j < 4009; j++){
			dpf[i][j] = inf;
			dpc[i][j] = inf;
		}

	}

	double ans = recurse(0,0);
	printf("%.3f\n", abs(ans));
	return 0;
}