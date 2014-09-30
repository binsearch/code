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
#include <queue>
#include <fstream>
#define mod 1000000007
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;

int main(){

	ifstream fin;
	ofstream fout;

	fin.open("square_detector.txt");
	fout.open("square_output.txt");

	int t;
	fin >> t;
	for(int k = 0; k < t; k++){
		int n;
		fin >> n;
		char g[20][20];
		int cnt = 0;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				fin >> g[i][j];
				if(g[i][j] == '#') cnt++;
			}
		}
		// cout << cnt << endl;
		int flag = 0;
		int root = sqrt(cnt) + 0.5;
		if(cnt - root*root == 0){
			// check for a square	
			int sr = -1; 
			int sc = -1;
			for(int i = 0; i < n; i++){
				for(int j = 0; j < n; j++){
					if(g[i][j] == '#'){
						sr = i;
						sc = j;
						break;
					}
				}
				if(sr != -1) break;
			}

			if(sr + root -1 < n && sc + root -1 < n){
				for(int i = sr; i < sr + root; i++){
					for(int j = sc; j < sc + root; j++){
						if(g[i][j] != '#'){
							flag = 1;
							break;
						}
					}
					if(flag == 1) break;
				}
				if(flag == 1)	fout << "Case #" << k+1 << ": NO" << endl;
				else fout << "Case #" << k+1 << ": YES" << endl;
			}
			else{
				fout << "Case #" << k+1 << ": NO" << endl; 				
			}


		}

		else{
			fout << "Case #" << k+1 << ": NO" << endl; 
		}
	}

	return 0;	
}