#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;
int main(){
	map<string,int> names;
	//cout << names["rohith"] << endl;

	int n;
	cin >> n;
	for(int i = 0; i <n; i++){
		string name;
		cin >> name;
		if(names[name] == 0){
			cout <<"OK" << endl;
			names[name] = 1;
		}

		else{
			
			cout << name << names[name] << endl;
			names[name]+=1;
		}
	}


	return 0;
}