#line 2 "RoadOrFlightHard.cpp"
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
typedef long long int lli;
class RoadOrFlightHard
        {
        public:
        lli r[100000],f[100000],A[100001][41],B[100001][41];
        long long minTime(int n, int rf, int rp, int ra, int rm, int ff, int fp, int fa, int fm, int k)
            {
            //$CARETPOSITION$
            	r[0]=rf%rm;
            	f[0]=ff%fm;

            	for(int i=1;i<n;i++) {
            		r[i]=((r[i-1]*(lli)rp)+(lli)ra)%(lli)rm;
            		f[i]=((f[i-1]*(lli)fp)+(lli)fa)%(lli)fm;
            	}

            	for(int i=0;i<=k;i++) {
            		A[1][i]=r[0];
            		B[1][i]=f[0];
            	}
            	B[1][0]=r[0];

            	for(int i=2;i<=n;i++) {
            		A[i][0]=r[i-1]+A[i-1][0];
            		for(int j=1;j<=k;j++) {
            			A[i][j]
            		}
            	}

            }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 14; int Arg2 = 1; int Arg3 = 2; int Arg4 = 10; int Arg5 = 18; int Arg6 = 1; int Arg7 = 10; int Arg8 = 17; int Arg9 = 1; long long Arg10 = 14LL; verify_case(0, Arg10, minTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 1; int Arg3 = 2; int Arg4 = 10; int Arg5 = 1; int Arg6 = 1; int Arg7 = 10; int Arg8 = 17; int Arg9 = 2; long long Arg10 = 11LL; verify_case(1, Arg10, minTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_2() { int Arg0 = 3; int Arg1 = 4; int Arg2 = 1; int Arg3 = 2; int Arg4 = 10; int Arg5 = 1; int Arg6 = 1; int Arg7 = 6; int Arg8 = 9; int Arg9 = 1; long long Arg10 = 12LL; verify_case(2, Arg10, minTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }
	void test_case_3() { int Arg0 = 5; int Arg1 = 85739; int Arg2 = 94847; int Arg3 = 93893; int Arg4 = 98392; int Arg5 = 92840; int Arg6 = 93802; int Arg7 = 93830; int Arg8 = 92790; int Arg9 = 3; long long Arg10 = 122365LL; verify_case(3, Arg10, minTime(Arg0, Arg1, Arg2, Arg3, Arg4, Arg5, Arg6, Arg7, Arg8, Arg9)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        RoadOrFlightHard ___test;
        ___test.run_test(-1);
        system("pause");
        }
    // END CUT HERE 

