
#include <stdio.h>

int main() {
    int n, i, j, temp;
    int start[100], finish[100], activity[100];

    printf("Enter the number of activities: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        activity[i] = i + 1;
        printf("Enter start and finish time of activity %d: ", i + 1);
        scanf("%d %d", &start[i], &finish[i]);
    }

    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (finish[j] > finish[j + 1]) {
                temp = finish[j];
                finish[j] = finish[j + 1];
                finish[j + 1] = temp;

                temp = start[j];
                start[j] = start[j + 1];
                start[j + 1] = temp;

                temp = activity[j];
                activity[j] = activity[j + 1];
                activity[j + 1] = temp;
            }
        }
    }

    printf("\nSelected activities are:\n");
    printf("Activity %d (%d, %d)\n", activity[0], start[0], finish[0]);

    j = 0;

    for (i = 1; i < n; i++) {
        if (start[i] >= finish[j]) {
            printf("Activity %d (%d, %d)\n", activity[i], start[i], finish[i]);
            j = i;
        }
    }

    return 0;
}
