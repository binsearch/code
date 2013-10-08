#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){

	int n;
	cin >> n;
	int t[100001];
	for(int i = 1; i <= n; i++){
		cin >> t[i];
	}
	int no[100001] = {0};
	int g[100001] = {0};
	for(int i = 1; i <=n ; i++){
		int temp;
		cin >> temp;
		g[i] = temp;
		no[temp]++;
	}	


	for(int i = 1; i <=n ; i++){
		if(no[g[i]] > 1){
			g[i] = 0;
		}
	}

	int max = 0;
	int max_h = 0;
	for(int i = 1; i <= n; i++){
		if(t[i] == 1){
			int v = i;
			int tmax = 1;
			while(1){
				if(g[v] != 0){
					v = g[v];
					tmax++;
				}
				else{
					break;
				}
			}

			if(tmax > max){
				max_h = i;
				max = tmax;
			}
		}
	}

	std::vector<int> path;
	int v = max_h;
	while(1){
		path.push_back(v);
		if(g[v]!= 0){
			v = g[v];
		}
		else{
			break;
		}
	}

	cout << max << endl;
	for(int i = path.size()-1; i >= 0; i--){
		cout << path[i] << " ";
	}
	cout << endl;
	return 0;

}