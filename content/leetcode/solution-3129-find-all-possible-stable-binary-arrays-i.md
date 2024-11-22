
+++
authors = ["grid47"]
title = "Leetcode 3129: Find All Possible Stable Binary Arrays I"
date = "2023-12-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3129: Find All Possible Stable Binary Arrays I in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "PVsRUVGHVCY"
youtube_upload_date="2024-04-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/PVsRUVGHVCY/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<vector<vector<vector<int>>>> mem;
    int limit, mod = 1000000007;
    int dp(int z, int o, int p, int lmt, vector<vector<vector<vector<int>>>> &mem) {
        if(z == 0 && o == 0) return 1;
        if(mem[p][o][lmt][z] != -1) return mem[p][o][lmt][z];
        long ans = 0;
        if(p == 0) {
            if(z > 0 && lmt < limit)    ans += dp(z - 1, o, 0, lmt + 1, mem) % mod;
            if(o > 0)                   ans += dp(z, o - 1, 1, 1, mem)% mod;
        } else {
            if(o > 0 && lmt < limit)    ans += dp(z, o - 1, 1, lmt + 1, mem)% mod;
            if(z > 0)                   ans += dp(z - 1, o, 0, 1, mem)% mod;
        }
        return mem[p][o][lmt][z] = ans % mod;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<vector<vector<int>>>> mem(2, vector<vector<vector<int>>>(one + 1, vector<vector<int>>(limit + 1, vector<int>(zero + 1, -1))));
        this->limit = limit;
        long res  = (dp(zero - 1, one, 0, 1, mem) +
                     dp(zero, one - 1, 1, 1, mem)) % mod;
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to count the number of **stable arrays** that can be formed from a given number of `0`s and `1`s. A **stable array** is defined by a specific set of rules:
1. The number of `1`s and `0`s in the array is given as input.
2. There is a constraint on the maximum number of consecutive `0`s (`limit`) that can be in the array.
3. The array must alternate between `1`s and `0`s, and if `0`s appear consecutively, the number must not exceed the specified `limit`.

The task is to count how many such stable arrays can be formed while adhering to the given constraints.

### Approach

To solve this problem, we can use a **dynamic programming (DP)** approach with memoization. The key idea is to break the problem down into smaller subproblems and use previously computed results to build up the solution for the larger problem.

1. **Dynamic Programming Representation**: We define a 4-dimensional DP array `mem` to store the results of subproblems. The state of the DP can be defined as:
   - `z`: The number of `0`s left to place in the array.
   - `o`: The number of `1`s left to place in the array.
   - `p`: A binary value (0 or 1) representing whether the last element placed was `0` or `1`.
   - `lmt`: The current count of consecutive `0`s placed in the array.
   
   The value of the DP state represents the number of ways to form a valid stable array with these parameters.

2. **Recursion**: The recursive function `dp(z, o, p, lmt, mem)` computes the number of valid stable arrays that can be formed by placing the remaining `z` `0`s and `o` `1`s under the condition that the last placed element was `p` (either `0` or `1`) and `lmt` is the current number of consecutive `0`s.

   The function computes:
   - If the last placed element was `0`, then we can place a `0` again if the number of consecutive `0`s (`lmt`) is less than the `limit`, or we can place a `1` if any `0` is already placed.
   - If the last placed element was `1`, then we can place a `0` or a `1`, with the appropriate constraints.

3. **Base Case**: When `z == 0` and `o == 0`, this means all `0`s and `1`s have been placed in the array, and the array is valid. Hence, we return `1`.

4. **Memoization**: We store the results of subproblems in the `mem` array to avoid redundant calculations and improve efficiency.

5. **Final Calculation**: The result is obtained by calling the `dp` function for the initial state with `zero - 1` `0`s, `one` `1`s, and the first element being a `0` or `1`.

### Code Breakdown

#### Step 1: Initialize DP Array

```cpp
vector<vector<vector<vector<int>>>> mem(2, vector<vector<vector<int>>>(one + 1, vector<vector<int>>(limit + 1, vector<int>(zero + 1, -1))));
```
- Here, we initialize a 4-dimensional vector `mem` to store the memoized results. The dimensions are:
  - `2`: This corresponds to the binary state `p`, which can either be `0` (last element placed was `0`) or `1` (last element placed was `1`).
  - `one + 1`: The number of `1`s left to place.
  - `limit + 1`: The number of consecutive `0`s that can be placed.
  - `zero + 1`: The number of `0`s left to place.

#### Step 2: Define Recursive DP Function

```cpp
int dp(int z, int o, int p, int lmt, vector<vector<vector<vector<int>>>> &mem) {
    if(z == 0 && o == 0) return 1;
    if(mem[p][o][lmt][z] != -1) return mem[p][o][lmt][z];
```
- We first check if the number of `0`s and `1`s left to place is zero. If it is, we return `1` because we have successfully placed all elements.
- If the result for the current state `(z, o, p, lmt)` has already been computed (i.e., `mem[p][o][lmt][z] != -1`), we return the previously computed value to avoid redundant calculations.

#### Step 3: Recursive Transitions

```cpp
long ans = 0;
if(p == 0) {
    if(z > 0 && lmt < limit)    ans += dp(z - 1, o, 0, lmt + 1, mem) % mod;
    if(o > 0)                   ans += dp(z, o - 1, 1, 1, mem)% mod;
} else {
    if(o > 0 && lmt < limit)    ans += dp(z, o - 1, 1, lmt + 1, mem)% mod;
    if(z > 0)                   ans += dp(z - 1, o, 0, 1, mem)% mod;
}
```
- If the last element placed was a `0` (`p == 0`), we have two choices:
  - We can place another `0` if there are remaining `0`s and the number of consecutive `0`s (`lmt`) is less than the `limit`.
  - We can place a `1` if there are remaining `1`s.
  
- If the last element placed was a `1` (`p == 1`), we again have two choices:
  - We can place another `1` if there are remaining `1`s.
  - We can place a `0` if there are remaining `0`s.

Each transition is recursive, and we accumulate the results in `ans`.

#### Step 4: Store and Return Result

```cpp
return mem[p][o][lmt][z] = ans % mod;
```
- After calculating the number of valid arrays for the current state `(z, o, p, lmt)`, we store the result in the `mem` array to be used later.

#### Step 5: Final Calculation in `numberOfStableArrays`

```cpp
long res  = (dp(zero - 1, one, 0, 1, mem) +
             dp(zero, one - 1, 1, 1, mem)) % mod;
```
- Finally, we calculate the result by calling the `dp` function for the initial state with one less `0` and `1` and the first element being either `0` or `1`.

```cpp
return res;
```
- The result is returned, which is the number of stable arrays modulo `1000000007`.

### Complexity

#### Time Complexity:
- The time complexity is **O(zero * one * limit)**. This is because, for each state `(z, o, p, lmt)`, we perform a constant amount of work (either transitioning to another state or returning the result). The number of states is bounded by the product of the number of `0`s, the number of `1`s, and the limit on consecutive `0`s.

#### Space Complexity:
- The space complexity is **O(zero * one * limit)**, primarily due to the storage of the `mem` array.

### Conclusion

This approach leverages dynamic programming with memoization to efficiently calculate the number of stable arrays that can be formed given the constraints. By breaking down the problem into smaller subproblems and using memoization to store intermediate results, the solution avoids redundant calculations and ensures optimal performance. The use of recursion allows us to explore all possible valid sequences of `0`s and `1`s while adhering to the limit on consecutive `0`s, providing an elegant and efficient solution to the problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-all-possible-stable-binary-arrays-i/description/)

---
{{< youtube PVsRUVGHVCY >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
