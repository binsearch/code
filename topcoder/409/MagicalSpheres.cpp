#line 2 "MagicalSpheres.cpp"
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
class MagicalSpheres
        {
        public:
        int divideWork(int spheresCount, int fakeSpheresCount, int gnomesAvailable)
            {
            //$CARETPOSITION$
            }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 3; int Arg1 = 1; int Arg2 = 3; int Arg3 = 2; verify_case(0, Arg3, divideWork(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 3; int Arg1 = 3; int Arg2 = 50; int Arg3 = 20; verify_case(1, Arg3, divideWork(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 4; int Arg1 = 3; int Arg2 = 4; int Arg3 = 1; verify_case(2, Arg3, divideWork(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arg0 = 15634; int Arg1 = 456; int Arg2 = 5000; int Arg3 = 4990; verify_case(3, Arg3, divideWork(Arg0, Arg1, Arg2)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        MagicalSpheres ___test;
        ___test.run_test(-1);
        system("pause");
        }
    // END CUT HERE 

