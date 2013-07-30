#include <iostream>
using namespace std;
int main(){
	float in;
	cin >> in;
	float sum;
	int i;
	while(in != 0.00){
		sum = 0;
		for(i = 1; sum < in; i++){
			sum = sum + 1.0/(i+1);
			//cout << sum << endl;
		}

		cout << i-1 << " card(s)" << endl;
		cin >> in;
	}

	return 0;
}