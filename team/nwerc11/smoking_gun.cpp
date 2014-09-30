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
typedef pair<long long int,long long int> pll;

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

lli dist(pll a, pll b){
  lli ans = (a.first-b.first)*(a.first-b.first) + (a.second - b.second)*(a.second - b.second);
  return ans;
}


int main(){

  int t;
  cin >> t;

  while(t--){
    // map<string, int> names;
    map<int,string> indices;
    int n,m;
    cin >> n >> m;
    map<string, pll> pos;

    for(int i = 0; i < n; i++){
      string temp;
      cin >> temp;
      int x,y;
      cin >> x >> y;
      pos[temp] = pll(x,y);
    }

    int g[110][110] = {0};
    int d[110] ={0};
    int cnt = 0;
    map<string,int> graph_names;
    for(int i = 0; i < m; i++){
      string temp, s1,s2,s3;
      cin >> s1 >> temp >> s2 >> temp >> temp >> s3;

      int g_s2_ind, g_s3_ind;
      if(graph_names.find(s2) != graph_names.end()) g_s2_ind = graph_names[s2];
      else {
      	g_s2_ind = cnt;
      	indices[cnt] = s2;
      	graph_names[s2] = cnt;
      	cnt++;
      }

			if(graph_names.find(s3) != graph_names.end()) g_s3_ind = graph_names[s3];
			else {
				g_s3_ind = cnt;
				indices[cnt] = s3;
				graph_names[s3] = cnt;
				cnt++;
			}

      if(dist(pos[s1],pos[s2]) >= dist(pos[s1],pos[s3])) {
        g[g_s2_ind][g_s3_ind] = 1; 
        d[g_s3_ind]++;
      }
    }
    int flag = 0;
    int ord[110];
    n = cnt;


    for(int j = 0; j < n; j++){
      int temp = -1;
      for(int i = 0; i < n; i++){
        if(d[i] == 0) temp = i;
      }
      if(temp == -1){
        flag = 1;
        break;
      }
      
      ord[j] = temp;
      d[temp] = -1;
      for(int i = 0; i < n; i++)
       if(g[temp][i]) d[i]--; 
    }
     
    if(flag) cout << "IMPOSSIBLE" << endl;
    else {
      for(int i = 0; i < n -1 ; i++){
        if(!g[ord[i]][ord[i+1]]) flag = 1;
      }
      if(flag) cout << "UNKNOWN" << endl;
      else {
        for(int i = 0; i < n; i++){
          cout << indices[i] << " "; 
        }
        cout << endl;
      }
    }
  }

	return 0;	
}
