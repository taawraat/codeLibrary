
#include <iostream>
#define MAX 20000001
char prime[MAX];
using namespace std;

// findGCD function to find GCD
int findGCD(int first, int second)
{ 
  if(!second)
    return first;
  
  return findGCD(second, first % second);
}

// check if n is prime
bool isPrime(int n){
  if(n == 2) return true;
  else if(!(n & 1)) return false;
  else if(!prime[n]) return true;
  else return false;
}

// prime function using sieve
void primeGen(){
  prime[1] = 1;
  for(int i = 3; i*i <= MAX ; i += 2)
    if(isPrime(i))
      for(int j = i+i; j <= MAX; j += i)
        prime[j] = 1;
}

// bigMod function to calculate (a^b mod m)
ll bigMod(ll a, ll b, ll m)
{
  ll ans = 1;
  a = a % m;
  
  while(b){
    // checking if bit is 1
    if(b & 1)
      ans = (ans * a) % m;
      
    a = (a*a) % m;
    b /= 2;
  }
  return ans;
}

// driver function
int main(){
  primeGen();
  
  // start
}