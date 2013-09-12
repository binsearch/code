#include<iostream>
#include<math.h>
using namespace std;
int main(){

	int no_t;
	int num;
	int count,add,sum,i;
	cin >> no_t;
	for (int j=0; j< no_t; j++)
	{
		i = 1;
		cin >> num;
		sum  = 0;
		
		while(1){
			
			add = num/pow(5,i);
		
			sum = sum + add;
			if(add == 0) {break;}
			
			i++;
			
			
		}
		cout << sum << endl;
	}
	
	return 0;
}
