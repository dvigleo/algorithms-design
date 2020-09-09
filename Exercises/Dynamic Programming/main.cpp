#include <iostream>
#include <chrono>
using namespace std;

int FibIterativo(int n){
  int suma, x, y;
  if(n <= 1)
    return 1;
  else {
    x = 1;
    y = 1;
    for(int i = 2; i < n; ++i){
      suma = x + y;
      y = x;
      x = suma;
    }
    return suma;
  }
}

int Fib(int n){
  if(n == 0 || n == 1){
    return 1;
  }
  else {
    return Fib(n - 1) + Fib(n - 2);
  }
  return -1;
}

int main(){
  int n, technique, answer;
  clock_t start, end;
  cout << "Input the value to calculate\n";
    cin >> n;
  cout << "1. Recursive Fibonacci\n2. Iterative Fibonacci\n";
    cin >> technique;

  switch(technique){
    case 1:
      {
        auto start = chrono::steady_clock::now();
        answer = Fib(n);
        auto end = chrono::steady_clock::now();
        cout << "Time taken by Recursive Fibonacci of " << n << " is \t" << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms\n" << endl;
        cout << "Fibonacci of: " << answer << endl;
      }
      break;
    case 2:
      {
        auto start = chrono::steady_clock::now();
        answer = FibIterativo(n);
        auto end = chrono::steady_clock::now();
        cout << "Time taken by Iterative Fibonacci of " << n << " is \t" << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms\n" << endl;
        cout << "Fibonacci of: " << answer << endl;
      }
      break;
  }
  return 0;
}
