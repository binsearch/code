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



const int maxnodes = 1000*1000 + 10;

int np; // number of patterns.
const int maxp = 1000;

string pat[maxp];

int aut[maxnodes][26] = {0}; //transitions
set<int> mat[maxnodes]; //matching patterns
int fail[maxnodes] = {0};

int cnt = 1;
//creating transitions.
void init (){
	for(int i = 0; i < np; i++){
		string temp = pat[i];
		int pstate = 1;
		for(int j = 0; j < temp.size(); j++){
			
			if(aut[pstate][temp[j]-'A'] == 0){
				cnt++;
				aut[pstate][temp[j]-'A'] = cnt; 
			}
			pstate = aut[pstate][temp[j]-'A']; 
			//cout << temp[j] << " " << pstate << endl;
		}
		mat[pstate].insert(i);
	}

	//creating transitions at root.
	for(int i = 0; i < 26; i++){
		if(aut[1][i] == 0)
			aut[1][i] = 1;
	}

	//failure tranisitons for all nodes
	queue<int> bfs;
	for(int i = 0; i < 26; i++){
		if(aut[1][i] != 1){
			bfs.push(aut[1][i]);
			fail[aut[1][i]] = 1;
		}
	}

	while(!bfs.empty()){
		int temp = bfs.front();
		bfs.pop();
		for(int i = 0; i < 26; i++){
			if(aut[temp][i] != 0){
				int tfail = temp;
				while(aut[fail[tfail]][i] == 0){
					tfail = fail[tfail];
				}
				bfs.push(aut[temp][i]);
				fail[aut[temp][i]] = aut[fail[tfail]][i];
				//do union.
				set<int> s1 = mat[aut[temp][i]];
				set<int> s2 = mat[aut[fail[tfail]][i]];
				set<int>:: iterator it;
				for(it = s2.begin(); it != s2.end(); it++){
					s1.insert(*it);
				}
				mat[aut[temp][i]] = s1;
			}
		}
	}

}


int nextstate(int state,char a){
	//if(aut[state][a-'a'] != 0)
	//	return aut[state][a-'a'];
	while(aut[state][a-'A'] == 0){
		state = fail[state];
	}
	return aut[state][a-'A'];
}

int main(){
	int t;
	inp(t);
	for(int i=0; i < t; i++){
		int l,c;
		inp(l);
		inp(c);
		inp(np);
		string board[1010];
		for(int j = 0; j < c; j++){
			cin >> board[j];
		}

		for(int j = 0; j < np; j++){
			cin >> pat[j];
		}

		for(int j = 0; j < maxnodes; j++){
			mat[i].clear();
		}

		cnt = 1;
		memset(fail,0,sizeof fail);
		memset(aut, 0, sizeof aut);
		int pat_x[1010];
		int pat_y[1010];
		char pat_d[1010];
		int state = 1;

		init();
		

		for(int j = 0; j < l; j++){
			state = 1;
			for(int k = 0; k < c; k++){
				//cout << j << " "  << k << endl; 
				state = nextstate(state,board[j][k]);

				set<int>::iterator it;
				for(it = mat[state].begin(); it != mat[state].end(); it++){
					int pid = *it;
					pat_x[pid] = j;
					pat_y[pid] = k - pat[pid].size();
					pat_d[pid] = 'C';
					cout << pid << " " << j << " " << k << " C" << endl;  
				}
			}

			state = 1;
			for(int k = c - 1; k >= 0; k--){
				//cout << j << " "  << k << endl; 
				state = nextstate(state,board[j][k]);

				set<int>::iterator it;
				for(it = mat[state].begin(); it != mat[state].end(); it++){
					int pid = *it;
					pat_x[pid] = j;
					pat_y[pid] = k + pat[pid].size();
					pat_d[pid] = 'G';
					cout << pid << " " << j << " " << k << " G" << endl;  
				}
			}

		}

		for(int k = 0; k < c; k++){
			state = 1;
			for(int j = 0; j < l; j++){
				state = nextstate(state,board[j][k]);
				set<int>::iterator it;
				for(it = mat[state].begin(); it != mat[state].end(); it++){
					int pid = *it;
					pat_x[pid] = j-pat[pid].size();
					pat_y[pid] = k;
					pat_d[pid] = 'E';
					cout << pid << " " << j << " " << k << " E" << endl;  
				}

			}

			state = 1;
			for(int j = l-1; j >= 0; j--){
				
				state = nextstate(state,board[j][k]);
				set<int>::iterator it;
				for(it = mat[state].begin(); it != mat[state].end(); it++){
					int pid = *it;
					pat_x[pid] = j+pat[pid].size();
					pat_y[pid] = k;
					pat_d[pid] = 'A';
					cout << pid << " " << j << " " << k << " A" << endl;  
				}
			}

		}

		for(int k=0;k<c;k++) { 
			cout << "came" << endl;
			state = 1;
			for(int k1=k,j=0;j<l && k1<c;k1++,j++) {
				if(k == 3){

				state = nextstate(state,board[j][k1]);
				cout << state << endl;
				set<int>::iterator it;
				for(it = mat[state].begin(); it != mat[state].end(); it++){
					int pid = *it;
					pat_x[pid] = j+pat[pid].size();
					pat_y[pid] = k;
					pat_d[pid] = 'D';
					cout << pid << " " << j << " " << k << " D" << endl;  
				}
				}

			}
			 
			state = 1;
			for(int k1=k,j=l-1;j>=0 && k1<c;k1++,j--) { 
				state = nextstate(state,board[j][k1]);
				set<int>::iterator it;
				for(it = mat[state].begin(); it != mat[state].end(); it++){
					int pid = *it;
					pat_x[pid] = j+pat[pid].size();
					pat_y[pid] = k;
					pat_d[pid] = 'B';
					cout << pid << " " << j << " " << k << " B" << endl;  
				}

			} 
		}

		for(int k=c-1;k>=0;k++) { 
			cout << "came 2" << endl;
			state = 1;
			for(int k1=k,j=0;j<l && k1>=0;k1--,j++) {

				state = nextstate(state,board[j][k1]);
				set<int>::iterator it;
				for(it = mat[state].begin(); it != mat[state].end(); it++){
					int pid = *it;
					pat_x[pid] = j+pat[pid].size();
					pat_y[pid] = k;
					pat_d[pid] = 'F';
					cout << pid << " " << j << " " << k << " F" << endl;  
				}

			} 
			state = 1;
			for(int k1=k,j=l-1;j>=0 && k1>=0;k1--,j--) { 
				state = nextstate(state,board[j][k1]);
				set<int>::iterator it;
				for(it = mat[state].begin(); it != mat[state].end(); it++){
					int pid = *it;
					pat_x[pid] = j+pat[pid].size();
					pat_y[pid] = k;
					pat_d[pid] = 'H';
					cout << pid << " " << j << " " << k << " H" << endl;  
				}

			} 
		}





	}
	return 0;
}



