#line 2 "WolfDelaymaster.cpp"
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
class WolfDelaymaster
        {
        public:
        string check(string str)
            {
                int i = 0;
                int flag = 0;
                while(i < str.size()){
                    int cnt = 0;
                    while(str[i] == 'w'){
                        cnt++;
                        i++;
                    }
                    if(cnt == 0){
                        flag = 1;
                        break;
                    }

                    int temp = 0;

                    while(str[i] == 'o'){ 
                        temp++;
                        i++;
                    }
                    if(temp != cnt){
                        flag = 1;
                        break;
                    }

                    temp = 0;
                    while(str[i] == 'l'){ 
                        temp++;
                        i++;
                    }
                    if(temp != cnt){
                        flag = 1;
                        break;
                    }

                    temp = 0;
                    while(str[i] == 'f'){ 
                        temp++;
                        i++;
                    }
                    if(temp != cnt){
                        flag = 1;
                        break;
                    }

                }

                if(flag == 1) return "INVALID";
                return "VALID";
            }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const string &Expected, const string &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "wolf"; string Arg1 = "VALID"; verify_case(0, Arg1, check(Arg0)); }
	void test_case_1() { string Arg0 = "wolfwwool"; string Arg1 = "INVALID"; verify_case(1, Arg1, check(Arg0)); }
	void test_case_2() { string Arg0 = "wolfwwoollffwwwooolllfffwwwwoooollllffff"; string Arg1 = "VALID"; verify_case(2, Arg1, check(Arg0)); }
	void test_case_3() { string Arg0 = "flowolf"; string Arg1 = "INVALID"; verify_case(3, Arg1, check(Arg0)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        WolfDelaymaster ___test;
        ___test.run_test(-1);
        system("pause");
        }
    // END CUT HERE 

