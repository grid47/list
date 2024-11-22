
+++
authors = ["grid47"]
title = "Leetcode 2571: Minimum Operations to Reduce an Integer to 0"
date = "2024-02-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2571: Minimum Operations to Reduce an Integer to 0 in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Dynamic Programming","Greedy","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "Z14XgQXPw2I"
youtube_upload_date="2023-02-19"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Z14XgQXPw2I/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    int dp(int n) {
        if(n == 0) return 0;
        // cout << n << " " ;
        int ans = 0;
        if((n & 1) == 0) {
            ans = dp(n >> 1);
        } else {
            if(((n >> 1) & 1)== 1) {
            // if(n == 5) cout << "'" << n<< "'";                
                n += 1;
                // while((n & 1) == 0) n >>= 1;
                ans = 1 + dp(n);
            } else {
                ans = 1 + dp(n >> 1);
            }
        }
        return ans;
    }
    
    int minOperations(int n) {
        // aggregate consecutive ones
        // turn of one
        return dp(n);
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires finding the minimum number of operations to reduce a given integer `n` to `0`. The operations are as follows:
- If the current number is even, divide it by 2.
- If the current number is odd, either add 1 or subtract 1 to make it even.

The goal is to determine the fewest number of steps required to reduce `n` to `0`.

### Approach

1. **Recursive Approach with Memoization**:
   - We can solve this problem using recursion. Starting from `n`, we apply the operations and recursively reduce the value of `n`.
   - Since we need to consider both addition and subtraction when `n` is odd, it becomes important to evaluate the minimum operations needed for both cases and select the optimal one.
   
2. **Base Case**:
   - When `n == 0`, the number is already reduced to `0`, so the number of operations is `0`.
   
3. **Recursive Case**:
   - If `n` is even, the optimal choice is to divide it by 2 because this operation reduces the number efficiently, halving the value.
   - If `n` is odd, we need to make it even first. To do this, we have two options:
     - **Option 1**: Add 1 to `n`, making it even and allowing the division by 2 in the next step.
     - **Option 2**: Subtract 1 from `n` to make it even and then divide it by 2 in the next step.
   - The recursive function will then calculate the number of operations for both choices and return the minimum of the two.

4. **Memoization**:
   - To improve the performance of the recursive solution, memoization can be used. This technique involves storing the results of subproblems (i.e., the number of operations for a given number) in a table (or a hash map) so that we do not recompute the results for the same input multiple times.
   
5. **Minimizing Operations**:
   - We continue to reduce `n` until we reach `0`. The minimum number of operations is determined by recursively evaluating the operations for each even and odd case.

### Code Breakdown (Step by Step)

1. **Recursive Function Definition**:
   ```cpp
   int dp(int n) {
       if (n == 0) return 0;
   ```
   - The function `dp(n)` takes an integer `n` and returns the minimum number of operations required to reduce `n` to `0`.
   - The base case is when `n == 0`, in which case no operations are needed, so the function returns `0`.

2. **Handling Even Numbers**:
   ```cpp
   if ((n & 1) == 0) {
       ans = dp(n >> 1);
   }
   ```
   - If `n` is even, the optimal operation is to divide `n` by 2. The bitwise operation `(n & 1) == 0` checks if the number is even (since the least significant bit of an even number is `0`).
   - The next step is to recursively call `dp(n >> 1)` where `n >> 1` shifts the bits of `n` to the right, effectively dividing it by 2.

3. **Handling Odd Numbers**:
   ```cpp
   else {
       if (((n >> 1) & 1) == 1) {
           n += 1;
           ans = 1 + dp(n);
       } else {
           ans = 1 + dp(n >> 1);
       }
   }
   ```
   - If `n` is odd, we have two possible operations:
     - **Option 1**: If the number obtained by shifting `n` to the right by one bit (`n >> 1`) is odd, we add 1 to `n` to make it even, then recursively call `dp(n + 1)`.
     - **Option 2**: If the number obtained by shifting `n` to the right by one bit is even, we subtract 1 from `n` to make it even and then recursively call `dp(n - 1)`.
   - The result of both operations is incremented by 1 (for the addition or subtraction operation) and the recursive call is made.

4. **Returning the Result**:
   ```cpp
   return ans;
   ```
   - The function returns `ans`, which holds the minimum number of operations for reducing `n` to `0`.

5. **Main Function to Call `dp`**:
   ```cpp
   int minOperations(int n) {
       return dp(n);
   }
   ```
   - The function `minOperations(n)` is the entry point of the solution. It simply calls the recursive `dp` function and returns the result.

### Complexity Analysis

- **Time Complexity**:
   - Without memoization, the time complexity is exponential, as the function recursively calls itself multiple times for the same values of `n`.
   - The recurrence tree grows exponentially, leading to a time complexity of \(O(2^n)\), where `n` is the size of the number.
   - However, with memoization (not implemented here), the complexity would reduce to \(O(\log n)\) as each number would be computed only once.

- **Space Complexity**:
   - The space complexity is \(O(\log n)\) due to the recursive call stack. This is because each recursive call divides `n` by 2, and the depth of the recursion tree is proportional to the logarithm of `n`.

### Conclusion

This recursive solution calculates the minimum number of operations required to reduce a number `n` to `0` by using bitwise operations. The approach efficiently handles both even and odd cases, ensuring that the optimal number of operations is selected for each scenario. The solution can be further optimized by adding memoization to store previously computed results, which would significantly improve the time complexity.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-operations-to-reduce-an-integer-to-0/description/)

---
{{< youtube Z14XgQXPw2I >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
