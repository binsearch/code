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
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
	n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int g[26][26];
int c[26];

void dfs(int v){
	c[v] = 1;
	for(int i = 0; i < 26; i++){
		if(g[v][i] == 1){
			if(c[i] == 0){
				dfs(i);			}
		}

	}
}

int main(){

	int t;
	inp(t);
	while(t--){
		memset(g,0,sizeof g);
		int n;
		inp(n);
		int in[26] = {0};
		int out[26] = {0};
		for(int i = 0; i < n; i++){
			string pl;
			cin >> pl;
			g[pl[0]-'a'][pl[pl.size()-1]-'a'] = 1;
			g[pl[pl.size()-1]-'a'][pl[0]-'a'] = 1;			
			out[pl[0]-'a']++;
			in[pl[pl.size()-1]-'a']++;
		}

		memset(c,0,sizeof c);
		int j;
		for(j = 0; j < 26; j++){
			if(in[j] != 0 || out[j] != 0) break;
		}
		
		dfs(j);
		int flag = 0; 

		for(int i = 0; i < 26; i++){
			if(in[i] != 0 || out[i] != 0){

				if(c[i] == 0){
					// cout << (char)(i+'a') << endl;
					flag = 1;
					break;
				}
			}
		}

		if(flag == 1){
			printf("The door cannot be opened.\n");
			continue;			
		}

		int start = 0;
		int end = 0;
		// cout << in['m'-'a'] << " " << out['m' - 'a'] << endl;
		for(int i = 0; i < 26; i++){
			if(in[i] != out[i]){
				if(in[i] == out[i] + 1){
					if(end == 1){
						// cout << " more ends" << endl;
						flag = 1;
						break;
					}
					end = 1;
				}

				else if(out[i] == in[i] + 1){
					if(start == 1){
						// cout << "more starts" << endl;
						flag = 1;
						break;
					}
					start = 1;
				}

				else {
					// cout << (char)(i+'a') << endl;
					flag = 1;
					break;
				}


			}
		}

		if(flag == 1){
			printf("The door cannot be opened.\n");			
		}

		else{
			printf("Ordering is possible.\n");
		}
	}

	return 0;	
}