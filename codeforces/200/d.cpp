#include <iostream>
#include <string>
using namespace std;

int main(){

	string inp;
	cin >> inp;
	string proc = "";
	char prev = inp[0];
	int count = 1;
	for(int i = 1; i < inp.size(); i++){
		// cout << i << " " << proc <<  endl;
		// cout << "prev" << prev << endl;
		// cout << "now" << inp[i] << endl;
		if(prev == inp[i]){
			count++;
		}
		else{
			if(count%2 != 0){
				if(proc.size() > 0){
					if(proc[proc.size()-1] == prev)
						proc = proc.substr(0,proc.size()-1);
					else
						proc = proc + prev;
				}
				else{
					proc = prev;
				}

			}
			prev = inp[i];
			count = 1;
		}
	}

	if(count%2 != 0){
		if(proc.size() > 0){
			if(proc[proc.size()-1] == prev)
				proc = proc.substr(0,proc.size()-1);
			else
				proc = proc + prev;
		}
		else{
			proc = prev;
		}

	}



	if(proc.size() == 0)
		cout << "Yes" << endl;
	else
		cout << "No" << endl;
	return 0;	

}