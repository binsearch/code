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
using namespace std;
char grid[500][500];
int rows;
int cols;
int primes[500];
int l[500][500];
int r[500][500];
int t[500][500];
int b[500][500];
int temp[500]={0};



void fill(){
	int cnt;

	for(int j = 0; j < rows; j++){
		cnt = 0;
		for (int k = 0; k < cols; k++)
		{	
			if(grid[j][k] == '^'){
				l[j][k] = cnt;
				cnt++;
			}
			else{
				l[j][k]=0;
				cnt = 0;
			}

			// cout<<j<<" "<<k<<" "<<l[j][k]<<endl;

		}
	}

	for(int j = 0; j < rows; j++){
		cnt = 0;
		for (int k = cols-1; k >= 0; k--)
		{	
			if(grid[j][k] == '^'){
				r[j][k] = cnt;
				cnt++;
			}
			else{
				r[j][k] = 0;
				cnt = 0;
			}
		// cout<<j<<" "<<k<<" "<<r[j][k]<<endl;
		}
	}

	for(int k = 0; k < cols; k++){
		cnt = 0;
		for (int j = 0; j < rows; j++)
		{	
			if(grid[j][k] == '^'){
				t[j][k] = cnt;
				cnt++;
			}
			else{
				t[j][k] = 0;
				cnt = 0;
			}
	// cout<<j<<" "<<k<<" "<<t[j][k]<<endl;
		}
	}

	for(int k = 0; k < cols; k++){
		cnt = 0;
		for (int j = rows-1; j >= 0; j--)
		{	
			if(grid[j][k] == '^'){
				b[j][k] = cnt;
				cnt++;
			}
			else{
				b[j][k] = 0;
				cnt = 0;
			}
			// cout<<j<<" "<<k<<" "<<b[j][k]<<endl;

		}
	}


}



int main(){
	int no_of_t;
	cin >> no_of_t;

	for(int i = 2; i < 500; i++){
		if(temp[i] == 0){
			for(int j = i; i*j < 500; j++)
				temp[i*j] = 1;
		}
	}


	primes[0] = 0;
	primes[1] = 0;
	for(int i = 2; i < 500; i++){
		if(temp[i] == 0)
			primes[i]=primes[i-1]+1;
		else
			primes[i] = primes[i-1]; 
	}


	while(no_of_t--) {

		cin >> rows;
		cin >> cols;

		for(int j = 0; j < rows; j++){
			for (int k = 0; k < cols; k++)
			{	
				char in;
				cin >> in;
				grid[j][k] = in;
			}
		}

		fill();



		int ans = 0,num;
		for(int j = 0; j < rows; j++){
			for(int k = 0; k < cols; k++){
				if(grid[j][k] == '^'){
					num=min(l[j][k],r[j][k]);
					num=min(num,t[j][k]);
					num=min(num,b[j][k]);
					ans+=primes[num]; 	
				}
			}
		}
		cout << ans << endl;	
	}
	return 0;
}