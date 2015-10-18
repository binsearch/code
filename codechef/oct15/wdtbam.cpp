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
        char ans[1010];
        char chef[1010];
        for(int i = 0; i < n; i++)
            cin >> ans[i];
        int cor_ans = 0;
        for(int i = 0; i < n; i++){
            cin >> chef[i];
            if(chef[i] == ans[i])
                cor_ans++;
        }
        int mon[1010];
        for(int i = 0; i <= n; i++)
            cin >> mon[i];
        int win = -1;
        for(int i = 0; i <= cor_ans; i++){
            if(win < mon[i])
                win = mon[i];
        }
        if(cor_ans == n)
            cout << mon[n] << endl;
        else
            cout << win << endl;
    }


    return 0;   
}