#include <iostream>
using namespace std;
int main(){
	int no_of_t;
	cin >> no_of_t;
	for(int i = 0; i < no_of_t; i++){
		float nCost;
		cin >> nCost;
		int mins;
		cin >> mins;
		int nPlans;
		cin >> nPlans;
		float savings;
		int plan_num;
		plan_num = 0;
		savings = 0;
		for(int j = 0; j < nPlans; j++){
			int months;
			cin >> months;
			float cost_min;
			cin >> cost_min;
			int cost;
			cin >> cost;
			float profit;
			profit = (months * (nCost - cost_min) * mins) - cost;
			if(profit > 0){
				if((profit / months) > savings){
					savings = profit / months;
					plan_num = j + 1;
				}
			}
		}

		cout << plan_num << endl;

	}

	return 0;
}