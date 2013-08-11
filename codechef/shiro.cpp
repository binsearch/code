#include <iostream>
#include <vector>
using namespace std;
int main(){
	int no_of_t;
	cin >> no_of_t;
	for(int i = 0; i < no_of_t; i++){
		int levels;
		cin >> levels;
		std::vector<int> probs;
		std::vector<int> flags;
		int totFlags = 0;
		for(int j = 0; j < levels; j++){
			int no_f;
			cin >> no_f;
			totFlags = totFlags + no_f;
			flags.push_back(no_f);
		}

		for(int j = 0; j < levels; j++){
			int prob;
			cin >> prob;
			probs.push_back(prob);
		}

		std::vector<float> dp;
		dp.assign(totFlags+1,0);
		dp[0] = 1;

		for(int j = 0; j < levels; j++){
			float lProb = probs[j];
			int lFlag = flags[j];
			lProb = lProb / 100.0;
			for(int k = totFlags; k > -1; k--){
				if(k - lFlag < 0){
					dp[k] = dp[k] * (1-lProb);
				}

				else{
					dp[k] = dp[k] * (1-lProb) + dp[k - lFlag] * lProb;
				}
			}
		}

		float sum = 0;

		for(int j = totFlags - totFlags/2; j < totFlags+1; j++){
			sum = sum + dp[j];
		}

		cout << sum << endl;
	}

	return 0;
}