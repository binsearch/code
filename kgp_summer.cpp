#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int distance(pair<int,int> x, pair<int,int> y){

	int dist = 0;

	dist = dist + (x.first - y.first) * (x.first - y.first);
	dist = dist  + (x.second - y.second) * (x.second - y.second);
	return dist;
}


// struct vertex
// {
// 	/* data */
// 	int in_cloud;
// 	int x;
// 	int y;
// 	int sweat;
// };
int main(){

	int no_of_t;
	int no_trees;
	
	int x_co;
	int y_co;
	int index;
	int d;
	int d_adj;
	pair<int,int> temp;

	vector<int> sweat(no_trees+2,1000000000);
	std::vector<int> marker(no_trees+2,0);
	vector<pair<int,int> > trees;
	priority_queue<pair<int,int>, vector<pair<int,int> >, greater<pair<int, int> > > adj;
	
	cin >> no_of_t;
	for(int i = 0; i < no_of_t; i++){
		cin >> no_trees;
		
		trees.clear();
		
		sweat.assign(no_trees+2,1000000000);
		marker.assign(no_trees+2,0);
		// adj = priority_queue <pair<int,int>, vector<pair<int,int> >, greater<pair<int, int> > >();
		for(int i = 0; i < no_trees + 2; i++){
			cin >> x_co;
			cin >> y_co;
			
			trees.push_back(make_pair(x_co,y_co));
		}

		
		temp = trees[0];
		trees[0] = trees[no_trees];
		trees[no_trees] = temp;
		adj.push(make_pair(0,0));
		// cout << trees[0].first << " " << trees[0].second << endl;
		while(!adj.empty()){
			temp = adj.top();
			adj.pop();
			// cout << "top" << temp.first << " " << temp.second << endl;
			index = temp.second;
			d = temp.first;
			
			//cout << index << endl;
			if(marker[index] == 0){
				sweat[index] = d;
				marker[index] = 1;
				// cout << "index" << " " <<index << endl;
				if(index == no_trees + 1){break;}
				for(int i = 0; i < no_trees + 2; i++){
					if(marker[i] == 0){
						// cout << trees[index].first << endl;
						// cout << trees[i].first << endl;
						// cout << trees[index].second << endl;
						// cout << trees[i].second << endl;
						d_adj = d + (((trees[index].first - trees[i].first)*(trees[index].first - trees[i].first)) + ((trees[index].second - trees[i].second)*(trees[index].second - trees[i].second)));
						if(d_adj < sweat[i]){
							adj.push(make_pair(d_adj,i));
							// cout << "push" << i << " " << d_adj << endl;
						}
					}
				}

			}



		}


		cout << sweat[no_trees+1] << endl;

		while(!adj.empty()){
			adj.pop();
		}
	}





	return 0;
	


	
}