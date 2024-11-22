
+++
authors = ["grid47"]
title = "Leetcode 137: Single Number II"
date = "2024-10-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 137: Single Number II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/137.webp"
youtube = "cOFAmaMBVps"
youtube_upload_date="2020-06-22"
youtube_thumbnail="https://i.ytimg.com/vi/cOFAmaMBVps/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/137.webp" 
    alt="Two radiant numbers standing out in a sequence, one representing the unique element and the other repeating."
    caption="Solution to LeetCode 137: Single Number II Problem"
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
        int n = nums.size();
        
        int ones = 0, twos = 0;
        for(int i = 0; i < n; i++) {
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;            
        }
        return ones;
    }
};
{{< /highlight >}}
---

### 🧩 Problem Statement

Imagine an array where every element appears exactly **three times**, except for **one special number** that appears only once. Your task is to find that unique number hiding among all the others! Sounds tricky, but with a clever approach, we can pinpoint that one number in a flash! ✨

---

### 🔍 Approach

To tackle this problem efficiently, we use **bitwise manipulation**—a powerful tool that allows us to track bits and uncover the number that shows up only once. With two simple variables, `ones` and `twos`, we can cleverly monitor the bits that appear **once** and **twice** throughout the array. By the end, the number that appears only once will be standing tall while the others get reset! 

The trick is to manage these two variables while keeping track of the bits that show up once and twice, and discarding the ones that appear **three times**.

---

### 💡 Step-by-Step Code Breakdown

#### 1️⃣ **Initialize `ones` and `twos`**

```cpp
int ones = 0, twos = 0;
```
Here, we set up two variables, `ones` and `twos`, both starting at zero. These will help us track which bits have appeared once and twice, respectively, as we loop through the array. Simple, right? 💪

---

#### 2️⃣ **Iterate Over the Array and Update `ones` and `twos`**

```cpp
for(int i = 0; i < n; i++) {
    ones = (ones ^ nums[i]) & ~twos;
    twos = (twos ^ nums[i]) & ~ones; 
}
```
This is where the magic happens! ✨ Here's what each line does:
- **Update `ones`**:
  ```cpp
  ones = (ones ^ nums[i]) & ~twos;
  ```
  - The XOR (`^`) operation toggles the bits in `ones` with those in the current number (`nums[i]`).
  - The `& ~twos` part ensures that if a bit has already appeared twice, we don't include it again in `ones`. This helps us focus on bits that appear **once**.

- **Update `twos`**:
  ```cpp
  twos = (twos ^ nums[i]) & ~ones;
  ```
  - Similarly, XOR is used to update `twos`, keeping track of bits that have appeared **twice**.
  - The `& ~ones` part ensures that bits already marked as "once" aren’t counted again in `twos`.

These steps efficiently track which bits appear once and twice, while any bits appearing three times are wiped out automatically! 🔄

---

#### 3️⃣ **Return the Unique Number**

```cpp
return ones;
```
By the time we’ve finished looping through the array, `ones` will hold the number that appears only **once**. Why? Because all bits that appeared three times get erased in both `ones` and `twos`, leaving only the unique number in `ones`. 🎯

---

### 🧠 Time and Space Complexity

#### ⏱️ Time Complexity:
- **O(n)**: We loop through the array once, where `n` is the number of elements. Each iteration involves constant-time operations with bitwise operations. So, this is as efficient as it gets! 🚀

#### 🧳 Space Complexity:
- **O(1)**: We only need two integer variables, `ones` and `twos`, to track the state. No extra space required! This makes the space complexity constant and optimal. 💡

---

### 🏁 Conclusion

With the **bitwise approach**, we’ve crafted a solution that finds the unique number in an array where every other number appears exactly three times. Thanks to bit manipulation, this algorithm runs in **O(n)** time and uses only **O(1)** space, making it highly efficient and perfect for large datasets. 🌟

Here’s a quick recap:
- **Time Complexity**: O(n) — We pass through the array once, performing constant-time operations!
- **Space Complexity**: O(1) — Only two variables needed to track the state, no extra space required!
- **Bitwise Magic**: With XOR and AND operations, we cleverly keep track of numbers appearing once and twice while ignoring the ones that appear three times.

This solution demonstrates how bitwise tricks can solve problems in an elegant and efficient way. It’s a fantastic technique to master, especially if you’re preparing for coding interviews! Keep practicing, and soon these tricks will feel like second nature. 💪 You’ve got this! Keep up the great work! 🌟

---

[`Link to LeetCode Lab`](https://leetcode.com/problems/single-number-ii/description/)

---
{{< youtube cOFAmaMBVps >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
