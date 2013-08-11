#include <iostream>
using namespace std;
int exp(int x,int pow,int mod){
	
	x = x % mod;
	if(pow == 0){
		return 1;
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

int eqPairs(int x1, int x2, int x3){
	int no;
	no = 0;
	if(x1 == x2){
		no++;
	}
	if(x2 == x3){
		no++;
	}

	if(x3 == x1){
		no++;
	}

	return no;
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
		long long int count = 0;
		long long int subcount = 0;
		int rem = upper%n;
		int quo = upper/n;
		for(int j = 0; j < n; j++){
			int temp1 = exp(j,d,n);
			for(int k = 0; k <= j; k++){
				int temp2 = exp(k,d,n);
				for(int l = 0; l <= k; l++){
					int temp3 = exp(l,d,n);
					if((temp1+temp2+temp3)%n == m){
						int comb = eqPairs(j,k,l);
						if(comb == 0){	
							count = count + 6;
						}

						if(comb == 1){
							count = count + 3;
						}

						if(comb == 3){
							count++;
						}
					}
				}
			}

			if(rem == j){
				subcount = count;
			}


		}

		long long int fcount;
		fcount  = ((count)*quo)%1000000007; 
		fcount = (fcount + subcount)%1000000007;
		cout << fcount << endl;
	}
	return 0;

}