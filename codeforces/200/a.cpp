#include <iostream>
using namespace std;

int main(){
	int n;
	cin >> n;

	int prev;
	int g = 1;
	cin >> prev;
	for(int i = 0; i < n-1 ; i++){
		int in;
		cin >> in;
		if(in != prev){
			prev = in;
			g++;
		}
	}
	cout << g << endl;

	return 0;	
}