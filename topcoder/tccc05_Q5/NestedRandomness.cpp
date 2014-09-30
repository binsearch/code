#line 2 "NestedRandomness.cpp"
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
class NestedRandomness
        {
        public:
        double probability(int N, int nestings, int target)
            {
                double a[N];
                for(int i = 0; i < N; i++){
                    a[i] = 1/(double) N;
                }
                for(int i = 0; i < nestings-1; i++){
                    double temp,temp1;
                    temp = a[N-2-i];
                    a[N-2-i] = a[N-1-i]/(double)(N-1-i);
                    for(int j = N-3-i; j >= 0; j--){
                        temp1 = a[j];
                        a[j] = a[j+1] + temp/(double)(j+1);
                        temp = temp1;
                    }
                }

                return a[target];
            }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 5; int Arg1 = 2; int Arg2 = 1; double Arg3 = 0.21666666666666667; verify_case(0, Arg3, probability(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arg0 = 10; int Arg1 = 4; int Arg2 = 0; double Arg3 = 0.19942680776014104; verify_case(1, Arg3, probability(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arg0 = 1000; int Arg1 = 10; int Arg2 = 990; double Arg3 = 1.0461776397050886E-30; verify_case(2, Arg3, probability(Arg0, Arg1, Arg2)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        NestedRandomness ___test;
        ___test.run_test(-1);
        system("pause");
        }
    // END CUT HERE 

