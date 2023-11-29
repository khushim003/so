/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <stdio.h>

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

// FIFO page replacement algorithm
int fifoPageReplacement(int *referenceString, int refStringLength, int frameSize) {
    int frames[frameSize];
    int pageFaults = 0;
    int frameIndex = 0; // Index to keep track of the oldest page in frames

    // Initialize frames to -1 (indicating empty frame)
    for (int i = 0; i < frameSize; i++) {
        frames[i] = -1;
    }

    // Iterate through the reference string
    for (int i = 0; i < refStringLength; i++) {
        int currentPage = referenceString[i];

        // If page is not present in memory, replace the oldest page using FIFO
        if (!isPagePresent(currentPage, frames, frameSize)) {
            frames[frameIndex] = currentPage;
            frameIndex = (frameIndex + 1) % frameSize; // Move to the next frame using modulo
            pageFaults++;
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

    int pageFaults = fifoPageReplacement(referenceString, refStringLength, frameSize);

    printf("\nTotal Page Faults: %d\n", pageFaults);

    return 0;
}


