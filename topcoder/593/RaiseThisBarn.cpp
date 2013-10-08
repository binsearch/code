#line 2 "RaiseThisBarn.cpp"
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
class RaiseThisBarn
        {
        public:
        int calc(string str)
            {
            //$CARETPOSITION$
                int tot = 0;
                for(int i = 0; str[i] != '\0'; i++){
                    if(str[i] == 'c')
                        tot++;
                }

                if(tot%2 != 0) return 0;

                tot = tot/2;
                int tsum = 0;
                int j = 0;
                while(1){
                    if(str[j] == 'c') tsum++;

                    if(tot == tsum)
                        break;
                    j++;
                }

                int cnt = 1;
                for(int i = j+1; i < str.size()-1; i++){
                    if(str[i] == '.') cnt++;
                    if(str[i] == 'c') break;
                }

                return cnt;

            }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "cc..c.c"; int Arg1 = 3; verify_case(0, Arg1, calc(Arg0)); }
	void test_case_1() { string Arg0 = "c....c....c"; int Arg1 = 0; verify_case(1, Arg1, calc(Arg0)); }
	void test_case_2() { string Arg0 = "............"; int Arg1 = 11; verify_case(2, Arg1, calc(Arg0)); }
	void test_case_3() { string Arg0 = ".c.c...c..ccc.c..c.c.cc..ccc"; int Arg1 = 3; verify_case(3, Arg1, calc(Arg0)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        RaiseThisBarn ___test;
        ___test.run_test(-1);
        system("pause");
        }
    // END CUT HERE 

