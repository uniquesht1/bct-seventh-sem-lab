#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TOTAL_GENERALS 9
#define ATTACK "attack"
#define RETREAT "retreat"

typedef struct
{
    int id;
    char *message;
} General;

void initializeGenerals(General generals[], int loyal, int traitors)
{
    for (int i = 0; i < loyal; i++)
    {
        generals[i].id = i + 1;
        generals[i].message = ATTACK;
    }
    for (int i = loyal; i < loyal + traitors; i++)
    {
        generals[i].id = i + 1;
        generals[i].message = RETREAT;
    }
}

void shuffleGenerals(General generals[], int n)
{
    srand(time(NULL));
    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        General temp = generals[i];
        generals[i] = generals[j];
        generals[j] = temp;
    }
}

void printMessages(General generals[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("General %d sends message: %s\n", generals[i].id, generals[i].message);
    }
}

char *determineConsensus(General generals[], int n)
{
    int attackCount = 0;
    int retreatCount = 0;
    for (int i = 0; i < n; i++)
    {
        if (generals[i].message == ATTACK)
        {
            attackCount++;
        }
        else
        {
            retreatCount++;
        }
    }
    return (attackCount > retreatCount) ? ATTACK : RETREAT;
}

int main()
{
    int loyal, traitors;

    printf("Enter the number of loyal generals: ");
    scanf("%d", &loyal);

    printf("Enter the number of traitors: ");
    scanf("%d", &traitors);

    if (loyal + traitors != TOTAL_GENERALS)
    {
        printf("The total number of generals must be %d.\n", TOTAL_GENERALS);
        return 1;
    }

    General generals[TOTAL_GENERALS];
    initializeGenerals(generals, loyal, traitors);
    shuffleGenerals(generals, TOTAL_GENERALS);

    printf("\nMessages from generals:\n");
    printMessages(generals, TOTAL_GENERALS);

    char *consensus = determineConsensus(generals, TOTAL_GENERALS);
    printf("\nThe consensus is to: %s\n", consensus);

    return 0;
}
