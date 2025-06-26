#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define N 3 

int mat1[N][N];
int mat2[N][N];
int result[N][N];

void print_matrix(int mat[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }
}


int main() {
    int mat1[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mat2[N][N] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    

    int pid, status;

    for (int i = 0; i < N; i++) {
        pid = fork();
        if (pid == 0) { // Child process
            int row_result[N] = {0}; 
            for (int j = 0; j < N; j++) {
                for (int k = 0; k < N; k++) {
                    row_result[j] += mat1[i][k] * mat2[k][j];
                }
            }
            printf("Child process %d calculated row %d\n", getpid(), i+1);
            printf("Row result:\n");
            for (int j = 0; j < N; j++) {
                printf("%d ", row_result[j]);
            }
            printf("\n");
            exit(0); 
        }
         else {
            wait(&status); 
        }
    }

    printf("All child processes completed.\n");

    return 0;
}
