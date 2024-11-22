
+++
authors = ["grid47"]
title = "Leetcode 287: Find the Duplicate Number"
date = "2024-10-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 287: Find the Duplicate Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/287.webp"
youtube = "P5Knc5OmL2o"
youtube_upload_date="2023-09-19"
youtube_thumbnail="https://i.ytimg.com/vi_webp/P5Knc5OmL2o/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/287.webp" 
    alt="A series of numbers, with the duplicate gently glowing and standing out from the rest."
    caption="Solution to LeetCode 287: Find the Duplicate Number Problem"
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
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0], fast = nums[nums[0]];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[nums[fast]];
        }
        fast = 0;
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }
        return fast;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

We're tasked with finding the **duplicate number** in an integer array `nums` containing `n + 1` numbers, with each number ranging between `1` and `n`. The catch? **Don't modify the array**, and aim for **constant extra space**.

For example:
- **Input:** `nums = [1, 3, 4, 2, 2]`
- **Output:** `2`

The duplicate here is `2` because it appears more than once. Ready to solve it? Let's go!

---

### 🧠 Approach: Cycle Detection with a Twist

We’ll use a clever approach known as **Floyd’s Tortoise and Hare algorithm** (a.k.a. Cycle Detection). Imagine each number in the array pointing to the next "index," like links in a chain. Since there's a duplicate, this "chain" forms a **cycle**!

Our goal is to detect the start of this cycle, which corresponds to the duplicate number. Here’s the plan:

1. **Phase 1 (Detect the Cycle):** Use two pointers—a **slow** pointer and a **fast** pointer.
2. **Phase 2 (Find the Duplicate):** After detecting the cycle, reset one pointer and advance both pointers step-by-step to find where they meet again. This meeting point is our duplicate.

---

### 🔨 Step-by-Step Code Breakdown

#### Step 1: Initialize Slow and Fast Pointers
```cpp
int slow = nums[0], fast = nums[nums[0]];
```
- We start `slow` at `nums[0]` and `fast` at `nums[nums[0]]` to establish a cycle-tracing setup.

#### Step 2: Detect the Cycle
```cpp
while(slow != fast) {
    slow = nums[slow];
    fast = nums[nums[fast]];
}
```
- **Slow pointer** moves one step (`slow = nums[slow]`), while the **fast pointer** moves two steps (`fast = nums[nums[fast]]`).
- When they meet, a cycle is detected. (🎉 We’re halfway there!)

#### Step 3: Find the Duplicate (Cycle Start)
```cpp
fast = 0;
while(slow != fast) {
    slow = nums[slow];
    fast = nums[fast];
}
return fast;
```
- Reset `fast` to the beginning, then move both pointers one step at a time.
- When they meet again, both `slow` and `fast` will point to the duplicate number—the start of the cycle. **Voila!**

---

### 📈 Complexity Analysis

#### Time Complexity:
- **O(n)** – Both pointers traverse the array linearly, resulting in **O(n)** time complexity.

#### Space Complexity:
- **O(1)** – Only two extra pointers are used, ensuring constant space usage.

---

### 🎯 Conclusion

This solution brilliantly finds the duplicate in **O(n)** time and **O(1)** space using cycle detection. It leverages the duplicate-induced "cycle" in the array structure to identify the duplicate efficiently. 

**Takeaways:**
- **Time Efficient**: Only one pass through the array is needed.
- **Space Efficient**: No extra arrays, just two pointers.
- **Cycle Detection Mastery**: Understanding this approach opens up new ways to handle cycle-related problems.

Keep up the great work! With techniques like this, you're building a powerful foundation in problem-solving! 🌟

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-the-duplicate-number/description/)

---
{{< youtube P5Knc5OmL2o >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
