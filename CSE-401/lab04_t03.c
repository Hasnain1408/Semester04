#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define N 3 

int mat1[N][N];
int mat2[N][N];
int result[N][N];

// void print_matrix(int mat[N][N]) {
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             printf("%d ", mat[i][j]);
//         }
//         printf("\n");
//     }
// }

// void input_matrix(int mat[N][N]) {
//     printf("Enter the elements of the matrix (%d x %d):\n", N, N);
//     for (int i = 0; i < N; i++) {
//         for (int j = 0; j < N; j++) {
//             scanf("%d", &mat[i][j]);
//         }
//     }
// }

int main() {
    int mat1[N][N] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int mat2[N][N] = {{9, 8, 7}, {6, 5, 4}, {3, 2, 1}};
    

    int pid, status;

    for (int i = 0; i < N; i++) {
    
            for (int j = 0; j < N; j++) {
                pid = fork();
                if (pid == 0) { // Child process
                int value=0;
                for (int k = 0; k < N; k++) {
                    value= mat1[i][k] * mat2[k][j];
                }
                 printf("Child process %d calculated index (%d x %d)\n", getpid(), i+1,j+1);
                 printf("Value: %d\n",value);
                exit(0); 
                 }
                else {
               wait(&status); 
                }
             }
            
           
       
    }

    printf("All child processes completed.\n");

    return 0;
}
