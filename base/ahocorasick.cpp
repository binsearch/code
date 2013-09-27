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
			
			if(aut[pstate][temp[j]-'a'] == 0){
				cnt++;
				aut[pstate][temp[j]-'a'] = cnt; 
			}
			pstate = aut[pstate][temp[j]-'a']; 
			cout << temp[j] << " " << pstate << endl;
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
	while(aut[state][a-'a'] == 0){
		state = fail[state];
	}
	return aut[state][a-'a'];
}

int main(){

	pat[0] = "he";
	pat[1] = "she";
	pat[2] = "hers";
	pat[3] = "his";
	np = 4;
	string text = "ahishers";
	init();
	//cout << cnt << endl;
	int state = 1;
	for(int i = 0; i < text.size(); i++){
		set<int>::iterator it;
		for(it = mat[state].begin(); it != mat[state].end(); it++){
			int pid = *it;
			cout << pat[pid] << " at " << i << endl;
		}
		state = nextstate(state,text[i]);
	}

	set<int>::iterator it;
	for(it = mat[state].begin(); it != mat[state].end(); it++){
		int pid = *it;
		cout << pat[pid] << " at " << text.size() << endl;
	}


	return 0;	
}