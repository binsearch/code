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



const int maxnodes = 500*5000 + 10;

int np; // number of patterns.
const int maxp = 500;

char pat[maxp][5010];

int aut[maxnodes][63] = {0}; //transitions
set<int> mat[maxnodes]; //matching patterns
int fail[maxnodes] = {0};

int cnt = 1;
//creating transitions.
void init (){
	for(int i = 0; i < np; i++){
		string temp = pat[i];
		int pstate = 1;
		for(int j = 0; j < temp.size(); j++){
			if(temp[j] == '-'){
				if(aut[pstate][62] == 0){
					cnt++;
					aut[pstate][62] = cnt; 
				}
				pstate = aut[pstate][62]; 
			}
			else if(temp[j]<='9' && temp[j] >= '0'){
				if(aut[pstate][temp[j]-'0'+52] == 0){
					cnt++;
					aut[pstate][temp[j]-'0'+52] = cnt; 
				}
				pstate = aut[pstate][temp[j]-'0'+52]; 
			}

			else if(temp[j] - 'A' < 26){
				if(aut[pstate][temp[j]-'A'] == 0){
					cnt++;
					aut[pstate][temp[j]-'A'] = cnt; 
				}
				pstate = aut[pstate][temp[j]-'A']; 
				//cout << temp[j] << " " << pstate << endl;
			}
			else{
				if(aut[pstate][temp[j]-'a'+26] == 0){
					cnt++;
					aut[pstate][temp[j]-'a'+26] = cnt; 
				}
				pstate = aut[pstate][temp[j]-'a'+26]; 
				//cout << temp[j] << " " << pstate << endl;

			}
		}
		mat[pstate].insert(i);
	}

	//creating transitions at root.
	for(int i = 0; i < 63; i++){
		if(aut[1][i] == 0)
			aut[1][i] = 1;
	}

	//failure tranisitons for all nodes
	queue<int> bfs;
	for(int i = 0; i < 63; i++){
		if(aut[1][i] != 1){
			bfs.push(aut[1][i]);
			fail[aut[1][i]] = 1;
		}
	}

	while(!bfs.empty()){
		int temp = bfs.front();
		bfs.pop();
		for(int i = 0; i < 63; i++){
			int next=aut[temp][i];
			int rev=aut[fail[temp]][i];

			if(aut[temp][i] != 0){
				// int tfail = temp;
				// while(aut[fail[tfail]][i] == 0){
				// 	tfail = fail[tfail];
				// }
				bfs.push(next);
				fail[next]=rev;
				//do union.
				// set<int> s1 = mat[aut[temp][i]];
				// set<int> s2 = mat[aut[fail[tfail]][i]];
				set<int>:: iterator it=mat[fail[next]].begin();
				for(; it != mat[fail[next]].end(); it++){
					mat[next].insert(*it);
				}
				// mat[aut[temp][i]] = s1;
			}
			else
				aut[temp][i]=rev;
		}
	}

}


int nextstate(int state,char a){
	//if(aut[state][a-'a'] != 0)
	//	return aut[state][a-'a'];
	if(a == '-'){
		// while(aut[state][62] == 0){
		// 	state = fail[state];
		// }
		return aut[state][62];
	}
	if( a >= '0' && a <= '9'){
		// while(aut[state][a-'0'+52] == 0){
		// 	state = fail[state];
		// }
		return aut[state][a-'0'+52];
	}
	if((a-'A') < 26){
		// while(aut[state][a-'A'] == 0){
		// 	state = fail[state];
		// }
		return aut[state][a-'A'];
	}

	else{
		// while(aut[state][a-'a'+26] == 0){
		// 	state = fail[state];
		// }
		return aut[state][a-'a'+26];		
	}
}

char text[50010];
int main(){

	scanf("%d",&np);
	for(int i = 0; i < np; i++)
		scanf("%s",pat[i]);
	init();
	long long int freq[500] = {0};
	int nsong;
	scanf("%d",&nsong);
	for(int i = 0; i < nsong; i++){
		int state = 1;
		scanf("%s",text);
		for(int i = 0; text[i] != '\0'; i++){
			state = nextstate(state,text[i]);
			set<int>::iterator it;

			for(it = mat[state].begin(); it != mat[state].end(); it++){
				freq[*it]++;
			}

		}
	}

	for(int i = 0; i < np ;i++){
		printf("%lld\n",freq[i]);
	}
	return 0;	
}