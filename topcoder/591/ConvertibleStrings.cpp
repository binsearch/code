#line 2 "ConvertibleStrings.cpp"
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
class ConvertibleStrings
        {
        public:
        string s1,s2;
        map<string,int> dp;
        int recurse (string mymap, int index){

            if(index == s1.size())
                return 0;

            stringstream ss;
            ss << mymap;
            ss << " ";
            ss << index;

            string query = ss.str();
            if(dp.find(query) != dp.end()){
                
                return dp.find(query)->second;
            }

            if(mymap[s1[index]-'A'] != 'Z'){
                if(mymap[s1[index] - 'A'] != s2[index]){
                    int temp = 1 + recurse(mymap,index+1);
                    dp[query] = temp;   
                    return temp;
                }
                else{
                    int temp = recurse(mymap,index+1);
                    dp[query] = temp;
                    return temp;
                }
            }

            
            for(int i = 0; i < 9; i++){
                if(i != s1[index]-'A'){
                    if(mymap[i] == s2[index]){
                        int temp = 1 + recurse(mymap,index+1);
                        dp[query] = temp;
                        return temp;
                    }
                }
            }



            int t1 = 1 + recurse(mymap,index+1);
            mymap[s1[index]-'A'] = s2[index];
            int t2 = recurse(mymap,index+1);
            dp[query] = min(t1,t2);
            return min(t1,t2);
        }

        int leastRemovals(string A, string B)
        {   
            dp.clear();
            s1 = A;
            s2 = B;
            return recurse("ZZZZZZZZZ",0);
        }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "DD"; string Arg1 = "FF"; int Arg2 = 0; verify_case(0, Arg2, leastRemovals(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "AAAA"; string Arg1 = "ABCD"; int Arg2 = 3; verify_case(1, Arg2, leastRemovals(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "AAIAIA"; string Arg1 = "BCDBEE"; int Arg2 = 3; verify_case(2, Arg2, leastRemovals(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "ABACDCECDCDAAABBFBEHBDFDDHHD"; string Arg1 = "GBGCDCECDCHAAIBBFHEBBDFHHHHE"; int Arg2 = 9; verify_case(3, Arg2, leastRemovals(Arg0, Arg1)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        ConvertibleStrings ___test;
        ___test.run_test(-1);
        ConvertibleStrings temp;
        string b1 = "ABACDCECDCDAAABBFBEHBDFDDABACDCECDCDAAABBFBEHBDFDD";
        string b2 = "GBGCDCECDCHAAIBBFHEBBDFHHGBGCDCECDCHAAIBBFHEBBDFHH";
        int ans = temp.leastRemovals(b1,b2);
        cout << ans << endl;
        system("pause");
        }
    // END CUT HERE 

