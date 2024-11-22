
+++
authors = ["grid47"]
title = "Leetcode 2741: Special Permutations"
date = "2024-02-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2741: Special Permutations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Bit Manipulation","Bitmask"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "AxXNOXj1upY"
youtube_upload_date="2023-06-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/AxXNOXj1upY/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mod = (int) 1e9 + 7;
    vector<vector<int>> grid;
    vector<map<int, int>> mp;
    int specialPerm(vector<int>& nums) {
        
        int conn = 0, n = nums.size();
        grid.resize(n);
        mp.resize(n);
        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++)
                if(nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0){
                    grid[i].push_back(j);
                    grid[j].push_back(i);
                }
        }
        long ans = 0;

        for(int i = 0; i < n; i++) {
            int msk = 0;
            msk |= (1 << i);
            ans = (ans + dfs(i, n - 1, msk)) % mod;            
        }
        return ans;
    }
    
    int dfs(int i, int n, int msk) {
        
        if(n == 0) return 1;
        if(mp[i].count(msk)) return mp[i][msk];
        long ans = 0;
        for(int x: grid[i]) {
            if(!(msk & (1 << x))) {
                msk ^= (1 << x);
                ans = (ans + dfs(x, n - 1, msk)) % mod;
                msk ^= (1 << x);
            }
        }
        return mp[i][msk] = ans;
    }
    
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to find the number of special permutations of a given list of integers, `nums`, where a permutation is considered "special" if, for every pair of adjacent numbers in the permutation, one number is divisible by the other. The solution must compute this count efficiently, given the constraint that the number of permutations can grow very large.

### Approach

This problem can be broken down into the following key steps:

1. **Graph Representation**: 
   - The first task is to represent the divisibility condition between numbers as a graph. Each number in the input array `nums` is treated as a node in the graph. There is an edge between two nodes if one number divides the other. This allows us to model the problem as finding valid paths in this graph, where the paths correspond to the "special" permutations.

2. **Bitmasking and Dynamic Programming (DP)**:
   - Since we are working with permutations, a brute-force approach would require generating all possible permutations of the numbers, which would be computationally expensive for large arrays. Instead, we use dynamic programming with bitmasking to track the numbers that have already been used in the permutation. The bitmask efficiently represents the state of which elements from the array have been included in the current permutation.

3. **DFS for Counting Permutations**:
   - Depth-first search (DFS) is used to explore all valid permutations of the numbers. At each step, we try to place a number in the current position, and we recursively explore the next possible positions while respecting the divisibility condition. We cache the results of subproblems using memoization to avoid redundant calculations.

4. **Modulo Operation**:
   - Given that the number of valid permutations can be very large, we return the result modulo \(10^9 + 7\), which is a common practice in competitive programming to prevent overflow and ensure that the result fits within standard integer limits.

### Code Breakdown (Step by Step)

Let's break down the code into smaller parts for better understanding:

#### 1. **Initialization and Setup**

```cpp
int mod = (int) 1e9 + 7;
vector<vector<int>> grid;
vector<map<int, int>> mp;
int specialPerm(vector<int>& nums) {
    int conn = 0, n = nums.size();
    grid.resize(n);
    mp.resize(n);
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++)
            if(nums[i] % nums[j] == 0 || nums[j] % nums[i] == 0){
                grid[i].push_back(j);
                grid[j].push_back(i);
            }
    }
```

- **Grid Construction**: 
  - A `grid` is created to represent the graph, where each element `grid[i]` contains the list of indices `j` that are connected to `i`. Two elements are connected if one is divisible by the other.
- **Memoization Table**: 
  - A memoization table `mp` is used to store the results of subproblems. Each entry `mp[i][msk]` will store the number of valid special permutations starting from the `i`-th index, with the subset of elements represented by the bitmask `msk` already used.
- **Nested Loops for Divisibility**:
  - Two nested loops iterate over all pairs of elements in the `nums` array, and if one element is divisible by the other (or vice versa), we add an edge between the corresponding nodes in the graph (by adding each index to the `grid` of the other index).

#### 2. **Main Logic for Special Permutation Count**

```cpp
long ans = 0;
for(int i = 0; i < n; i++) {
    int msk = 0;
    msk |= (1 << i);
    ans = (ans + dfs(i, n - 1, msk)) % mod;            
}
return ans;
```

- **DFS for Permutation Counting**:
  - We initiate a DFS call for each number in the list, treating it as the first element in the permutation. The bitmask `msk` is used to mark the number as "used," ensuring that no number is repeated in the permutation.
  - We sum up the results of the DFS calls for each number, using the modulo operation to avoid overflow.

#### 3. **Depth-First Search (DFS) with Memoization**

```cpp
int dfs(int i, int n, int msk) {
    if(n == 0) return 1;
    if(mp[i].count(msk)) return mp[i][msk];
    long ans = 0;
    for(int x: grid[i]) {
        if(!(msk & (1 << x))) {
            msk ^= (1 << x);
            ans = (ans + dfs(x, n - 1, msk)) % mod;
            msk ^= (1 << x);
        }
    }
    return mp[i][msk] = ans;
}
```

- **Base Case**: 
  - When `n == 0`, we have successfully constructed a valid permutation, so we return `1`.
- **Memoization Lookup**: 
  - Before proceeding with the DFS, we check if the result for the current state (current index `i` and bitmask `msk`) has already been computed and stored in `mp[i][msk]`. If it has, we return the stored value to avoid redundant computations.
- **DFS Exploration**:
  - For each adjacent element `x` in `grid[i]`, we check if `x` has already been included in the permutation by checking the corresponding bit in `msk`. If not, we add `x` to the permutation by updating `msk`, recursively call DFS to explore further permutations, and then backtrack by reverting `msk`.

#### 4. **Result Calculation and Modulo Operation**

- After all recursive calls, we store the result in `mp[i][msk]` and continue the DFS exploration. The final result is returned modulo \(10^9 + 7\).

### Complexity Analysis

#### Time Complexity:

- **Grid Construction**:
  - The nested loops to build the `grid` take \(O(n^2)\) time, where \(n\) is the size of the `nums` array.
  
- **DFS and Memoization**:
  - The DFS explores all subsets of the array (represented by the bitmask `msk`), leading to a time complexity of \(O(n \cdot 2^n)\), where \(2^n\) represents the number of possible subsets and \(n\) is the number of nodes (elements in the array).

Thus, the overall time complexity is \(O(n^2 + n \cdot 2^n)\).

#### Space Complexity:

- **Grid and Memoization Tables**:
  - The `grid` takes \(O(n^2)\) space, and the memoization table `mp` takes \(O(n \cdot 2^n)\) space.
  
Thus, the overall space complexity is \(O(n^2 + n \cdot 2^n)\).

### Conclusion

This approach efficiently calculates the number of special permutations using graph theory and dynamic programming with bitmasking. By leveraging memoization and DFS, we can avoid recalculating results for overlapping subproblems, significantly reducing the computational effort compared to a brute-force approach.

- **Time Complexity**: \(O(n^2 + n \cdot 2^n)\), where \(n\) is the size of the input array.
- **Space Complexity**: \(O(n^2 + n \cdot 2^n)\).

This solution is optimal for the problem, utilizing efficient techniques like DFS and bitmasking to handle large input sizes effectively.

[`Link to LeetCode Lab`](https://leetcode.com/problems/special-permutations/description/)

---
{{< youtube AxXNOXj1upY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
