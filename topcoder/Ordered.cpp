#line 2 "Ordered.cpp"
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
class Ordered
        {
        public:
        string getType(vector <int> values)
            {
            //$CARETPOSITION$
            }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); if ((Case == -1) || (Case == 6)) test_case_6(); if ((Case == -1) || (Case == 7)) test_case_7(); if ((Case == -1) || (Case == 8)) test_case_8(); if ((Case == -1) || (Case == 9)) test_case_9(); if ((Case == -1) || (Case == 10)) test_case_10(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1,2,4,11}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ASCENDING 9/2"; verify_case(0, Arg1, getType(Arg0)); }
	void test_case_1() { int Arr0[] = {1,2,2,2,3,4}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NONDESCENDING 3"; verify_case(1, Arg1, getType(Arg0)); }
	void test_case_2() { int Arr0[] = {6,5,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "DESCENDING 4/1"; verify_case(2, Arg1, getType(Arg0)); }
	void test_case_3() { int Arr0[] = {5,5,4,4,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NONASCENDING 2"; verify_case(3, Arg1, getType(Arg0)); }
	void test_case_4() { int Arr0[] = {1,2,3,4,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NOTHING"; verify_case(4, Arg1, getType(Arg0)); }
	void test_case_5() { int Arr0[] = {1000,999,998}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "DESCENDING 999/1"; verify_case(5, Arg1, getType(Arg0)); }
	void test_case_6() { int Arr0[] = {999,1000,1000,1000,1000,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NONDESCENDING 5"; verify_case(6, Arg1, getType(Arg0)); }
	void test_case_7() { int Arr0[] = {1,1000,1,1000,1,1000}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NOTHING"; verify_case(7, Arg1, getType(Arg0)); }
	void test_case_8() { int Arr0[] = {1,2,3,4,5,6,7,8,9,10,
11,12,13,14,15,16,17,18,19,20,
21,22,23,24,25,26,27,28,29,30,
31,32,33,34,35,36,37,38,39,40,
41,42,43,44,45,46,47,48,49,51}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "ASCENDING 638/25"; verify_case(8, Arg1, getType(Arg0)); }
	void test_case_9() { int Arr0[] = {2,2,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NONASCENDING 2"; verify_case(9, Arg1, getType(Arg0)); }
	void test_case_10() { int Arr0[] = {1,2,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); string Arg1 = "NONDESCENDING 2"; verify_case(10, Arg1, getType(Arg0)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        Ordered ___test;
        ___test.run_test(-1);
        system("pause");
        }
    // END CUT HERE 

