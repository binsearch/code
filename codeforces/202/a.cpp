#include <iostream>
using namespace std;


int main(){

	int n;
	cin >> n;
	int t = 0;
	int f = 0;
 	while(n--){
 		int now;
 		cin >> now;
 		if(now == 25){
 			t++;
 			continue;
 		}
 		if(now == 50){
 			if(t == 0){
 				cout << "NO" << endl;
 				return 0;
 			}
 			f++;
 			t--;
 			continue;

 		}

 		if(now == 100){
 			if(f == 0){
 				if(t < 3){
 					cout << "NO" << endl;
 					return 0;
 				}
 				t = t - 3;
 				continue;
 			}
 			else{
 				if(t == 0){
 					cout << "NO" << endl;
 					return 0;
 				}

 				t--;
 				f--;
 				continue;

 			}
 				
 		}		
 			
	}
	cout << "YES" << endl;
	return 0;	
 		
}