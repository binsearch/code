#include <iostream>
#include <set>
#include <cstdio>
int min(int a,int b)
{
 return (a<b)?a:b;
}
int minDistance(int word1[], int word2[],int l1,int l2)
{
 
    int d[l1+1][l2+1];
 
    for (int i = 0; i < l2 + 1; i++) {
        d[0][i] = i;
    }
 
    // the edit distance between an empty string and the prefixes of
    // word1
    for (int j = 0; j < l1 + 1; j++) {
        d[j][0] = j;
    }
 
    for (int i = 1; i < l1 + 1; i++) {
        for (int j = 1; j < l2 + 1; j++) {
            if (word1[i - 1] == word2[j - 1]) {
                d[i][j] = d[i - 1][j - 1];
            } else {
                d[i][j] =min(1 + d[i][j - 1],min(1 + d[i - 1][j],1 + d[i - 1][j - 1])); // min of insertion,
                // deletion, replacement
            }
        }
    }
 
    return d[l1][l2];
}
int main()
{
     int t,st,fa,i;
    scanf("%d",&t);
	while(t--)
	{
	 scanf("%d",&st);
	 int stud[st];
	 for(i=0;i<st;i++)
	 {
	  scanf("%d",&stud[i]);
	 } 
	 scanf("%d",&fa);
	 int fac[fa];
	 for(i=0;i<fa;i++)
	 {
	  scanf("%d",&fac[i]);
	 }
	 printf("%d\n",minDistance(stud,fac,st,fa));
  }	 
 return 0;
} 