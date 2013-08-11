#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
	int no_of_t;
	cin >> no_of_t;
	for(int i = 0; i < no_of_t; i++){
		int n;
		int m;
		cin >> n;
		cin >> m;
		vector<int> rooms;
		for(int ro = 0; ro < m; ro++){
			int temp;
			cin >> temp;
			rooms.push_back(temp);
		}

		vector<vector<int> > vols;//content litres

		for(int j =0 ; j < n; j++){
			int bCount;
			cin >> bCount;
			std::vector<int> temp;
			for(int k = 0; k < bCount; k++){
				int bvol;
				cin >> bvol;
				temp.push_back(bvol);
			}
			sort(temp.begin(),temp.end());
			vols.push_back(temp);
		}
		int sum = 0;
		for(int j = 0; j < m;j++){
			vector<int> temp;
			temp = vols[rooms[j]];
			if(temp.size() != 0){
				sum = sum + temp[temp.size() - 1];
				vols[rooms[j]].erase(vols[rooms[j]].begin()+(temp.size() - 1));
			}
		}

		cout << sum << endl;



	}

	return 0;

}