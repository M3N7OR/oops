#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main() {
    int RQ[100], i, n, TotalHeadMoment = 0, initial, size;
    printf("Enter the number of Requests\n");
    scanf("%d", &n);
    printf("Enter the Requests sequence\n");
    for(i = 0; i < n; i++)
        scanf("%d", &RQ[i]);
    printf("Enter initial head position\n");
    scanf("%d", &initial);
    printf("Enter total disk size\n");
    scanf("%d", &size);
    
    int visited[100] = {0}; // Array to keep track of visited requests
    
    // Find the request with the shortest seek time from the initial head position
    for(i = 0; i < n; i++) {
        int minDistance = INT_MAX;
        int minIndex = -1;
        for(int j = 0; j < n; j++) {
            if(!visited[j]) {
                int distance = abs(RQ[j] - initial);
                if(distance < minDistance) {
                    minDistance = distance;
                    minIndex = j;
                }
            }
        }
        visited[minIndex] = 1; // Mark the request as visited
        TotalHeadMoment += minDistance; // Update total head movement
        initial = RQ[minIndex]; // Move the head to the selected request
    }
    
    printf("Total head movement is %d", TotalHeadMoment);
    
    return 0;
}
