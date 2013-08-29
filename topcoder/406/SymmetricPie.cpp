#line 2 "SymmetricPie.cpp"
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
class SymmetricPie
        {
        public:
        int getLines(vector <int> dogs)
            {
                int max;
                max = 0;
                set<int> vals;

                int count = 0;
                int pie = 0;
                vals.clear();
                sort(dogs.begin(),dogs.end());
                //vals.insert(pie);
                for(int i = 0; i < dogs.size(); i++){
                    pie = pie + dogs[i];
                    vals.insert(pie);
                    if(vals.find(pie-50) != vals.end())
                        count++;
                    // cout << dogs[i] << " ";
                }
                // cout << endl;

                // cout << "count  " << count <<  endl;
                if(count > max)
                    max = count;

                while(next_permutation(dogs.begin(),dogs.end())) {
                    count = 0;
                    pie = 0;
                    vals.clear();
                    //vals.insert(pie);
                    for(int i = 0; i < dogs.size(); i++){
                        pie = pie + dogs[i];
                        vals.insert(pie);
                        if(vals.find(pie-50) != vals.end())
                            count++;
                        // cout << dogs[i] << " ";
                    }
                    // cout << endl;
                    

                    // cout << "count  " << count <<  endl;
                    if(count > max)
                        max = count;

                };

                

                return max;

            }

        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {25,25,1,1,2,2,22,22}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 4; verify_case(0, Arg1, getLines(Arg0)); }
	void test_case_1() { int Arr0[] = {10,50,40}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(1, Arg1, getLines(Arg0)); }
	void test_case_2() { int Arr0[] = {50,50}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; verify_case(2, Arg1, getLines(Arg0)); }
	void test_case_3() { int Arr0[] = {1,48,1,1,48,1}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 3; verify_case(3, Arg1, getLines(Arg0)); }
	void test_case_4() { int Arr0[] = {2,2,96}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 0; verify_case(4, Arg1, getLines(Arg0)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        SymmetricPie ___test;
        ___test.run_test(-1);
        system("pause");
        }
    // END CUT HERE 

