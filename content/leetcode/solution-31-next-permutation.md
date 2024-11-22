
+++
authors = ["grid47"]
title = "Leetcode 31: Next Permutation"
date = "2024-11-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 31: Next Permutation in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/31.webp"
youtube = "6qXO72FkqwM"
youtube_upload_date="2021-05-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/6qXO72FkqwM/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/31.webp" 
    alt="A flowing sequence of shapes or words shifting and reshaping into a new, calming formation."
    caption="Solution to LeetCode 31: Next Permutation Problem"
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
    void nextPermutation(vector<int>& nums) {
        int idx = -1;
        for(int i = nums.size() - 2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) { 
                idx = i;
                break;
            }
        }
        if(idx ==-1) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i = nums.size() - 1; i > idx; i--) {
            if(nums[i] > nums[idx]) {
                swap(nums[idx], nums[i]);
                break;
            }
        }
        reverse(nums.begin() + idx + 1, nums.end());
    }
};
{{< /highlight >}}
---

### 🌟 **Next Lexicographically Greater Permutation**

This problem involves finding the next lexicographically greater permutation of a list of numbers. If no greater permutation exists (i.e., the input is already the largest permutation), the list should be rearranged into the smallest permutation possible (sorted in ascending order).

---

### 🧠 **Approach Overview**

To find the next permutation, we use a well-defined approach that optimizes the process. We work by examining the permutation from right to left, identifying a point where the current arrangement can be increased, then making the smallest possible increase to ensure we generate the next permutation in lexicographical order.

#### **Steps to Solve the Problem:**

1. **Find the Rightmost Ascending Pair:**  
   Identify the first position from the right where the sequence stops increasing. This tells us where we can make the permutation larger.

2. **Find the Next Larger Element:**  
   Find the smallest element to the right of this position that is larger than the element at that position.

3. **Swap the Elements:**  
   Swap the two identified elements to create a larger permutation.

4. **Reverse the Suffix:**  
   Reverse the elements after the swapped position to ensure the resulting sequence is the smallest possible permutation (sorted in ascending order).

5. **Edge Case (Largest Permutation):**  
   If no such pair exists, the permutation is the largest possible. In this case, simply reverse the entire list to get the smallest permutation.

---

### 👇 **Breaking Down the Code:**

#### **Step 1: Find the Rightmost Ascending Pair**
```cpp
int idx = -1;
for(int i = nums.size() - 2; i >= 0; i--) {
    if(nums[i] < nums[i+1]) { 
        idx = i;
        break;
    }
}
```
- We scan from right to left to find the first element `nums[i]` that is smaller than `nums[i+1]`. This marks the point where the order breaks, indicating that the permutation can still be increased.

#### **Step 2: Handle the Edge Case (Largest Permutation)**
```cpp
if(idx == -1) {
    reverse(nums.begin(), nums.end());
    return;
}
```
- If no such ascending pair is found (i.e., the list is in descending order), we reverse the entire list to obtain the smallest permutation.

#### **Step 3: Find the Next Larger Element**
```cpp
for(int i = nums.size() - 1; i > idx; i--) {
    if(nums[i] > nums[idx]) {
        swap(nums[idx], nums[i]);
        break;
    }
}
```
- We now look for the smallest element larger than `nums[idx]` from the right side. Once found, we swap them to ensure the next permutation is as close as possible to the current one but larger.

#### **Step 4: Reverse the Suffix**
```cpp
reverse(nums.begin() + idx + 1, nums.end());
```
- After swapping, the sublist from `idx+1` to the end of the list is in descending order. Reversing this part ensures that the list is in the smallest lexicographical order after the change.

---

### ⏳ **Complexity Breakdown**

- **Time Complexity: O(n)**  
  The algorithm involves:
  1. A linear scan from right to left to find the first ascending pair (O(n)).
  2. Another linear scan from the right side to find the element to swap with `nums[idx]` (O(n)).
  3. A reverse operation (O(n)) on the portion of the list after the swap.
  
  Thus, the overall time complexity is **O(n)**, where `n` is the number of elements in the list.

- **Space Complexity: O(1)**  
  The algorithm uses only a constant amount of extra space (excluding the input list), which is required for the index `idx` and the loop variables.

---

### 💡 **Key Insights**

- **In-Place Algorithm:** The algorithm works by modifying the input list in place, meaning it doesn’t require any additional space beyond the variables needed for the calculation.
  
- **Efficient:** This solution operates in **O(n)** time, making it suitable for large input sizes. The use of **constant space** ensures minimal memory usage.

- **Edge Case Handling:** The algorithm efficiently handles the case when the input is already the largest permutation by reversing the entire list.

---

### 🚀 **Conclusion**

This solution provides an optimal way to generate the next lexicographically greater permutation of a list of numbers. By using an efficient in-place algorithm with a time complexity of **O(n)** and a space complexity of **O(1)**, it ensures that the next permutation is computed quickly and with minimal memory usage.

This approach is ideal for problems involving permutations or order constraints, and the techniques used here (finding ascending pairs, swapping, and reversing) are commonly applied in various algorithmic challenges related to permutations.

[`Link to LeetCode Lab`](https://leetcode.com/problems/next-permutation/description/)

---
{{< youtube 6qXO72FkqwM >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
