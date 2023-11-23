#include <stdio.h>

#define MAX_STATES 10
#define MAX_TRANSITIONS 10

void epsilonClosure(int n, int m, int transitions[MAX_TRANSITIONS][3], int epsilonClosureSet[MAX_STATES][MAX_STATES]) {
    for (int i = 0; i < n; i++) {
        // Initialize epsilon closure set for each state with the state itself
        epsilonClosureSet[i][0] = i;
        int epsilonClosureSize = 1;

        // Keep track of visited states to avoid infinite loops
        int visited[MAX_STATES] = {0};
        visited[i] = 1;

        // Perform depth-first search to find epsilon closure
        for (int j = 0; j < epsilonClosureSize; j++) {
            int currentState = epsilonClosureSet[i][j];

            for (int k = 0; k < m; k++) {
                if (transitions[k][0] == currentState && transitions[k][1] == 'e') {
                    int nextState = transitions[k][2];

                    // Check if nextState is not already in epsilon closure set
                    int isVisited = 0;
                    for (int l = 0; l < epsilonClosureSize; l++) {
                        if (epsilonClosureSet[i][l] == nextState) {
                            isVisited = 1;
                            break;
                        }
                    }

                    if (!isVisited) {
                        // Add nextState to epsilon closure set
                        epsilonClosureSet[i][epsilonClosureSize++] = nextState;

                        // Mark nextState as visited
                        visited[nextState] = 1;
                    }
                }
            }
        }
    }
}

int main() {
    int n, m;

    // Input the number of states and transitions
    printf("Enter the number of states: ");
    scanf("%d", &n);
    printf("Enter the number of transitions: ");
    scanf("%d", &m);

    int transitions[MAX_TRANSITIONS][3];

    // Input the transitions
    for (int i = 0; i < m; i++) {
        printf("Enter transition %d (start symbol end): ", i + 1);
        scanf("%d %c %d", &transitions[i][0], &transitions[i][1], &transitions[i][2]);
    }

    // Calculate epsilon closure for all states
    int epsilonClosureSet[MAX_STATES][MAX_STATES];
    epsilonClosure(n, m, transitions, epsilonClosureSet);

    // Output epsilon closure sets
    for (int i = 0; i < n; i++) {
        printf("epsilon-closure(%d): { ", i);
        for (int j = 0; j < n; j++) {
            if (epsilonClosureSet[i][j] != -1) {
                printf("%d ", epsilonClosureSet[i][j]);
            }
        }
        printf("}\n");
    }

    return 0;
}

