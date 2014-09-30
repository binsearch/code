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
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;
#define vvi vector<vector<int> > 
#define vi vector<int>
//intializing ---- vvi res(k, vi(k,0))
#define rep(i,a,b) for(int i = a; i < b; i++)

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=getchar_unlocked(),sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=getchar_unlocked();}
	while( ch >= '0' && ch <= '9' )
	n=(n<<3)+(n<<1)+ ch-'0', ch=getchar_unlocked();
	n=n*sign;
}

int main(){

	int t;
	cin >> t;
	while(t--){
		string s;
		cin >> s;

		int m = 0;
		int ind = -1;

		for(int i = 0; i < s.size(); i++){
			if(s[i] > m) {
				m = s[i];
				ind = i;
			}
			else if(s[i] == m){
				int j = 1;
				int temp = -1;
				while((i+j)%s.size() != i){
					// cout << i + j << endl;
					if(i+j < s.size() && s[i+j] == m){
						temp = (i+j);
					}
					if(s[(i+j)%s.size()] > s[(ind+j)%s.size()]){
						ind = i;
						if(temp != -1) i = temp;
						else i = i + j;
						i--;
						break;
					}
					else if(s[(i+j)%s.size()] < s[(ind+j)%s.size()]){
						if(temp != -1) i = temp; 
						else i = i + j;
						i--;
						break;
					}
					j++;
				}
			}
		}

		for(int i = ind; s[i] != '\0'; i++){
			cout << s[i];
		}

		for(int i = 0; i < ind; i++)
			cout << s[i];
		cout << endl;

	}

	return 0;	
}