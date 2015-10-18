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
#define MAX 5000010
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
int s[MAX];
int ans[MAX];
vi primes;

int main(){
    int t;
    cin >> t;

    for(int i = 0; i < MAX; i++){
        s[i] = 1;
    }
    // cout << s[5] << endl;
    for(int i = 2; i < sqrt(MAX)+2; i++){
        if(s[i]){
            for(int j = i * i; j < MAX; j+=i){
                s[j] = 0;
            }
        }
    }

    for(int i = 2; i < MAX; i++){
        if(s[i] && i %4 == 1)
            primes.push_back(i);
    }

    memset(ans, 0, sizeof(ans));
    for(int i = 0; i < primes.size(); i++){
            for(int j = primes[i]; j < MAX; j+=primes[i]){
                ans[j] = 1;
            }
    }

    while(t--){
        int n;
        scanf("%d", &n);
        if(ans[n])
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;   
}