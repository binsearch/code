#include <iostream>
using namespace std;
int main(){
	int no_of_t;
	cin >> no_of_t;
	for(int i = 0; i < no_of_t; i++){
		int x[4];
		int y[4];

		for(int  j =0; j < 4;j++){
			cin >> x[j];
			cin >> y[j];
		}
		//chck for line

		int flag = 0;
		for(int j = 0; j < 4; j++){

			int x0;
			int x1;
			int x2;
			x0 = j;
			x1 = (j+1)%4;
			x2 = (j+2)%4;
			int val1;
			int val2;
			val1 = (x[x1]-x[x0]) * (y[x2]-y[x1]);
			val2 = (x[x2] - x[x1]) * (y[x1] - y[x0]);
			// cout << val1 << endl;
			// cout << val2 << endl;
			if (val1 == val2){
				flag = 1;
				break;
			}
		}

		if(flag == 1){
			cout << "NONE" << endl;
			continue;
		};
		
		flag == 0;

		//check for parallelogram
		int val[4];
		for(int j = 0; j < 4; j++){
			val[j] = (x[j]-x[(j+1)%4])*(x[j]-x[(j+1)%4]) + (y[j]-y[(j+1)%4])*(y[j]-y[(j+1)%4]);
		}

		if(!(val[0] == val[2] && val[1] == val[3])) flag ==1;

		// cout << "kri" <<endl;
		if(flag == 1){
			cout << "QUADRILATERAL" << endl;
			continue;
		}
		// cout << "kri" <<endl;
		// for(int j = 0; j < 4; j++){
		//   	cout << val[j]<<endl;
		//  }

		if(val[0] == val[1]){
			//check for rhombus
			int angle = (x[0]-x[1])*(x[0] - x[3]) + (y[0] - y[1])*(y[0]-y[3]);
			if(angle == 0){
				cout << "SQUARE" << endl;
				continue;
			}

			else{
				cout << "RHOMBUS" << endl;
				continue;
			}


		}

		else{

			int angle = (x[0]-x[1])*(x[0] - x[3]) + (y[0] - y[1])*(y[0]-y[3]);
			if(angle = 0){
				cout << "RECTANGLE" << endl;
				continue;
			}

			else{
				cout << "PARALLELOGRAM" << endl;
				continue;
			}


		}










	}

	return 0;
}