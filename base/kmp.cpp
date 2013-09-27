#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
typedef long long int lli;
using namespace std;
inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
	n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int* fail;
char* pat;
int n;
void build(){
	fail[0] = 0;
	for(int i = 1; i < n; i++){
		int len;
		len = fail[i-1];
		while(pat[len] != pat[i]){
			if(len == 0){
				len = -1;
				break;
			}
			else{
				len = fail[len-1];	
			}
		}
		fail[i] = len+1;
	}
}

int main(){

	while(scanf("%d",&n) != EOF){

		pat = new char[n+10];
		scanf("%s\n", pat);
		fail = new int[n];
		build();
		int i = 0;
		long long int num = 0;
		
		i = 0;
		while(1){
			char ch = getchar_unlocked();
			if(ch == '\n')
				break;
			if(ch == pat[i]){
				i++;
			}
			
			else{
					
				while(pat[i] != ch){
					if(i == 0){
						i = -1;
						break;
					}	
					i = fail[i-1];
				}

				i++;
				num++;
				continue;

			}
			
			if(i == n){
				printf("%lld\n",num-n+1);
				i = fail[n-1]; 
			}

			num++;
		}

		// delete [] 
		printf("\n");
	}
	return 0;	
}