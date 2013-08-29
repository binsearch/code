#line 2 "grafixMask.cpp"
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
#include <queue>
#include <cstring>
#define rows 400
#define cols 600
using namespace std;
class grafixMask
        {
        public:
        std::vector<vector<int> > fill;
        vector <int> sortedAreas(vector <string> rectangles)
            {   
                std::vector<int> temp;

                temp.assign(600,0);
                fill.assign(400,temp);
                for(int i = 0; i < rectangles.size(); i++){
                    string coord = rectangles[i];
                    stringstream in;
                    in << coord;
                    int x1,y1,x2,y2;
                    in >> x1 >> y1 >> x2 >> y2;
                    for(int j = x1; j <= x2; j++){
                        for(int k = y1; k <= y2; k++){
                            fill[j][k] = 1;
                        }
                    }                    
                }

                int x,y;
                x = 0; y = 0;
                std::vector<int> ans;
                while (true){
                    queue<pair<int,int> > bfs;
                    // bfs.clear();
                    int flag = 0;
                    int area = 0;
                    for(int i = 0; i < rows; i++){
                        for(int j = 0; j < cols; j++){
                            if(fill[i][j] == 0){
                                // x = i;
                                // y = j;
                                bfs.push(make_pair(i,j));
                                flag = 1;
                                break;
                            }
                        }

                        if(flag == 1)break;
                    }
                    
                    if(flag == 0) break;

                    while(!bfs.empty()){
                        int tx;
                        int ty;

                        tx = (bfs.front()).first;
                        ty = (bfs.front()).second;
                        bfs.pop();
                        if(tx >= rows || ty >= cols || tx < 0 || ty < 0)
                            continue;
                        if(fill[tx][ty] == 1)
                            continue;

                        fill[tx][ty] = 1;
                        area++;
                        bfs.push(make_pair(tx-1,ty));
                        bfs.push(make_pair(tx+1,ty));
                        bfs.push(make_pair(tx,ty-1));
                        bfs.push(make_pair(tx,ty+1));


                    }

                    ans.push_back(area);



                }
                sort(ans.begin(),ans.end());
                return ans;

            //$CARETPOSITION$
            }
        
// BEGIN CUT HERE
	public:
	void run_test(int Case) { if ((Case == -1) || (Case == 0)) test_case_0(); if ((Case == -1) || (Case == 1)) test_case_1(); if ((Case == -1) || (Case == 2)) test_case_2(); if ((Case == -1) || (Case == 3)) test_case_3(); if ((Case == -1) || (Case == 4)) test_case_4(); }
	private:
	template <typename T> string print_array(const vector<T> &V) { ostringstream os; os << "{ "; for (typename vector<T>::const_iterator iter = V.begin(); iter != V.end(); ++iter) os << '\"' << *iter << "\","; os << " }"; return os.str(); }
	void verify_case(int Case, const vector <int> &Expected, const vector <int> &Received) { cerr << "Test Case #" << Case << "..."; if (Expected == Received) cerr << "PASSED" << endl; else { cerr << "FAILED" << endl; cerr << "\tExpected: " << print_array(Expected) << endl; cerr << "\tReceived: " << print_array(Received) << endl; } }
	void test_case_0() { string Arr0[] = {"0 292 399 307"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 116800,  116800 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(0, Arg1, sortedAreas(Arg0)); }
	void test_case_1() { string Arr0[] = {"48 192 351 207", "48 392 351 407", "120 52 135 547", "260 52 275 547"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 22816,  192608 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(1, Arg1, sortedAreas(Arg0)); }
	void test_case_2() { string Arr0[] = {"0 192 399 207", "0 392 399 407", "120 0 135 599", "260 0 275 599"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 22080,  22816,  22816,  23040,  23040,  23808,  23808,  23808,  23808 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(2, Arg1, sortedAreas(Arg0)); }
	void test_case_3() { string Arr0[] = {"50 300 199 300", "201 300 350 300", "200 50 200 299", "200 301 200 550"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 1,  239199 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(3, Arg1, sortedAreas(Arg0)); }
	void test_case_4() { string Arr0[] = {"0 20 399 20", "0 44 399 44", "0 68 399 68", "0 92 399 92",
 "0 116 399 116", "0 140 399 140", "0 164 399 164", "0 188 399 188",
 "0 212 399 212", "0 236 399 236", "0 260 399 260", "0 284 399 284",
 "0 308 399 308", "0 332 399 332", "0 356 399 356", "0 380 399 380",
 "0 404 399 404", "0 428 399 428", "0 452 399 452", "0 476 399 476",
 "0 500 399 500", "0 524 399 524", "0 548 399 548", "0 572 399 572",
 "0 596 399 596", "5 0 5 599", "21 0 21 599", "37 0 37 599",
 "53 0 53 599", "69 0 69 599", "85 0 85 599", "101 0 101 599",
 "117 0 117 599", "133 0 133 599", "149 0 149 599", "165 0 165 599",
 "181 0 181 599", "197 0 197 599", "213 0 213 599", "229 0 229 599",
 "245 0 245 599", "261 0 261 599", "277 0 277 599", "293 0 293 599",
 "309 0 309 599", "325 0 325 599", "341 0 341 599", "357 0 357 599",
 "373 0 373 599", "389 0 389 599"}; vector <string> Arg0(Arr0, Arr0 + (sizeof(Arr0) / sizeof(Arr0[0]))); int Arr1[] = { 15,  30,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  45,  100,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  115,  200,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  230,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  300,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345,  345 }; vector <int> Arg1(Arr1, Arr1 + (sizeof(Arr1) / sizeof(Arr1[0]))); verify_case(4, Arg1, sortedAreas(Arg0)); }

// END CUT HERE

        };

    // BEGIN CUT HERE
    int main()
        {
        grafixMask ___test;
        ___test.run_test(-1);
        system("pause");
        }
    // END CUT HERE 

