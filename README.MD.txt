# Question 7 - Hashing and Linear Search

## Aim

To implement hashing using the division method and linear probing, and compare hashing search with linear search using song IDs.

## Song IDs

105, 210, 315, 420, 525, 630, 735, 840

## Hash Function

The division method is used.

h(k) = k % 10

## Collision Resolution

Linear probing is used to resolve collisions.

## Hash Table Size

10

## Load Factor

Load Factor = Number of elements / Hash table size

= 8 / 10

= 0.80

= 80%

## Comparison

| Song ID | Hashing Comparisons | Linear Search Comparisons |
|---------|---------------------|---------------------------|
| 105     | 1                   | 1                         |
| 210     | 1                   | 2                         |
| 315     | 2                   | 3                         |
| 420     | 2                   | 4                         |
| 525     | 3                   | 5                         |
| 630     | 3                   | 6                         |
| 735     | 4                   | 7                         |
| 840     | 4                   | 8                         |

## Average Comparisons

Average Hashing Comparisons = 2.50

Average Linear Search Comparisons = 4.50

## Complexity Analysis

### Hashing

Average Case: O(1) expected

Worst Case: O(n)

### Linear Search

Best Case: O(1)

Average Case: O(n)

Worst Case: O(n)

## Files

- hashing.c - C program
- input.txt - input song IDs
- output.txt - program output
- comparison_table.csv - comparison table
- complexity_analysis.md - complexity analysis