#line 2 "ChessKnight.cpp"
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
class ChessKnight
        {
        public:
            double dp[8][8][101];
            int to[8][8][101];

            double recurse(int x, int y, int n){
                
                if(x > 7 || x < 0 || y > 7 || y < 0)
                    return 0;

                if(to[x][y][n] != 0) return dp[x][y][n];

                if(n == 0) return 1;
                double ans = 0;
                
                ans+= recurse(x+1, y+2, n-1)/8;
                ans+= recurse(x+2, y+1, n-1)/8;
                ans+= recurse(x+2, y-1, n-1)/8;
                ans+= recurse(x+1, y-2, n-1)/8;
                ans+= recurse(x-1, y+2, n-1)/8;
                ans+= recurse(x-2, y+1, n-1)/8;
                ans+= recurse(x-1, y-2, n-1)/8;
                ans+= recurse(x-2, y-1, n-1)/8;
                
                dp[x][y][n] = ans;
                to[x][y][n] = 1;
                return dp[x][y][n];

            }

            double probability(int x, int y, int n){   
                memset(to,0,sizeof to);
                double ans = recurse(x-1,y-1,n);
                return ans;
            }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 1; int Arg2 = 2; double Arg3 = 0.1875; verify_case(0, Arg3, probability(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 4; int Arg1 = 4; int Arg2 = 1; double Arg3 = 1.0; verify_case(1, Arg3, probability(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 2; int Arg1 = 3; int Arg2 = 10; double Arg3 = 0.0522148497402668; verify_case(2, Arg3, probability(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 50; double Arg3 = 8.356427906809618E-7; verify_case(3, Arg3, probability(Arg0, Arg1, Arg2)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        ChessKnight ___test;
        ___test.run_test(-1);
        system("pause");
        }
    // END CUT HERE 

