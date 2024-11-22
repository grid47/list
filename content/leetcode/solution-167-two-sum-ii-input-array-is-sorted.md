
+++
authors = ["grid47"]
title = "Leetcode 167: Two Sum II - Input Array Is Sorted"
date = "2024-10-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 167: Two Sum II - Input Array Is Sorted in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/167.webp"
youtube = "ciPrKYoOQkI"
youtube_upload_date="2024-01-14"
youtube_thumbnail="https://i.ytimg.com/vi/ciPrKYoOQkI/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/167.webp" 
    alt="A sorted array with glowing pairs of numbers, gently highlighting the solution to the sum."
    caption="Solution to LeetCode 167: Two Sum II - Input Array Is Sorted Problem"
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
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2, 0);
        map<int, int> mp;
        for(int i = 0; i < nums.size(); i++) {
            if(mp.count(nums[i])) {
                ans[0] = mp[nums[i]] + 1;
                ans[1] = i + 1;
                return ans;
            } else {
                mp[target - nums[i]] = i;
            }
        }
        return ans;
    }
};
{{< /highlight >}}
---

### 🌐 Two Sum: Efficiently Finding a Pair of Numbers that Sum to a Target

The problem is to find two indices in an array such that the numbers at those indices sum up to a given target value. Specifically, we need to return the **1-based indices** of the two numbers that add up to the target.

### 💡 Approach

To solve this efficiently, we use a **hash map** (in C++, `map`) to store the numbers we've already encountered while iterating through the array. This allows us to check, in constant time, if the complement of the current number (i.e., `target - current_number`) exists in the array. By leveraging this strategy, we reduce the time complexity from a brute-force **O(n^2)** solution to an optimal **O(n)** solution.

---

### 📝 Code Breakdown (Step-by-Step)

#### 🔹 Step 1: Initialize the Variables

```cpp
vector<int> ans(2, 0);
map<int, int> mp;
```
- `ans`: A vector to store the two indices of the numbers that sum up to the target. It's initialized with two zeroes as placeholders.
- `mp`: A map (or hash table) used to store the complement of each number as we iterate through the array. The key will be the complement (`target - nums[i]`), and the value will be the index `i` of the number.

#### 🔹 Step 2: Iterate Through the Array

```cpp
for(int i = 0; i < nums.size(); i++) {
    if(mp.count(nums[i])) {
        ans[0] = mp[nums[i]] + 1;
        ans[1] = i + 1;
        return ans;
    } else {
        mp[target - nums[i]] = i;
    }
}
```
- The loop iterates over each element in the array `nums`. For each element:
  - **Check if the current number exists in the map (`mp`)**:
    - If `mp.count(nums[i])` is true, it means the complement (`target - nums[i]`) has already been encountered. Thus, we have found a valid pair that sums up to the target.
    - We then set `ans[0] = mp[nums[i]] + 1` and `ans[1] = i + 1` to store the **1-based indices** of the two numbers.
    - The function returns the `ans` immediately, as we've found the pair.
  - **If the complement is not found in the map**:
    - We store the complement of the current number (`target - nums[i]`) as the key in the map, with the current index `i` as the value. This will allow us to find the complement when we encounter it later in the array.

#### 🔹 Step 3: Return the Result

```cpp
return ans;
```
- If no pair is found, `ans` would be returned. However, the problem guarantees that there is exactly one solution, so we would always find and return the pair within the loop.

---

### 🔎 Complexity

#### Time Complexity:
- **O(n)**: The algorithm iterates over the array once. Each iteration involves a constant-time check (`mp.count`) and a constant-time insertion/update (`mp[target - nums[i]]`). Hence, the time complexity is **O(n)**, where `n` is the size of the array.

#### Space Complexity:
- **O(n)**: The space complexity is determined by the space used by the map `mp`. In the worst case, the map will store up to `n` elements (one for each number in the array). Therefore, the space complexity is **O(n)**.

---

### ✅ Conclusion

This solution is both time-efficient and space-efficient, with a time complexity of **O(n)** and a space complexity of **O(n)**. By using a **hash map**, we are able to track the complements of the numbers and check for pairs that sum up to the target in constant time. This approach is far more efficient than a brute-force **O(n^2)** solution.

#### Key Takeaways:
- The core idea is to store the complement of each number in a map and check if it has already been encountered during the iteration.
- The time complexity of **O(n)** ensures that the solution works well for large input sizes.
- The **O(n)** space complexity comes from the map, which is necessary to achieve the time efficiency.

This approach is ideal when solving problems that involve finding pairs in an array that satisfy certain conditions (like summing to a target value).

[`Link to LeetCode Lab`](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/description/)

---
{{< youtube ciPrKYoOQkI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
