
+++
authors = ["grid47"]
title = "Leetcode 283: Move Zeroes"
date = "2024-10-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 283: Move Zeroes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/283.webp"
youtube = "39VJV4KVyi8"
youtube_upload_date="2020-01-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/39VJV4KVyi8/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/283.webp" 
    alt="A sequence where zeroes gently move to the end, and the remaining elements shift into place."
    caption="Solution to LeetCode 283: Move Zeroes Problem"
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
    void moveZeroes(vector<int>& nums) {
        int j = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0)
                swap(nums[i], nums[j]), j++;
        }
        while(j < nums.size())
            nums[j++] = 0;
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

The challenge here is to **move all zeroes in a given array** `nums` to the end, without changing the order of non-zero elements. And here’s the twist: we want to do this with an efficient **O(n)** time complexity and **O(1)** extra space.

For example:
- **Input:** `nums = [0, 1, 0, 3, 12]`
- **Output:** `nums = [1, 3, 12, 0, 0]`

See how all the zeroes are at the end while the other numbers stay in order? Let’s dive into how we can achieve this efficiently! 

---

### 🔍 Approach

To solve this problem, we’ll use a classic **two-pointer technique**. This method allows us to traverse the list and rearrange it without needing extra space—just a simple, efficient, in-place modification.

**Main Idea:**
1. **Pointer `i`:** Moves through each element in the array.
2. **Pointer `j`:** Tracks where the next non-zero element should go.

As we move through the array, every time we find a non-zero element, we swap it with the element at position `j` (the spot where the next non-zero belongs). Then, we move `j` forward to prep it for the next non-zero.

---

### 🛠️ Step-by-Step Code Breakdown

#### Step 1: Initialize Pointer `j`
```cpp
int j = 0;
```
- Here, `j` starts at `0`. This is the position where the next non-zero element should be placed.

#### Step 2: Traverse the Array with Pointer `i`
```cpp
for(int i = 0; i < nums.size(); i++) {
    if(nums[i] != 0)
        swap(nums[i], nums[j]), j++;
}
```
- We iterate through each element in `nums`.
- Every time we encounter a non-zero (`nums[i] != 0`), we swap it with `nums[j]`.
    - This swap puts the non-zero element in the correct place at the front.
    - Then, we move `j` to the next spot where a non-zero element should go.
- By the end, all non-zero elements are clustered at the beginning in the correct order.

#### Step 3: Fill the Remaining Positions with Zeroes
```cpp
while(j < nums.size())
    nums[j++] = 0;
```
- Once all non-zero elements are at the front, `j` will be at the first position where a zero should go.
- We then set each remaining position (from `j` onward) to zero.

---

### 📊 Complexity Analysis

#### Time Complexity
- **O(n):** We process each element in the array once in the main loop, and the second loop fills in zeroes in **O(n)** worst-case time.
- Both loops combined give an overall time complexity of **O(n)**.

#### Space Complexity
- **O(1):** The algorithm only uses a constant amount of extra space—no additional arrays or data structures needed. Everything is done in-place.

---

### 🎯 Conclusion

This solution efficiently moves all zeroes to the end while keeping the relative order of non-zero elements intact. Using the **two-pointer technique** gives us an optimal **O(n)** time and **O(1)** space complexity, making it a great fit for performance-sensitive applications.

#### Key Takeaways:
- **Optimal Efficiency:** **O(n)** time complexity for fast performance.
- **In-Place Solution:** **O(1)** space complexity—modifies the array without extra memory.
- **Preserves Order:** Keeps non-zero elements in their original order.

The two-pointer approach is a fantastic way to handle similar array rearrangement problems, making it a valuable technique in your toolkit! Keep up the good work, and happy coding! 😊

[`Link to LeetCode Lab`](https://leetcode.com/problems/move-zeroes/description/)

---
{{< youtube 39VJV4KVyi8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
