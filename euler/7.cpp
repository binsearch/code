#include <iostream>
#include "stdio.h"
#include <math.h>
#define lim 1000000
using namespace std;
int main(){

	int isprime[lim] = {0};
	for(int i = 2; i < sqrt(lim) + 3; i++)
		if(isprime[i] == 0)
			for(int j = i*i; j < lim; j+=i)
				isprime[j] = 1;

	int cnt = 0;
	for(int i = 2; i < lim; i++)
		if(isprime[i] == 0){
			cnt++;
			if(cnt == 10001)
				printf("answer: %d\n", i);
		}

	printf("%d\n", cnt);
	return 0;
}