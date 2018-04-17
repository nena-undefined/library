
struct edge{int u, v; llong cost;};

bool comp(const edge& e1, const edge& e2){
  return e1.cost < e2.cost;
}

llong kruskal(int V, int E, vector<edge> es){
  sort(ALL(es), comp);
  int *par, *rank;

  par = new int[V];
  rank = new int[V];

  init(par, V);
  REP(i,V){
    rank[i] = 0;
  }

  llong res = 0;
  REP(i,E){
    edge e = es[i];
    if(!same(e.u, e.v, par)){
      unite(e.u, e.v, par, rank);
      res += e.cost;
    }
  }
  
  delete[] par;
  delete[] rank;

  return res;
}
