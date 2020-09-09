/*
  Daniela Vignau
  A01021698
  Exercise 2: Paragraph division
  Technique: Greedy algoritm
    Greedy choice: It tries to fit as many words as possible in the same line
  Commplexity: Because there's only one loop for the complexity is O(n)
*/

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

float reduceCost(float red, float amplitudeI, int j, int i) {
  return (fabs(red - amplitudeI) * (j - i) );
}

float extendCost(float amp, float amplitudeI, int j, int i)  {
  return (fabs(amp - amplitudeI) * (j - i - 1) );
}

void printLine(vector<string> line){
  cout << endl;
  for (int i = 0; i < line.size(); i++)
    cout << line[i] << " ";
}

int main() {
  vector<string> text = {"Daniela", "come", "sandia", "mientras", "hace", "su","tarea"};
  vector<int> sizeWords;
  vector<string> line;

  float sizeLine = 30, wholeWord = 0, sizeWordSpan = 0, amplitudeI = 0, surplus = 0, red = 0, amp = 0;
  int i = 0, j = 0;
  bool shown = true;

  for (int i = 0; i < text.size(); ++i)
    sizeWords.push_back(int(text[i].length()));

  for (j = 0; j < text.size(); j++) {
    if (shown) {
      i = j;
      shown = false;
      line.clear();
      wholeWord = 0;
    }

    wholeWord += sizeWords[j];
    sizeWordSpan = wholeWord + ((j - i) * amplitudeI);

    if (sizeWordSpan > sizeLine) {
      surplus = sizeWordSpan - sizeLine;
      red = amplitudeI - (surplus/(j - i));
      amp = amplitudeI + (sizeLine - ((wholeWord - sizeWords[j]) + (amplitudeI * (j - i - 1) ))) / (j - i - 1);

      if (extendCost(amp,amplitudeI,j,i) > reduceCost(red, amplitudeI, j, i) && red > 0 ) {
        line.push_back(text[j]);
        cout << endl;
        printLine(line);
        cout << "\t--> This line has been reduced by: " << red << " mm" << endl;
        shown = true;
      }
      else {
        printLine(line);
        cout << "\t--> This line has grown by: " << amp << " mm" << endl;
        j--;
        shown = true;
      }
    }
    line.push_back(text[j]);
  }

  printLine(line);
  cout << endl;

}
