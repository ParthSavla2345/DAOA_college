#include <stdio.h> 
#include <conio.h> 
 
void swapFloat(float *a, float *b) { 
    float temp; 
    temp = *a; 
    *a = *b; 
    *b = temp; 
} 
 
 
void swapInt(int *a, int *b) { 
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 
 
 
void sortByRatio(float ratio[], int profit[], int weight[], int n) { 
    int i, j; 
    for(i = 0; i < n - 1; i++) { 
 for(j = i + 1; j < n; j++) { 
     if(ratio[j] > ratio[i]) { 
  swapFloat(&ratio[i], &ratio[j]); 
  swapInt(&profit[i], &profit[j]); 
  swapInt(&weight[i], &weight[j]); 
     } 
Subject: DAOA Class/ Sem: T. Y.  B. Tech/ Sem-V A.Y: 2025-26 (Odd) 
 
 
  
} 
    } 
} 
 
void fractionalKnapsack(int profit[], int weight[], int n, int capacity) { 
    float ratio[20]; 
    int i; 
    float totalProfit = 0.0; 
    int currentWeight = 0; 
 
    for(i = 0; i < n; i++) { 
 ratio[i] = (float)profit[i] / weight[i]; 
    } 
 
    sortByRatio(ratio, profit, weight, n); 
 
    printf("Items selected (weight, profit):\n"); 
 
    for(i = 0; i < n; i++) { 
 if(currentWeight + weight[i] <= capacity) { 
     currentWeight += weight[i]; 
     totalProfit += profit[i]; 
     printf("Full item (Weight: %d, Profit: %d)\n", weight[i], profit[i]); 
 } else { 
     int remain = capacity - currentWeight; 
     float fraction = (float)remain / weight[i]; 
     totalProfit += profit[i] * fraction; 
     printf("Fractional item (Weight: %d, Profit: %.2f)\n", remain, profit[i] * fraction); 
     break; 
 } 
    } 
 
    printf("\nTotal profit = %.2f\n", totalProfit); 
} 
 
int main() { 
    int n, capacity; 
    int profit[20], weight[20]; 
    int i; 
 
    clrscr(); 
    printf("Enter number of items: "); 
    scanf("%d", &n); 
 
    printf("Enter weights of items:\n"); 
Subject: DAOA 
Class/ Sem: T. Y.  B. Tech/ Sem-V 
for(i = 0; i < n; i++) { 
printf("Weight of item %d: ", i + 1); 
scanf("%d", &weight[i]); 
} 
printf("Enter profits of items:\n"); 
for(i = 0; i < n; i++) { 
printf("Profit of item %d: ", i + 1); 
scanf("%d", &profit[i]); 
} 
printf("Enter capacity of knapsack: "); 
scanf("%d", &capacity); 
fractionalKnapsack(profit, weight, n, capacity); 
getch(); 
return 0; 
} 