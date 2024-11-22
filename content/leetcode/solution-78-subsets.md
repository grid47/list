
+++
authors = ["grid47"]
title = "Leetcode 78: Subsets"
date = "2024-10-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 78: Subsets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/78.webp"
youtube = "UP3dOYJa05s"
youtube_upload_date="2024-04-24"
youtube_thumbnail="https://i.ytimg.com/vi/UP3dOYJa05s/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/78.webp" 
    alt="Multiple floating subsets gently coming together, forming a whole."
    caption="Solution to LeetCode 78: Subsets Problem"
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
    vector<int> nums;
    vector<vector<int>> subsets(vector<int>& nums) {
        this->nums = nums;
        vector<vector<int>> ans;
        vector<int> tmp;
        bt(ans, tmp, 0);
        return ans;
    }
    
    void bt(vector<vector<int>> & ans, vector<int> &tmp, int idx) {
        if(idx == nums.size()) {
            ans.push_back(tmp);
            return;
        }

        
        bt(ans, tmp, idx + 1);
        
        tmp.push_back(nums[idx]);
        bt(ans, tmp, idx + 1);
        tmp.pop_back();
        
    }
};
{{< /highlight >}}
---

### 🏷️ **Problem Statement**

The goal of this problem is to generate all possible subsets from a given list of integers, `nums`. A subset of a set is any combination of its elements, including the empty set. The output should be a collection of all subsets where the order of subsets does not matter.

#### Example:
- **Input:** `nums = [1, 2, 3]`
- **Output:** `[[ ], [1], [2], [3], [1, 2], [1, 3], [2, 3], [1, 2, 3]]`

Here, we are tasked with generating all possible combinations of the elements of the list, including the empty set and the set containing all elements.

---

### 🧠 **Approach**

The solution to this problem uses **backtracking**, a technique where we explore all possible combinations of elements by making incremental decisions and undoing those decisions when necessary. This is a perfect fit for problems like subset generation.

#### Key Concepts:
1. **Recursive Backtracking:** 
   We use a helper function (`bt`) to recursively explore all possible subsets by either including or excluding each element in the set.

2. **Exploration of Subsets:**
   For each element in `nums`, we make two choices:
   - **Exclude it** from the current subset.
   - **Include it** in the current subset.
   By exploring both choices recursively, we cover all subsets.

3. **Base Case:**
   When the function has considered all elements (i.e., `idx == nums.size()`), we add the current subset (`tmp`) to the result list (`ans`).

4. **Backtracking:** 
   After including an element, we backtrack by removing it from the current subset (`tmp`) and proceed with the next recursive step to explore other possibilities.

---

### 📝 **Code Breakdown**

#### Step 1: Definition of Member Variables
```cpp
vector<int> nums;
```
This vector holds the input list `nums`. It will be set through the method call.

#### Step 2: Subsets Method
```cpp
vector<vector<int>> subsets(vector<int>& nums) {
    this->nums = nums;          // Store the input nums in the member variable
    vector<vector<int>> ans;    // Vector to store all subsets
    vector<int> tmp;            // Temporary vector to store the current subset
    bt(ans, tmp, 0);            // Start the backtracking function
    return ans;                 // Return the answer containing all subsets
}
```
- **Explanation:**
  - The method stores the input `nums` and initializes the `ans` vector (which holds all subsets) and `tmp` (used for the current subset).
  - The backtracking function (`bt`) is called to start exploring subsets from index `0`.
  
#### Step 3: Backtracking Method
```cpp
void bt(vector<vector<int>> &ans, vector<int> &tmp, int idx) {
    if (idx == nums.size()) {
        ans.push_back(tmp);  // Add current subset to the answer when all elements are considered
        return;
    }

    bt(ans, tmp, idx + 1);    // Case 1: Exclude the current element

    tmp.push_back(nums[idx]); // Case 2: Include the current element
    bt(ans, tmp, idx + 1);    // Recurse with the updated subset
    tmp.pop_back();           // Backtrack, remove the last element to explore other possibilities
}
```
- **Base Case:** When `idx == nums.size()`, we've considered all elements, so the current subset (`tmp`) is added to the result.
  
- **Recursive Steps:**
  - **Exclude the current element:** The first recursive call `bt(ans, tmp, idx + 1)` explores subsets without including `nums[idx]`.
  - **Include the current element:** The second recursive call `bt(ans, tmp, idx + 1)` explores subsets with `nums[idx]` included, before backtracking.

- **Backtracking:** After including `nums[idx]`, the function removes it (`tmp.pop_back()`) to explore subsets that don't include it.

---

### 🧮 **Complexity Analysis**

#### Time Complexity:
The number of subsets of a list of size `n` is **2^n** because each element has two choices: to be included or excluded. Therefore, the time complexity is **O(2^n)**. For each subset, we also spend **O(n)** time to store and process it.

Thus, the overall time complexity is **O(2^n * n)**.

#### Space Complexity:
- The recursive call stack has a maximum depth of `n` (the number of elements in `nums`), so the space complexity for recursion is **O(n)**.
- The space required to store all subsets is **O(2^n * n)**, since there are `2^n` subsets, and each subset can have up to `n` elements.

Thus, the overall space complexity is **O(2^n * n)**, dominated by the space required to store the subsets.

---

### 🎯 **Conclusion**

This approach effectively generates all subsets of a given list of integers using the **backtracking** technique. By recursively considering both including and excluding each element, we explore all possible subsets. The time and space complexities are both exponential, reflecting the large number of subsets, but the algorithm is efficient and elegant for solving the problem of subset generation.

Backtracking allows us to systematically explore all possibilities, making it a perfect solution for combinatorial problems like this one.

---

### ✨ **Key Takeaways**
- **Backtracking** is a useful technique for exploring all combinations or subsets.
- The time complexity of **O(2^n * n)** accounts for generating and storing all subsets.
- Space complexity is also **O(2^n * n)**, dominated by the storage of subsets.
- This solution is optimal for smaller input sizes, though it can be expensive for very large lists.


[`Link to LeetCode Lab`](https://leetcode.com/problems/subsets/description/)

---
{{< youtube UP3dOYJa05s >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
