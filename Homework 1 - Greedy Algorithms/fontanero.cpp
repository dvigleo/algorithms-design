/*
  Daniela Vignau
  A01021698
*/

#include<iostream>
#include<algorithm>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Job{
   int id;      // Job Id
   int deadline;    // Deadline of job
   int profit;  // Profit if job is over before or on deadline
};

// Sort current jobs according to its profit
bool comparison(Job a, Job b){
  return (a.profit > b.profit);
}

// Returns minimum number of platforms reqquired
void printJobScheduling(Job arr[], int n){
  // Sort according to decreasing order of prfit
  sort(arr, arr+n, comparison);

  int result[n]; // To store result (Sequence of jobs)
  bool slot[n];  // To keep track of free time slots

  // Initialize all slots to be free
  for (int i=0; i<n; i++)
      slot[i] = false;

  // Iterate through all given jobs
  for (int i=0; i<n; i++){
     // Find a free slot for this job (Note that we start
     // from the last possible slot)
     for (int j=min(n, arr[i].deadline)-1; j>=0; j--){
        // Free slot found
        if (slot[j]==false){
           result[j] = i;  // Add this job to result
           slot[j] = true; // Make this slot occupied
           break;
        }
     }
  }

  // Print the result
  for (int i=0; i<n; i++)
     if (slot[i])
       cout << arr[result[i]].id << " ";
}

int main(){
  srand(time(NULL)); // Seed to generate random numbers over and over
  int nJobs = 0;
  cout << "Type in the total number of jobs to do: ";
    cin >> nJobs;
  Job todo[nJobs];

  for(int i = 0; i < nJobs; ++i){
    todo[i].id;
    int deadline = (rand() % 10) + 100;
    todo[deadline].deadline;
    int profit = (rand() % 10) + 200;
    todo[profit].profit;
  }
  cout << "\n    ID     |    DEADLINE     |     PROFIT     |" << endl;
  for (size_t i = 0; i < nJobs; i++) {
    cout << todo[i].id << "  \t";
    cout << todo[i].deadline << " \t";
    cout << todo[i].profit << endl;
  }

  cout << "\nSequence of jobs for amximum profit: \n";
  printJobScheduling(todo, nJobs);
  return 0;
}
