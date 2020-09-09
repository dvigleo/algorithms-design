/*
  Daniela Vignau
  A01021698
  Exercise 4: Stable marriage
  Technique: Greedy algorithm
    Because at each step, the one's who propose make a locally optimal choice by selecting the best partner that hasn't been proposed to at the time.
  Complexity: Because the matrix is iterated n times two times (one for the men and one for the women), it is: O(n^2)
*/

#include <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;

#define N  4  // Number of men and women

void printCouples(int wPartner []) {
  cout << "Woman #   \t      Man #" << endl;
  for(int i = 0; i < N; ++i){
    cout << "   " << i+N << "   is engaged to    " << wPartner[i] << endl;
  }
}

bool chooseBetweenMen(int prefer[2*N][N], int woman, int secondMan, int firstMan) {
    for (int i = 0; i < N; i++)  {
        // if the second man has preference over the firstMan, woman changes her current engagement to the second man
        if (prefer[woman][i] == firstMan) return false;

        // If firstMan has preference over secondMan, the woman changes her current engangement to the firstMan
        if (prefer[woman][i] == secondMan) return true;
    }
    return false;
}

void stableMarriage(int prefer[2*N][N]) {
    int wPartner[N];
    bool mFree[N]; // If mFree is false, then he is single, otherwise he's engaged

    memset(wPartner, -1, sizeof(wPartner)); // Women are all single
    memset(mFree, false, sizeof(mFree)); // Men are all single
    int singleCount = N; //Number of single men

    while (singleCount > 0) {
      int firstMan;
      for (firstMan = 0; firstMan < N; firstMan++){
        if (mFree[firstMan] == false) break;
      }

      //Check preference of first freeMan picked
      for (int i = 0; i < N && mFree[firstMan] == false; i++) {
        int woman = prefer[firstMan][i];
        //If the woman the man wants is single, they become engaged
        if (wPartner[woman-N] == -1) {
          wPartner[woman-N] = firstMan;
          mFree[firstMan] = true;
          singleCount--;
        }
        else   // If the woman is not single
        {
          int secondMan = wPartner[woman-N]; //Current engagement of woman
          // Check if the woman prefers firstMan over her current engagement.
          bool changeOfEngagement = chooseBetweenMen(prefer, woman, secondMan, firstMan);
          if (changeOfEngagement == false){
              wPartner[woman-N] = firstMan;
              mFree[firstMan] = true;
              mFree[secondMan] = false;
          }
        }
      }

    }
    printCouples(wPartner);
}

int main() {
    int couples[2*N][N] = {
        // men
        {7, 4, 6, 5},
        {5, 6, 4, 7},
        {4, 5, 6, 7},
        {6, 5, 4, 7},

        // women
        {0, 1, 2, 3},
        {1, 2, 3, 0},
        {2, 3, 0, 1},
        {3, 2, 1, 0},
    };
    stableMarriage(couples);
    return 0;
}
