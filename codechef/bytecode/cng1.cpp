#include <iostream>
#include <vector>
using namespace std;
int main(){

	int no_of_t;
	cin >> no_of_t;


	for (int i = 0; i < no_of_t; i++)
	{
		/* code */
	
		vector<int> flag;
		flag.push_back(1);
		int p1;
		cin >> p1;
		int p2;
		cin >> p2;
		int lo;
		lo = p1;
		if(p1 > p2){
			lo = p2;
		}

		int count = 0;
		int high = -1;
		for(int j = 1; j < 10; j++){
			int flag1 = 0;
			//cout << count << endl;
			if(j-p1 >= 0){
				if(flag[j-p1] == 1){

					flag1 = 1;
				}
			}

			if(j-p2 >=0){
				if(flag[j-p2] == 1){
					flag1 = 1;
				}
			}

			if(flag1 == 1){
				flag.push_back(1);
				count++;

			}

			if(flag1 == 0){
				flag.push_back(0);
				count = 0;
				high = j;
			}
			flag1 = 0;
			if(count == lo){
				break;
			}
		}

		cout << high << endl;

	}

	return 0;
}