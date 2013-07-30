
	/*
	ID: rohithk1
	PROG: ride
	LANG: C++
	*/
	#include <iostream>
	#include <fstream>
	#include <string>

	using namespace std;

	int main() {
	    ofstream fout ("ride.out");
	    ifstream fin ("ride.in");
	    string comet;
	    string group;
	    fin >> comet;
	    fin >> group;
	    int product;
	    int product1;
	    product = 1;
	    product1 = 1;
	    for(int i = 0; comet[i] != '\0'; i++){
	    	product = ((comet[i] - 64) * product) % 47;
	    }

	    for(int i = 0; group[i] != '\0'; i++){
	    	product1 = ((group[i] - 64) * product1) % 47;
	    }

	    if(product1 == product){
	    	fout << "GO" << endl;
	    }

	    else{
	    	fout << "STAY" << endl;
	    }

	    
	    return 0;
	}
