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
#define INF 110

int dp[60][3];
char g[5][INF];
int n, k;

int recurse(int tim, int p_y){
    int p_x = 3*tim;
    
    // if(g[p_y][p_x] != '.') return 0;
    if(p_x >= n) return 1;
    
    if(dp[tim][p_y] != -1)
        return dp[tim][p_y];

    if(g[p_y][p_x + 1] != '.'){
        dp[tim][p_y] = 0;
        return dp[tim][p_y];
    }

    int ans = 0;
    for(int j = -1; j < 2; j+= 1){
        if(g[p_y + j][p_x+1] == '.' && g[p_y + j][p_x+2] == '.' && g[p_y+j][p_x+3] == '.')
            // cout << p_y+j << " " << p_x << endl;
            if(recurse(tim+1, p_y+j))
                ans = 1;
    }
    dp[tim][p_y] = ans;
    return ans;
    
}


int main(){
    int t;
    cin >> t;
    while(t--){
        memset(dp, -1, sizeof(dp));
        int p_y;
        cin >> n >> k;

        for(int j = 0; j < 5; j++){
            for(int i = 0; i < INF; i++){
                if(j == 0 || j == 4)
                    g[j][i] = 'A';
                else
                    g[j][i] = '.';
            }
        }

        for(int j = 1; j < 4; j++){
            for(int i = 0; i < n; i++){
                cin >> g[j][i]; 
                if (g[j][i] == 's'){
                    g[j][i] = '.';
                    p_y = j;
                }
            }
        }
        // cout << "p_y " << p_y << endl; 
        int ans = recurse(0,p_y);
        if(ans)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }

    return 0;   
}