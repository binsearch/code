#include <vector>
#include <list>
#include <map>
#include <set>
#include <bitset>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <queue>
using namespace std;
typedef long long int lli;
typedef pair<int,int> ii;
inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
	n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

bool check(ii a,ii b) {

	if(b.second==0) {
		if(a.second)
			return true;
		return a.first>b.first;
	}
	if(a.second==0)
		return false;
	lli n,m;
	n=(lli)a.first*(lli)b.second;
	m=(lli)b.first*(lli)a.second;

	if(n>m)
		return true;
	if(n==m) {
		if((a.first+a.second)>(b.first+b.second))
			return true;
	}
	return false;
}
int main(){
	int t,len;
	string s;
	inp(t);
	int A[1000000][2];

	ii val,ans;

	while(t--) {
		cin>>s;
		len=s.length();
	

		for(int i=0;i<len;i++) {
			if(s[i]=='A' || s[i]=='G')
				s[i]=1;
			else
				s[i]=0;
		}

		if(s[0]==0) {
			A[0][0]=1;
			A[0][1]=0;
		}
		else {
			A[0][0]=0;
			A[0][1]=1;			
		}

		for(int i=1;i<len;i++) {
			A[i][0]=A[i-1][0];
			A[i][1]=A[i-1][1];
			A[i][s[i]]++;
		}

		ans=ii(A[0][1],A[0][0]);

		for(int i=0;i<len;i++) {
			for(int j=i;j<len;j++) {
				val.first=A[j][1];
				val.second=A[j][0];

				if(i) {
					val.first-=A[i-1][1];
					val.second-=A[i-1][0];
				}

				// cout<<val.first<<" "<<val.second<<endl;
				// cout<<ans.first<<" "<<ans.second<<endl;
				if(check(val,ans)) {
					ans=val;
				}
			}
		}

		printf("%d %d\n", ans.first,ans.second);
	}

	return 0;	
}