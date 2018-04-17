struct edge{int to, cost;};

vector<edge> G[MAX_V];
int d[MAX_V][MAX_V]; //sからの最短距離(dは0で初期化する)

void dijkstra(int s){
  priority_queue<pii, vector<pii>, greater<pii>> que;
  d[s][s] = 0;
  que.push(pii(0,s));

  while(!que.empty()){
    pii p = que.top(); que.pop();
    int v = p.second;
    if(d[s][v] < p.first) continue;
    REP(i,(int)G[v].size()){
      edge e = G[v][i];
      if(d[s][e.to] > d[s][v] + e.cost){
        d[s][e.to] = d[s][v] + e.cost;
        que.push(pii(d[s][e.to], e.to));
      }
    }
  }
}
