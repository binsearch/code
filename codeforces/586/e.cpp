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

lli gcd(lli x, lli y){
    if(x % y == 0)
        return y;
    return gcd(y, x%y);
}


int main(){
    lli x,y;
    cin >> x >> y;
    lli g;
    if(x > y)
        g = gcd(x,y);
    else
        g = gcd(y,x);

    if(g != 1)
        cout << "Impossible" << endl;
    else{

        while(x!= 0 && y != 0) {
            if(x > y){
                lli quot = x/y;
                if(x%y == 0) quot--;
                printf("%lld%c", quot, 'A');
                x = x%y;
            }
            else{
                lli quot = y/x;
                if(y%x == 0) quot--;
                printf("%lld%c", quot, 'B');
                y = y % x;
            }
        }
        cout << endl;
    }
    return 0;   
}