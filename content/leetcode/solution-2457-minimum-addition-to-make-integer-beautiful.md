
+++
authors = ["grid47"]
title = "Leetcode 2457: Minimum Addition to Make Integer Beautiful"
date = "2024-03-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2457: Minimum Addition to Make Integer Beautiful in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "NoGK4582ey8"
youtube_upload_date="2022-10-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/NoGK4582ey8/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:

    int sum(long long n) {
        int res = 0;
        while(n > 0) {
            res += n % 10;
            n /= 10;
        }
        return res;
    }

    long long makeIntegerBeautiful(long long n, int target) {
        long long n0 = n, base = 1;
        while(sum(n) > target) {
            n = n / 10 + 1;
            base *= 10;
        }
        return n * base - n0;
    }
};
{{< /highlight >}}
---

### Problem Statement:
In this problem, we are given a number `n` and a target sum `target`. The task is to transform the number `n` into a number such that the sum of its digits does not exceed the given `target`. The transformation must be achieved by increasing `n` minimally such that the sum of the digits of the new number is less than or equal to the target.

We need to return the smallest positive integer that needs to be added to `n` to achieve the desired sum of digits.

### Approach:
The approach involves the following steps:
1. **Calculate the sum of digits of the number `n`**: The first step is to calculate the sum of digits of the number `n`. If this sum is already less than or equal to the target, then no transformation is needed, and the answer is 0.
2. **Increase the number minimally**: If the sum of digits is greater than the target, we need to increment `n` in such a way that the sum of its digits becomes less than or equal to the target. This is achieved by adjusting the least significant digits of `n` and then recalculating the sum.
3. **Repeat the process**: This process continues until the sum of digits is less than or equal to the target, and the minimal increment to `n` is found.

### Code Breakdown (Step by Step):

Let’s break down the code to understand each part:

1. **Helper Function to Calculate the Sum of Digits**:
   ```cpp
   int sum(long long n) {
       int res = 0;
       while(n > 0) {
           res += n % 10;  // Add the last digit to the sum
           n /= 10;         // Remove the last digit from n
       }
       return res;  // Return the sum of digits
   }
   ```
   - The `sum` function takes a long long integer `n` as input and returns the sum of its digits.
   - The function repeatedly extracts the last digit of `n` using the modulus operation (`n % 10`) and adds it to the result `res`.
   - Then, the last digit is removed from `n` using integer division (`n /= 10`), and the process continues until all digits are processed.
   - Finally, the sum of the digits is returned.

2. **Main Function to Make the Integer Beautiful**:
   ```cpp
   long long makeIntegerBeautiful(long long n, int target) {
       long long n0 = n, base = 1;
   ```
   - `n0` is initialized to store the original value of `n`. This will be used later to calculate the result after the minimal increment is found.
   - `base` is initialized to `1`. This variable is used to keep track of the place value of the digits being incremented as the number `n` is modified.

3. **Main Loop to Adjust the Number**:
   ```cpp
   while(sum(n) > target) {
       n = n / 10 + 1;
       base *= 10;
   }
   ```
   - The `while` loop continues as long as the sum of the digits of `n` is greater than the target.
   - In each iteration:
     - `n = n / 10 + 1`: This step removes the last digit of `n` by dividing it by 10, then adds 1 to the result. This operation effectively increments the number in such a way that it causes a carry-over to the next digit, reducing the sum of digits.
     - `base *= 10`: This step increases the place value of `base`. It is multiplied by 10 in each iteration to adjust the place value correctly when calculating the minimal increment later.
   - This loop continues until the sum of digits is less than or equal to the target.

4. **Calculate and Return the Result**:
   ```cpp
   return n * base - n0;
   ```
   - Once the sum of digits of `n` is less than or equal to the target, we calculate the difference between the modified number `n` and the original number `n0` multiplied by the place value `base`.
   - The result represents the smallest number that needs to be added to `n` to achieve the target sum of digits.
   - Finally, this result is returned.

### Complexity:

1. **Time Complexity**:
   - The time complexity is dominated by the number of digits in the number `n`. In the worst case, the number of digits in `n` is proportional to \( \log_{10}(n) \), where \( n \) is the size of the input number.
   - The `sum` function processes each digit of `n` once, which takes \( O(\log_{10}(n)) \) time.
   - The main loop runs while the sum of the digits exceeds the target. In each iteration, the number of digits is reduced, and the operation involves constant-time arithmetic operations and the call to the `sum` function.
   - Hence, the time complexity of the solution is \( O(\log_{10}(n)) \), where \( n \) is the number being transformed.

2. **Space Complexity**:
   - The space complexity is \( O(1) \) because the algorithm uses a constant amount of extra space, irrespective of the size of the input number `n`. The space used is for storing variables such as `n0`, `base`, and `res` during the calculation.

### Conclusion:

The `makeIntegerBeautiful` function efficiently solves the problem of transforming a number such that the sum of its digits does not exceed a given target. The algorithm works by iterating over the digits of `n` and adjusting the least significant digits minimally to reduce the sum of digits. The use of a helper function to calculate the sum of digits and a loop that increments the number until the sum is within the target makes the solution both simple and effective.

The time complexity of the solution is logarithmic in the size of the number, making it efficient even for large inputs. The space complexity is constant, as no additional space proportional to the input size is used. This makes the solution highly scalable and efficient, suitable for large inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-addition-to-make-integer-beautiful/description/)

---
{{< youtube NoGK4582ey8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
