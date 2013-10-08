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
inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
	n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

struct  point
{
	int index;
	lli px;
	lli py;
};
bool comp(point p1, point p2){
	return p1.px < p2.px;
}

long long int dist(point p1, point p2){

	return (p1.px-p2.px)*(p1.px-p2.px)  + (p1.py-p2.py)*(p1.py-p2.py);

}

struct classcomp {
  bool operator() (const point& p1, const point& p2) const{
  	return p1.py < p2.py;
  }
};

int main(){
	int n;
	inp(n);
	point pts[50000];
	for (int i = 0; i < n; ++i)
	{	
		pts[i].index = i;
		scanf("%lld", &pts[i].px);
		scanf("%lld", &pts[i].py);
	}

	sort(pts, pts + n, comp);
	set<point,classcomp> strip;
	long long int d = 1e15;
	int left = 0;
	strip.insert(pts[0]);
	int min1;
	int min2;
	for(int i = 1; i < n; i++){
		for(; left < i && pts[i].px-pts[left].px > sqrt(d); left++)
			strip.erase(pts[left]);
		
		point temp;
		temp.index = 0;
		temp.px = pts[i].px-sqrt(d);
		temp.py = pts[i].py-sqrt(d);

		for( set<point>::iterator it = strip.lower_bound(temp);
		 it->py - pts[i].py <= sqrt(d) && it!= strip.end(); it++ ){
			
			if(dist(pts[i],*it) < d){
				min1 = it->index;
				min2 = pts[i].index;
				d = dist(pts[i],*it);
			}

		}
		strip.insert(pts[i]);
	}

	if(min1 > min2){
		int temp = min1;
		min1 = min2;
		min2 = temp;
	}

	printf("%d %d %.6f\n", min1, min2 , sqrt(d));



	return 0;	
}