#include <iostream>
#include <vector>
using namespace std;
int main(){
	std::vector<int> id;
	std::vector<int> id_sum;
	int no_of_t;
	int num;
	int mark;
	int sum;
	int temp;
	cin >> no_of_t;
	for(int i = 0; i < no_of_t; i++){
		id.clear();
		id_sum.clear();
		cin >> num;
		mark = 0;
		for(int j = 0; j < num; j++){
			cin >> temp;
			id.push_back(temp);
			cin >> temp;
			id_sum.push_back(temp);
		}

		for(mark = 0; mark <  num; mark++){
			sum = 0;
			for(int k = 0; k < num; k++){
				if(k == mark)
					continue;
				sum = sum + id[k] - id_sum[k]; 
			}
			if(sum == id_sum[mark])
				break;
		}

		cout << id[mark] << endl;

	}
	

	return 0;

}
