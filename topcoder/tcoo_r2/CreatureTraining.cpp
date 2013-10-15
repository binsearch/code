#line 2 "CreatureTraining.cpp"
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
class CreatureTraining
        {
            public:
            long long int dp[101][101][51];
            std::vector<int> c,p;

            long long int recurse(int d, int ec, int l){
                if(dp[d][ec][l] != -1) return dp[d][ec][l];
                
                if(l == c.size()-1) {
                    long long int temp = c[l]+ec;
                    temp = temp*p[l];
                    dp[d][ec][l] = temp;
                    return dp[d][ec][l];
                }

                long long int mp = -1;
                for(int i = 0; i <= min(d, c[l]+ec); i++){
                    long long int temp = (c[l]+ec-i);
                    temp = temp*p[l];
                    temp+= recurse(d-i, i, l+1);
                    if(temp > mp) mp = temp;
                }
                dp[d][ec][l] = mp;
                return dp[d][ec][l];
            }

            long long maximumPower(vector <int> count, vector <int> power, int D)
            {
                c = count;
                p = power;
                memset(dp, -1, sizeof dp);
                return recurse(D,0,0);

            }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const long long &Expected, const long long &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3, 4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 2, 3, 4, 5}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; long long Arg3 = 65LL; verify_case(0, Arg3, maximumPower(Arg0, Arg1, Arg2)); }
	void test_case_1() { int Arr0[] = {1, 2, 3, 4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {1, 4, 9, 16, 25}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 10; long long Arg3 = 309LL; verify_case(1, Arg3, maximumPower(Arg0, Arg1, Arg2)); }
	void test_case_2() { int Arr0[] = {1000, 0, 0, 0, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {0, 100, 10, 1000, 0}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 8; long long Arg3 = 2200LL; verify_case(2, Arg3, maximumPower(Arg0, Arg1, Arg2)); }
	void test_case_3() { int Arr0[] = {1, 2, 3, 4, 5}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {5, 4, 3, 2, 1}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 50; long long Arg3 = 35LL; verify_case(3, Arg3, maximumPower(Arg0, Arg1, Arg2)); }
	void test_case_4() { int Arr0[] = {0, 5, 0, 0, 5, 0}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {13, 20, 21, 30, 32, 36}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 12; long long Arg3 = 318LL; verify_case(4, Arg3, maximumPower(Arg0, Arg1, Arg2)); }
	void test_case_5() { int Arr0[] = {0, 2, 1, 0, 0, 1, 2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = {25, 292, 328, 391, 618, 771, 952}; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); int Arg2 = 11; long long Arg3 = 5088LL; verify_case(5, Arg3, maximumPower(Arg0, Arg1, Arg2)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        CreatureTraining ___test;
        ___test.run_test(-1);
        system("pause");
        }
    // END CUT HERE 

