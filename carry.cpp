#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main(){
	queue<pair<float,int> > q;
	vector<float> probs;
	int no_of_t;
	int mult;
	int t_prob;
	int sum;
	int query;
	cin >> no_of_t;
	pair<float,int> temp;
	probs.assign(100000,0);
	probs[0] = 0.45;
	q.push(make_pair(0.45,1));
	q.push(make_pair(0.55,0));
	q.push(make_pair(0,-1));
	bool flag;
	for(int i = 1; i < 20; i++){
		flag = 0;
		sum = 0;
		cout << i << endl;
		while(1){
			mult = 0.55*(1-flag) + 0.45 * flag;
			temp = q.front();
			q.pop();
			if(temp.second == -1){
				probs[i] = sum;
				q.push(make_pair(0,-1));
				break;
			}
			t_prob = mult * temp.first * (temp.second+1);
			sum = sum + t_prob;
			q.push(make_pair(t_prob,temp.second+1));
			t_prob = (1-mult)*temp.first*(temp.second);
			q.push(make_pair(t_prob,temp.second));
			sum = sum+t_prob;

			flag = !flag;




		}
	}


	for(int i = 0; i < no_of_t; i++){
		cin >> query;
		cout << probs[query-1] << endl; 
	}
	return 0;
}