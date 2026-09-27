#include <stdio.h>

#define SIZE 10
#define N 8

int hashTable[SIZE];

/* Division Method */
int hashFunction(int key)
{
    return key % SIZE;
}

/* Initialize hash table */
void initializeTable()
{
    for (int i = 0; i < SIZE; i++)
    {
        hashTable[i] = -1;
    }
}

/* Display hash table */
void displayTable()
{
    printf("\nHash Table:\n");

    for (int i = 0; i < SIZE; i++)
    {
        if (hashTable[i] == -1)
            printf("%d : EMPTY\n", i);
        else
            printf("%d : %d\n", i, hashTable[i]);
    }
}

/* Insert using Linear Probing */
int insert(int key)
{
    int index = hashFunction(key);
    int originalIndex = index;
    int collisions = 0;

    while (hashTable[index] != -1)
    {
        collisions++;

        index = (index + 1) % SIZE;

        if (index == originalIndex)
        {
            printf("Hash table is full!\n");
            return -1;
        }
    }

    hashTable[index] = key;

    printf("\nInserting %d\n", key);
    printf("Initial hash index = %d\n", originalIndex);

    if (collisions == 0)
    {
        printf("No collision\n");
    }
    else
    {
        printf("Collision occurred %d time(s)\n", collisions);
    }

    printf("Inserted at index = %d\n", index);

    return collisions;
}

/* Search using Hashing */
int hashSearch(int key, int *comparisons)
{
    int index = hashFunction(key);
    int originalIndex = index;

    *comparisons = 0;

    while (hashTable[index] != -1)
    {
        (*comparisons)++;

        if (hashTable[index] == key)
        {
            return index;
        }

        index = (index + 1) % SIZE;

        if (index == originalIndex)
        {
            break;
        }
    }

    return -1;
}

/* Search using Linear Search */
int linearSearch(int arr[], int n, int key, int *comparisons)
{
    *comparisons = 0;

    for (int i = 0; i < n; i++)
    {
        (*comparisons)++;

        if (arr[i] == key)
        {
            return i;
        }
    }

    return -1;
}

int main()
{
    int ids[N] = {
        105, 210, 315, 420,
        525, 630, 735, 840
    };

    int totalCollisions = 0;

    initializeTable();

    printf("========================================\n");
    printf(" HASHING USING DIVISION METHOD\n");
    printf("========================================\n");

    printf("Hash Table Size = %d\n", SIZE);
    printf("Hash Function: h(k) = k %% %d\n", SIZE);

    /* ---------------- INSERTION ---------------- */

    printf("\n\n========== INSERTION ==========\n");

    for (int i = 0; i < N; i++)
    {
        int collisions;

        collisions = insert(ids[i]);

        if (collisions != -1)
            totalCollisions += collisions;

        displayTable();
    }

    printf("\nTotal collision/probe steps = %d\n", totalCollisions);

    /* ---------------- HASHING SEARCH ---------------- */

    printf("\n\n========== HASHING SEARCH ==========\n");

    int totalHashComparisons = 0;

    for (int i = 0; i < N; i++)
    {
        int comparisons;
        int position;

        position = hashSearch(ids[i], &comparisons);

        totalHashComparisons += comparisons;

        printf("Search %d -> ", ids[i]);

        if (position != -1)
            printf("Found at index %d, Comparisons = %d\n",
                   position, comparisons);
        else
            printf("Not Found, Comparisons = %d\n",
                   comparisons);
    }

    /* ---------------- LINEAR SEARCH ---------------- */

    printf("\n\n========== LINEAR SEARCH ==========\n");

    int totalLinearComparisons = 0;

    for (int i = 0; i < N; i++)
    {
        int comparisons;
        int position;

        position = linearSearch(ids, N, ids[i], &comparisons);

        totalLinearComparisons += comparisons;

        printf("Search %d -> ", ids[i]);

        if (position != -1)
            printf("Found at position %d, Comparisons = %d\n",
                   position, comparisons);
        else
            printf("Not Found, Comparisons = %d\n",
                   comparisons);
    }

    /* ---------------- COMPARISON ---------------- */

    printf("\n\n========== COMPARISON ==========\n");

    printf("%-10s %-20s %-20s\n",
           "Song ID",
           "Hashing",
           "Linear Search");

    for (int i = 0; i < N; i++)
    {
        int hashComp;
        int linearComp;

        hashSearch(ids[i], &hashComp);
        linearSearch(ids, N, ids[i], &linearComp);

        printf("%-10d %-20d %-20d\n",
               ids[i],
               hashComp,
               linearComp);
    }

    printf("\nAverage Hashing Comparisons = %.2f\n",
           (float)totalHashComparisons / N);

    printf("Average Linear Search Comparisons = %.2f\n",
           (float)totalLinearComparisons / N);

    /* ---------------- LOAD FACTOR ---------------- */

    float loadFactor = (float)N / SIZE;

    printf("\n\n========== LOAD FACTOR ==========\n");

    printf("Load Factor = n / m\n");
    printf("             = %d / %d\n", N, SIZE);
    printf("             = %.2f\n", loadFactor);
    printf("             = %.0f%%\n", loadFactor * 100);

    /* ---------------- COMPLEXITY ---------------- */

    printf("\n\n========== COMPLEXITY ==========\n");

    printf("Hashing Search - Average Case : O(1) expected\n");
    printf("Hashing Search - Worst Case   : O(n)\n");

    printf("Linear Search - Best Case     : O(1)\n");
    printf("Linear Search - Average Case  : O(n)\n");
    printf("Linear Search - Worst Case    : O(n)\n");

    return 0;
}