#line 2 "TheLuckySequence.cpp"
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
#define modu 1234567891
using namespace std;
class TheLuckySequence
        {
        public:
        int x4y4;
        int x4y7;
        int x7y4;
        int x7y7;
        set<int> distnm;
        void preprocess(){
            std::set<int>::iterator it;
            for(it=distnm.begin(); it!=distnm.end(); ++it){
                // cout << "i  " << numbers[i] << endl;
                std::stringstream out;
                out << *it;
                string temp = out.str();
                // cout << "temp " << temp << endl;
                int flag = 0;
                for(int j = 0; j < temp.length(); j++)
                {
                    if(temp[j] != '4' && temp[j] != '7'){
                        // cout << temp[j] << endl;
                        flag = 1;
                        break;
                    }
                }


                if(flag == 0){
                    // cout << "came" << endl;
                    if(temp[0] == '4' && temp[temp.length() -1] == '4')x4y4++;
                    if(temp[0] == '4' && temp[temp.length() -1] == '7')x4y7++;
                    if(temp[0] == '7' && temp[temp.length() -1] == '4')x7y4++;
                    if(temp[0] == '7' && temp[temp.length() -1] == '7')x7y7++;

                }
            }
        }

        long long int ans (int len, int start, int end){
            if(len == 1){
                if(start == 4 && end == 4)return x4y4;
                if(start == 4 && end == 7)return x4y7;
                if(start == 7 && end == 4)return x7y4;
                if(start == 7 && end == 7)return x7y7;
            }

            else{
                long long int ans1;
                cout << len/2 << "  " << len-len/2 << endl;
                ans1 = (ans(len/2,start,4)*ans(len-len/2, 4, end))%modu;
                ans1 = ans1 + ((ans(len/2,start,7)*ans(len-len/2, 7, end))%modu);
                ans1 = ans1%modu;
                return ans1;
            }
        }

        int count(vector <int> numbers, int length)
        {
                //$CARETPOSITION$
                x4y4 = 0;
                x4y7 = 0;
                x7y4 = 0;
                x7y7 = 0;
                distnm.clear();
                // set<int> myset;
                for (int i = 0; i < numbers.size(); ++i)
                {

                    distnm.insert(numbers[i]);
                }

                preprocess();
                


                long long int a0 = ans(length, 4,4);
                
                long long int a2 = ans(length, 4,7);
                
                long long int a4 = ans(length, 7,4);
                long long int a6 = ans(length, 7,7);
                long long int answer = 0;
                
                answer = a0+a2+a4+a6;
                answer = answer%modu;
                return answer; 
        }

        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const int &Expected, const int &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: \"" << Expected << '\"' << endl; cerr << "\tReceived: \"" << Received << '\"' << endl; } }
	void test_case_0() { int Arr0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 1; int Arg2 = 2; verify_case(0, Arg2, count(Arg0, Arg1)); }
	void test_case_1() { int Arr0[] = {444444444, 777777777, 47474747, 74747474}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 123456789; int Arg2 = 647595951; verify_case(1, Arg2, count(Arg0, Arg1)); }
	void test_case_2() { int Arr0[] = {100, 4774, 200, 747, 300}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 47; int Arg2 = 2; verify_case(2, Arg2, count(Arg0, Arg1)); }
	void test_case_3() { int Arr0[] = {44, 47, 74, 77}; vector <int> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arg1 = 2; int Arg2 = 8; verify_case(3, Arg2, count(Arg0, Arg1)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        TheLuckySequence ___test;
        ___test.run_test(-1);
        system("pause");
        }
    // END CUT HERE 

