
+++
authors = ["grid47"]
title = "Leetcode 47: Permutations II"
date = "2024-11-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 47: Permutations II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/47.webp"
youtube = "qhBVWf0YafA"
youtube_upload_date="2021-01-27"
youtube_thumbnail="https://i.ytimg.com/vi_webp/qhBVWf0YafA/maxresdefault.webp"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/47.webp" 
    alt="A similar sequence with a touch more complexity, glowing in multiple variations."
    caption="Solution to LeetCode 47: Permutations II Problem"
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
    void f(vector<int>&nums,vector<vector<int>>&ans,int ind){
        if(ind==nums.size()){
            ans.push_back(nums);
            return;
        }
        unordered_map<int,int>mp;
        for(int i=ind;i<nums.size();i++){
            if(mp.find(nums[i])!=mp.end()){
                continue;
            }else{
                mp[nums[i]]++;
                swap(nums[i],nums[ind]);
                f(nums,ans,ind+1);
                swap(nums[i],nums[ind]);
            }
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>ans;
        f(nums,ans,0);
        return ans;
    }
};
{{< /highlight >}}
---

### 💡 **Generate Unique Permutations** – Let’s Solve It Together!

The task is to generate all **unique permutations** of a list of integers. The input array `nums` may contain duplicate values, and the goal is to ensure that the permutations generated are **unique**, i.e., no duplicate permutations are included in the result. Let's dive in and solve this together!

### 📝 **Problem Statement**

Given an array `nums` of integers, return **all possible unique permutations**. The solution must account for any duplicate values in the array.

### 🔍 **Approach**

We will use a **backtracking** approach combined with an **unordered map (hash map)** to ensure that we generate only unique permutations. Here's the step-by-step breakdown:

1. **Backtracking**: We recursively generate permutations of the list, swapping elements and exploring all possible configurations.
2. **Handling Duplicates**: We use a hash map (`unordered_map`) to track elements already used at the current level of recursion, ensuring we don’t generate duplicate permutations.
3. **Swapping Elements**: We swap the current element with the elements following it, exploring different permutations for the sublist.
4. **Base Case**: Once we’ve processed all elements, we add the current permutation to the result.
5. **Recursive Case**: For each index, if the current element hasn’t been used yet at the current recursion level, we swap it and recursively generate the remaining permutations.

### 💻 **Code Breakdown (Step-by-Step)**

#### Step 1: `permuteUnique` Function

```cpp
vector<vector<int>> permuteUnique(vector<int>& nums) {
    vector<vector<int>> ans;
    f(nums, ans, 0);
    return ans;
}
```

- **Input**: Takes a vector `nums` of integers.
- **Initialization**: Creates an empty result vector `ans` to store the unique permutations.
- **Backtracking Call**: Calls the recursive function `f(nums, ans, 0)` to start generating permutations from the 0th index.
- **Return**: After recursion completes, the result vector `ans` is returned.

#### Step 2: `f` Function (Backtracking Logic)

```cpp
void f(vector<int>& nums, vector<vector<int>>& ans, int ind) {
    if(ind == nums.size()) {
        ans.push_back(nums);
        return;
    }
    
    unordered_map<int, int> mp;
    for(int i = ind; i < nums.size(); i++) {
        if(mp.find(nums[i]) != mp.end()) {
            continue;
        } else {
            mp[nums[i]]++;
            swap(nums[i], nums[ind]);
            f(nums, ans, ind + 1);
            swap(nums[i], nums[ind]);
        }
    }
}
```

- **Base Case**: When `ind` reaches the size of `nums`, the current permutation is complete and is added to `ans`.

  ```cpp
  if(ind == nums.size()) {
      ans.push_back(nums);
      return;
  }
  ```

- **Map for Duplicate Checking**: An unordered map `mp` is used to keep track of elements that have already been swapped at the current recursion level to avoid duplicates.

  ```cpp
  unordered_map<int, int> mp;
  ```

- **Loop Through Remaining Elements**: For each element from `ind` to the end, we check if it has been used already in the current recursion. If it has, we skip it.

  ```cpp
  for(int i = ind; i < nums.size(); i++) {
      if(mp.find(nums[i]) != mp.end()) {
          continue;
      }
  }
  ```

  If the element hasn't been used, we proceed with the following steps.

- **Swap the Element**: We swap the current element with the element at `ind` to place it in the correct position.

  ```cpp
  swap(nums[i], nums[ind]);
  ```

- **Recursive Call**: Recursively generate permutations for the sublist starting from the next index `ind + 1`.

  ```cpp
  f(nums, ans, ind + 1);
  ```

- **Backtrack**: After the recursive call, we undo the swap to restore the original order and explore other possible swaps.

  ```cpp
  swap(nums[i], nums[ind]);
  ```

### 🌟 **Handling Duplicates**

The key to solving this problem is ensuring that we **don’t generate duplicate permutations**. We achieve this by using the `unordered_map` (`mp`), which tracks whether a number has already been used at the current recursion level. If an element has already been swapped into the current position during the current recursive call, we skip that element to avoid duplicate permutations.

### ⏱️ **Time and Space Complexity**

#### Time Complexity

The time complexity for generating all permutations of `n` elements is `O(n!)` because there are `n!` possible permutations. However, the presence of duplicates in the input array reduces the number of unique permutations. In the worst case, where all elements are distinct, the time complexity remains `O(n!)`.

- **Time Complexity**: `O(n * n!)`, where `n` is the number of elements in the array `nums`. This includes the time to generate and process each permutation.

#### Space Complexity

The space complexity is driven by:
1. The result vector, which stores all unique permutations. There are `n!` permutations, each with `n` elements, leading to a total space of `O(n * n!)`.
2. The recursion stack, which has a maximum depth of `n` (the length of the input list), and temporary arrays used during backtracking. This gives a space complexity of `O(n)` for the recursion stack.

- **Space Complexity**: `O(n * n!)` for storing the result, plus `O(n)` for the recursion stack.

### 🎯 **Conclusion**

This solution efficiently generates all unique permutations of a given list of integers using **backtracking** and an **unordered map** to avoid duplicates. The algorithm explores all possible permutations while ensuring that no duplicate permutations are included.

- **Time Complexity**: `O(n * n!)`, optimal for generating permutations.
- **Space Complexity**: `O(n * n!)` for storing the permutations, plus `O(n)` for the recursion stack.

By leveraging backtracking and the hash map for duplicate checking, this approach is both **time-efficient** and **space-efficient**, making it a great choice for generating permutations of moderate-sized arrays.

---

Happy coding, and keep exploring! 🚀

[`Link to LeetCode Lab`](https://leetcode.com/problems/permutations-ii/description/)

---
{{< youtube qhBVWf0YafA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
