#line 2 "OrderedSuperString.cpp"
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
class OrderedSuperString
        {
        public:
        vector<string> wordcopy;
        int recurse(int index, string base, int valind){
            // cout << "base " << base << endl;
            // cout << "valind " << valind << endl; 
            int i = 0;
            string temp;
            if(index == wordcopy.size()){
                return base.length();
            }
            temp = wordcopy[index];

            if(base.length()-valind >= temp.length()){
                for(int i = 0; i < base.length()-valind-temp.length()+1; i++){
                    if(base.substr(i+valind,temp.length()) == temp){
                        return recurse(index+1,base,valind+i);
                    }
                }
            }
            //cout << 1 << endl;
            for(int i = 0; i < base.length()-valind; i++){
                if(temp.substr(0,base.length()-valind-i) == base.substr(valind+i)){
                    return recurse(index+1,base.append(temp.begin()+base.length()-valind-i,temp.end()),valind+i);
                }
            }

            return recurse(index+1, base.append(temp), base.length());
        }
        int getLength(vector <string> words)
            {
            //$CARETPOSITION$

                wordcopy = words;
                int ans = recurse(1,words[0],0);
                return ans;
            }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"abc","ca"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, getLength(Arg0)); }
	void test_case_1() { string Arr0[] = {"a","a","b","a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(1, Arg1, getLength(Arg0)); }
	void test_case_2() { string Arr0[] = {"abcdef", "ab","bc", "de","ef"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 6; verify_case(2, Arg1, getLength(Arg0)); }
	void test_case_3() { string Arr0[] = {"x", "w", "v", "u", "t", "s", "r", "q", "p", "o", "n", "m", "l", "k", "j", "i", "h", "g", "f", "e", "d", "c", "b", "a", "z", "y", "x", "w", "v", "u", "t", "s", "r", "q", "p", "o", "n", "m", "l", "k", "j", "i", "h", "g", "f", "e", "d", "c", "b", "a"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 50; verify_case(3, Arg1, getLength(Arg0)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        OrderedSuperString ___test;
        ___test.run_test(-1);
        system("pause");
        }
    // END CUT HERE 

