
+++
authors = ["grid47"]
title = "Leetcode 935: Knight Dialer"
date = "2024-08-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 935: Knight Dialer in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "vlsUUm_qqsY"
youtube_upload_date="2023-11-27"
youtube_thumbnail="https://i.ytimg.com/vi/vlsUUm_qqsY/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
    int mod = 1e9 + 7;
public:
    int knightDialer(int n) {
        long long res = 0;
        vector<vector<long long>> arr(4, vector<long long>(3, -1));
        vector<vector<vector<long long>>> mem(n + 1, arr);

        for(int i = 0; i < 4; i++)
        for(int j = 0; j < 3; j++)
        {
            res = (res + path(i, j, n, mem))% mod;
        }
        return res;
    }

long long path(int i, int j, int n, vector<vector<vector<long long>>> &mem) {
        
        if(i < 0 || j < 0|| i >= 4 || j >= 3 || (i==3 && j !=1))
            return 0;

        if(mem[n][i][j] != -1) return mem[n][i][j] % mod;

        if (n == 1) return 1;

        mem[n][i][j] = path(i -1 , j -2, n - 1, mem) % mod +
                  path(i -1 , j +2, n - 1, mem) % mod +
                  path(i -2 , j -1, n - 1, mem) % mod +
                  path(i -2 , j +1, n - 1, mem) % mod +
                  path(i +1 , j -2, n - 1, mem) % mod +
                  path(i +1 , j +2, n - 1, mem) % mod +
                  path(i +2 , j -1, n - 1, mem) % mod +
                  path(i +2 , j +1, n - 1, mem) % mod;
        return mem[n][i][j];
    }

};
{{< /highlight >}}
---

### Problem Statement

The problem at hand involves counting the number of distinct ways a knight can dial a number on a standard keypad after making `n` moves. The knight starts at any key on a 3x4 keypad (with the keys arranged as follows):

```
1 2 3
4 5 6
7 8 9
  0
```

The knight can move to a key that is two rows away and one column away, or one row away and two columns away. The task is to determine how many distinct ways the knight can land on a number after `n` moves, starting from any key on the keypad.

### Approach

This problem can be solved efficiently using dynamic programming and memoization. Here's a step-by-step explanation of the approach:

1. **Understanding the Knight's Moves**: The knight in this problem moves in an "L" shape, i.e., it can either move two rows and one column or one row and two columns. There are a total of 8 possible moves for any given position, except for some boundary conditions (like the bottom row, where the knight cannot move down further).

2. **Memoization to Avoid Repetition**: To optimize the solution, we use a memoization technique to store the results of previously computed states. Since there are multiple recursive calls for the same position and the number of moves, we avoid recalculating these states by storing the results in a memoization table.

3. **Recursive Function to Explore All Possible Paths**: The recursive function `path` calculates the number of distinct ways to reach a key after a certain number of moves. Starting from any given key on the keypad, it recursively explores all possible moves and accumulates the results. Each call checks if a move is within the bounds of the keypad, and if not, it returns 0.

4. **Base Case**: The base case of the recursion is when `n == 1`, meaning we have only one move left. In this case, every key on the keypad is reachable from the starting key, so the result is 1 for that specific key.

5. **Memoization Table**: The memoization table `mem` is a 3-dimensional array where the first dimension represents the number of moves left (`n`), and the second and third dimensions represent the position of the knight on the keypad (`i` for row and `j` for column). If a state has been computed before, we return the stored result to avoid recalculating it.

6. **Modulo Operation**: Since the result may be a large number, the answer is taken modulo `1e9 + 7` to ensure the result fits within the constraints and prevents integer overflow.

7. **Iterating Over All Keys**: Finally, the `knightDialer` function iterates over all positions on the keypad (represented by the grid coordinates `i` and `j`), and for each position, it computes the number of distinct paths starting from that key by calling the `path` function.

### Code Breakdown (Step by Step)

1. **Initialization**:
   ```cpp
   long long res = 0;
   vector<vector<long long>> arr(4, vector<long long>(3, -1));
   vector<vector<vector<long long>>> mem(n + 1, arr);
   ```
   - The variable `res` holds the result, which is the total number of distinct paths.
   - `arr` is a temporary 2D array used to initialize the memoization table `mem`. This table has dimensions `[n+1][4][3]`, where `n+1` is for the number of moves, and `4` and `3` represent the number of rows and columns on the keypad.

2. **Iterating Over All Keys**:
   ```cpp
   for(int i = 0; i < 4; i++)
       for(int j = 0; j < 3; j++)
       {
           res = (res + path(i, j, n, mem)) % mod;
       }
   ```
   - This double loop iterates over each key on the keypad (from `(0,0)` to `(3,2)`), calling the `path` function for each key to compute the number of distinct paths starting from that key.

3. **Path Calculation with Memoization**:
   ```cpp
   long long path(int i, int j, int n, vector<vector<vector<long long>>> &mem) {
       if(i < 0 || j < 0 || i >= 4 || j >= 3 || (i == 3 && j != 1))
           return 0;
       if(mem[n][i][j] != -1) return mem[n][i][j] % mod;
       if (n == 1) return 1;
       mem[n][i][j] = path(i - 1, j - 2, n - 1, mem) % mod +
                      path(i - 1, j + 2, n - 1, mem) % mod +
                      path(i - 2, j - 1, n - 1, mem) % mod +
                      path(i - 2, j + 1, n - 1, mem) % mod +
                      path(i + 1, j - 2, n - 1, mem) % mod +
                      path(i + 1, j + 2, n - 1, mem) % mod +
                      path(i + 2, j - 1, n - 1, mem) % mod +
                      path(i + 2, j + 1, n - 1, mem) % mod;
       return mem[n][i][j];
   }
   ```
   - **Base Case**: If the knight moves outside the boundaries of the keypad or tries to move from an invalid key (like the bottom-left or right corners), we return 0.
   - If the state has already been computed (`mem[n][i][j] != -1`), we return the stored value.
   - If there is only one move left (`n == 1`), we return 1 because any key is reachable from the starting key.
   - The recursion explores all 8 possible moves and accumulates the results using modulo `1e9 + 7` to prevent overflow.

4. **Returning the Final Result**:
   ```cpp
   return res;
   ```
   After all calculations, the final result is returned, which is the sum of the distinct paths starting from all keys on the keypad.

### Complexity

- **Time Complexity**: The time complexity of this solution is O(n * 4 * 3), which simplifies to O(n). This is because for each key on the keypad (12 total), we compute the number of distinct paths by exploring 8 possible moves recursively, and memoization ensures that we only compute each state once.
  
- **Space Complexity**: The space complexity is O(n * 4 * 3), which simplifies to O(n). This is due to the memoization table `mem` that stores the results for each key position and the number of remaining moves.

### Conclusion

This solution leverages dynamic programming and memoization to efficiently count the number of distinct ways a knight can dial a number on a keypad after `n` moves. By storing previously computed results, the algorithm avoids redundant calculations, ensuring an optimal solution. This approach works well even for large values of `n` and provides the answer modulo `1e9 + 7` to handle large outputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/knight-dialer/description/)

---
{{< youtube vlsUUm_qqsY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
