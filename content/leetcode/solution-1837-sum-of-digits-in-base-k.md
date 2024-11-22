
+++
authors = ["grid47"]
title = "Leetcode 1837: Sum of Digits in Base K"
date = "2024-05-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1837: Sum of Digits in Base K in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "tPbypmspAi8"
youtube_upload_date="2021-04-25"
youtube_thumbnail="https://i.ytimg.com/vi/tPbypmspAi8/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumBase(int n, int k) {
        int res=0;
        while(n!=0)
        {
            res+=(n%k);
            n/=k;
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The task is to calculate the sum of the digits of a given integer \( n \) when it is represented in base \( k \). For example, if \( n = 34 \) and \( k = 6 \), then the base \( k \) representation of \( n \) would be \( 34_{10} = 54_6 \) (5 * 6^1 + 4 * 6^0). The sum of the digits \( 5 + 4 = 9 \) would be the desired output. The solution should be efficient and straightforward, working well within the constraints typically associated with integer operations.

### Approach

The approach to solve this problem involves repeatedly dividing the number \( n \) by the base \( k \) while keeping track of the remainder at each step. The remainder represents the least significant digit (rightmost) of the number in base \( k \). By summing up these remainders, we can obtain the total sum of the digits of \( n \) in base \( k \). Here are the steps to achieve this:

1. **Initialize a Result Variable**: Create a variable to accumulate the sum of the digits.
  
2. **Loop Until \( n \) Becomes Zero**: Use a while loop to repeatedly extract digits until \( n \) is reduced to zero.
   
3. **Calculate the Remainder**: In each iteration, calculate the remainder of \( n \) when divided by \( k \) (this gives the current least significant digit).
   
4. **Update the Sum**: Add the remainder to the result variable.
  
5. **Update \( n \)**: Update \( n \) by performing integer division by \( k \) to remove the least significant digit.
  
6. **Return the Result**: After exiting the loop, return the accumulated sum.

This method efficiently computes the sum without requiring conversion of the entire number to its base \( k \) representation in a string or array format, thus minimizing space and time overhead.

### Code Breakdown (Step by Step)

Here is the breakdown of the provided code:

```cpp
class Solution {
public:
    int sumBase(int n, int k) {
```
- A class named `Solution` is defined, containing a public method `sumBase` which takes two integers \( n \) (the number) and \( k \) (the base).

```cpp
        int res=0;
```
- A variable `res` is initialized to zero. This variable will store the accumulated sum of the digits as we process the number.

```cpp
        while(n!=0)
        {
```
- A while loop is initiated that will run as long as \( n \) is not zero. This ensures that we continue processing until all digits have been accounted for.

```cpp
            res+=(n%k);
```
- Inside the loop, the expression `n % k` calculates the remainder when \( n \) is divided by \( k \). This remainder corresponds to the least significant digit in the base \( k \) representation. The result is then added to `res`.

```cpp
            n/=k;
```
- The line `n /= k` updates \( n \) by performing integer division by \( k \). This operation effectively removes the least significant digit from \( n \) for the next iteration.

```cpp
        }
        return res;
    }
};
```
- After exiting the loop (when \( n \) becomes zero), the accumulated sum `res` is returned as the result. The method concludes here.

### Complexity

- **Time Complexity**: The time complexity of this approach is \( O(\log_k n) \) because each division operation reduces the size of \( n \) significantly. Specifically, the number of iterations needed to reduce \( n \) to zero corresponds to the number of digits in \( n \) when expressed in base \( k \).

- **Space Complexity**: The space complexity is \( O(1) \) since we are using a constant amount of space regardless of the input size. The calculations are performed in-place without requiring additional data structures.

### Conclusion

The provided solution efficiently calculates the sum of the digits of a number \( n \) when expressed in a specified base \( k \). By leveraging basic mathematical operations like division and modulus, the solution avoids unnecessary complexity associated with data structure manipulation or conversion processes.

This method is particularly beneficial in contexts where performance is critical, such as competitive programming or applications involving large numbers. The use of a simple loop to extract and sum the digits keeps the implementation clean and understandable.

In conclusion, the `sumBase` function offers an optimal approach to solve the problem at hand, combining clarity with efficiency. It serves as a useful algorithm for programmers and developers looking to enhance their skills in numerical representations and manipulation in different bases.

[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-digits-in-base-k/description/)

---
{{< youtube tPbypmspAi8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
