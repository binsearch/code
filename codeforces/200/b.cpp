#include <iostream>
using namespace std;

int main(){

	int a,b,c;
	cin >> a >> b >> c;
	int flag = 0;
	for(int i = 0; i <= b; i++){
		if(a-i < 0 || c-b+i < 0)
			continue;
		if(a-i == c-b+i){
			flag =1;
			cout << i << " " << b-i << " " << a-i << endl; 
			break;
		}

	}
	if(flag == 0){
		cout << "Impossible" << endl;
	}
	return 0;	

}