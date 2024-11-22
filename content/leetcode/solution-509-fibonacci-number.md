
+++
authors = ["grid47"]
title = "Leetcode 509: Fibonacci Number"
date = "2024-09-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 509: Fibonacci Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Dynamic Programming","Recursion","Memoization"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/509.webp"
youtube = "WPBTYmvcHXs"
youtube_upload_date="2019-12-02"
youtube_thumbnail="https://i.ytimg.com/vi_webp/WPBTYmvcHXs/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/509.webp" 
    alt="A sequence of numbers where each Fibonacci number glows as it is calculated in the sequence."
    caption="Solution to LeetCode 509: Fibonacci Number Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int fib(int n) {
        if(n == 0) return 0;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
            
        return dp[n];
    }
};
{{< /highlight >}}
---

### Problem Statement

The Fibonacci sequence is a series of numbers in which each number is the sum of the two preceding ones, starting from 0 and 1. That is:

- Fibonacci(0) = 0
- Fibonacci(1) = 1
- Fibonacci(n) = Fibonacci(n-1) + Fibonacci(n-2) for n ≥ 2

In this problem, you are given an integer `n`, and your task is to compute the `n`-th Fibonacci number.

### Approach

The Fibonacci sequence can be computed using different methods: recursion, dynamic programming (DP), and matrix exponentiation. Here, we will discuss a solution using dynamic programming, which provides a time-efficient and space-efficient way to compute the Fibonacci sequence.

**Dynamic Programming Approach**:

- The Fibonacci sequence exhibits an optimal substructure, meaning that the Fibonacci number at position `n` can be calculated using the Fibonacci numbers at positions `n-1` and `n-2`.
- Using dynamic programming, we avoid redundant recalculations by storing intermediate Fibonacci numbers in a table (or array) and building the solution iteratively.

#### Steps:

1. **Base Cases**: 
   - If `n = 0`, the result is `0`.
   - If `n = 1`, the result is `1`.
   
2. **Iterative Calculation**: 
   - We initialize a vector `dp` to store the Fibonacci numbers from `0` to `n`.
   - Set `dp[0] = 0` and `dp[1] = 1` since these are the base cases.
   - For each number `i` from `2` to `n`, calculate `dp[i]` as the sum of `dp[i - 1]` and `dp[i - 2]`.
   
3. **Return the Result**: 
   - The `n`-th Fibonacci number will be stored in `dp[n]`, which can be returned as the result.

This approach efficiently computes the Fibonacci number in `O(n)` time and uses `O(n)` space to store intermediate results.

### Code Breakdown (Step by Step)

#### 1. Function Definition

```cpp
int fib(int n) {
    if(n == 0) return 0;
    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;
    
    for(int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
        
    return dp[n];
}
```

The function `fib(int n)` takes an integer `n` as input and returns the `n`-th Fibonacci number. 

#### 2. Handling Base Case (`n == 0`)

```cpp
if(n == 0) return 0;
```

- The function first checks if `n` is `0`. If so, the Fibonacci number is `0`, and we return it immediately. This handles the base case.

#### 3. Initializing the DP Array

```cpp
vector<int> dp(n + 1, 0);
dp[0] = 0;
dp[1] = 1;
```

- We create a vector `dp` of size `n + 1` to store the Fibonacci numbers from `0` to `n`. Initially, all elements are set to `0`.
- We then manually set the base cases:
  - `dp[0] = 0` (Fibonacci of 0 is 0).
  - `dp[1] = 1` (Fibonacci of 1 is 1).

#### 4. Iterative Calculation of Fibonacci Numbers

```cpp
for(int i = 2; i <= n; i++)
    dp[i] = dp[i - 1] + dp[i - 2];
```

- Starting from `i = 2`, we iterate until `i = n`.
- For each `i`, we calculate the Fibonacci number at index `i` as the sum of the Fibonacci numbers at indices `i - 1` and `i - 2`. This is based on the recursive relation: `Fibonacci(i) = Fibonacci(i - 1) + Fibonacci(i - 2)`.

#### 5. Returning the Result

```cpp
return dp[n];
```

- Once the loop completes, the Fibonacci number at position `n` is stored in `dp[n]`. This value is returned as the result.

### Complexity

#### Time Complexity:
- **Iterative Calculation**: The loop runs from `i = 2` to `n`, so the total number of iterations is `O(n)`.
- **Overall Time Complexity**: The time complexity of the algorithm is `O(n)` because we are iterating through the sequence once, performing constant-time operations at each step.

#### Space Complexity:
- **DP Array**: We are using an array of size `n + 1` to store the Fibonacci numbers, so the space complexity is `O(n)`.
- **Overall Space Complexity**: The space complexity of the algorithm is `O(n)` because of the `dp` array used to store intermediate Fibonacci numbers.

### Conclusion

The dynamic programming approach to solving the Fibonacci sequence is both time and space efficient, with a time complexity of `O(n)` and a space complexity of `O(n)`. By storing the intermediate results, we avoid redundant computations, making this approach significantly faster than a naive recursive solution.

**Optimization Potential**: 
- If space efficiency is a concern, we could reduce the space complexity to `O(1)` by keeping only the last two Fibonacci numbers at any point in time, since we only need `dp[i-1]` and `dp[i-2]` to compute `dp[i]`. However, this would require modifying the code to use a constant amount of space instead of a full array.

[`Link to LeetCode Lab`](https://leetcode.com/problems/fibonacci-number/description/)

---
{{< youtube WPBTYmvcHXs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
