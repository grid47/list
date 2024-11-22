
+++
authors = ["grid47"]
title = "Leetcode 3044: Most Frequent Prime"
date = "2024-01-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3044: Most Frequent Prime in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Matrix","Counting","Enumeration","Number Theory"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "vyLo_FMR3IU"
youtube_upload_date="2024-02-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/vyLo_FMR3IU/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
char sieve[1000001] = {};
class Solution {
public:
    int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
    int dy[8] = {1, 0, -1, 1, 0, -1, 1, -1};
    void make() {
        sieve[1] = 1;
        for (int i = 2; i < 1000001; i++) {
            if (!sieve[i]) for (int j = 2*i; j < 1000001; j += i) sieve[j] = 1;
        }
    } 
    int mostFrequentPrime(vector<vector<int>>& mat) {
        if (sieve[1] == 0) make();
        map<int, int> freq;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[i].size(); j++) {
                for (int k = 0; k < 8; k++) {
                    int a = i, b = j;
                    int cur = 0;
                    while (a >= 0 && b >= 0 && a < mat.size() && b < mat[i].size()) {
                        cur *= 10;
                        cur += mat[a][b];
                        if(cur>10 && sieve[cur] == 0) freq[cur]++;
                        a += dx[k]; b += dy[k];
                    }
                }
            }
        }
        int mx = -1;
        int ans = -1;
        for (auto i : freq) {
            if(i.second >= mx) {
                ans = i.first;
                mx = i.second;
            }
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement:

The goal of this problem is to find the most frequent prime number formed by traversing the elements of a 2D grid `mat`. A prime number is formed by traversing the grid in any of the 8 possible directions: up-right, right, down-right, down-left, left, up-left, up, and down. The direction of traversal starts from any element, and as you traverse, you form a number by concatenating the elements of the grid. After all valid prime numbers are formed, the task is to return the prime number that appears most frequently in all directions. If there is a tie, return the smallest prime number.

### Approach:

To solve this problem efficiently, we need to consider the following approach:

1. **Prime Number Calculation (Sieve of Eratosthenes):**
   - First, we need to identify prime numbers. Given the potential large size of the numbers formed by grid elements, we use the **Sieve of Eratosthenes** to mark all prime numbers up to 1,000,000 (since the grid values are limited to the range of integers). We only need to check for primes in the range of numbers that can be formed by up to 6 digits (as the grid elements are integers and we're concatenating them in multiple directions).

2. **Grid Traversal:**
   - For each element in the grid, we need to traverse in all 8 possible directions. As we traverse, we will form numbers by concatenating the digits of the grid. If a valid prime number is formed, we update its frequency in a frequency map.

3. **Map of Prime Frequency:**
   - For each valid prime number found during the traversal, we store the frequency of its occurrence in a map (or hash map). After all grid cells have been traversed and all possible prime numbers are formed, the prime number that appears the most times in the grid is returned.

4. **Final Output:**
   - We return the prime number with the highest frequency. In case of a tie, the smallest prime number among them is returned.

### Code Breakdown (Step by Step):

#### Step 1: Sieve of Eratosthenes
```cpp
char sieve[1000001] = {};

void make() {
    sieve[1] = 1;
    for (int i = 2; i < 1000001; i++) {
        if (!sieve[i]) {
            for (int j = 2*i; j < 1000001; j += i) {
                sieve[j] = 1; // Marking non-primes
            }
        }
    }
}
```
- We create a sieve array of size `1,000,001` (since the numbers we need to consider can go up to 6 digits).
- The `make()` function initializes the sieve array. If a number `i` is found to be prime (i.e., `sieve[i]` is 0), we mark all its multiples as non-prime by setting `sieve[j]` to 1.
- We start from `i = 2` and mark all multiples of `i` as non-prime. This way, at the end of the process, all prime numbers will have `sieve[i] = 0`.

#### Step 2: Directions for Grid Traversal
```cpp
int dx[8] = {1, 1, 1, -1, -1, -1, 0, 0};
int dy[8] = {1, 0, -1, 1, 0, -1, 1, -1};
```
- These arrays represent the 8 possible directions for traversal: down-right, right, up-right, up-left, left, down-left, up, and down.
- `dx[i]` and `dy[i]` represent the change in the row and column indices respectively for the `i`th direction.

#### Step 3: Traversing the Grid and Forming Numbers
```cpp
for (int i = 0; i < mat.size(); i++) {
    for (int j = 0; j < mat[i].size(); j++) {
        for (int k = 0; k < 8; k++) {
            int a = i, b = j;
            int cur = 0;
            while (a >= 0 && b >= 0 && a < mat.size() && b < mat[i].size()) {
                cur *= 10;
                cur += mat[a][b];
                if (cur > 10 && sieve[cur] == 0) freq[cur]++;
                a += dx[k]; b += dy[k];
            }
        }
    }
}
```
- This part of the code is responsible for iterating over each cell in the matrix `mat` and checking all 8 possible directions from that cell.
- For each direction `k`, we start at the current cell `(i, j)` and attempt to move in the direction defined by `dx[k]` and `dy[k]`. During the traversal, we concatenate the digits of the grid to form a number (`cur`).
- If the formed number is greater than 10 and is prime (i.e., `sieve[cur] == 0`), we increase its frequency in the `freq` map.
- The condition `cur > 10` ensures that we only count numbers with more than one digit, preventing single-digit numbers from being included in the prime frequency count.

#### Step 4: Finding the Most Frequent Prime
```cpp
int mx = -1;
int ans = -1;
for (auto i : freq) {
    if (i.second >= mx) {
        ans = i.first;
        mx = i.second;
    }
}
return ans;
```
- After all numbers have been processed, we need to determine the prime number with the highest frequency.
- We iterate over the `freq` map, which contains the prime numbers as keys and their respective counts as values.
- If we find a prime number with a higher frequency (`i.second >= mx`), we update `ans` to this prime and set `mx` to the new maximum frequency.
- Finally, we return the prime number with the highest frequency.

### Time Complexity:

1. **Sieve of Eratosthenes:**
   - The sieve function runs in `O(n log log n)` where `n` is `1,000,000`. This is efficient for marking prime numbers up to `10^6`.
   
2. **Grid Traversal:**
   - We are iterating over each cell of the matrix, and for each cell, we check all 8 directions. For each direction, we can traverse a maximum of `min(rows, cols)` steps before going out of bounds. In the worst case, this can lead to checking all cells in the grid, giving us a time complexity of `O(rows * cols * min(rows, cols))`.

3. **Frequency Calculation:**
   - The frequency map `freq` contains prime numbers. Since we are only interested in numbers up to `10^6`, the size of the map will be limited. Finding the maximum frequency and determining the most frequent prime will take `O(k)` time, where `k` is the number of primes found.

Thus, the overall time complexity is dominated by the grid traversal and sieve generation, resulting in `O(n log log n + rows * cols * min(rows, cols))`.

### Space Complexity:

- The space complexity is primarily determined by the sieve array, which takes `O(10^6)` space, and the frequency map, which stores the prime numbers formed. Thus, the space complexity is `O(n + rows * cols)` where `n` is the size of the sieve array, and `rows * cols` is the space required for storing frequencies.

### Conclusion:

This solution efficiently finds the most frequent prime number formed from a 2D grid by using the Sieve of Eratosthenes for prime detection and exploring all 8 possible directions from each grid cell to form numbers. The result is the prime number that appears most frequently in the grid. The approach ensures optimal performance for large inputs, making it suitable for problems with large grid sizes.

[`Link to LeetCode Lab`](https://leetcode.com/problems/most-frequent-prime/description/)

---
{{< youtube vyLo_FMR3IU >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
