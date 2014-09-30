#line 2 "PillarsDivTwo.cpp"
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
class PillarsDivTwo
        {
        public:
            std::vector<int> h;
            int np;
            int width;
            double dp[110][60];
            int find[110][60];
            double recurse(int prev, int ind){
                if(ind == np){return 0;}
                if(find[prev][ind] == 1) return dp[prev][ind];
                double minlen = -1;
                for(int i = 1; i <= h[ind]; i++){
                    double temp;
                    temp = sqrt(width*width + (i-prev)*(i-prev));
                    // cout << temp << endl;
                    temp = temp + recurse(i, ind+1);
                    if(temp > minlen) minlen = temp;
                }
                find[prev][ind] = 1;
                dp[prev][ind] = minlen;
                return minlen;
            }
                    
            double maximalLength(vector <int> height, int w)
            {
                memset(find, 0, sizeof find);
                width = w;
                np = height.size();
                h = height;
                double minlen = 0;
                for(int i = 1; i <= h[0]; i++){
                    double temp;
                    temp = recurse(i,1);
                    if(temp > minlen) minlen = temp;

                }
                return minlen;
            }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const double &Expected, const double &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {3,3,3}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; double Arg2 = 5.656854249492381; verify_case(0, Arg2, maximalLength(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {1,1,1,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 100; double Arg2 = 300.0; verify_case(1, Arg2, maximalLength(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {100,2,100,2,100}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; double Arg2 = 396.32310051270036; verify_case(2, Arg2, maximalLength(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {2,1,1,2}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; double Arg2 = 3.82842712474619; verify_case(3, Arg2, maximalLength(Arg0, Arg1)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        PillarsDivTwo ___test;
        ___test.run_test(-1);
        system("pause");
        }
    // END CUT HERE 

