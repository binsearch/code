#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#define lim 100
using namespace std;
int A[lim+1]={0};
int B[lim],cnt=0;

inline void inp()
int main() {
	int k=sqrt(lim);
	for(int i=2;i<=k;i++) {
		if(A[i]==0) {
			for(int j=i*i;j<=lim;j+=i) {
				A[j]=i;
			}
		}
	}

	//A[n]=0;

	//cout<<A[12]<<endl;

	int n=12;

	while(1) {
		cin>>n;
		k=n;
		int ans=1;

		while(k!=1) {
			//cout<<k<<endl;
			if(A[k]==0) {
				ans=ans*2;
				k=1;
			}

			else {
				int val=A[k],pow=1;
				while(k%val==0) {
					pow++;
					k/=val;
				}
				ans=ans*pow;
			}
		}

		cout<<ans<<endl;

	}

	for(int i=2;i<=lim;i++) {
		if(A[i]==0) {
			B[cnt++]=i;
			cout<<i<<endl;
		}
	}

	cout<<cnt<<endl;
	
	return 0;
}