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
#include <queue>
struct block{
	int x;
	int y;
	int z;
};
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
bool comp(block b1, block b2){
	return (b1.x < b2.x);
}
int main(){

	while(1){
		int n;
		inp(n);
		if(n == 0)
			break;
		int b[3];
		std::vector<block> vals;
		while(n--){
			inp(b[0]);
			inp(b[1]);
			inp(b[2]);
			sort(b,b+3);
			do{
				block temp;
				temp.x = b[0];
				temp.y = b[1];
				temp.z = b[2];
				vals.push_back(temp);
			} while ( std::next_permutation(b,b+3) );


		}
		// cout << 1 << endl;
		sort(vals.begin(), vals.end(),comp);
		int dp[500];
		// cout << 1 << endl;
		for(int i = vals.size()-1; i >= 0; i--){
			int max = vals[i].z;
			for(int j = i+1; j < vals.size(); j++){
				if(vals[j].x > vals[i].x && vals[j].y > vals[i].y){
					if(vals[i].z + dp[j] > max){
						max = vals[i].z + dp[j];
					}
				}
			}
			dp[i] = max;
		}
		// cout << 1 << endl;
		sort(dp,dp+vals.size());
		printf("%d\n", dp[vals.size()-1]);

	}

	return 0;	
}