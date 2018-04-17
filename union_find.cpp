#include <cstdio>

#define MAX 100

int par[MAX], rank[MAX];
int n;


void init(int par[], int V){
  for(int i = 0; i < V; ++i)
    par[i] = i;
}

int find(int x, int par[]){
  if(par[x] == x){
    return x;
  }else{
    return par[x] = find(par[x], par);
  }
}

void unite(int x, int y, int par[], int rank[]){
  x = find(x, par);
  y = find(y, par);

  if(x == y)
    return;

  if(rank[x] > rank[y]){
    par[y] = x;
  }else{
    par[x] = y;
    if(rank[x] == rank[y])
      rank[y]++;
  }
}

int same(int x, int y, int par[]){
  return find(x, par) == find(y, par);
}

