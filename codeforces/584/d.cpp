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

int is_prime(int n){
    if(n == 1) return 0;
    for(int i = 2; i <= sqrt(n)+1 && i < n; i++)
        if(n%i == 0) return 0;
    return 1;
}


int main(){
    int n;
    cin >> n;
    int t = n;
    while(!is_prime(t)){
        t--;
    }

    int k = 1;
    int ans[3];
    if(n - t == 0)
        ans[0] = n;
    else{
        int dif = n - t;
        ans[0] = t;
        for(int i = 2; i <= dif; i++){
            if(is_prime(i) && is_prime(dif-i)){
                k = 3;
                ans[1] = i;
                ans[2] = dif-i;
                break;
            }
        }
        if(ans[2] == 0)
            k = 2;
    }
    cout << k << endl;
    for(int i = 0; i < k; i++){
        cout << ans[i] << " ";
    }
    cout << endl;


    return 0;   
}