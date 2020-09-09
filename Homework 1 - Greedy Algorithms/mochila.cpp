/*
  Daniela Vignau
  A01021698
*/

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

void backpack(float wb[][2], int maxWeight, int maxElements) {
	float bp[maxElements + 1][maxWeight + 1];

  // The bag is empty
	for (int i = 0; i <= maxElements; ++i){
    for (int j = 0; j <= maxWeight; ++j) {
      bp[i][j] = 0;
    }
  }

	for (int i = 1; i <= maxElements; ++i) {
		for (int j = 0; j <= maxWeight; ++j) {
			bp[i][j] = bp[i - 1][j];
      float weight = wb[i - 1][1];
      float benefit = wb[i - 1][2];
			if ((j >= weight) && (bp[i][j] < (bp[i - 1][j - weight] + benefit))) {
				bp[i][j] = bp[i - 1][j - weight] + benefit;
			}

			cout << bp[i][j] << " " << endl;
		}
		cout << endl;
	}

  cout << "Max Value:\t" <<  bp[maxElements][maxWeight] << endl;
  cout << "Selected packs: ";

	while (maxElements != 0) {
		if (bp[maxElements][maxWeight] != bp[maxElements - 1][maxWeight]) {
      cout << "\tPackage " << maxElements << " with W = " << wb[maxElements - 1][1] << " and Value = " << wb[maxElements - 1][2] << endl;
			maxElements = maxElements - wb[maxElements - 1][1];
		}

		maxElements--;
	}
}

float floatRand(float mW){
  return float(rand())/(float(RAND_MAX/(mW)));
}

int main(){
  int maxElements = 0, maxWeight = 0;
  cout << "Type in the total number of elements that your bag can handle: ";
    cin >> maxElements;
  cout << "Type in the maximum weight that your bag can handle: ";
    cin >> maxWeight;

  // Creating a dynamic arrays
  float weight[maxElements];
  int benefit[maxElements];
  float ratio[maxElements];

  srand(time(NULL)); // Seed to generate random numbers over and over

  // Creating a randomly filled array of weight and benefit
  for(int i = 0; i < maxElements; ++i){
    weight[i] = floatRand(maxWeight) + 1;
    benefit[i] = rand() % 10;
  }

  float weightBenefit[maxElements][2];
  // Making one array for our weights and its corresponding benefit
  for(int i = 0; i < maxElements; ++i){
    weightBenefit[i][1] = weight[i];
    weightBenefit[i][2] = (float)benefit[i];
  }

  float temp[maxElements][1];
  for(int i = 0; i < maxElements - 1; ++i){
    for(int j = 0; j < maxElements - i - 1; ++j){
      if(weightBenefit[j][1] > weightBenefit[j + 1][1]){
        temp[j][1] = weightBenefit[j][1];
        weightBenefit[j][1] = weightBenefit[j + 1][1];
        weightBenefit[j + 1][1] = temp[j][1];

        temp[j][2] = weightBenefit[j][2];
        weightBenefit[j][2] = weightBenefit[j + 1][2];
        weightBenefit[j + 1][2] = temp[j][2];

      }
      ratio[j] = weightBenefit[j][2]/weightBenefit[j][1];
    }
  }

  cout << "\n\nMaximum weight: " << maxWeight << endl;
  cout << "\nElement |  Weight  |  Benefit  |  Ratio  " << endl;
  for(int i = 0; i < maxElements; ++i){
     cout << " " <<  i + 1 << "  \t  " << weightBenefit[i][1] << "\t  " << weightBenefit[i][2] << "\t  " << ratio[i] << endl;
  }

  backpack(weightBenefit, maxWeight, maxElements);
  return 0;
}
