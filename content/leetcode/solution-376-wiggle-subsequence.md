
+++
authors = ["grid47"]
title = "Leetcode 376: Wiggle Subsequence"
date = "2024-09-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 376: Wiggle Subsequence in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Greedy"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/376.webp"
youtube = "IpWoZvKzpug"
youtube_upload_date="2021-03-18"
youtube_thumbnail="https://i.ytimg.com/vi/IpWoZvKzpug/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/376.webp" 
    alt="A sequence of numbers gently moving into a wiggle pattern, each step softly highlighted as they align."
    caption="Solution to LeetCode 376: Wiggle Subsequence Problem"
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
    int wiggleMaxLength(vector<int> nums) {
        if(nums.size() == 0) return 0;
        
        int n = nums.size();
        
        vector<int> up(n, 0);
        vector<int> down(n, 0);        
        
        up[0] = 1;
        down[0] = 1;
        
        for(int i = 1; i < n; i++) {
                 if(nums[i] < nums[i - 1]) {
                down[i] = up[i - 1] + 1;
                up[i] = up[i - 1];
            }
            else if(nums[i] > nums[i - 1]) {            
                up[i] = down[i - 1] + 1;
                down[i] = down[i - 1];                
            }
            else {
                down[i] = down[i - 1];
                up[i]   =   up[i - 1];                
            }
        }
        
        return max(down[n - 1], up[n - 1]);
    }
};
{{< /highlight >}}
---

### 🚀 Problem Statement

In this problem, we're tasked with determining the length of the longest "wiggle subsequence" in an integer array. A **wiggle subsequence** is defined as one where the differences between consecutive elements strictly alternate between positive and negative.

For example:
- In the sequence `[1, 7, 4, 9, 2, 5]`, the longest wiggle subsequence is `[1, 7, 4, 9, 2, 5]` because the differences between consecutive numbers alternate in sign.
- In the sequence `[1, 2, 3, 4, 5]`, the longest wiggle subsequence is `[1, 2]` or `[1, 5]`, as there are no alternating differences between all the elements.

Our goal is to find the length of the longest subsequence that forms a wiggle pattern.

---

### 🧠 Approach

This problem can be efficiently solved using **dynamic programming**. We’ll track two possible scenarios for each element:
1. **Upward movement**: The difference between the current element and the previous one is positive.
2. **Downward movement**: The difference between the current element and the previous one is negative.

#### Key Observations:
- We need two arrays to represent the dynamic programming states:
  - `up[i]`: The length of the longest wiggle subsequence that ends with an upward movement at index `i`.
  - `down[i]`: The length of the longest wiggle subsequence that ends with a downward movement at index `i`.

If the current element is greater than the previous one, the sequence continues upward. If it’s smaller, the sequence continues downward. If it’s equal, no change occurs.

The result will be the maximum of the last values in the `up` and `down` arrays.

---

### 🔨 Step-by-Step Code Breakdown

#### 1. **Check for Empty Array**

```cpp
if(nums.size() == 0) return 0;
```
- If the array is empty, there is no subsequence to form, so we immediately return `0`.

---

#### 2. **Initialize the DP Arrays**

```cpp
int n = nums.size();
vector<int> up(n, 0);
vector<int> down(n, 0);

up[0] = 1;
down[0] = 1;
```
- We initialize two vectors, `up` and `down`, to store the lengths of the longest subsequences that end at each index with an upward or downward movement.
- The first element (`up[0]` and `down[0]`) is set to `1` because any single element is a valid subsequence of length 1.

---

#### 3. **Loop Through the Array**

```cpp
for(int i = 1; i < n; i++) {
    if(nums[i] < nums[i - 1]) {
        down[i] = up[i - 1] + 1;
        up[i] = up[i - 1];
    }
    else if(nums[i] > nums[i - 1]) {
        up[i] = down[i - 1] + 1;
        down[i] = down[i - 1];
    }
    else {
        down[i] = down[i - 1];
        up[i] = up[i - 1];
    }
}
```
- We iterate through the array starting from the second element.
- For each element, we compare it with the previous element:
  - If it's smaller, we update `down[i]` to be the length of the longest subsequence with a downward movement (`up[i-1] + 1`).
  - If it’s larger, we update `up[i]` to reflect the longest subsequence with an upward movement (`down[i-1] + 1`).
  - If the elements are equal, no updates are made since there’s no wiggle.

---

#### 4. **Return the Maximum Wiggle Length**

```cpp
return max(down[n - 1], up[n - 1]);
```
- After the loop finishes, the longest wiggle subsequence can either end with an upward or downward movement. So, we return the maximum of `up[n-1]` and `down[n-1]`.

---

### 📈 Complexity Analysis

#### Time Complexity:
- **O(n)**: We only need one pass through the array to calculate the values of the `up` and `down` arrays, making the time complexity linear.

#### Space Complexity:
- **O(n)**: We use two arrays (`up` and `down`), each of size `n`, to store the lengths of subsequences for each index.

---

### 🏁 Conclusion

This dynamic programming approach efficiently finds the length of the longest wiggle subsequence in an integer array. By keeping track of subsequences that end with upward and downward movements, we ensure that each step builds on the previous ones. The time complexity is **O(n)**, which makes this solution optimal for large inputs.

Stay motivated and keep practicing! With dynamic programming, you can solve many such interesting problems by breaking them down into smaller, manageable subproblems!

[`Link to LeetCode Lab`](https://leetcode.com/problems/wiggle-subsequence/description/)

---
{{< youtube IpWoZvKzpug >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
