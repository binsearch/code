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
    int cumm_shop[60];
    memset(cumm_shop, 0, 60);
    for(int i = 1; i < n; i++){
        int t;
        cin >> t;
        cumm_shop[i] = t + cumm_shop[i-1];
    }

    int cumm_house[60];
    memset(cumm_house, 0, 60);
    for(int i = 1; i < n; i++){
        cin >> cumm_house[i];
    }

    int aven[60];
    for(int i = 0; i < n; i++){
        cin >> aven[i];
    }

}