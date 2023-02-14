// Junayad Bin Forhad
// Student ID: 160158218
// Lab- 01
// Date Created: 23/01/22

#include <stdio.h>

#define NUM 4

int main()
{
    int high_values[NUM];
    int low_values[NUM];
    int total_highs = 0, total_lows = 0;
    int highest = -40, lowest = 40;
    int highest_day = 1, lowest_day = 1;

    printf("---=== SEP Temperature Analyzer ===---\n");

    for (int i = 0; i < NUM; i++)
    {
        int valid = 0;
        int high, low;
        while (!valid)
        {
            printf("Enter the high value for day %d: ", i + 1);
            scanf("%d", &high);
            printf("Enter the low value for day %d: ", i + 1);
            scanf("%d", &low);

            if (high <= 40 && high >= -40 && low <= 40 && low >= -40 && low <= high)
            {
                valid = 1;
            }
            else
            {
                printf("\nIncorrect values, temperatures must be in the range -40 to 40, high must be greater than low.\n\n");
            }
        }
        high_values[i] = high;
        low_values[i] = low;
        if (high > highest)
        {
            highest = high;
            highest_day = i + 1;
        }
        if (low < lowest)
        {
            lowest = low;
            lowest_day = i + 1;
        }
        total_highs += high;
        total_lows += low;
        printf("\n");
    }

    printf("The high temperatures were:");
    for (int i = 0; i < NUM; i++)
        printf(" %d", high_values[i]);
    printf("\nThe low temperatures were:");
    for (int i = 0; i < NUM; i++)
        printf(" %d", low_values[i]);

    printf("\nThe average LOW temperature was: %.2f\n", (float)total_lows / NUM);
    printf("The average HIGH temperature was: %.2f\n", (float)total_highs / NUM);
    printf("The average temperature was: %.2f\n", (float)(total_lows + total_highs) / (NUM * 2));
    printf("The highest temperature was %d, on day %d\n", highest, highest_day);
    printf("The lowest temperature was %d, on day %d\n", lowest, lowest_day);

    return 0;
}