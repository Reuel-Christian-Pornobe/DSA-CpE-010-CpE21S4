#include <iostream>
#include <cstdlib>
#include <ctime>
#include "insertion.h"
#include "print.h"
using namespace std;

const int N = 100;

// Function declaration  of counting votes and determine the winner
void countVotes(int arr[], const int N);

int main() {
    srand(time(0));
    int votes[N];
    
    // Generate random votes between 1 and 5
    for (int i = 0; i < N; i++) {
        votes[i] = rand() % 5 + 1; // Random value between 1 and 5
    }
    
    // Display unsorted votes
    cout << "Unsorted Votes: " << endl;
    printArray(votes, N);
    
    // Sort the votes using Insertion Sort
    insertionSort(votes, N);
    
    // Display sorted votes
    cout << "\nSorted Votes: " << endl;
    printArray(votes, N);
    
    // Count the votes and determine the winner
    countVotes(votes, N);

    return 0;
}

// Function to count votes and determine the winner
void countVotes(int arr[], const int N) {
    int count1 = 0, count2 = 0, count3 = 0, count4 = 0, count5 = 0;
    
    // Counting the votes for each candidate
    for (int i = 0; i < N; i++) {
        switch (arr[i]) {
            case 1: count1++; break;
            case 2: count2++; break;
            case 3: count3++; break;
            case 4: count4++; break;
            case 5: count5++; break;
        }
    }
    
    // Display vote counts for each candidate
    cout << "Votes for Candidate 1 (Bo Dalton Capistrano): " << count1 << endl;
    cout << "Votes for Candidate 2 (Cornelius Raymon Agustin): " << count2 << endl;
    cout << "Votes for Candidate 3 (Deja Jayla Banaga): " << count3 << endl;
    cout << "Votes for Candidate 4 (Lalla Brielle Yabut): " << count4 << endl;
    cout << "Votes for Candidate 5 (Franklin Relano Castro): " << count5 << endl;

    // Determine the winner by comparing vote counts
    int maxVotes = max(max(max(max(count1, count2), count3), count4), count5);
    cout << "\nThe winning candidate is: ";
    if (maxVotes == count1) cout << "Bo Dalton Capistrano" << endl;
    else if (maxVotes == count2) cout << "Cornelius Raymon Agustin" << endl;
    else if (maxVotes == count3) cout << "Deja Jayla Banaga" << endl;
    else if (maxVotes == count4) cout << "Lalla Brielle Yabut" << endl;
    else if (maxVotes == count5) cout << "Franklin Relano Castro" << endl;
}



