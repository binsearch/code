#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(){
	int n;
	int k;
	string action;
	cin >> n;
	cin >> k;
	std::vector<bool> state;
	state.assign(n,0);
	int count;
	count = 0;
	for(int i = 0; i < k; i++){
		cin >> action;
		if(action == "CLOSEALL"){
			state.assign(n,0);
			count = 0;
		}

		if(action == "CLICK"){
			int tweet;
			cin >> tweet;
			if(state[tweet-1] == 0){
				count++;
				state[tweet-1] = 1;

			}

			else{
				count--;
				state[tweet-1] = 0;
			}
		}

		cout << count << endl;
	}

	return 0;

}