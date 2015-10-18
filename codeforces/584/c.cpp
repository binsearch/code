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
char rand_char(char c1, char c2){
    char ans = 'a';
    for(ans = 'a'; ans <= 'z'; ans++){
        if(ans != c1 && ans != c2)
            return ans;
    }
}


int main(){
    int n, t;
    cin >> n >> t;
    string in[2], dif[2], s;
    cin >> in[0] >> in[1];
    string d_ans, s_ans;
    string ans;
    for(int i = 0; i < n; i++){
        if(in[0][i] != in[1][i]){
            dif[0].push_back(in[0][i]);
            dif[1].push_back(in[1][i]);
        }
        else
            s.push_back(in[0][i]);

    }   
    int d = dif[0].size();
    if(t < (d+1)/2)
        cout << -1 << endl;
    else{
        int y = min(t, d);

        for(int i = 0; i < 2 * (d - y); i++){
            d_ans.push_back(dif[i%2][i]);
        }
        for(int i = 2*(d-y); i < d; i++){
            d_ans.push_back(rand_char(dif[0][i], dif[1][i]));
        }
        for(int i = d; i < d + t - y; i++){
            s_ans.push_back(rand_char(s[i-d], s[i-d]));
        }
        for(int i = d + t -y; i < n; i++){
            s_ans.push_back(s[i-d]);
        }

        int d_cnt = 0;
        int s_cnt = 0;
        for(int i = 0; i < n; i++){
            if(in[0][i] == in[1][i]){
                ans.push_back(s_ans[s_cnt]);
                s_cnt++;
            }
            else{
                ans.push_back(d_ans[d_cnt]);
                d_cnt++;
            }
        }
        cout << ans << endl;
    }



    return 0;   
}