#line 2 "StrongPrimePower.cpp"
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
#define lim 1000000
using namespace std;
class StrongPrimePower
        {
        public:
            int squaroot(long long int val,int left, int right){
                // cout << val << endl;
                long long int newval = (left+right)/2;
                long long int check;
                check = newval*newval;
                // cout << check << endl;
                // cout << left << "    " << right <<  endl;
                // cout << check - val << endl;
                if(check - val == 0){
                    return newval;
                }

                if(right-left == 1){
                    return -1;
                }

                if(check-val < 0){
                    return squaroot(val, newval, right);
                }
                else{
                    return squaroot(val, left, newval);
                }
            }

            int A[1000001];
            vector <int> baseAndExponent(string n)
            {
                memset(A,0,sizeof A);
                long long int num;
                num = 0;
                std::vector<int> sol;
                for(int i = 0; n[i] != '\0'; i++){
                    num = num*10 + (n[i] - '0'); 
                }
                // cout << num << " value" << endl;
                int root = squaroot(num,1,1000000001);
                if(root != -1){
                    int flag = 0;
                    for(int i = 2; i <= sqrt(root); i++){
                        if(root%i == 0) {
                            flag = 1;
                            break;
                        }
                    }

                    if(flag == 0){
                        sol.push_back(root);
                        sol.push_back(2);
                        return sol;
                    } 
                }

                int lim1 = sqrt(lim); 
                for(int i=2;i<=lim1+4;i++) {
                    if(A[i]==0) {
                        for(int j=i*i;j<=lim;j+=i) {
                            A[j]=1;
                        }
                    }
                }

                for(int i = 2; i <= lim ; i++){
                    if(A[i] == 0){
                        if(num%i == 0){
                            int flag = 0;
                            long long int temp = num;
                            int j = 0;
                            while(1){

                                if(temp == 1){
                                    flag = 1;
                                    break;
                                }
                                if(temp%i == 0){
                                    temp = temp / i;

                                }
                                else{
                                    break;
                                }
                                j++;
                            }

                            if(flag == 1 && j > 1){
                                sol.push_back(i);
                                sol.push_back(j);
                                break;
                            }


                        }
                    }
                }

                return sol;
            
            //$CARETPOSITION$
            }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); if ((Case == -1) || (Case == 5)) test_case_5(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arg0 = "27"; int Arr1[] = {3, 3 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, baseAndExponent(Arg0)); }
	void test_case_1() { string Arg0 = "10"; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, baseAndExponent(Arg0)); }
	void test_case_2() { string Arg0 = "7"; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, baseAndExponent(Arg0)); }
	void test_case_3() { string Arg0 = "1296"; int Arr1[] = { }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, baseAndExponent(Arg0)); }
	void test_case_4() { string Arg0 = "576460752303423488"; int Arr1[] = {2, 59 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, baseAndExponent(Arg0)); }
	void test_case_5() { string Arg0 = "999999874000003969"; int Arr1[] = {999999937, 2 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(5, Arg1, baseAndExponent(Arg0)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        StrongPrimePower ___test;
        ___test.run_test(-1);
        system("pause");
        }
    // END CUT HERE 

