#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
	int freq[26];
	for(int i = 0; i < 26; i++)
		freq[i] = 0;
	
	char in[72];
	for(int i = 0; i < 4; i++){
		gets(in);
		string input(in);
		for(int j = 0; j < input.length(); j++){
			if( 64 < input[j] && input[j] < 91 ){
				freq[input[j] - 65]++;
			}
		}
	}
	int high = 0;
	while(true){
		high = 0;
		for(int i = 0; i < 26; i++){
			if(high < freq[i])
				high = freq[i];
		}
		if(high == 0)break;
		for(int i = 0; i < 26; i++){
			if(freq[i] == high){
				cout << "*";
				freq[i]--;
			}
			else{
				cout << " ";
			}
			if(i != 25){
				cout << " ";
			}
		}
		cout << endl;
	}

	cout << "A B C D E F G H I J K L M N O P Q R S T U V W X Y Z" << endl;
	

	return 0;
}