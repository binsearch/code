#include <iostream>
using namespace std;

int main(){

	long long int a;
	long long int b;
	long long int c;
	cin >> a >> b;
	long long int count = 0;

	while(1){
		//cout << a << " " << b << endl;
		if(b == 0)
			break;
		c = a/b;
		count+= c;
		a = a - b*c;
		if(a == 0){
			break;
		}
		c = b/a;

		count+=c;
		b = b- c*a;
	}
	cout << count << endl;
	return 0;	

}