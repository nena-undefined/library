struct edge{int to, cost;};

vector<edge> G[MAX_V];
int d[MAX_V]; //sからの最短距離(dはINFで初期化する)

void dijkstra(int s){
  priority_queue<pii, vector<pii>, greater<pii>> que;
  d[s] = 0;
  que.push(pii(0,s));

  while(!que.empty()){
    pii p = que.top(); que.pop();
    int v = p.second;
    if(d[v] < p.first) continue;
    REP(i,(int)G[v].size()){
      edge e = G[v][i];
      if(d[e.to] > d[v] + e.cost){
        d[e.to] = d[v] + e.cost;
        que.push(pii(d[e.to], e.to));
      }
    }
  }
}
