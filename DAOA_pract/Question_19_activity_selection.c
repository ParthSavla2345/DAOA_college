#include <stdio.h>

int main()
{
    int n;
    int s[10], f[10], id[10];
    int temp;

    printf("Enter number of activities: ");
    scanf("%d", &n);

    printf("Enter start time and finish time of each activity:\n");
    for (int i = 0; i < n; i++)
    {
        id[i] = i + 1;     // Activity number
        printf("Activity %d: ", i + 1);
        scanf("%d %d", &s[i], &f[i]);
    }

    /* Sort activities by finish time */
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (f[i] > f[j])
            {
                temp = f[i]; f[i] = f[j]; f[j] = temp;
                temp = s[i]; s[i] = s[j]; s[j] = temp;
                temp = id[i]; id[i] = id[j]; id[j] = temp;
            }
        }
    }

    printf("\nSelected activities are:\n");

    /* Select first activity */
    int lastFinish = f[0];
    printf("Activity %d (Start=%d, Finish=%d)\n", id[0], s[0], f[0]);

    /* Select remaining activities */
    for (int i = 1; i < n; i++)
    {
        if (s[i] >= lastFinish)
        {
            printf("Activity %d (Start=%d, Finish=%d)\n",
                   id[i], s[i], f[i]);
            lastFinish = f[i];
        }
    }

    return 0;
}

/*

Input:
Enter number of activities: 6
Enter start time and finish time of each activity:
Activity 1: 1 2
Activity 2: 3 4
Activity 3: 0 6
Activity 4: 5 7
Activity 5: 8 9
Activity 6: 5 9

Output:
Selected activities are:
Activity 1 (Start=1, Finish=2)
Activity 2 (Start=3, Finish=4)
Activity 4 (Start=5, Finish=7)
Activity 5 (Start=8, Finish=9)


*/
