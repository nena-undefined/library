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
#define SV(n,v) {int tmp;for(int i=0;i<n;++i){scanf("%d",&tmp);v.push_back(tmp);}}

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

using namespace std;

typedef pair<int,int> pii;

//ベルマンフォード法はここから
//負の閉路の検出にも使える。正の閉路の検出に使いたい場合は
//コストの正負を逆にすればよい(結果も逆になるが)
//|V|回目でもループの更新があると、負の閉路があることになる。

#define MAX_V 10000
#define MAX_E 10000

struct edge{int from, to; llong cost;};

edge es[MAX_E]; //辺はこの配列に入れる

llong d[MAX_V]; //最短距離
int V, E; //頂点数と辺数

void shortest_path(int s){
  REP(i,V){
    d[i] = LLONG_MAX; //INFで間に合うか確認
  }

  d[s] = 0;
  while(true){
    bool update = false;
    REP(i,E){
      edge e = es[i];
      if(d[e.from] != LLONG_MAX && d[e.to] > d[e.from] + e.cost){
        d[e.to] = d[e.from] + e.cost;
        update = true;
      }
    }
    if(!update){
      break;
    }
  }
}

//ここまで

int main(){

  
  return 0;
}

