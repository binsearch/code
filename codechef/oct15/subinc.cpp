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
        int n;
        cin >> n;
        int a[100010];
        for (int i = 0; i < n; ++i)
        {
            cin >> a[i];
        }
        int len = 1;
        lli ans = 1;
        for(int i = 1; i < n; i++){
            if(a[i] >= a[i-1])
                len++;
            else
                len = 1;

            ans+= (lli) len;

        }
        cout << ans << endl;
    }

    return 0;   
}