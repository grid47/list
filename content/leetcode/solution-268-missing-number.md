
+++
authors = ["grid47"]
title = "Leetcode 268: Missing Number"
date = "2024-10-11"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 268: Missing Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Math","Binary Search","Bit Manipulation","Sorting"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/268.webp"
youtube = "WnPLSRLSANE"
youtube_upload_date="2021-07-26"
youtube_thumbnail="https://i.ytimg.com/vi/WnPLSRLSANE/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/268.webp" 
    alt="A series of numbers, with one missing number softly highlighted as the gap is revealed."
    caption="Solution to LeetCode 268: Missing Number Problem"
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
    int missingNumber(vector<int>& nums) {
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++)
            sum ^= nums[i];
        for(int i = 0; i <= nums.size(); i++)
            sum ^= i;
        return sum;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

In this problem, you’re given an array `nums` of integers where each integer is between 0 and `n` (inclusive), and the array contains `n` distinct numbers. Your goal is to find the missing number from the range `0` to `n`. 

For example:
- **Input**: `nums = [3, 0, 1]`
- **Output**: `2`
  - The array contains the numbers `0`, `1`, and `3`, so the missing number is `2`.

Let's dive into an efficient approach to solve this! 🏃‍♂️💨

---

### 🧠 Approach

The key to solving this problem efficiently is the **XOR (exclusive OR)** operation, which has some awesome properties that help us identify the missing number in no time! ⚡

1. **Properties of XOR**:
   - `a ^ a = 0` (XOR of any number with itself is 0)
   - `a ^ 0 = a` (XOR of any number with 0 is the number itself)
   - XOR is both commutative and associative, which means the order of operations doesn’t matter.

Given these properties, XOR is like a magic tool for canceling out matching numbers. Here’s the trick:
- XOR all elements of the array with the numbers from `0` to `n`.
- Numbers that appear in both the array and the range cancel out, and the missing number is the one that’s left!

---

### 🔨 Step-by-Step Code Breakdown

Let’s break down the code to see how XOR works its magic! ✨

```cpp
class Solution {
public:
    int missingNumber(vector<int>& nums) {
```
- We define a function `missingNumber` inside the `Solution` class, which takes an array `nums` as input and returns the missing number from the range `0` to `n`.

```cpp
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++)
            sum ^= nums[i];
```
- First, we initialize a variable `sum` with the first element of the array `nums[0]`. 
- Then, we loop through the rest of the array and XOR `sum` with each element. This ensures we accumulate the XOR of all the elements in the array.

```cpp
        for(int i = 0; i <= nums.size(); i++)
            sum ^= i;
```
- In the second loop, we XOR `sum` with all integers from `0` to `n` (where `n = nums.size()`).
- This ensures that all the numbers in the range `0` to `n` are included, and the numbers that appear in both the array and the range will cancel out.

```cpp
        return sum;
    }
};
```
- After both loops, `sum` will hold the missing number because all other numbers have canceled out. We return `sum`, which is our final result! 🎉

---

### 📈 Complexity Analysis

Let's see how efficient our solution is! 🔍

#### Time Complexity:
- **O(n)**, where `n` is the size of the array `nums`. 
  - We have two loops:
    - The first loop processes all the elements in the array (`nums.size()` iterations).
    - The second loop processes all integers from `0` to `n` (another `n + 1` iterations).
  - Since both loops iterate linearly over the array and the range, the overall time complexity is proportional to the size of the array.

#### Space Complexity:
- **O(1)**, constant space. 
  - The algorithm only uses a few variables (`sum`, `i`), which do not depend on the size of the input array. No additional space is required, so it's super space-efficient! 💡

---

### 🏁 Conclusion

We’ve now solved the problem efficiently using XOR. Let’s quickly recap the main points:

#### Key Takeaways:
1. **XOR Properties**: XOR is a powerful tool that helps us find the missing number by canceling out matching numbers.
2. **Optimal Time Complexity**: The solution runs in **O(n)** time, which is great for large inputs.
3. **No Extra Space**: With **O(1)** space complexity, the solution doesn’t require any additional memory, making it space-efficient.
4. **Simplicity**: XOR operations simplify the problem, allowing us to find the missing number in just a few lines of code! ✨

### 🎯 Quick Recap:
- **Time**: O(n) ⏱️
- **Space**: O(1) 💡
- **Solution**: Use XOR to cancel out numbers and find the missing one!

This approach is both elegant and efficient, making it perfect for coding interviews or competitive programming. Keep practicing, and you’ll be a master at solving XOR-based problems in no time! 💪🎉

[`Link to LeetCode Lab`](https://leetcode.com/problems/missing-number/description/)

---
{{< youtube WnPLSRLSANE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
