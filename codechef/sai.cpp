#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <string>
#include <set>
#include <queue>
#define x getchar_unlocked()
#define lli long long int
#define mod 1000000007
#define inf 999999999
#define ii pair<int,int>
using namespace std;

inline void inp(int &n ) {//fast input function
	n=0;
	int ch=x,sign=1;
	while( ch < '0' || ch > '9' ){if(ch=='-')sign=-1; ch=x;}
	while( ch >= '0' && ch <= '9' )
		n=(n<<3)+(n<<1)+ ch-'0', ch=x;
	n=n*sign;
}

int g[1000010][26],t,w,n,m;
int f[1000010],states=1,cur;
char words[1010][1010],board[1010][1010];
int sz[1000]={0};
queue<int> q;
int out[1000001];

void build_ahocorasick() {
	memset(g[0],-1,sizeof g[0]);
	// memset(f,-1,sizeof f);
	// memset(out,-1,sizeof out);
	out[0]=-1;
	// memset(sz,0,sizeof sz);
	states=1;
	for(int i=0;i<w;i++) {
		cur=0;
		int j;
		for(j=0;words[i][j]!='\0';j++) {
			 // cout<<cur<<" "<<i<<" "<<j<<" "<<words[i][j]<<endl;
			 // cout<<g[cur][words[i][j]-'A']<<endl;
			if(g[cur][words[i][j]-'A']==-1) {
				// cout<<"man\n";
				memset(g[states],-1,sizeof g[states]);
				out[states]=-1;
				g[cur][words[i][j]-'A']=states++;
			}
			// cout<<states<<endl;
			cur=g[cur][words[i][j]-'A'];
			// cout<<cur<<" "<<words[i][j]<<endl;
		}
		sz[i]=j;
		// out[cur].insert(i);
		out[cur]=i;

		// cout<<cur<<" "<<out[cur]<<endl;
	}

	f[0]=0;
	

	for(int i=0;i<26;i++) {
		if(g[0][i]!=-1) {
			f[g[0][i]]=0;
			q.push(g[0][i]);
		}
		else
			g[0][i]=0;
	}


	while(!q.empty()) {
		cur=q.front();

		q.pop();

		for(int i=0;i<26;i++) {
			int next=g[cur][i];
			int rev=g[f[cur]][i];

			if(next==-1)
				g[cur][i]=rev;

			else {
				q.push(next);
				f[next]=rev;
				if(out[f[next]]!=-1)
					out[next]=out[f[next]];
			}


				// while(g[f[cur]][i]==-1)
				// 	cur=f[cur];

				// f[r]=g[f[cur]][i];

				// if(out[f[r]]!=-1)
				// 	out[r]=out[f[r]];
				//for(set<int>::iterator it=out[f[r]].begin();it!=out[f[r]].end();it++)
				//	out[r].insert(out[cur]);
			// }

			// int next=g[cur][i];
			// int rev=g[fail[cur]][i];
		}

	}
}

inline int nextstate(int state,char ch) {
	// while(g[state][ch-'A']==-1)
	// 	state=f[state];

	return g[state][ch-'A'];
}

int ans[1000][3];

int main() {

	inp(t);
	for(int a=0;a<t;a++) {
		inp(n);
		inp(m);
		inp(w);
		for(int i=0;i<n;i++) {
			// getline(cin,board[i]);
			scanf("%s",board[i]);
		}

		for(int i=0;i<w;i++) {
			// getline(cin,words[i]);
			scanf("%s",words[i]);
		}



		build_ahocorasick();

		for(int i=0;i<n;i++) {
			cur=0;
			for(int j=0;j<m;j++) {
				cur=nextstate(cur,board[i][j]);

				
				if(out[cur]!=-1) {
					ans[out[cur]][0]=i;
					ans[out[cur]][1]=j-sz[out[cur]]+1;
					ans[out[cur]][2]=2;
				}
			}

			cur=0;
			for(int j=m-1;j>=0;j--) {
				cur=nextstate(cur,board[i][j]);

				
				if(out[cur]!=-1) {
					ans[out[cur]][0]=i;
					ans[out[cur]][1]=j+sz[out[cur]]-1;
					ans[out[cur]][2]=6;
				}
			}


			cur=0;
			for(int j=0,i1=i;j<m && i1<n;i1++,j++) {
				cur=nextstate(cur,board[i1][j]);

				
				if(out[cur]!=-1) {
					ans[out[cur]][0]=i1-sz[out[cur]]+1;
					ans[out[cur]][1]=j-sz[out[cur]]+1;
					ans[out[cur]][2]=3;
				}
			}

			cur=0;
			for(int j=m-1,i1=i;j>=0 && i1<n;i1++,j--) {
				cur=nextstate(cur,board[i1][j]);

				
				if(out[cur]!=-1) {
					ans[out[cur]][0]=i1-sz[out[cur]]+1;
					ans[out[cur]][1]=j+sz[out[cur]]-1;
					ans[out[cur]][2]=5;
				}
			}
			// cout<<"Sai\n";
			cur=0;
			for(int j=0,i1=i;j<m && i1>=0;i1--,j++) {
				cur=nextstate(cur,board[i1][j]);

				// cout<<board[i][j];
				
				if(out[cur]!=-1) {
					ans[out[cur]][0]=i1+sz[out[cur]]-1;
					ans[out[cur]][1]=j-sz[out[cur]]+1;
					ans[out[cur]][2]=1;
					// cout<<"wahh\n";
				}
			}

			// cout<<endl;

			cur=0;
			for(int j=m-1,i1=i;j>=0 && i1>=0;i1--,j--) {
				cur=nextstate(cur,board[i1][j]);

				
				if(out[cur]!=-1) {
					ans[out[cur]][0]=i1+sz[out[cur]]-1;
					ans[out[cur]][1]=j+sz[out[cur]]-1;
					ans[out[cur]][2]=7;
				}
			}

		}

		for(int j=0;j<m;j++) {
			cur=0;
			for(int i=0;i<n;i++) {
				cur=nextstate(cur,board[i][j]);

				
				if(out[cur]!=-1) {
					ans[out[cur]][0]=i-sz[out[cur]]+1;
					ans[out[cur]][1]=j;
					ans[out[cur]][2]=4;
				}
			}

			cur=0;
			for(int i=n-1;i>=0;i--) {
				cur=nextstate(cur,board[i][j]);

				
				if(out[cur]!=-1) {
					ans[out[cur]][0]=i+sz[out[cur]]-1;
					ans[out[cur]][1]=j;
					ans[out[cur]][2]=0;
				}
			}


			cur=0;
			for(int i=0,j1=j;i<n && j1<m;i++,j1++) {
				cur=nextstate(cur,board[i][j1]);

				
				if(out[cur]!=-1) {
					ans[out[cur]][0]=i-sz[out[cur]]+1;
					ans[out[cur]][1]=j1-sz[out[cur]]+1;
					ans[out[cur]][2]=3;
				}
			}

			cur=0;
			for(int i=n-1,j1=j;i>=0 && j1>=0;i--,j1--) {
				cur=nextstate(cur,board[i][j1]);

				
				if(out[cur]!=-1) {
					ans[out[cur]][0]=i+sz[out[cur]]-1;
					ans[out[cur]][1]=j1+sz[out[cur]]-1;
					ans[out[cur]][2]=7;
				}
			}


			cur=0;
			for(int i=0,j1=j;i<n && j1>=0;i++,j1--) {
				cur=nextstate(cur,board[i][j1]);

				
				if(out[cur]!=-1) {
					ans[out[cur]][0]=i-sz[out[cur]]+1;
					ans[out[cur]][1]=j1+sz[out[cur]]-1;
					ans[out[cur]][2]=5;
				}
			}

			cur=0;
			for(int i=n-1,j1=j;i>=0 && j1<m;i--,j1++) {
				cur=nextstate(cur,board[i][j1]);

				
				if(out[cur]!=-1) {
					ans[out[cur]][0]=i+sz[out[cur]]-1;
					ans[out[cur]][1]=j1-sz[out[cur]]+1;
					ans[out[cur]][2]=1;
				}
			}

		}

		if(a)
			printf("\n");
		char ch;
		for(int i=0;i<w;i++) {
			ch='A'+ans[i][2];
			printf("%d %d %c\n",ans[i][0],ans[i][1],ch);
			// cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ch<<endl;
		}

	}
	return 0;
}
