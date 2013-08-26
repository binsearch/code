#include <iostream>
#include <vector>
using namespace std;
int main(){
	int d;
	int sumTime;
	std::vector<int> mins;
	std::vector<int> maxs;
	std::vector<int> sol;
	cin >> d;
	cin >> sumTime;
	
	int max = 0;
	int min = 0;
	for(int i = 0; i < d; i++){
		int tmin;
		int tmax;
		cin >> tmin;
		cin >> tmax;
		mins.push_back(tmin);
		maxs.push_back(tmax);
		sol.push_back(tmin);
		min+= tmin;
		max+= tmax;
	}
	if(sumTime<=max && sumTime>=min){
		cout << "YES" << endl;
		int diff = sumTime-min;

		for(int i = 0; i < d; i++){
			if(diff <= 0)break;
			int inc = maxs[i]-mins[i];
			if(inc >= diff){
				sol[i]+= diff;
				break;
			}

			else{
				diff = diff - inc;
				sol[i] = maxs[i];
			}

		}

		for(int i = 0; i < d; i++){
			cout << sol[i] << " ";
		}
		cout << endl;

	}

	else{
		cout << "NO" << endl;
	}
	return 0;
}