#include<iostream>
#include<stdio.h>
using namespace std;

int main(){
	
	int a[1000001];
	int no_of_t,num;
	
	for(int i = 0; i < 1000001; i++)
		a[i] = 0;
	
	cin >> no_of_t;
	
	for(int i= 0; i < no_of_t; i++){
	
		scanf("%d",&num);
		a[num]++;
	}
	
	
	for(int i = 0; i < 1000001 ; i++){
		
		if(a[i] != 0){
			
			
			while(a[i] != 0){
			
			
				printf("%d\n", i);
				a[i] --;
			}
		}
	}
	return 0;
}
