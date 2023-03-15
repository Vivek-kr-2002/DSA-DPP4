#include<bits/stdc++.h>
using namespace std;

#define nn                    '\n' 
#define pb                    push_back 
#define SS                    stringstream 
#define ull                   unsigned long long 
#define mod                   1000000007 
#define INF                   2147483647 
#define SIZE                  2000001 
 
#define sf1(a)                scanf("%d", &a) 
#define sf2(a,b)              scanf("%d %d",&a, &b) 
#define sf3(a,b,c)            scanf("%d %d %d", &a, &b, &c) 
#define sf4(a,b,c, d)         scanf("%d %d %d %d", &a, &b, &c, &d)
 #define sf(n) scanf("%d", &n)
#define sff(n,m) scanf("%d%d",&n,&m)
#define sfl(n) scanf("%I64d", &n)
#define sffl(n,m) scanf("%I64d%I64d",&n,&m)
#define pf(n) printf("%d",n)
#define pff(n,m) printf("%d %d",n,m)
#define pffl(n,m) printf("%I64d %I64d",n,m)
#define pfl(n) printf("%I64d",n)
#define pfs(s) printf("%s",s)
#define lli long long int
#define pb push_back
#define f first
#define sec second

int knapsack(int * weights, int * profits, int n, int maxWeight) {
  
  int ** dp = new int * [n + 1];

  
  for (int i = 0; i < n + 1; i++) {

   
    dp[i] = new int[maxWeight + 1];
  }

  
  
  for (int i = 0; i < n + 1; i++) {
    
    for (int j = 0; j < maxWeight + 1; j++) {
      
      if (i == 0 || j == 0)
     
        dp[i][j] = 0;

      
      else if (weights[i - 1] > j) {
       
        dp[i][j] = dp[i - 1][j];
      } 
       else {

     
        dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - weights[i - 1]] + profits[i - 1]);

      }

    }

  
  }
  return dp[n][maxWeight];

}


int main() {

  
  int n;
  
  cin >> n;
  
  int * weights = new int[n];
  
  int * profits = new int[n];

  
  for (int i = 0; i < n; i++) {
    
    cin >> weights[i];
  }

  
  for (int i = 0; i < n; i++) {
    
    cin >> profits[i];
  }

  
  int maxWeight;
  
  cin >> maxWeight;

  
  cout << knapsack(weights, profits, n, maxWeight);


}
