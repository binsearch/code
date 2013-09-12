#include <vector>
#include <iostream>
using namespace std;
int main(){
	std::vector<pair <pair<int,int>, int> > v;
	v.assign(100000000,make_pair(make_pair(2,2),2));
	cout << (v[0].first).first << endl;
	return 0;
}


