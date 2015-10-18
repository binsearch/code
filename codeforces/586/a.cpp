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

int main(){
    int n;
    cin >> n;
    int a[110];
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
    }

    int ans = 0;
    int mode = 0;

    for(int i = 0; i < n-1; i++){
        if(a[i] == 1){
            if(mode == 0) mode = 1;
        }
        if(a[i] == 0 && a[i+1] == 0){
            mode = 0;
        }
        if(mode) ans++;
        
    }
    ans = ans + a[n-1];
    cout << ans << endl;

    return 0;   
}