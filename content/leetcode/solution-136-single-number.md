
+++
authors = ["grid47"]
title = "Leetcode 136: Single Number"
date = "2024-10-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 136: Single Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/136.webp"
youtube = "mriHA5vEh0A"
youtube_upload_date="2024-08-22"
youtube_thumbnail="https://i.ytimg.com/vi/mriHA5vEh0A/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/136.webp" 
    alt="A glowing, solitary number standing out in a sequence, signifying its uniqueness."
    caption="Solution to LeetCode 136: Single Number Problem"
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
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(int y: nums)
            x ^= y;
        return x;
    }
};
{{< /highlight >}}
---

### 🔍 **Problem: Single Number**

You are given an integer array `nums[]`, where every element appears **exactly twice** except for one element, which appears **once**. The task is to determine the element that appears only once, using the most efficient solution possible.

---

### 🧠 **Approach:**

To solve this problem efficiently, we can leverage the **XOR** (exclusive OR) operation. The XOR operation has the following useful properties:

1. **a ^ a = 0**: XOR-ing a number with itself results in zero.
2. **a ^ 0 = a**: XOR-ing a number with zero results in the number itself.
3. XOR is **commutative** and **associative**, which means the order of applying XOR does not matter.

By using these properties, we can XOR all the elements of the array. Here’s how this works:
- **Duplicate elements**: When two identical numbers are XOR-ed, they cancel each other out (because **a ^ a = 0**).
- **The unique element**: The single number that doesn’t have a pair will be left out after all XOR operations, as it won’t cancel out with any other number.

---

### 🔧 **Code Walkthrough:**

#### Step 1: **Initialize the variable**
We start by initializing a variable `x` to `0`, which will hold the result after performing XOR on all elements.

```cpp
int x = 0;
```

Starting with `0` is important because XOR-ing any number with `0` leaves the number unchanged.

#### Step 2: **Iterate through the array**
We then loop through each element in the array and XOR it with `x`.

```cpp
for(int y: nums)
    x ^= y;
```

- If `y` is a number that appears twice, XOR-ing it with `x` will cancel it out (i.e., set it to `0`).
- If `y` is the single number that appears only once, it will accumulate in `x` because it doesn’t have a duplicate to cancel it out.

#### Step 3: **Return the result**
After completing the loop, the variable `x` will hold the value of the number that appears only once.

```cpp
return x;
```

---

### ⏱️ **Complexity Analysis:**

#### Time Complexity:
- **O(n)**: We iterate over the array once, and each XOR operation is constant time (O(1)). Therefore, the time complexity is **O(n)**, where `n` is the length of the array.

#### Space Complexity:
- **O(1)**: We only use a constant amount of extra space. The only variable used is `x`, so the space complexity is **O(1)**.

---

### 🚀 **Conclusion:**

This solution is optimal both in terms of time and space:

- **Time Efficiency**: It runs in **O(n)** time, making it suitable for large arrays.
- **Space Efficiency**: It uses **O(1)** space, meaning no extra storage is required except for the result.

By exploiting the XOR properties, this solution efficiently cancels out pairs of identical elements and leaves the single unique element.

---

### 🧑‍🏫 **Example Walkthrough:**

Let’s take an example to see how this works:

```cpp
nums = [4, 1, 2, 1, 2]
```

1. Initialize `x = 0`.
2. XOR-ing through the array:
   - `x = 0 ^ 4 = 4`
   - `x = 4 ^ 1 = 5`
   - `x = 5 ^ 2 = 7`
   - `x = 7 ^ 1 = 6`
   - `x = 6 ^ 2 = 4`
3. At the end of the iteration, `x = 4`, which is the number that appears only once.

This approach is simple, efficient, and elegant!

---

[`Link to LeetCode Lab`](https://leetcode.com/problems/single-number/description/)

---
{{< youtube mriHA5vEh0A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
