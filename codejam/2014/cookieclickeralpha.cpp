#include <iostream>
#include <stdio.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    int te = t;
    while(t--){
        double cookie_cost,f_add,tot;
        cin >> cookie_cost;
        cin >> f_add;
        cin >> tot;
        double c_rate = 2;
        double temp_tot = 0;
        double ti = 0;
        while(1){
           if((tot/c_rate) < (cookie_cost/c_rate  + (tot/(c_rate+f_add)))){
               //cout << "break" << tot/c_rate << endl;
               break;
           }
           ti+= cookie_cost/c_rate;
           c_rate+= f_add;
        }
        ti+= tot/c_rate;
        cout << "Case #" << te-t << ": ";
        printf("%.7f\n", ti);
    }
    return 0;
}
