/*
Author:Atul Pandey
*/
#include <bits/stdc++.h>
typedef long long int ll;
#define pll pair <ll, ll>
#define pii pair <int, int>
#define f first
#define s second
#define pb push_back
#define vll vector <ll>
#define mll map <ll ,ll>
#define prtq priority_queue <long long>
#define all(c) c.begin(), c.end()
#define rep(a,b) for(i=a;i<b;i++)
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define inf 1e18
using namespace std;
#define Mod 1000000007
// #define endl "\n"
////////////////////////////////////////////////////////////////////

void fio() // file input output
{
#ifndef ONLINE_JUDGE
  freopen("input1.txt", "r", stdin);
  freopen("output1.txt", "w", stdout);
#else
#endif
}

void tim()
{
#ifndef ONLINE_JUDGE
  cerr << "Time elapsed: " << clock() / 1000 << " ms" << endl;
#endif
}
const int N=200011;
vll adj[N];
int up[N][20];
int level[N];
void dfs(int node,int par,int lvl)
{

  
    level[node]=lvl;
    up[node][0]=par;
    for(int j=1;j<20;j++)
    {
    // if(node==10)cout<<up[8][1];
        if(up[node][j-1]!=-1)up[node][j] = up[up[node][j-1]][j-1];
        else up[node][j]=up[node][j-1];
    }
    for(int child:adj[node])
    {
      if(child!=par)
        dfs(child,node,lvl+1);
    }
    
  

}

    int get_lca(int a,int b)
    {   
            if(level[a]<level[b])swap(a,b);
            int dif=level[a]-level[b];
            int j=19;
            while(j>=0)
            {
              if(dif&(1<<j)){
                // cout<<a<<" ";        
                a=up[a][j];   
                // dif-=1<<j;     
              }

              j--;
            }

           // if b and a on same path then now will be equal to b;
            // cout<<level[a]<<level[b]<<endl;
            if(a==b)return a;
            // cout<<"yes";
            j=19;
            while(j>=0)
            {
              if(up[a][j]!=up[b][j]){
                a=up[a][j];
                b=up[b][j];
              }
              j--;
            }
            return up[a][0];

    }
int main()
{
  fio();
  IOS;
  int t;
  t = 1;
  // cin >> t;   

  while (t--)
  { 
    int n,m;
    cin>>n>>m;

    for(int i=2;i<=n;i++){
      int x,y;
      cin>>x>>y;
      adj[x].pb(y);
      adj[y].pb(x);
    }
    dfs(1,-1,1);

    while(m--)
    {
      int a,b;
      cin>>a>>b;
      // cout<<up[8][1];
      cout<< level[a]+level[b]-2*level[get_lca(a,b)]<<endl;
    }

      
          


  }
  return 0;

}
