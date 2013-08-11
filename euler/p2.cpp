#include <iostream>
using namespace std;
int main(){

	int limit = 4000000;
	int f1 = 1;
	int f2 = 2;
	long long int count = 0;
	count = count + 2;
	int next;
	while(1){
		cout << next << endl;
		next = f1 + f2;
		f1 = f2;
		f2 = next;
		if(next > limit)
			break;
		if(next % 2 == 0){
			count = count + next;
		}
	}

	cout << count << endl;
	return 0;	

}