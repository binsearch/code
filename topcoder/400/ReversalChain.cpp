#line 2 "ReversalChain.cpp"
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
#define inf 9999999
using namespace std;
class ReversalChain
        {
        public:
        int debug;
        // std::vector<int> vals;
        std::map<string, int> ans;

        int mins(std::vector<int> v){
            sort(v.begin(),v.end());
            return v[0];
        }

        int solve(string in, string g){
            
            
            std::vector<int> vals;
            string comb;
            vals.clear();
            comb.append(in);
            comb.append(" ");
            comb.append(g);
            if(in.length() == 1){
                if(in[0] == g[0]){return 0;}
                else return inf;
            } 
            if(ans.find(comb) != ans.end()){
                return (ans.find(comb)->second);
            }

            else{
                if(in[0] == g[0]){
                    vals.push_back(solve(in.substr(1),g.substr(1)));
                }
                
                else{
                    vals.push_back(inf);
                }

                if(in[in.length()-1] == g[g.length()-1]){
                    vals.push_back(solve(in.substr(0,in.length()-1), g.substr(0,g.length()-1)));
                }

                else{
                    vals.push_back(inf);
                }

                //reversing in

                for(int i = 0; i < in.length()/2;i++){
                    char temp;
                    temp = in[i];
                    in[i] = in[in.length()-i-1];
                    in[in.length()-i-1] = temp; 
                }

                if(in[0] == g[0]){
                    vals.push_back(solve(in.substr(1),g.substr(1)) + 1);
                }
                
                else{
                    vals.push_back(inf);
                }

                if(in[in.length()-1] == g[g.length()-1]){
                    vals.push_back(solve(in.substr(0,in.length()-1), g.substr(0,g.length()-1))+1);
                }

                else{
                    vals.push_back(inf);
                }

                int sol;
                sol = mins(vals);
                ans[comb] = sol;
                if(debug == 1){
                    cout << vals[0] << " " << vals[1] << " " << vals[2] << " " << vals[3] << endl;
                    cout << in <<  " " << g << endl;
                    cout << sol << endl;
                }
                return sol;
            }
        }



        int minReversal(string init, string goal)
            {
            //$CARETPOSITION$
                ans.clear();
                int solu;
                if(init == "111000" && goal == "101010"){
                    debug = 0;
                }
                else{
                    debug = 0;
                }
                solu = solve(init, goal);
                if(solu == inf){return -1;}
                return solu;

               
            }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { string Arg0 = "1100"; string Arg1 = "0110"; int Arg2 = 1; verify_case(0, Arg2, minReversal(Arg0, Arg1)); }
	void test_case_1() { string Arg0 = "111000"; string Arg1 = "101010"; int Arg2 = 2; verify_case(1, Arg2, minReversal(Arg0, Arg1)); }
	void test_case_2() { string Arg0 = "0"; string Arg1 = "1"; int Arg2 = -1; verify_case(2, Arg2, minReversal(Arg0, Arg1)); }
	void test_case_3() { string Arg0 = "10101"; string Arg1 = "10101"; int Arg2 = 0; verify_case(3, Arg2, minReversal(Arg0, Arg1)); }
	void test_case_4() { string Arg0 = "111000111000"; string Arg1 = "001100110011"; int Arg2 = 4; verify_case(4, Arg2, minReversal(Arg0, Arg1)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        ReversalChain ___test;
        ___test.run_test(-1);
        // string test1;
        // string test2;
        // test1 =  "001000011000000111000000001111";
        // test2 = "100100100100100100100100100100";
        // int swap;
        // ReversalChain crap;
        // swap = crap.minReversal(test1,test2);
        // cout << swap << endl;

        }
    // END CUT HERE 

