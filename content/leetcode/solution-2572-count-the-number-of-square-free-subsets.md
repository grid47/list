
+++
authors = ["grid47"]
title = "Leetcode 2572: Count the Number of Square-Free Subsets"
date = "2024-02-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2572: Count the Number of Square-Free Subsets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math","Dynamic Programming","Bit Manipulation","Bitmask"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "rT4w58kX818"
youtube_upload_date="2023-02-19"
youtube_thumbnail="https://i.ytimg.com/vi_webp/rT4w58kX818/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int mod = (int) 1e9 + 7, n;
    vector<int> nums, prime;
    int memo[1001][1 << 11];
    
    int getMask(int num) {
        int mask = 0;
        for(int i= 0; i < prime.size(); i++) {
            int cnt = 0;
            while(num % prime[i] == 0) {
                cnt++;
                num /= prime[i];
            }
            if(cnt > 1) return -1;
            if(cnt == 1) {
                mask |= (1 << (i + 1));                
            }
        }
        return mask;
    }    

    int dp(int idx, int mask) {
        if(idx == n) return 1;

        if(memo[idx][mask] != -1) return memo[idx][mask];        
        int ans = dp(idx + 1, mask);

        int nmask = getMask(nums[idx]);
        if((nmask != -1) && ((nmask & mask) == 0)) {
            ans = (ans + dp(idx + 1, nmask | mask)) % mod;
        }
        return memo[idx][mask] = ans;
    }
    
    int squareFreeSubsets(vector<int>& nums) {
        n = nums.size();
        this->nums = nums;
        prime = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29 };
        memset(memo, -1, sizeof memo);
        return (dp(0, 0) - 1 + mod) % mod;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to find the number of square-free subsets of a given list of integers `nums`. A **square-free subset** is one where no element is divisible by any perfect square greater than `1` (i.e., no element has a square of a prime factor in its prime factorization).

### Approach

1. **Prime Factorization & Square-Free Concept**:
   - A **square-free number** is a number whose prime factorization contains no prime raised to a power greater than or equal to 2. For example, `6` is square-free because its prime factorization is `2 * 3`, but `12` is not because `12 = 2^2 * 3`.
   - To check if a number is square-free, we need to verify if any of its prime factors appear more than once.

2. **Dynamic Programming with Bitmasking**:
   - The idea is to use dynamic programming (DP) to count subsets that satisfy the square-free condition. We use bitmasking to represent subsets of prime factors efficiently.
   - Since we are only concerned with the primes `2, 3, 5, 7, 11, 13, 17, 19, 23, 29` (a fixed set of primes), we represent any number's prime factorization as a bitmask of size 10.
   - Each bit of the mask represents whether a specific prime divides the number. For instance, if a number is divisible by `2` and `3`, its corresponding mask will have the first and second bits set.

3. **Memoization**:
   - To avoid recomputing results for the same state multiple times, we use memoization. The state is represented by the current index in the array (`idx`) and the bitmask (`mask`) representing which primes have been included so far.

4. **Recursive Function**:
   - The recursive function `dp(idx, mask)` explores all subsets starting from index `idx` and keeps track of the primes that are already part of the subset using the bitmask `mask`.
   - If the current number’s prime factors conflict with the current `mask` (i.e., it shares any common prime factor), it is excluded from the subset. Otherwise, we explore both possibilities: including or excluding the current number.

5. **Base Case**:
   - When the recursion reaches the end of the array (`idx == n`), return `1` to indicate that we've found a valid subset.
   
6. **Modular Arithmetic**:
   - Since the result could be large, all calculations are done modulo `10^9 + 7` to prevent overflow and keep the numbers manageable.

### Code Breakdown (Step by Step)

1. **Prime Initialization and Mask Computation**:
   ```cpp
   prime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29};
   ```
   - We initialize a list of the first 10 primes to handle the prime factorization of numbers up to a certain limit. These primes are used to build the bitmask for each number.

2. **Function to Get the Bitmask**:
   ```cpp
   int getMask(int num) {
       int mask = 0;
       for(int i= 0; i < prime.size(); i++) {
           int cnt = 0;
           while(num % prime[i] == 0) {
               cnt++;
               num /= prime[i];
           }
           if(cnt > 1) return -1;
           if(cnt == 1) {
               mask |= (1 << (i + 1));                
           }
       }
       return mask;
   }
   ```
   - This function calculates the bitmask representation of a number. For each prime, we divide `num` by the prime until it's no longer divisible.
   - If any prime appears more than once in the factorization, the number is not square-free, and the function returns `-1`.
   - Otherwise, it sets the corresponding bit in the mask to `1` if that prime divides the number.

3. **Dynamic Programming with Memoization**:
   ```cpp
   int dp(int idx, int mask) {
       if(idx == n) return 1;
       if(memo[idx][mask] != -1) return memo[idx][mask];
       int ans = dp(idx + 1, mask);
       int nmask = getMask(nums[idx]);
       if((nmask != -1) && ((nmask & mask) == 0)) {
           ans = (ans + dp(idx + 1, nmask | mask)) % mod;
       }
       return memo[idx][mask] = ans;
   }
   ```
   - `dp(idx, mask)` is the recursive function that counts the number of square-free subsets.
   - We first check if the result for the current state is already computed using the `memo` table.
   - If not, we compute it:
     - First, we count the subsets that exclude the current number: `dp(idx + 1, mask)`.
     - Then, we calculate the mask of the current number using `getMask(nums[idx])`. If the number is square-free (i.e., `nmask != -1`), and its prime factors do not conflict with the primes already in the subset (`(nmask & mask) == 0`), we add the number to the subset.
   - Finally, the result is stored in the `memo` table to avoid redundant calculations.

4. **Main Function**:
   ```cpp
   int squareFreeSubsets(vector<int>& nums) {
       n = nums.size();
       this->nums = nums;
       memset(memo, -1, sizeof memo);
       return (dp(0, 0) - 1 + mod) % mod;
   }
   ```
   - `squareFreeSubsets(nums)` initializes the DP process by calling `dp(0, 0)`, starting with index `0` and an empty bitmask (`0`).
   - The final result is returned after subtracting `1` to exclude the empty subset, ensuring the result is always positive by using modulo arithmetic.

### Complexity Analysis

- **Time Complexity**:
   - The dynamic programming approach explores each possible subset using a bitmask. The number of possible masks is \(2^{10} = 1024\), as there are 10 primes. The number of states is \(n \times 1024\), where `n` is the size of `nums`.
   - Thus, the time complexity is \(O(n \times 1024)\), which simplifies to \(O(n)\), where `n` is the size of the input array.

- **Space Complexity**:
   - The space complexity is dominated by the `memo` table, which has a size of \(n \times 1024\), leading to a space complexity of \(O(n \times 1024)\), or \(O(n)\).

### Conclusion

This solution efficiently counts the number of square-free subsets of the given list of integers by using dynamic programming with bitmasking. The use of memoization ensures that overlapping subproblems are avoided, significantly improving performance. By leveraging modular arithmetic, the solution ensures that the results remain manageable even for large inputs. This approach is both time-efficient and space-efficient for the problem at hand.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-the-number-of-square-free-subsets/description/)

---
{{< youtube rT4w58kX818 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
