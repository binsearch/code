#include <iostream>
using namespace std;

#define MAX_NUM 218000 // 200

// array will be initialized to 0 being global
int primes[MAX_NUM];

void gen_sieve_primes(void)
{
    for (int p=2; p<MAX_NUM; p++) // for all elements in array
    {
        if(primes[p] == 0) // it is not multiple of any other prime
            primes[p] = 1; // mark it as prime

        // mark all multiples of prime selected above as non primes
        int c=2;
        int mul = p * c;
        for(; mul < MAX_NUM;)
        {
            primes[mul] = -1;
            c++;
            mul = p*c;
        }
    }
}






/*-----------------------------------------------------------------------------------------------------------------------------------*/

int comb (int n){
	if(n == 0 || n == 1 || n == 2 || n == 3){ 
		return 1;
	}
	else{
		return (comb(n-1) + comb(n-4));
	}
}

int main(){
	int n,no_of_t;
	cin >> no_of_t;
	gen_sieve_primes();
	int combs;
	int count;
	for(int i =0; i < no_of_t; i++){
		cin >> n;
		count = 0;
		combs = comb(n);
		for(int j =2; j <= combs; j++){
			if(primes[j] == 1){

				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}

