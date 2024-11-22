
+++
authors = ["grid47"]
title = "Leetcode 456: 132 Pattern"
date = "2024-09-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 456: 132 Pattern in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Stack","Monotonic Stack","Ordered Set"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/456.webp"
youtube = "TfgWauHLuRE"
youtube_upload_date="2023-09-30"
youtube_thumbnail="https://i.ytimg.com/vi/TfgWauHLuRE/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/456.webp" 
    alt="A sequence of numbers where the 132 pattern lights up, showing the correct order and placement of elements."
    caption="Solution to LeetCode 456: 132 Pattern Problem"
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
    bool find132pattern(vector<int>& nums) {
        
        int n = nums.size();
        int prv = INT_MIN;
        stack<int> stk;
        
        for(int i = n - 1; i >= 0; i--) {

            if (nums[i] < prv) return true;

            while(!stk.empty() && nums[i] > stk.top()) {

                prv = stk.top();
                stk.pop();

            }

            stk.push(nums[i]);
        }

        return false;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to determine if a given list of integers contains a **132 pattern**. A **132 pattern** is defined as a subsequence `i`, `j`, `k` where:
- `i < j < k`
- `nums[i] < nums[k] < nums[j]`

In other words, the sequence must consist of three integers where the first is smaller than the third, and the third is smaller than the second. The goal is to return `true` if such a pattern exists in the array, otherwise return `false`.

### Approach

To solve this problem efficiently, we need to leverage a **monotonic stack** combined with a backward traversal of the input array. The main idea is to track potential 132 patterns as we iterate through the array from right to left, updating potential candidates for the middle (`2`) and largest (`3`) values.

### Key Observations

1. **The Stack**: The stack will help us maintain potential candidates for the `3` value in the 132 pattern, i.e., the middle element (`nums[j]`) and the largest element (`nums[k]`).
2. **The `prv` Variable**: This variable is used to store the largest value that can serve as the `2` in the 132 pattern. It is updated as we process each element from right to left.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Variables

```cpp
int n = nums.size();
int prv = INT_MIN;
stack<int> stk;
```

- `n`: This stores the size of the `nums` array.
- `prv`: This is initialized to `INT_MIN`, and it will be used to store the largest potential `2` value that can form part of a 132 pattern.
- `stk`: This is a stack that will help us track potential candidates for the `3` value (the largest number in the pattern).

#### Step 2: Iterate through the Array in Reverse

```cpp
for(int i = n - 1; i >= 0; i--) {
    if (nums[i] < prv) return true;
    while(!stk.empty() && nums[i] > stk.top()) {
        prv = stk.top();
        stk.pop();
    }
    stk.push(nums[i]);
}
```

- We start iterating over the array `nums` from the last element to the first (i.e., in reverse order). The idea is that for each element, we will try to find a potential 132 pattern by looking for the smallest (`i`), middle (`j`), and largest (`k`) values.
- The first `if` condition checks if `nums[i]` is less than the value stored in `prv`. If true, it means we've found a 132 pattern where `nums[i]` can be the `1`, `prv` is the `2`, and the current element in the stack is the `3`. Therefore, we immediately return `true`.
- The `while` loop checks whether `nums[i]` is greater than the top of the stack. If so, it means we can pop the stack and update `prv` to the new value on top of the stack. This process ensures that `prv` always holds the largest number that can serve as the `2` in a 132 pattern.
- Finally, after processing the current element, we push `nums[i]` onto the stack, as it could potentially serve as the `3` in a 132 pattern for future elements.

#### Step 3: Return False if No Pattern is Found

```cpp
return false;
```

- If no valid 132 pattern is found during the entire iteration, we return `false`, indicating that no such subsequence exists in the array.

### Complexity Analysis

#### Time Complexity:

- **Iteration**: The algorithm iterates through the array once, and for each element, we perform a constant amount of work (either pushing or popping elements from the stack). This means the time complexity is `O(n)`, where `n` is the length of the input array `nums`.

#### Space Complexity:

- **Stack**: The stack stores at most `n` elements, where `n` is the number of elements in the array. Therefore, the space complexity is `O(n)`.

### Conclusion

This solution efficiently detects the presence of a 132 pattern in the array using a monotonic stack and backward traversal. The key idea is to maintain a stack of potential candidates for the largest number in the pattern and use a variable `prv` to track the middle value. The algorithm operates in linear time and requires linear space, making it optimal for this problem.

[`Link to LeetCode Lab`](https://leetcode.com/problems/132-pattern/description/)

---
{{< youtube TfgWauHLuRE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
