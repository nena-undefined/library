int cost[MAX_V][MAX_V];
int mincost[MAX_V];
bool used[MAX_V];
int V;

int prim(){
  REP(i,V){
    mincost[i] = INF;
    used[i] = false;
  }

  mincost[0] = 0;
  int res = 0;

  while(true){
    int v = -1;

    REP(u,V){
      if(!used[u] && (v == -1 || mincost[u] < mincost[v])){
        v = u;
      }
    }

    if(v == -1) break;
    used[v] = true;
    res += mincost[v];

    REP(u,V){
      mincost[u] = min(mincost[u], cost[v][u]);
    }
  }

  return res;
}
