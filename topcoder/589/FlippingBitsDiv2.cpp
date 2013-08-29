#line 2 "FlippingBitsDiv2.cpp"
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
class FlippingBitsDiv2
        {
        public:
        // int debug;
        int recurse(string inp, int mul){
            // cout << inp << endl;
            // debug++;
            vector<int> freq;
            freq.clear();
            freq.push_back(0);
            
            int index = -1;
            for(int i = 0; i < inp.size(); i++){
                if(inp[i] == '0'){
                    index = i;
                    freq.push_back(freq[i]+1);
                }

                else{
                    freq.push_back(freq[i]);
                }
            }

            if(index == -1){
                return 0;
            }

            int highind = 0;
            int maxflip = 0;
            for(int i = 1; mul*i <= inp.size(); i++){
                int flip = 2*freq[mul*i]-mul*i;
                if(flip > maxflip){
                    maxflip = flip;
                    highind = i;
                }
            }

            for(int i = 1; mul*i <= inp.size(); i++){
                int flip = 2*(freq[inp.size()] - freq[inp.size() - mul*i])-mul*i ;
                if(flip > maxflip){
                    maxflip = flip;
                    highind = -i;
                }
            }

            if(highind == 0){
                inp[index] = '1';
                return 1+recurse(inp,mul);
            }

            else{
                int start;
                int end;
                if(highind > 0){
                    start = 0;
                    end = mul*highind;
                }

                else{
                    start = inp.size() + mul*highind;
                    end = inp.size();
                }

                for(int i = start; i < end; i++){
                    if(inp[i] == '1')inp[i] = '0';
                    else{inp[i] = '1';}
                }
                // cout << "high" << highind << endl;
                return 1+recurse(inp,mul);
            }




        }

        int getmin(vector <string> S, int M)
            {
                // debug = 0;
                string quer;
                quer = S[0];
                for(int i = 1; i < S.size(); i++){
                    quer.append(S[i]);
                }

                int ans;
                ans = recurse(quer,M);

                return ans;
            //$CARETPOSITION$
            }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arr0[] = {"00111000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, getmin(Arg0, Arg1)); }
	void test_case_1() { string Arr0[] = {"00111000"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 3; verify_case(1, Arg2, getmin(Arg0, Arg1)); }
	void test_case_2() { string Arr0[] = {"111111"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; int Arg2 = 0; verify_case(2, Arg2, getmin(Arg0, Arg1)); }
	void test_case_3() { string Arr0[] = {"00100"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 5; int Arg2 = 2; verify_case(3, Arg2, getmin(Arg0, Arg1)); }
	void test_case_4() { string Arr0[] = {"00010","11010110","1010111","110001010","0110001100"
,"000110110","011010101","00","111","100"}
; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 13; int Arg2 = 31; verify_case(4, Arg2, getmin(Arg0, Arg1)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        FlippingBitsDiv2 ___test;
        ___test.run_test(-1);
        system("pause");
        }
    // END CUT HERE 

