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
typedef pair<int,int> pii;
typedef long long int lli;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
	n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}
const int MAX  = 100001;
set<pii> s[MAX];
bool comp(int si, pii val){
	set<pii>::iterator it;
	for(it = s[si].begin(); it != s[si].end(); it++){
		if(val.first > it->first && val.second > it->second) return true;
		if(val.first <= it->first) return false;
	}
	return false;
}
int findpos(int start, int end, pii val){

	int dist;
	dist = end - start;
	while(dist > 0){
		int mid = start + dist/2;
		if(comp(mid,val)){
			start = mid+1;
		}

		else{
			end = mid;
		}
		dist = end - start;
	}
	return start;

	// if(!comp(start,val))
	// 	return start;
	// if(comp(end,val))
	// 	return end+1;

	// int mid = (start + end)/2;
	// if(comp(mid,val))
	// 	return findpos(mid+1,end,val);
	// else
	// 	return findpos(start+1,mid,val);
	// int cnt = end - start, idx, stp;
	// while(cnt > 0) {
	// idx = start, stp = cnt>>1, idx += stp;
	// if(comp(idx, val)) start = ++idx, cnt -= ++stp;
	// else cnt = stp;
	// }
	// return start;
}
int main(){

	int n;
	inp(n);
	for(int i = 0; i < n; i++){
		int x,y;
		inp(x);
		inp(y);
		pii temp = pii(x,y);
		int pos = findpos(0,i,temp);
		s[pos].insert(temp);
		set<pii>::iterator it = s[pos].find(temp);
		it++;
		while(it != s[pos].end()){
			if(temp.first < it-> first && temp.second < it-> second){
				set<pii>::iterator tmp = --it;
				++it;
				s[pos].erase(it);
				it = tmp;
			}
			it++;
		}
	}

	int cnt = 0;
	
	for(int i = 0; i < n; i++){
		if(s[i].empty()) break;
		cnt++;
	}
	printf("%d\n", cnt);

	return 0;	
}