#include <stdio.h>
#include <string.h>
#define MAX_FOODS 100
#define MAX_WEIGHT 10000

struct Food {
    char name[50];
    int calories;
};

void knapsack(struct Food foods[], int n, int W) {
    int i, w;
    int K[n+1][W+1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            K[i][w] = 0;
        }
    }

    for (i = 1; i <= n; i++) {
        for (w = 1; w <= W; w++) {
            if (foods[i-1].calories <= w) {
                if (1 + K[i-1][w-foods[i-1].calories] > K[i-1][w]) {
                    K[i][w] = 1 + K[i-1][w-foods[i-1].calories];
                } else {
                    K[i][w] = K[i-1][w];
                }
            } else {
                K[i][w] = K[i-1][w];
            }
        }
    }

    printf("Diet Plan:\n");
    int j = W;
    for (i = n; i > 0 && j > 0; i--) {
        if (K[i][j] != K[i-1][j]) {
            printf("%s\n", foods[i-1].name);
            j = j - foods[i-1].calories;
        }
    }
}

int main() {

    struct Food foods[MAX_FOODS];

    int n;
    printf("Enter the number of food items: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("\nEnter the details of food item %d:\n", i+1);
        printf("Name: ");
        scanf("%s", foods[i].name);
        printf("Calories: ");
        scanf("%d", &foods[i].calories);
    }

    int W;
    printf("\nEnter the maximum weight of the knapsack (in calories): ");
    scanf("%d", &W);

    knapsack(foods, n, W);

    return 0;
}
