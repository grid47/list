
+++
authors = ["grid47"]
title = "Leetcode 90: Subsets II"
date = "2024-10-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 90: Subsets II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking","Bit Manipulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/90.webp"
youtube = "Vn2v6ajA7U0"
youtube_upload_date="2021-12-14"
youtube_thumbnail="https://i.ytimg.com/vi/Vn2v6ajA7U0/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/90.webp" 
    alt="A glowing, branching set of subsets gently forming in a calm, peaceful pattern."
    caption="Solution to LeetCode 90: Subsets II Problem"
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
    map<vector<int>, bool> mp;
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        mp.clear();
        bt(ans, tmp, nums, 0);
        return ans;
    }
    
    void bt(vector<vector<int>> &ans, vector<int> &tmp,
            vector<int> &nums, int idx) {
        
        if(idx == nums.size()) {

            if(!mp.count(tmp)) {
                ans.push_back(tmp);
                mp[tmp] = true;
            }
            return;
        }
        
        bt(ans, tmp, nums, idx + 1);
        
        tmp.push_back(nums[idx]);
        bt(ans, tmp, nums, idx + 1);
        tmp.pop_back();            
        
    }
    
};
{{< /highlight >}}
---

### 📝 **Problem Statement**

Given a list of integers `nums`, generate all possible subsets. If `nums` contains duplicate elements, avoid including duplicate subsets in the final result.

#### Example:
- **Input:** `nums = [1, 2, 2]`
- **Output:** `[[], [1], [1, 2], [1, 2, 2], [2], [2, 2]]`

### 🔍 **Approach**

The problem can be tackled using **backtracking**. Additionally, to avoid duplicates, we'll **sort the input array** and apply a **recursive approach** to generate subsets efficiently. Here's a breakdown of the approach:

1. **Sort the Input**: Sorting ensures that duplicates are adjacent, which makes it easier to skip duplicates during the generation process.
  
2. **Backtracking with Recursion**:
   - Use a backtracking function to recursively decide whether to include or exclude each element in the subset.
   - Avoid adding duplicate subsets by ensuring the subsets are built in a specific order and skipping over duplicate elements when necessary.

### 🧑‍💻 **Code Breakdown**

#### Step 1: Initial Setup

```cpp
vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> ans;
    vector<int> tmp;
    sort(nums.begin(), nums.end());  // Sort to handle duplicates
    backtrack(ans, tmp, nums, 0);    // Start the backtracking process
    return ans;
}
```
- `ans`: Holds all unique subsets.
- `tmp`: A temporary vector to store the current subset during recursion.
- We sort `nums` to group duplicate elements together, which helps in avoiding generating duplicate subsets.
- The backtracking function `backtrack` is called starting from index `0`.

#### Step 2: The Backtracking Function

```cpp
void backtrack(vector<vector<int>>& ans, vector<int>& tmp, vector<int>& nums, int idx) {
    ans.push_back(tmp);  // Add the current subset to the result

    for (int i = idx; i < nums.size(); i++) {
        // Skip duplicates: If the current element is the same as the previous one, skip it
        if (i > idx && nums[i] == nums[i - 1]) continue;

        tmp.push_back(nums[i]);      // Include the current element
        backtrack(ans, tmp, nums, i + 1);  // Recurse with the next element
        tmp.pop_back();             // Backtrack: Remove the last element
    }
}
```

- **Base Case**: At each recursive step, we add the current subset (`tmp`) to `ans` before making any recursive calls.
- **Recursive Case**: We iterate through `nums`, starting from the current index `idx`. For each element:
  - We skip duplicate elements by checking if the current element is the same as the previous one (this ensures we don't generate duplicate subsets).
  - We then recursively generate subsets by including the current element, and after recursion, we backtrack by removing the last added element.

#### Step 3: Handling Duplicates

- **Skip Duplicate Elements**: By sorting `nums` initially, duplicates are adjacent. We skip over duplicate elements by checking if the current element is equal to the previous one in the iteration (`if (i > idx && nums[i] == nums[i - 1]) continue`).

### ⏱ **Complexity Analysis**

#### Time Complexity:
- **Sorting**: Sorting the input array `nums` takes **O(n log n)**, where `n` is the length of `nums`.
- **Backtracking**: In the worst case, we generate all subsets, which takes **O(2^n)** time. For each subset, we might perform a check to avoid duplicates, but the skipping mechanism ensures we don't generate duplicate subsets.
  - The overall time complexity is **O(n log n + 2^n)**.

#### Space Complexity:
- **Result Storage**: The space required to store all unique subsets is proportional to the number of subsets, which is **O(2^n)** in the worst case.
- **Recursion Stack**: The maximum depth of the recursion is `n`, so the recursion stack requires **O(n)** space.
  - Total space complexity: **O(2^n + n)**.

### 🎯 **Conclusion**

This approach efficiently generates all unique subsets of the list `nums` using **backtracking** with a sorted array to handle duplicates. The time complexity is driven by the exponential number of possible subsets, and the space complexity accounts for both the recursion stack and the storage of the result. This method ensures that no duplicate subsets are included in the final result and is well-suited for handling input lists with duplicate elements.

---

#### 🌟 **Final Thoughts**:
This backtracking solution is both time-efficient and space-efficient, handling the complexity of duplicates elegantly. By sorting the input and skipping duplicates in the iteration, we ensure optimal performance for generating subsets.

[`Link to LeetCode Lab`](https://leetcode.com/problems/subsets-ii/description/)

---
{{< youtube Vn2v6ajA7U0 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
