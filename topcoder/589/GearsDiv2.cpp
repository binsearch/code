#line 2 "GearsDiv2.cpp"
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
class GearsDiv2
        {
        public:
        int recurse (string dir){
            // std::vector<int> values;
            cout << dir << endl;
            int index = -1;
            int mistake = 0;
            int dlen = dir.length();
            for(int i = 0; i < dlen; i++){
                int prev = (dlen + i-1)%dlen;
                int next = (i+1)%dlen;
                int count = 0;
                if(dir[i] != 'G'){https://www.google.co.in/
                    // cout << "next" << 
                    if(dir[i] == dir[next])count++;

                    if(dir[i] == dir[prev])count++;
                }

                if(count > mistake){
                    mistake = count;
                    // cout << "index " << i << endl;
                    // cout << "mistake " << mistake << endl;
                    index = i;
                }
            }

            if(index == -1){return 0;}
            dir[index] = 'G';
            return 1+recurse(dir);

        }
        int getmin(string Directions)
            {

                int ans = recurse (Directions);
                return ans;
            //$CARETPOSITION$
            }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "LRRR"; int Arg1 = 1; verify_case(0, Arg1, getmin(Arg0)); }
	void test_case_1() { string Arg0 = "RRR"; int Arg1 = 2; verify_case(1, Arg1, getmin(Arg0)); }
	void test_case_2() { string Arg0 = "LLLLLLLLLLLLLLLRLRRRRLLLLLLLLLLLLLLLLLRLRLL"; int Arg1 = 18; verify_case(2, Arg1, getmin(Arg0)); }
	void test_case_3() { string Arg0 = "LRLLRRLLLRRRLLLL"; int Arg1 = 6; verify_case(3, Arg1, getmin(Arg0)); }
	void test_case_4() { string Arg0 = "RRRRRRRLRRRRRRRLRLRLLRLRLRLRRLRLRLLLRLRLLRLLRRLRRR"; int Arg1 = 14; verify_case(4, Arg1, getmin(Arg0)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        GearsDiv2 ___test;
        ___test.run_test(-1);
        system("pause");
        }
    // END CUT HERE 

