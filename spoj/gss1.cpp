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

struct data{
	int sum;
	int suff;
	int pref;
	int max;
};

data seg[200100];
int arr[50005];

data combine(data d1, data d2){

	data res;
	res.sum = d1.sum + d2.sum;
	if(d2.suff > d2.sum + d1.suff){
		res.suff = d2.suff;
	}
	else{
		res.suff = d2.sum + d1.suff;
	}

	if(d1.pref > d1.sum + d2.pref){
		res.pref = d1.pref;
	}
	else{
		res.pref = d1.sum + d2.pref;
	}

	int tempm = max(d1.max,d2.max);
	if(d1.suff + d2.pref > tempm){
		res.max = d1.suff + d2.pref;
	}
	else{
		res.max = tempm;
	}
	return res;

}


void build(int left, int right, int index){
	if(left == right){
		data temp;
		temp.sum = arr[left];
		temp.suff = arr[left];
		temp.pref = arr[left];
		temp.max = arr[left];
		seg[index]=  temp;
	}

	else{
		
		int mid = (left+right)/2;
		build(left,mid,2*index);
		build(mid+1,right,2*index+1);
		seg[index] = combine(seg[index*2],seg[index*2+1]);

	}
}

data query(int ql, int qr, int left, int right, int index){
	if(ql == left && qr == right){
		return seg[index];
	}
	int mid = (left+right)/2;
	if(qr <= mid){
		return query(ql,qr,left,mid,index*2);
	}
	if(ql > mid){
		return query(ql,qr,mid+1,right,index*2+1);
	}
	return combine(query(ql,mid,left,mid,index*2),query(mid+1,qr,mid+1,right,index*2+1));
}


void update(int arrind, int val, int left, int right, int index){
	if(right == arrind && left == arrind){
		data temp;
		temp.sum = val;
		temp.suff = val;
		temp.pref = val;
		temp.max = val;
		seg[index]= temp;
	}
	else{
		int mid = (left+right)/2;
		if(arrind > mid){
			update(arrind,val,mid+1,right,2*index+1);
		}
		else{
			update(arrind,val,left,mid,2*index);
		}
		seg[index] = combine(seg[index*2],seg[index*2+1]);
	}

}











int main(){

	int n;
	inp(n);
	for(int i = 0; i < n; i++){
		inp(arr[i]);
	}

	lli m;
	cin >> m;
	build(0,n-1,1);
	for(lli i = 0; i < m; i++){
		int left,choice;
		int right;
		inp(choice);
		inp(left);
		inp(right);
		if(choice == 0){
			update(left-1,right,0,n-1,1);
		}
		else{
			data res = query(left-1,right-1,0,n-1,1);
			printf("%d\n",res.max);	
		}
		
	}



return 0;	
}