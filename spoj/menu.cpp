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
#define INF 100000000
using namespace std;
typedef long long int lli;
typedef pair<int,int> pii;

int d,n,m;
int check[30][110][60][2];
int dp[30][110][60][2];
int cost[30][110][60][2];
int c[60];
int v[60];

pair<double, int> rec(int days, int mon, int start, int rep){
    if(mon <= 0){
    	return pair<double, int> (-INF, INF);
    }
    if(check[days][mon][start][rep])
        return pair<double, int> (dp[days][mon][start][rep], cost[days][mon][start][rep]);
    double val = -INF;
    int co = INF;
    if(days == 1){
        if(mon >= c[start]){
            return pair<double, int> (v[start], c[start]);
        }
        else
            return pair<double, int>(-INF, INF);
    }

    if(rep == 1){
        double t_val = v[start]*0.5 + rec(days-1, mon-c[start], start, 0).first;
        int t_cost = c[start] + rec(days-1, mon-c[start], start, 0).second;
        if(t_val < rec(days-1, mon-c[start], start, 1).first || (abs(t_val - rec(days-1, mon-c[start], start, 1).first) < 0.4 && t_cost > c[start] + rec(days-1, mon-c[start], start, 1).second)){
        	t_val = rec(days-1, mon-c[start], start, 1).first;
        	t_cost = c[start] + rec(days-1, mon-c[start], start, 1).second;
        }
        if(t_val > val || (abs(t_val - val) < 0.4 && t_cost < co)){
          val = t_val;
        	co = t_cost;	
        }
    }
    else{

        for(int i = 0; i < n; i++){
            if(i != start){
		           double t_val = v[start] + rec(days-1, mon-c[start], i, 0).first;
		           int t_cost = c[start] + rec(days-1, mon-c[start], i, 0).second;
		           if(t_val < v[start] + rec(days-1, mon-c[start], i, 1).first || (abs(t_val - v[start] + rec(days-1, mon-c[start], i, 1).first) < 0.4 && t_cost > c[start] + rec(days-1, mon-c[start], i ,1).second)){
		           	t_val = v[start] + rec(days-1, mon-c[start], i, 1).first;
		           	t_cost = c[start] + rec(days-1, mon-c[start], i, 1).second;
		           }

               if(t_val > val || (abs(t_val-val) < 0.4 && t_cost < co)){
                  val = t_val;
                  co = t_cost;
							 }
            }
        }
    }
    dp[days][mon][start][rep] = val;
    cost[days][mon][start][rep] = co;
    check[days][mon][start][rep] = 1;
    return pair<double, int>(val, co);
}

void backtrack(int days, int mon, int start, int rep){
	if(days == 1)
		cout << start+1 << " ";
	else{
		if(rep){
				int flag = 0;
		    double t_val = v[start]*0.5 + rec(days-1, mon-c[start], start, 0).first;
		    int t_cost = c[start] + rec(days-1, mon-c[start], start, 0).second;
		    if(t_val < rec(days-1, mon-c[start], start, 1).first || (abs(t_val - rec(days-1, mon-c[start], start, 1).first) < 0.4 && t_cost > c[start] + rec(days-1, mon-c[start], start, 1).second)){
		    	t_val = rec(days-1, mon-c[start], start, 1).first;
		    	t_cost = c[start] + rec(days-1, mon-c[start], start, 1).second;
		    	flag = 1;
		    }		    
		    cout << start+1 << " ";
		    backtrack(days-1, mon-c[start], start, flag);
		}
		else{
			double val = -INF;
			int co = INF;
			int req;
			int re_flag;
			for(int i = 0; i < n; i++){
            if(i != start){
               double t_val = v[start] + rec(days-1, mon-c[start], i, 0).first;
               int t_cost = c[start] + rec(days-1, mon-c[start], i, 0).second;
               int flag = 0;
               if(t_val < v[start] + rec(days-1, mon-c[start], i, 1).first || (abs(t_val - v[start] - rec(days-1, mon-c[start], i, 1).first) < 0.4 && t_cost > c[start] + rec(days-1, mon-c[start], i, 1).second)){
               	t_val = v[start] + rec(days-1, mon-c[start], i, 1).first;
               	t_cost = c[start] + rec(days-1, mon-c[start], i ,1).second;
               	flag = 1;
               }

               if(t_val > val || (abs(t_val - val) < 0.4 && t_cost < co)){
               		req = i;
               		re_flag = flag; 
                  val = t_val;
                  co = t_cost;
							 }

            }
      }
      cout << start + 1 << " ";
      backtrack(days-1, mon-c[start], req, re_flag);
		}
	}
}

int main(){
		while(1){
	    cin >> d >> n >> m;
	    if(d == 0 && m == 0 && n == 0) break;
	    
	    memset(check, 0, sizeof check);
	    for(int i = 0; i < n; i++){
	        cin >> c[i] >> v[i];
	    }
	    double ans = -1;
	    int co = INF;
	    int re, re_flag;
	    
	    for( int i = 0; i < n; i++){
	        double t_val = rec(d, m, i , 0).first; 
	        int t_cost = rec(d, m, i, 0).second;
	        int flag = 0;
	        if(t_val < rec(d,m, i, 1).first || (abs(t_val - rec(d, m,i,1).first) < 0.4 && t_cost > rec(d,m,i,1).second)) {
	        	t_val = rec(d, m, i , 1).first;
	     			t_cost = rec(d,m,i,1).second;
	        	flag = 1;
	        }
	        if(ans < t_val || ((abs(ans - t_val) < 0.4) && co > t_cost)) {
	        	re = i;
	        	re_flag = flag;
	        	ans = t_val;
	        	co = t_cost;
	        }

	    }
	    
	    if(ans > -.5){
		    printf("%.1f\n", ans); 
		    backtrack(d, m, re, re_flag);
		  }
		  else{
		  	cout << "0.0" << endl;
		  }
		  cout << endl;
		}
	return 0;	
}
