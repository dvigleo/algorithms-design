/*
  Daniela Vignau
  A01021698
  Exercise 1: Driver truck
  Technique: Greedy algorithm
    It makes a greedy choice when filling up the tank at the farthest reachable gas station
  Complexity: O(n) because there's only one for loop going through the n distances of the gas stations
*/
#include <iostream>
using namespace std;

int main() {
  int tank = 95, distanceTravelled = 0, refill = 0, n = 6;
  int gasStation [n]= {58, 49, 25, 78, 94, 76};

  cout << "\nCDMX                              Acapulco" << endl;
  cout << "|-----|-----|-----|-----|-----|-----|" << endl;
  cout << "0----58----107---132---210---304---380   km\n\n";

  cout << "Tank capacity: " << tank << endl << endl;
  int usedGas = tank;
  for(int i = 0; i <= n - 1; ++i){
      usedGas -= gasStation[i];
      distanceTravelled += gasStation[i];
      if(usedGas < gasStation[i + 1]){
          cout << "Stopping at gas station located at km " << distanceTravelled << endl;
          usedGas = tank;
          refill++;
      }
  }
  cout << "\nThe driver must stop to refill " << refill << " times"<< endl;
  refill = 0;
  return 0;
}
