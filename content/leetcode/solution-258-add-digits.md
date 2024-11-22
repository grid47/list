
+++
authors = ["grid47"]
title = "Leetcode 258: Add Digits"
date = "2024-10-12"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 258: Add Digits in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","Simulation","Number Theory"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/258.webp"
youtube = "gPZvXaniFDQ"
youtube_upload_date="2023-04-27"
youtube_thumbnail="https://i.ytimg.com/vi/gPZvXaniFDQ/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/258.webp" 
    alt="A number gradually breaking down into smaller digits, with each step glowing brighter until a single digit is left."
    caption="Solution to LeetCode 258: Add Digits Problem"
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
    int addDigits(int num) {
        int res = 0;
        while(num > 9) {
            while(num > 0) {
                res += num % 10;
                num /= 10;
            }
            
            num = res;
            res = 0;
        }
        return num;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

In this challenge, we are tasked with implementing a function that repeatedly adds the digits of a given integer `num` until a single digit is obtained. This process is known as the **digit root**. ✨

For example:
- **Input**: `num = 38`
- **Output**: `2`
  - First, sum of digits: 3 + 8 = 11
  - Second, sum of digits: 1 + 1 = 2

Your goal is to create a function that efficiently computes this digit root! 🌟

---

### 🧠 Approach

To solve this problem, we need to repeatedly reduce the number by summing its digits until only a single digit remains. Here's how we can approach it:

1. **Extract and Sum Digits**: We'll break the number down into its individual digits, sum them, and repeat the process until the result is a single-digit number.
2. **Termination Condition**: The process stops as soon as the result is less than 10, meaning we have a single digit.

Now, let's dive deeper into the steps needed to implement this solution in an efficient manner. 🧑‍💻

---

### 🔨 Step-by-Step Code Breakdown

Let's break down the code step by step to see how this process works! 🛠️

```cpp
class Solution {
public:
    int addDigits(int num) {
```
- Here, we define a function `addDigits` that takes an integer `num`. Our goal is to reduce this number to a single-digit number by summing its digits repeatedly.

```cpp
        int res = 0;
```
- We initialize a variable `res` to 0. This will temporarily store the sum of the digits in each iteration.

```cpp
        while(num > 9) {
```
- The `while` loop runs as long as `num` is greater than 9. This ensures we keep summing the digits until `num` is a single digit.

```cpp
            while(num > 0) {
                res += num % 10;
                num /= 10;
            }
```
- In the inner loop, we:
  1. **Extract the Last Digit**: `num % 10` gives the last digit of the number. We add this digit to `res`.
  2. **Remove the Last Digit**: `num /= 10` removes the last digit from `num`.

- This ensures we sum all digits of `num` in each iteration.

```cpp
            num = res;
            res = 0;
```
- After summing the digits, we assign the sum (`res`) back to `num`, effectively reducing `num` to the sum of its digits. We reset `res` to 0 for the next iteration.

```cpp
        }
        return num;
    }
};
```
- The loop continues until `num` is a single-digit number. Once that happens, we return `num` as the final digit root. 🏆

---

### 📈 Complexity Analysis

Let's now analyze the performance of our solution! 🔍

#### Time Complexity:
- **O(d)**, where `d` is the number of digits in `num`. This is because, in the worst case, we need to sum the digits of `num` multiple times. Each time, the number of digits reduces by a factor of 10 (since the sum of digits is usually smaller than the original number). So, the loop runs a number of times proportional to the number of digits in `num`.

#### Space Complexity:
- **O(1)**, constant space. We're only using a few variables (`num`, `res`), regardless of the size of the input number. This makes our solution highly space-efficient. 💡

---

### 🏁 Conclusion

In this solution, we efficiently compute the digit root of a number by repeatedly summing its digits until only one digit remains. Let's quickly recap the key points:

#### Key Takeaways:
1. **Efficient Calculation**: We use a simple iterative approach to sum digits and reduce the number to a single digit.
2. **Time Complexity**: The time complexity is **O(d)**, where `d` is the number of digits in the input number. This makes the solution fast even for larger numbers.
3. **Space Complexity**: Our solution is space-efficient with **O(1)** space complexity, as we only need a few variables.
4. **Practical**: This method can be useful for problems involving checksums or reducing numbers to a simpler form. 🌱

By following this approach, you'll be able to quickly reduce any number to its digit root, making it a powerful tool for many number-based problems! 🎯

### ✨ Quick Recap:
- **Time**: O(d) ⏱️
- **Space**: O(1) 💡
- **Solution**: Repeated digit summing! 

Keep practicing, and you'll become a pro at solving such number-based challenges! 💪🎉

[`Link to LeetCode Lab`](https://leetcode.com/problems/add-digits/description/)

---
{{< youtube gPZvXaniFDQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
