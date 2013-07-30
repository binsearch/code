#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<char> in;
	int n;
	char temp;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> temp;
		in.push_back(temp);
	}
	int ccode;
	//blue = 1, red = 2
	if(v[0] == 'b')
		ccode = 1;
	if(v[0] == 'r')
		ccode = 2;
	else
		ccode = 0;
	int i = n-1;
	int count = 0;

	while(1){
		if(ccode == 0){
			if(v[i] == 'b')
				ccode = 1;
			if(v[i] == 'r')
				ccode = 2;
			count++;
		}
		if(ccode == 1){
			if(v[i] == 'r')
				break;
			else
				count++;
		}
		
		if(ccode == 2){
			if(v[i] == 'b')
				break;
			else
				count++;
		}

		i--;

	}

	
}