#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <climits>
#include <vector>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <queue>
#include <algorithm>
#include <iostream>
#include <string>

#define REP(i,n) for(int i=0;i<n;++i)
#define REPR(i,n) for(int i=n;i>=0;--i)
#define REPI(itr,v) for(auto itr=v.begin();itr!=v.end();++itr)
#define REPIR(itr,v) for(auto itr=v.rbegin();itr!=v.rend();++itr)
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define SORT(v,n) sort(v, v+n)
#define SORTV(v) sort(v.begin(), v.end())
#define ALL(v) v.begin(),v.end()
#define llong long long
#define INF 999999999
#define SUR 1000000007
#define pb(a) push_back(a)
#define pf(a) push_front(a)
#define MP make_pair

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

using namespace std;

typedef pair<int,int> pii;

//木の頂点sからgまでのパスを求める
vector<int> G[100000];
list<int> path;
bool used[100000];
int s, g;

bool getPath(int v){
  if(v == g){
    //gを入れる場合
    //list.push_front(g);
    return true;
  }

  REP(i,G[v].size()){
    if(used[G[v][i]]) continue;
    used[G[v][i]] = true;
    if(getPath(G[v][i])){
      if(v != s)//s入れる場合抜く
        path.push_front(v);
        return true;
    }
  }
  return false;
}

//ここまで

//使用例
int main(){

  int n;
  scanf("%d", &n);

  REP(i,n - 1){
    int a, b;
    scanf("%d %d", &a, &b);
    a--; b--;
    G[a].pb(b);
    G[b].pb(a);
  }

  s = 0; g = n - 1;
  //sのみ使用済みに
  used[s] = true;
  getPath(s);

  REPI(itr,path){
    printf("%d\n", *itr);
  }
  
  return 0;
}

