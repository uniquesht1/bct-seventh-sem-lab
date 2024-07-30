#include <stdio.h>
#include <stdlib.h>

#define MAX_NODES 5

// Structure to represent a process
typedef struct
{
    int id;
    int is_active;
    int is_coordinator;
} Process;

// Function to perform the Bully Algorithm
void bully_algorithm(Process processes[], int num_nodes, int initiator)
{
    int i, j;

    printf("Process %d initiates the election\n", processes[initiator].id);

    // Process initiating the election sends messages to higher ID processes
    for (i = initiator + 1; i < num_nodes; i++)
    {
        if (processes[i].is_active)
        {
            printf("Process %d sends election message to Process %d\n", processes[initiator].id, processes[i].id);
        }
    }

    // Higher ID processes respond and start their own election if active
    for (i = initiator + 1; i < num_nodes; i++)
    {
        if (processes[i].is_active)
        {
            printf("Process %d receives election message from Process %d\n", processes[i].id, processes[initiator].id);
            printf("Process %d starts its own election\n", processes[i].id);
            bully_algorithm(processes, num_nodes, i);
            return;
        }
    }

    // No higher ID process responded, the initiator becomes the coordinator
    processes[initiator].is_coordinator = 1;
    for (j = 0; j < num_nodes; j++)
    {
        if (j != initiator && processes[j].is_active)
        {
            printf("Process %d informs Process %d that it is the new coordinator\n", processes[initiator].id, processes[j].id);
        }
    }
    printf("Process %d is the new coordinator\n", processes[initiator].id);
}

int main()
{
    Process processes[MAX_NODES];
    int num_nodes = MAX_NODES;
    int initiator;

    // Initialize process IDs and prompt user to set active/inactive status
    for (int i = 0; i < num_nodes; i++)
    {
        processes[i].id = i;
        printf("Is process %d active? (1 for Yes, 0 for No): ", i);
        scanf("%d", &processes[i].is_active);
        processes[i].is_coordinator = 0;
    }

    // Prompt user to select the initiator of the election
    printf("Enter the ID of the process initiating the election: ");
    scanf("%d", &initiator);

    if (initiator < 0 || initiator >= num_nodes || !processes[initiator].is_active)
    {
        printf("Invalid initiator selected. Process must be active and within valid range.\n");
        return 1;
    }

    bully_algorithm(processes, num_nodes, initiator);

    return 0;
}
// Remove the empty parentheses