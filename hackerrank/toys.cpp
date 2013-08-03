#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	int n,k;
	cin >> n;
	cin >> k;
	vector<int> prices;
	long long int tot = 0;
	for(int i = 0; i < n; i++){
		int price;
		cin >> price;
		prices.push_back(price);
	}

	sort(prices.begin(), prices.end());
	int i;
	for(i = 0; i < n; i++){
		tot = tot + prices[i];
		if(tot > k)
			break;

	}

	cout << i << endl;
	return 0;
}
