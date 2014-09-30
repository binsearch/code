#line 2 "Unique.cpp"
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
class Unique
        {
        public:
        string removeDuplicates(string S)
            {
                int a[26] = {0};
                string ans;
                for(int i = 0; S[i] != '\0'; i++){
                    if(a[S[i] - 'a'] != 1)
                        ans = ans + S[i];
                    a[S[i] - 'a'] = 1;
                }
                return ans;
            }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "banana"; string Arg1 = "ban"; verify_case(0, Arg1, removeDuplicates(Arg0)); }
	void test_case_1() { string Arg0 = "aardvark"; string Arg1 = "ardvk"; verify_case(1, Arg1, removeDuplicates(Arg0)); }
	void test_case_2() { string Arg0 = "xxxxx"; string Arg1 = "x"; verify_case(2, Arg1, removeDuplicates(Arg0)); }
	void test_case_3() { string Arg0 = "topcoder"; string Arg1 = "topcder"; verify_case(3, Arg1, removeDuplicates(Arg0)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        Unique ___test;
        ___test.run_test(-1);
        system("pause");
        }
    // END CUT HERE 

