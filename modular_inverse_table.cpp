#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

// Repeat squares method. This algorithm is  O(logn)
long long mod_pow(long long x, long long n){
  long long res = 1;
  while(n > 0){
    if((n & 1) == 1){
      res = res * x % MOD;
    }
    x = x * x  % MOD;
    n /= 2;
  }
  return res;
}

struct modular_table{
public:
  vector<long long> table;  //table[N] is N^(-1) % MOD
  
  modular_table(int n): table(n + 1){
    long long fact = 1;
    
    for(int i = 1; i <= n; ++i){
      fact = fact * i % MOD;
    }

    table[n] = mod_pow(fact, MOD - 2);
    for(int i = n - 1; i >= 0; --i){
      table[i] = table[i + 1] * (i + 1) % MOD;
    }
  }
};

int main(){

  modular_table modt(100);

  for(int i = 0; i < 101; ++i){
    cout << i << " " << modt.table[i] << endl;
  }
  return 0;
}
