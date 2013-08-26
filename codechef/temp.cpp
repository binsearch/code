#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#define x getchar_unlocked()
#define lli unsigned long long int
#define mod 1000000007
using namespace std;
inline void inp(lli &n ) {//fast input function
	n=0;
	lli ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

lli pow(lli a,lli p,lli n) {
	if(p==0)
		return 1%n;
	if(a==0)
		return 0;
	lli result=1;
	while(p>0){
		if(p%2!=0)
			result=(result*a)%n;
		p=(p>>1);
		a=(a*a)%n;
	}
	return result;
}

int main() {
	lli t,up,d,n,m,A[40],B[40],C[40];
	lli ans,val;
	inp(t);
	while(t--) {
	inp(up);
	inp(d);
	inp(m);
	inp(n);
	for(int i=0;i<n;i++) {
		A[i]=up/n;
		B[i]=pow((lli)i,d,n);
		C[i]=0;
	}
	for(int i=0;i<=(up%n);i++) {
		A[i]++;
		//B[i]=pow(i,d,n);
		//cout<<i<<" "<<d<<" "<<n<<endl;
		//cout<<i<<" "<<A[i]<<" "<<B[i]<<endl;
	}
	for(int i=0;i<n;i++) {
		//cout<<i<<" y "<<B[i]<<" "<<A[i]<<endl;
		C[B[i]]+=A[i];
	}

	ans=0;
	//int l=min(n,up+1);
	for(int i=0;i<n ;i++) {
		for(int j=0;j<n;j++) {
			for(int k=0;k<n ;k++) {
			if((i+j+k)%n==m) {
			//cout<<i<<" "<<j<<" "<<k<<endl;
			//cout<<C[i]<<" "<<C[j]<<" "<<C[k]<<endl;
			val=(C[i]*C[j])%mod;
			//val%=mod;
			val=(val*C[k])%mod;
			//val%=mod;
			ans=(ans+val)%mod;
			}
			}
			}
		}
		cout<<ans<<endl;
	}
	 
	return 0;
}