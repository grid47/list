
+++
authors = ["grid47"]
title = "Leetcode 1390: Four Divisors"
date = "2024-06-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1390: Four Divisors in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Math"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
+++



---
**Code:**

{{< highlight cpp >}}


class Solution {
public:

    int sumFourDivisors(vector<int>& nums) {
        
        int sum = 0;
        
        for(auto n: nums) {
            int d = 0;
            for(int i = 2; i * i <= n; i++) {
                if(n % i == 0) {
                    if(d == 0) {
                        d = i;
                    } else {
                        d = 0;
                        break;
                    }
                }
            }
            if(d > 0 && d != n/d) {
                sum += 1 + n + d + n/d;
            }            
        }
        return sum;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to find the sum of all integers in a given array `nums` that have exactly four divisors. If a number has four divisors, we need to sum those numbers together and return the result. A number with exactly four divisors can be expressed in one of the following ways:
1. The number is a product of two distinct prime numbers \( p \) and \( q \) (i.e., \( n = p \times q \)). Its divisors will be \( 1, p, q, n \).
2. The number is a cube of a prime number \( p^3 \) (i.e., \( n = p^3 \)). Its divisors will be \( 1, p, p^2, n \).

### Approach

The approach to solving the problem involves iterating through each number in the input array and determining if it has exactly four divisors. We can achieve this by:
1. Checking divisors of each number up to its square root.
2. Counting valid divisors found, ensuring they meet the conditions for having exactly four distinct divisors.
3. If a number meets the conditions, we add it to the total sum.

### Code Breakdown (Step by Step)

Let's break down the provided C++ code into its components:

1. **Class Definition**:
   ```cpp
   class Solution {
   public:
   ```
   - The `Solution` class is defined, which contains the method to solve the problem.

2. **Method Definition**:
   ```cpp
       int sumFourDivisors(vector<int>& nums) {
   ```
   - The method `sumFourDivisors` takes a vector of integers `nums` as input and returns an integer.

3. **Variable Initialization**:
   ```cpp
           int sum = 0;
   ```
   - An integer variable `sum` is initialized to zero. This variable will hold the cumulative sum of all integers with exactly four divisors.

4. **Iterating Over Each Number**:
   ```cpp
           for(auto n: nums) {
               int d = 0;
   ```
   - A for-each loop iterates through each number `n` in the `nums` vector.
   - A variable `d` is initialized to zero, which will be used to keep track of a potential divisor.

5. **Finding Divisors**:
   ```cpp
               for(int i = 2; i * i <= n; i++) {
                   if(n % i == 0) {
                       if(d == 0) {
                           d = i;
                       } else {
                           d = 0;
                           break;
                       }
                   }
               }
   ```
   - An inner loop iterates through possible divisors starting from 2 up to the square root of `n` (i.e., \( i \times i \leq n \)).
   - If `i` divides `n`, we check if `d` is still zero. If so, we assign `d` to `i` (indicating we've found one divisor).
   - If `d` already has a value (indicating a previous divisor was found), we reset `d` to zero and break out of the loop, as more than one divisor was found.

6. **Checking Conditions for Four Divisors**:
   ```cpp
               if(d > 0 && d != n/d) {
                   sum += 1 + n + d + n/d;
               }            
           }
   ```
   - After exiting the inner loop, we check if `d` is greater than zero and if `d` is not equal to `n/d` (to ensure the divisors are distinct).
   - If both conditions are satisfied, we add the divisors \( 1, n, d, \) and \( n/d \) to `sum`.

7. **Returning the Result**:
   ```cpp
           return sum;
       }
   };
   ```
   - Finally, the method returns the calculated `sum`.

### Complexity

- **Time Complexity**:
  - The time complexity of the solution is \( O(m \sqrt{n}) \), where \( m \) is the size of the input array `nums` and \( n \) is the largest number in the array. This is because for each number, we potentially check divisors up to its square root.

- **Space Complexity**:
  - The space complexity is \( O(1) \), as we are using a constant amount of extra space regardless of the size of the input.

### Conclusion

The provided solution efficiently calculates the sum of integers that have exactly four divisors by iterating through each number in the input array and checking for valid divisors. 

The key points to note include:
- Understanding the mathematical properties that lead to a number having exactly four divisors.
- Employing efficient divisor-finding logic that minimizes unnecessary calculations.
- Ensuring that the conditions for distinct prime factors or cube roots are adequately checked.

This code provides a clear and effective method for solving the problem, demonstrating both mathematical insight and practical programming skills. 

Overall, it is an excellent example of how to approach problems involving number theory and divisor counting in an algorithmic context. By mastering such techniques, programmers can tackle a wide array of challenges in competitive programming and algorithm design.

[`Link to LeetCode Lab`](https://leetcode.com/problems/four-divisors/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
