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
 
 
void seive(){
	int lim = 500;
	int temp[500]={0};
	// memset(temp,0,sizeof temp);
	for(int i = 2; i < 500; i++){
		if(temp[i] == 0){
			for(int j = i; i*j < 500; j++)
				temp[i*j] = 1;
		}
	}
 
	int count = 0;
	primes[0] = 0;
	primes[1] = 0;
	for(int i = 2; i < 500; i++){
		if(temp[i] == 0)count++;
		primes[i] = count; 
	}
}
 
void fill(){
	int count;
 
	for(int j = 0; j < rows; j++){
		count = 0;
		for (int k = 0; k < cols; k++)
		{	
			if(grid[j][k] == '^'){
				l[j][k] = count;
				count++;
			}
			else{
				l[j][k]=0;
				count = 0;
			}
 
		}
	}
 
	for(int j = 0; j < rows; j++){
		count = 0;
		for (int k = cols-1; k >= 0; k--)
		{	
			if(grid[j][k] == '^'){
				r[j][k] = count;
				count++;
			}
			else{
				r[j][k] = 0;
				count = 0;
			}
 
		}
	}
 
	for(int k = 0; k < cols; k++){
		count = 0;
		for (int j = 0; j < rows; j++)
		{	
			if(grid[j][k] == '^'){
				t[j][k] = count;
				count++;
			}
			else{
				t[j][k] = 0;
				count = 0;
			}
 
		}
	}
 
	for(int k = 0; k < cols; k++){
		count = 0;
		for (int j = rows-1; j >= 0; j--)
		{	
			if(grid[j][k] == '^'){
				b[j][k] = count;
				count++;
			}
			else{
				b[j][k] = 0;
				count = 0;
			}
 
		}
	}
 
 
}
 
int cross(int row,int col){
	int arr[4];
	arr[0] = l[row][col];
	arr[1] = t[row][col];
	arr[2] = r[row][col];
	arr[3] = b[row][col];
	sort(arr,arr+4);
	// cout << "row " << row << " col " << col << " min " << arr[0] << " primes " << primes[arr[0]] << endl; 
	return primes[arr[0]];
}
 
 
int main(){
	int no_of_t;
	cin >> no_of_t;
	seive();
 
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
 
 
 
		int ans = 0;
		for(int j = 1; j < rows; j++){
			for(int k = 1; k < cols; k++){
				if(grid[j][k] == '^'){
					ans = ans + cross(j,k); 	
				}
			}
		}
		cout << ans << endl;	
	}
	return 0;
} 