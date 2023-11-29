/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

// Function to find the index of the least recently used page in frames
int findLRU(int *recentlyUsed, int frameSize) {
    int min = recentlyUsed[0];
    int minIndex = 0;

    for (int i = 1; i < frameSize; i++) {
        if (recentlyUsed[i] < min) {
            min = recentlyUsed[i];
            minIndex = i;
        }
    }

    return minIndex;
}

// Function to find if a page is present in the memory
int isPagePresent(int page, int *frames, int frameSize) {
    for (int i = 0; i < frameSize; i++) {
        if (frames[i] == page) {
            return 1; // Page is present in memory
        }
    }
    return 0; // Page is not present in memory
}

// Function to display the content of frames
void displayFrames(int *frames, int frameSize) {
    for (int i = 0; i < frameSize; i++) {
        if (frames[i] == -1) {
            printf(" _ ");
        } else {
            printf(" %d ", frames[i]);
        }
    }
    printf("\n");
}

// LRU page replacement algorithm
int lruPageReplacement(int *referenceString, int refStringLength, int frameSize) {
    int frames[frameSize];
    int recentlyUsed[frameSize];
    int pageFaults = 0;

    // Initialize frames and recentlyUsed to -1 (indicating empty frame and unused page)
    for (int i = 0; i < frameSize; i++) {
        frames[i] = -1;
        recentlyUsed[i] = -1;
    }

    // Iterate through the reference string
    for (int i = 0; i < refStringLength; i++) {
        int currentPage = referenceString[i];

        // If page is not present in memory, replace the least recently used page using LRU
        if (!isPagePresent(currentPage, frames, frameSize)) {
            int lruIndex = findLRU(recentlyUsed, frameSize);
            frames[lruIndex] = currentPage;
            recentlyUsed[lruIndex] = i; // Update the recently used time
            pageFaults++;
        } else {
            // If page is present in memory, update the recently used time
            for (int j = 0; j < frameSize; j++) {
                if (frames[j] == currentPage) {
                    recentlyUsed[j] = i;
                    break;
                }
            }
        }

        // Display the current state of frames
        printf("Reference: %d, Frames:", currentPage);
        displayFrames(frames, frameSize);
    }

    return pageFaults;
}

int main() {
    int refStringLength, frameSize;

    // Get the length of the reference string from the user
    printf("Enter the length of the reference string: ");
    scanf("%d", &refStringLength);

    int referenceString[refStringLength];

    // Get the reference string from the user
    printf("Enter the reference string (space-separated integers): ");
    for (int i = 0; i < refStringLength; i++) {
        scanf("%d", &referenceString[i]);
    }

    // Get the number of frames from the user
    printf("Enter the number of frames: ");
    scanf("%d", &frameSize);

    printf("\nReference String: ");
    for (int i = 0; i < refStringLength; i++) {
        printf("%d ", referenceString[i]);
    }
    printf("\n");

    int pageFaults = lruPageReplacement(referenceString, refStringLength, frameSize);

    printf("\nTotal Page Faults: %d\n", pageFaults);

    return 0;
}


