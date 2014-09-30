#include <iostream>
#define lim 1000000
using namespace std;
int main(){
    int cnt = 0;
    int a[101][101] = {0};
    a[1][0] = 1; a[1][1] = 1;
    for(int i = 2; i < 101; i++){
       a[i][0] = 1;
       for(int j = 1; j <= i; j++){
            a[i][j] = a[i-1][j] + a[i-1][j-1];
            if(a[i][j] > lim){
                cnt++;
                a[i][j] = lim;
            }
       }
    }
    cout << cnt << endl;
    return 0;
}
