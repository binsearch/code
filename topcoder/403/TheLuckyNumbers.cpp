#line 2 "TheLuckyNumbers.cpp"
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
class TheLuckyNumbers
        {
        public:
        std::vector<int> vals;
        std::vector<std::vector<int> > allvals;

        int mypow(int ind){
            int retVal;
            retVal = 1;
            for(int i = 0; i < ind ; i++){
                retVal = retVal*10;
            }
            return retVal;
        }

        void fill(){
            std::vector<int> temp;
            temp.push_back(4);
            temp.push_back(7);
            vals.push_back(4);
            vals.push_back(7);
            allvals.push_back(temp);

            for(int i = 1; i < 9; i++){
                std::vector<int> temp1;
                std::vector<int> temp2;
                temp1 = allvals[i-1];
                int tpow = mypow(i);
                for(int j=0; j < temp1.size(); j++){
                    int tpush;
                    tpush = 4*tpow + temp1[j];
                    temp2.push_back(tpush);
                    vals.push_back(tpush);
                }

                for(int j=0; j < temp1.size(); j++){
                    int tpush;
                    tpush = 7*tpow + temp1[j];
                    temp2.push_back(tpush);
                    vals.push_back(tpush);
                }

                allvals.push_back(temp2);
            }
        }


        int count(int a, int b)
            {   
                vals.clear();
                allvals.clear();
                fill();
                int ans;
                ans = 0;
                cout << "size : " << vals.size() << endl;
                for(int i = 0; i < vals.size(); i++){
                    //cout << "in" << endl;
                    if(vals[i] <= b && vals[i] >= a){
                        ans++;
                    }
                }

                return ans;
            //$CARETPOSITION$
            }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arg0 = 1; int Arg1 = 10; int Arg2 = 2; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arg0 = 11; int Arg1 = 20; int Arg2 = 0; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arg0 = 74; int Arg1 = 77; int Arg2 = 2; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arg0 = 1000000; int Arg1 = 5000000; int Arg2 = 64; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        TheLuckyNumbers ___test;
        ___test.run_test(-1);
        system("pause");
        }
    // END CUT HERE 

