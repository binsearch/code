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
    int v[4010];
    int d[4010];
    int p[4010];

    for(int i = 0; i < n; i++){
        cin >> v[i];
        cin >> d[i];
        cin >> p[i];
    }

    int ord[4010];
    int ans = 0;
    int left[4010];
    memset(left, 0, 4010);
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(p[j] < 0 && left[j] == 0){
                for(int k = j+1; k < n; k++){
                    p[k] = p[k] - d[j];
                }
                left[j] = 1;
            }
        }
        if(p[i] >= 0){
            ord[ans] = i+1;
            ans++;
            int val = v[i];
            for(int j = i+1; j < n && val > 0; j++){
                if(left[j] == 0){
                    p[j] = p[j] - val;
                    val--;
                }
            }
        }
    }

    cout << ans << endl;
    for(int i = 0; i < ans; i++)
        cout << ord[i] << " ";
    cout << endl;

    return 0;
}   