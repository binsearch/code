#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#define high 1000000000000000000
typedef long long int lli;
using namespace std;


inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
	n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

lli c[200][200];


lli combi (int n, int r){
	if(c[n][r] != -1)
		return c[n][r];
	
	if(n == r){
		c[n][r] = 1;
		return c[n][r];
	}

	if(r == 0){
		c[n][r] = 1;
		return c[n][r];
	}
	if(r == 1){
		c[n][r] = n;
		return c[n][r];

	}


	else{
		c[n][r] = combi(n-1,r) + combi(n-1,r-1);
		return c[n][r];
	}
}

int main(){


	int i;
	for( i = 0; i < 200; i++){
		for(int j = 0; j < 200; j++)
			c[i][j] = -1;
	}
	lli val[200] = {0};
	val[0] = 1;
	for(i = 1; i < 111; i++){
		lli temp =  combi(i,i/2);
		val[i] = temp;
		
	}

	int t;
	inp(t);
	for(i = 0;i < t; i++){
		long long int spoon;
		cin >> spoon;
		for(int j = 1; j < 111; j++){
			if(val[j] >= spoon){
				cout << j << endl;
				break;
			}
		}
	}


	return 0;	
}