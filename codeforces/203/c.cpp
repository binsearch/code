#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef pair<int,int> pts;

bool comp(pts p1, pts p2){
	if(abs(p1.first) == abs(p2.first)){
		return abs(p1.second) < abs(p2.second);
	}
	return abs(p1.first) < abs(p2.first);
}
int main(){


	pts p[100010];
	int n;
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> p[i].first;
		cin >> p[i].second;
	}

	sort(p,p+n,comp);
	int count = 0;
	for(int i = 0; i < n; i++){
		if(p[i].first != 0){
			count++;
		}

		if(p[i].second != 0){
			count++;
		}


		count++;

		if(p[i].second != 0){
			count++;
		}


		if(p[i].first != 0){
			count++;
		}


		count++;

	}

	cout << count << endl;

	for(int i = 0; i < n; i++){
		if(p[i].first > 0){
			cout << "1 " << p[i].first << " R" << endl;
		}

		if(p[i].first < 0){
			cout << "1 " << -p[i].first << " L" << endl;
		}

		if(p[i].second > 0){
			cout << "1 " << p[i].second << " U" << endl;
		}

		if(p[i].second < 0){
			cout << "1 " << -p[i].second << " D" << endl;
		}

		cout << 2 << endl;

		if(p[i].second > 0){
			cout << "1 " << p[i].second << " D" << endl;
		}

		if(p[i].second < 0){
			cout << "1 " << -p[i].second << " U" << endl;
		}

		if(p[i].first > 0){
			cout << "1 " << p[i].first << " L" << endl;
		}

		if(p[i].first < 0){
			cout << "1 " << -p[i].first << " R" << endl;
		}

		cout << 3 << endl;

	}



	return 0;
}