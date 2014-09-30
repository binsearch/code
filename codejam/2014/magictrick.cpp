#include <iostream>
using namespace std;
int main(){
        int t;
        cin >> t;
        int te = t;
        while(t--){
                int fa, sa;
                cin >> fa;
                int a[4][4];
                for(int i = 0; i < 4; i++){
                       for(int j = 0; j < 4; j++)
                           cin >> a[i][j];
                }
                cin >> sa;
                int b[4][4];
                for(int i = 0; i < 4; i++)
                    for(int j = 0; j < 4; j++)
                        cin >> b[i][j];
                int ans;
                int flag = 0;
                fa--;sa--;
                for(int i = 0; i < 4; i++)
                    for(int j = 0; j < 4; j++)
                        if(a[fa][i] == b[sa][j]){
                            flag ++;
                            ans = a[fa][i];
                        }
                cout << "Case #" << te-t<< ": " ;
                if(flag == 0)
                    cout << "Volunteer cheated!" << endl;
                if(flag == 1)
                    cout << ans << endl;
                if(flag > 1)
                    cout << "Bad magician!" << endl;

        }
        return 0;
};
