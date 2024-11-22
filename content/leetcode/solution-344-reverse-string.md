
+++
authors = ["grid47"]
title = "Leetcode 344: Reverse String"
date = "2024-10-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 344: Reverse String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Two Pointers","String"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/344.webp"
youtube = "P68JPXtFyYg"
youtube_upload_date="2020-01-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/P68JPXtFyYg/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/344.webp" 
    alt="A string gently reversing itself, with the characters softly shifting places in a calming, fluid motion."
    caption="Solution to LeetCode 344: Reverse String Problem"
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
    void reverseString(vector<char>& s) {
        int i = 0, j = s.size() - 1;
        while(i <= j) {
            swap(s[i++], s[j--]);
        }
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

In this problem, you're given a string represented as a vector of characters. Your task is to **reverse the string in-place** without using additional space for another string (aside from a few auxiliary variables). The string is mutable, so you’ll be modifying it directly. Can you come up with an efficient solution?

#### Example:
- For `s = ["h", "e", "l", "l", "o"]`, after reversing, the result should be `s = ["o", "l", "l", "e", "h"]`.

---

### 🧠 Approach

To solve this problem, we can take advantage of a **two-pointer technique**. The idea is simple: place one pointer at the start of the string and another at the end, then swap the characters at these positions. After each swap, move the pointers towards the center until they meet.

This approach is both efficient and simple, as it uses:
1. **In-place reversal**: No extra space is needed for a second string, making the solution space-efficient.
2. **Constant time swaps**: Swapping two elements is a constant-time operation, meaning that the solution runs quickly.

The process of swapping characters from both ends toward the middle ensures that the string is reversed effectively.

---

### 🔨 Step-by-Step Code Breakdown

Let's break down the code into digestible steps:

```cpp
void reverseString(vector<char>& s) {
    int i = 0, j = s.size() - 1;  // Initialize two pointers

    // Step 1: Start swapping characters until the pointers meet
    while (i < j) {
        swap(s[i], s[j]);  // Swap characters at positions i and j
        i++;               // Move pointer i to the right
        j--;               // Move pointer j to the left
    }
}
```

#### Step 1: Initialize Two Pointers

```cpp
int i = 0, j = s.size() - 1;
```
- We initialize two pointers: `i` at the start of the string (`0`) and `j` at the end (`s.size() - 1`).
- These pointers will help us traverse the string from both ends and swap characters as we move toward the middle.

#### Step 2: Start the Reversal Loop

```cpp
while (i < j) {
    swap(s[i], s[j]);
    i++;
    j--;
}
```
- The `while` loop runs as long as `i` is less than `j`. This ensures that the pointers meet in the middle, and the string is reversed by the time they do.
- Inside the loop, we perform a `swap(s[i], s[j])` to exchange the characters at the positions `i` and `j`. Then:
  - `i++` moves the `i` pointer towards the center.
  - `j--` moves the `j` pointer towards the center.

#### Step 3: End of Function
- Once the loop finishes, the string has been reversed in-place, and no return is necessary because we modified the input vector directly.

---

### 📈 Complexity Analysis

#### Time Complexity:
- **O(n)**: The time complexity is **O(n)**, where `n` is the length of the string. The `while` loop runs for `n / 2` iterations, swapping characters in constant time, so the total number of operations is proportional to the length of the string.

#### Space Complexity:
- **O(1)**: The space complexity is **O(1)** because the reversal happens in-place. We only use a fixed amount of extra space for the two pointers (`i` and `j`), regardless of the size of the input.

---

### 🏁 Conclusion

This solution is an optimal way to reverse a string in-place using the two-pointer technique. Here's a quick recap:

#### Key Points:
- **Greedy Approach**: By swapping characters from both ends towards the middle, we can reverse the string efficiently.
- **Efficiency**: The algorithm runs in linear time (**O(n)**) and uses constant space (**O(1)**).
- **Simplicity**: The solution is easy to implement, and the two-pointer technique is an elegant way to reverse a string in-place.

Reversing a string doesn’t need to be complicated — just swap, move the pointers, and you’re done! Keep practicing and mastering these efficient techniques! 💡🎉

[`Link to LeetCode Lab`](https://leetcode.com/problems/reverse-string/description/)

---
{{< youtube P68JPXtFyYg >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
