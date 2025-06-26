#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    int oddSum = 0;
    int evenSum = 0;

    int pid = fork();
    
    if (pid == 0) { // Child process

        for (int i = 1; i <= n; i += 2) {
            oddSum += i;
        }
        printf("Sum of odd numbers in child process: %d\n", oddSum);
    }else { // Parent process

        for (int i = 2; i <= n; i += 2) {
            evenSum += i;
        }
        printf("Sum of even numbers in parent process: %d\n", evenSum);
    } 

    return 0;
}
