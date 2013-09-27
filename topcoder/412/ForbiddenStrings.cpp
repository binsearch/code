#line 2 "ForbiddenStrings.cpp"
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
class ForbiddenStrings
        {
        public:
        std::vector<long long int> dp1;
        std::vector<long long int> dp2;        
        long long int recurse(int flag, int len){
            if(flag == 1){
                if(dp1[len] != -1)
                    return dp1[len];
                dp1[len] = 3*recurse(1,len-2) + 2*recurse(2,len-2);
                return dp1[len];
            }
            
            if(dp2[len] != -1)
                return dp2[len];
            dp2[len] = 4*recurse(1,len-2) + 3*recurse(2,len-2);
            return dp2[len];
        }
        long long countNotForbidden(int n)
            {
                dp1.assign(31,-1);
                dp2.assign(31,-1);

                long long int ans;
                dp1[2] = 3;
                dp2[2] = 6;
                dp1[3] = 9;
                dp2[3] = 12;
                if(n == 1)
                    return 3;

                ans = recurse(1,n) + recurse(2,n);
                return ans;
                
            }

        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 2; long long Arg1 = 9LL; verify_case(0, Arg1, countNotForbidden(Arg0)); }
	void test_case_1() { int Arg0 = 3; long long Arg1 = 21LL; verify_case(1, Arg1, countNotForbidden(Arg0)); }
	void test_case_2() { int Arg0 = 4; long long Arg1 = 51LL; verify_case(2, Arg1, countNotForbidden(Arg0)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        ForbiddenStrings ___test;
        ___test.run_test(-1);
        system("pause");
        }
    // END CUT HERE 

