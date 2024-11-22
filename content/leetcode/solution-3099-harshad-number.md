
+++
authors = ["grid47"]
title = "Leetcode 3099: Harshad Number"
date = "2024-01-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 3099: Harshad Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "QplrY0LW62M"
youtube_upload_date="2024-03-31"
youtube_thumbnail="https://i.ytimg.com/vi_webp/QplrY0LW62M/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumOfTheDigitsOfHarshadNumber(int x) {
        int sum = 0;
        int tmp = x;
        while(tmp > 0) {
            sum += tmp % 10;
            tmp /= 10;
        }
        return x % sum == 0? sum : -1;
    }
};
{{< /highlight >}}
---

### Problem Statement

In this problem, you are given a positive integer `x`. The task is to determine if the number `x` is a Harshad number (or Niven number). A number is called a Harshad number if it is divisible by the sum of its digits. If `x` is a Harshad number, return the sum of its digits; otherwise, return `-1`.

### Approach

To solve this problem, we need to follow these steps:

1. **Sum of Digits:** Calculate the sum of the digits of the given number `x`.
2. **Check Divisibility:** Check if the number `x` is divisible by the sum of its digits.
3. **Return the Result:** If `x` is divisible by the sum of its digits, return the sum. Otherwise, return `-1`.

### Code Breakdown (Step by Step)

Let's break down the code to understand each part:

#### Step 1: Initialize Variables

```cpp
int sum = 0;
int tmp = x;
```

- Here, we initialize the `sum` variable to store the sum of the digits of `x`.
- The variable `tmp` is initialized with the value of `x`. This is used for iterating over the digits of `x`.

#### Step 2: Calculate the Sum of Digits

```cpp
while(tmp > 0) {
    sum += tmp % 10;
    tmp /= 10;
}
```

- In this part of the code, we use a `while` loop to iterate over each digit of the number `x`. The loop runs as long as `tmp` is greater than 0 (i.e., as long as there are digits left to process).
- `tmp % 10` extracts the last digit of the number. This value is added to the `sum` variable.
- `tmp /= 10` removes the last digit of `tmp` by performing an integer division by 10. This process continues until `tmp` becomes 0, at which point all digits of `x` have been processed.

#### Step 3: Check if `x` is Divisible by the Sum of its Digits

```cpp
return x % sum == 0 ? sum : -1;
```

- After calculating the sum of digits, we check if the original number `x` is divisible by the sum (`sum`).
- If `x % sum == 0`, it means `x` is divisible by the sum of its digits, so we return the sum of the digits.
- If `x` is not divisible by the sum of its digits, we return `-1`.

### Complexity

#### Time Complexity:

- **O(d)** where `d` is the number of digits in `x`.
  - The loop that calculates the sum of digits runs once for each digit in `x`. The number of digits in `x` is proportional to the logarithm of `x`, specifically `O(log(x))`. Therefore, the time complexity is linear in terms of the number of digits.

#### Space Complexity:

- **O(1)**: We are using only a constant amount of extra space (the integer variables `sum` and `tmp`). Thus, the space complexity is constant.

### Conclusion

The problem is solved by following a simple algorithm where we calculate the sum of the digits of the number `x`, check if `x` is divisible by this sum, and return the result accordingly. 

- If `x` is divisible by the sum of its digits, we return the sum.
- If `x` is not divisible by the sum, we return `-1`.

This approach is efficient with a time complexity of **O(d)** and space complexity of **O(1)**. It is an optimal solution for determining if a number is a Harshad number and returning the sum of its digits if it is.

The code efficiently calculates the sum of digits, performs the divisibility check, and returns the result in constant space. It’s a straightforward solution to the problem, and it works well for all positive integers `x`.

[`Link to LeetCode Lab`](https://leetcode.com/problems/harshad-number/description/)

---
{{< youtube QplrY0LW62M >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
