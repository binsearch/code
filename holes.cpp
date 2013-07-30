#include<iostream>
using namespace std;
int main(){
	int hole[26];
	string input;
	int no_of_t,sum;
	
	cin >> no_of_t;
	
	for(int i = 0; i < no_of_t; i++){
		cin >> input;
		sum = 0;
		for(int j = 0; j < input.length(); j++){
			
			if( input[j] == 'A'){
				sum++;
			}
			
			if( input[j] == 'B'){
				sum = sum+2;
			}
			
			if(input[j] == 'D'){
				sum++;
			}
			
			if(input[j] == 'O'){
				sum++;
			}
			
			if(input[j] == 'P'){
				sum++;
			}
			
			if(input[j] == 'Q'){
				sum++;
			}
			
			if(input[j] == 'R'){
				sum++;
			}
			
		}
		
		cout << sum << endl;
	}
	
	return 0;
}
