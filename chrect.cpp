#include<iostream>
using namespace std;
int main(){
	int no_of_t;
	int n,m,k;

	cin >> no_of_t;
	
	int total;
	for(int i = 0; i < no_of_t; i++){
		cin >> n;
		cin >> m;
		cin >> k;
		if(n + m <= 3){
			total = 0;
		}
		
		else if(n == 1 || m == 1){
			total = k;
		}

		if((n > 1) && (m > 1)){
			if(k%2 == 0){
				total = k/2;
			}

			else{
				total = k/2 + 1;
			}
		}
		cout << total << endl;
	}

	return 0;
}