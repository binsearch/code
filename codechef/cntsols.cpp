#include <iostream>
#include <vector>
using namespace std;
int exp(int x,int pow,int mod){
	
	x = x % mod;
	if(pow == 0){
		return 1%mod;
	}

	else if(pow%2 == 0){
		int temp;
		temp = exp(x,pow/2,mod);
		return (temp*temp)%mod;
	}

	else{
		return (x*exp(x,pow-1,mod))%mod;
	}
}



int main(){
	int no_of_t;
	cin >> no_of_t;
	for(int i = 0; i < no_of_t; i++){
		int upper;
		cin >> upper;
		int d;
		cin >> d;
		int m;
		cin >> m;
		int n;
		cin >> n;
		vector<long long int> group;
		group.assign(n,upper/n);
		for(int j = 0; j <= upper%n; j++){
			group[j]++;
		}

		vector<long long int> exGroup;
		exGroup.assign(n,0);
		for(int j = 0; j < n; j++){
			exGroup[exp(j,d,n)]+= group[j];
		}

		long long int count;
		count = 0;
		for(int j = 0; j < n; j++){
			for(int k = 0; k < n; k++){
				for(int l = 0; l < n; l++){
					if((j+k+l)%n == m){
						long long int temp;
						temp = (exGroup[j]*exGroup[k])%	1000000007;
						temp = (temp * exGroup[l])%1000000007;
						count = (count + temp)%1000000007; 				
					}
				}
			}

		}

		
		cout << count << endl;
	}
	return 0;

}