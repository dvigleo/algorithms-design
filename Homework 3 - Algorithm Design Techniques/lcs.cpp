/*
  Daniela Vignau
  A01021698
  Exercise 3: Longest Common Subsequence
  Technique: Dynamic programming
    Because of its optimal substructure and overlapping subproblems
  Complexity: The worst case scneario is when there is no common subsequence. The complexity is O(nm) where n and m are the sizes of each string. This is because it needs to go through each of the characters in the string
*/

#include <iostream>
#include <cstring>
using namespace std;

int max(int a, int b){
  return (a > b) ? a : b;
}

int lcs(string a, string b, int sizeA, int sizeB){
  int lcsCount[sizeA + 1][sizeB + 1];
  int i = 0, j = 0;

  for (i = 0; i <= sizeA; ++i) {
    for (j = 0; j <= sizeB; ++j) {
      if (i == 0 || j == 0)
        lcsCount[i][j] = 0;
      else if (a[i - 1] == b[j - 1])
        lcsCount[i][j] = lcsCount[i - 1][j - 1] + 1;
      else
        lcsCount[i][j] = max(lcsCount[i - 1][j], lcsCount[i][j - 1]);
    }
  }
  return lcsCount[sizeA][sizeB];
}


int main(){
  string stringA, stringB;
  cout << "\nLongest Common Subsequence\n";
  cout << "\nType in word 1: ";
    cin >> stringA;
  cout << "Type in word 2: ";
    cin >> stringB;
  int sizeA = stringA.length(), sizeB = stringB.length();

  cout<<"\nThe LCS is: " << lcs(stringA, stringB, sizeA, sizeB) << endl;

  return 0;
}
