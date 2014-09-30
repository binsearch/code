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
typedef pair<char,int> pci;
#define vvi vector<vector<int> > 
#define vi vector<int>

std::vector<std::vector<pci> > trie;


bool insert(string s){
  int curr_node = 0;
  for(int i = 0; i < s.size(); i++){
    int flag = 1;
    for(int j = 0; j < trie[curr_node].size(); j++){
      if(trie[curr_node][j].first == s[i]){
        flag = 0;
        curr_node = trie[curr_node][j].second;
        break;
      }
    }
    if(flag){
      //insert a new node.
      trie[curr_node].push_back(pci(s[i], trie.size()));
      curr_node = trie.size();
      std::vector<pci> temp;
      temp.clear();
      trie.push_back(temp);
    }
  }
}

bool winlose(int node, int status){
  if(trie[node].empty()){
    if(status){
      return true;
    }
    else{
      return false;
    }
  }

  bool ans = false;

  for(int i = 0; i < trie[node].size(); i++){
    ans = ans || (! winlose(trie[node][i].second, status));
  }

  return ans;
}

int main(){

  int n,k;
  cin >> n >> k;
  std::vector<pci> temp1;
  temp1.clear();
  trie.push_back(temp1);
  for (int i = 0; i < n; ++i)
  {
    string temp;
    cin >> temp;
    insert(temp);
  }

  //print trie
  // for (int i = 0; i < trie.size(); ++i)
  // {
  //   cout << "node: " << i << endl;
  //   for (int j = 0; j < trie[i].size(); ++j)
  //   {
  //     cout << trie[i][j].first << " " << trie[i][j].second << ";";
  //   }
  //   cout << endl;
  // }

  bool win = winlose(0,0);
  bool lose = winlose(0,1);

  if(win && lose) cout << "First" << endl;
  else if(!win) cout << "Second" << endl;
  else if(win && !lose){
    if(k%2 == 0) cout << "Second" << endl;
    else cout << "First" << endl;
  }



	return 0;	
}
