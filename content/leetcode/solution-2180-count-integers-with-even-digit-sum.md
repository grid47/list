
+++
authors = ["grid47"]
title = "Leetcode 2180: Count Integers With Even Digit Sum"
date = "2024-04-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2180: Count Integers With Even Digit Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Simulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "McbkGprY2C4"
youtube_upload_date="2022-02-20"
youtube_thumbnail="https://i.ytimg.com/vi_webp/McbkGprY2C4/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int countEven(int num) {
        int temp = num, sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum % 2 == 0 ? temp / 2 : (temp - 1) / 2;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to count the number of even integers from 1 to a given integer `num` based on the sum of its digits. Specifically:
- The function needs to evaluate if the sum of the digits of a given number `num` is even.
- If the sum of the digits is even, return half of the original number (`num / 2`).
- If the sum of the digits is odd, return half of the number minus one (`(num - 1) / 2`).

### Approach

The approach to solving this problem is relatively simple and involves iterating through the digits of the given number `num`. The solution is based on these steps:
1. First, we compute the sum of the digits of `num`.
2. We check whether the sum of the digits is even or odd.
3. If the sum is even, we return `num / 2` (integer division).
4. If the sum is odd, we return `(num - 1) / 2`.

### Code Breakdown (Step by Step)

Let's walk through the code in detail:

```cpp
class Solution {
public:
    int countEven(int num) {
        int temp = num, sum = 0;
```
- The function `countEven` is defined to take an integer `num` as input and return an integer result.
- The `temp` variable is used to store the original number (`num`) because we may modify `num` in the process of calculating the sum of its digits. `sum` is initialized to 0 and will be used to store the sum of the digits of `num`.

```cpp
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
```
- This is a `while` loop that iterates through each digit of `num`:
  - `num % 10` gives the last digit of `num`. We add this to `sum`.
  - `num /= 10` removes the last digit from `num` by performing integer division by 10.
- This process continues until `num` becomes zero, meaning all digits have been processed and added to `sum`.

```cpp
        return sum % 2 == 0 ? temp / 2 : (temp - 1) / 2;
    }
};
```
- Once the sum of the digits has been calculated, we check if the sum is even or odd:
  - `sum % 2 == 0` checks if the sum of the digits is even.
  - If the sum is even, we return `temp / 2`, which is the original number divided by 2.
  - If the sum is odd, we return `(temp - 1) / 2`, which is the number minus 1, then divided by 2.

This concise and efficient approach ensures that we compute the result based on the sum of digits and return the correct result as per the problem's requirements.

### Example Walkthrough

Let’s walk through some examples to understand the behavior of the code:

#### Example 1: `num = 30`

- **Step 1**: Calculate the sum of digits.
  - `3 + 0 = 3` (sum of digits is odd).
  
- **Step 2**: Since the sum is odd, the code returns `(num - 1) / 2 = (30 - 1) / 2 = 29 / 2 = 14`.

Thus, the output for `num = 30` will be `14`.

#### Example 2: `num = 22`

- **Step 1**: Calculate the sum of digits.
  - `2 + 2 = 4` (sum of digits is even).
  
- **Step 2**: Since the sum is even, the code returns `num / 2 = 22 / 2 = 11`.

Thus, the output for `num = 22` will be `11`.

#### Example 3: `num = 15`

- **Step 1**: Calculate the sum of digits.
  - `1 + 5 = 6` (sum of digits is even).
  
- **Step 2**: Since the sum is even, the code returns `num / 2 = 15 / 2 = 7`.

Thus, the output for `num = 15` will be `7`.

### Time Complexity

- **Time Complexity**: The time complexity is **O(d)**, where `d` is the number of digits in `num`. This is because we are iterating through each digit of `num` once to calculate the sum of the digits.
  - In the worst case, if `num` is a very large number, the number of digits is proportional to `log(num)`, so the time complexity can be considered **O(log(num))**.

- **Space Complexity**: The space complexity is **O(1)**. We only use a constant amount of space to store intermediate values like `sum`, `temp`, and the current `num` while computing the sum of digits.

### Conclusion

This solution is efficient and works well for solving the problem of determining how many even numbers there are from `1` to `num` based on the sum of the digits of `num`. By using basic integer arithmetic and modular operations, we can efficiently compute the result in **O(d)** time complexity, where `d` is the number of digits in `num`. The space complexity is minimal, with constant space used for intermediate variables.

This approach is simple yet effective, offering a clear understanding of how the sum of digits affects the final output. By following the modular arithmetic and checking if the sum is even or odd, the solution efficiently determines the correct result in all cases.

[`Link to LeetCode Lab`](https://leetcode.com/problems/count-integers-with-even-digit-sum/description/)

---
{{< youtube McbkGprY2C4 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
