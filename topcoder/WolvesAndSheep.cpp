#line 2 "WolvesAndSheep.cpp"
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
using namespace std;
class WolvesAndSheep
        {
        public:
            int dp[20][20][20][20];
            int wo[20][20][20][20];
            int sh[20][20][20][20];            
            int si;
            std::vector<string> fi;
        int recursewo(int r1, int r2, int c1, int c2){
            if(wo[r1][r2][c1][c2] != -1)
                return wo[r1][r2][c1][c2];
            if((r1 == r2) && (c1 == c2)){
                if(fi[r1][c1] == 'W')
                    wo[r1][r2][c1][c2] = 0;
                else
                    wo[r1][r2][c1][c2] = 1;
            }
            else{
                if(fi[r2][c2] == 'W')
                    wo[r1][r2][c1][c2] = 0;
                else
                    if(c1 != c2 && r1 != r2)
                        if(recursewo(r1,r2-1,c1,c2) && recursewo(r1,r2,c1,c2-1))
                            wo[r1][r2][c1][c2] = 1;
                        else
                            wo[r1][r2][c1][c2] = 0;
                    else if(c1 != c2)
                        if(recursewo(r1,r2,c1,c2-1))
                            wo[r1][r2][c1][c2] = 1;
                        else
                            wo[r1][r2][c1][c2] = 0;
                    else if(r1 != r2)
                        if(recursewo(r1,r2-1,c1,c2))
                            wo[r1][r2][c1][c2] = 1;
                        else
                            wo[r1][r2][c1][c2] = 0; 
            }
            return wo[r1][r2][c1][c2];
        }

        int recursesh(int r1, int r2, int c1, int c2){
            if(sh[r1][r2][c1][c2] != -1)
                return sh[r1][r2][c1][c2];
            if((r1 == r2) && (c1 == c2)){
                if(fi[r1][c1] == 'S')
                    sh[r1][r2][c1][c2] = 0;
                else
                    sh[r1][r2][c1][c2] = 1;
            }
            else{
                if(fi[r2][c2] == 'S')
                    sh[r1][r2][c1][c2] = 0;
                else
                    if(c1 != c2 && r1 != r2)
                        if(recursesh(r1,r2-1,c1,c2) && recursesh(r1,r2,c1,c2-1))
                            sh[r1][r2][c1][c2] = 1;
                        else
                            sh[r1][r2][c1][c2] = 0;
                    else if(c1 != c2)
                        if(recursesh(r1,r2,c1,c2-1))
                            sh[r1][r2][c1][c2] = 1;
                        else
                            sh[r1][r2][c1][c2] = 0;
                    else if(r1 != r2)
                        if(recursesh(r1,r2-1,c1,c2))
                            sh[r1][r2][c1][c2] = 1;
                        else
                            sh[r1][r2][c1][c2] = 0; 
            }
            return sh[r1][r2][c1][c2];
        }



        int recurseans(int r1, int r2, int c1, int c2){
            if(dp[r1][r2][c1][c2] != -1)
                return dp[r1][r2][c1][c2];
            if((r1 == r2) && (c1 == c2)){
                // cout << "in one block" << endl;
                return 0;
            }
            if(recursewo(r1,r2,c1,c2) || recursesh(r1,r2,c1,c2) ) {
                // cout << "in recursewo cond" << endl;
                return 0;
            }
            int val = 100;
            for(int i = r1; i < r2; i++){
                val = min(val, 1+recurseans(r1,i,c1,c2) + recurseans(i+1,r2,c1,c2));
                // cout << val << endl;
            }
            for(int i = c1; i < c2; i++){
                val = min(val, 1+recurseans(r1,r2,c1,i) + recurseans(r1,r2, i+1,c2));
                // cout << val << endl;
            }
            dp[r1][r2][c1][c2] = val;
            return dp[r1][r2][c1][c2];
        }
        
        int getmin(vector <string> field)
        {
            si = field.size();
            cout << si << endl;
            memset(wo, -1, sizeof wo);
            memset(dp, -1, sizeof dp);
            memset(sh, -1, sizeof sh);
            fi = field;
            return recurseans(0,si-1,0,si-1);
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"W.WSS",
 "WW.S.",
 ".SSS.",
 "SSS.S",
 ".SS.S"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arr0[] = {".....",
 ".....",
 "....."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(1, Arg1, getmin(Arg0)); }
    void test_case_2() { string Arr0[] = {"WWWSWWSSWWW",
 "WWSWW.SSWWW",
 "WS.WSWWWWS."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 10; verify_case(3, Arg1, getmin(Arg0)); }
    void test_case_3() { string Arr0[] = {".W.S.W.W",
 "W.W.S.W.",
 ".S.S.W.W",
 "S.S.S.W.",
 ".S.W.W.S",
 "S.S.W.W.",
 ".W.W.W.S",
 "W.W.S.S."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 7; verify_case(4, Arg1, getmin(Arg0)); }
    void test_case_4() { string Arr0[] = {"W.SSWWSSSW.SS",
 ".SSSSW.SSWWWW",
 ".WWWWS.WSSWWS",
 "SS.WSS..W.WWS",
 "WSSS.SSWS.W.S",
 "WSS.WS...WWWS",
 "S.WW.S.SWWWSW",
 "WSSSS.SSW...S",
 "S.WWSW.WWSWSW",
 ".WSSS.WWSWWWS",
 "..SSSS.WWWSSS",
 "SSWSWWS.W.SSW",
 "S.WSWS..WSSS.",
 "WS....W..WSS."}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 24; verify_case(5, Arg1, getmin(Arg0)); }
	void test_case_5() { string Arr0[] = {".SS",
 "...",
 "S..",
 "W.W"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, getmin(Arg0)); }
    void test_case_6() { string Arr0[] = {"WW..SS",
 "WW..SS",
 "......",
 "......",
 "SS..WW",
 "SS..WW"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; verify_case(6, Arg1, getmin(Arg0)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        WolvesAndSheep ___test;
        ___test.run_test(-1);
        system("pause");
        }
    // END CUT HERE 

