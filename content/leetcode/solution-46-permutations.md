
+++
authors = ["grid47"]
title = "Leetcode 46: Permutations"
date = "2024-11-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 46: Permutations in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/46.webp"
youtube = "s7AvT7cGdSo"
youtube_upload_date="2020-12-17"
youtube_thumbnail="https://i.ytimg.com/vi/s7AvT7cGdSo/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/46.webp" 
    alt="A sequence of shimmering, rotating orbs, rearranging gently in endless variations."
    caption="Solution to LeetCode 46: Permutations Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given a list of distinct integers, generate and return all possible permutations of the elements. The result can be returned in any order.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of distinct integers.
- **Example:** `[1, 2, 3]`
- **Constraints:**
	- 1 <= nums.length <= 6
	- -10 <= nums[i] <= 10
	- All elements of nums are unique.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return all possible permutations of the input list.
- **Example:** `[[1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], [3, 2, 1]]`
- **Constraints:**
	- The number of permutations is n!, where n is the length of the input list.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to generate all possible permutations of the input list of distinct integers.

- 1. Use a backtracking approach to explore all permutations of the input list.
- 2. At each step, keep track of elements used and backtrack when a permutation is completed.
- 3. Once a valid permutation is found, store it in the result list.
{{< dots >}}
### Problem Assumptions ✅
- The integers in the input array are distinct.
{{< dots >}}
## Examples 🧩
- **Input:** `[1, 2, 3]`  \
  **Explanation:** For the input [1, 2, 3], all possible permutations include [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], and [3, 2, 1].

- **Input:** `[4, 5]`  \
  **Explanation:** For the input [4, 5], the two possible permutations are [4, 5] and [5, 4].

- **Input:** `[8]`  \
  **Explanation:** For the input [8], the only possible permutation is [8].

{{< dots >}}
## Approach 🚀
The solution uses backtracking to generate all possible permutations of the input list. At each step, we explore every element that hasn't been used in the current permutation.

### Initial Thoughts 💭
- The number of permutations grows factorially with the size of the input list.
- Backtracking is a good approach for generating all possible combinations.
- To generate the permutations, we can use recursion and backtrack once we find a valid permutation.
{{< dots >}}
### Edge Cases 🌐
- The input will never be empty because the constraints specify a minimum length of 1.
- The maximum input size is 6, so the solution should handle the factorial growth of the number of permutations.
- The elements are distinct, so no duplicates will occur in the input.
- Ensure efficient backtracking, especially as the number of permutations grows with input size.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> permute(vector<int>& nums) {
    map<int, bool> mp;
    vector<vector<int>> ans;
    vector<int> tmp;
    bt(ans, tmp, nums, 0, mp);
    return ans;
}

void bt(vector<vector<int>> &ans, vector<int> &tmp, vector<int> &nums, int idx, map<int, bool> &mp) {
    if(idx == nums.size()) {
        ans.push_back(tmp);
        return;
    }
    
    for(int i = 0; i < nums.size(); i++) {
        if(mp.count(nums[i])) continue;
        mp[nums[i]] = true;
        tmp.push_back(nums[i]);
        bt(ans, tmp, nums, idx + 1, mp);
        tmp.pop_back();
        mp.erase(nums[i]);
    }
}
```

This code generates all possible permutations of a given array of integers using backtracking.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<vector<int>> permute(vector<int>& nums) {
	```
	This line declares a function named `permute` that takes a vector of integers `nums` as input and returns a vector of vectors representing all possible permutations of the input array.

2. **Map Initialization**
	```cpp
	    map<int, bool> mp;
	```
	This line initializes a map `mp` to keep track of which numbers have already been used in the current permutation.

3. **Vector Initialization**
	```cpp
	    vector<vector<int>> ans;
	```
	This line initializes a 2D vector `ans` to store the resulting permutations.

4. **Vector Initialization**
	```cpp
	    vector<int> tmp;
	```
	This line initializes a vector `tmp` to store the current permutation being built.

5. **Backtracking Function Call**
	```cpp
	    bt(ans, tmp, nums, 0, mp);
	```
	This line calls the helper function `bt` to perform the backtracking process. The `ans`, `tmp`, `nums`, `0`, and `mp` are passed as arguments.

6. **Return Result**
	```cpp
	    return ans;
	```
	This line returns the `ans` vector containing all possible permutations.

7. **Backtracking Function Declaration**
	```cpp
	void bt(vector<vector<int>> &ans, vector<int> &tmp, vector<int> &nums, int idx, map<int, bool> &mp) {
	```
	This line declares a recursive backtracking function `bt` that takes the following parameters: `ans` to store the result, `tmp` to store the current permutation, `nums` the input array, `idx` to track the current index in the permutation, and `mp` to keep track of used numbers.

8. **Base Case and Result Addition**
	```cpp
	    if(idx == nums.size()) {
	```
	This line checks the base case: if the current index `idx` reaches the end of the array, it means a complete permutation has been formed. The current permutation `tmp` is added to the `ans` vector.

9. **Base Case and Result Addition**
	```cpp
	        ans.push_back(tmp);
	```
	This line adds the current permutation `tmp` to the `ans` vector.

10. **Base Case and Result Addition**
	```cpp
	        return;
	```
	This line returns from the function as a complete permutation has been found.

11. **Loop Iteration**
	```cpp
	    for(int i = 0; i < nums.size(); i++) {
	```
	This line starts a `for` loop to iterate over each number in the `nums` array.

12. **Skip Used Numbers**
	```cpp
	        if(mp.count(nums[i])) continue;
	```
	This line checks if the current number `nums[i]` has already been used in the current permutation. If so, it skips to the next number.

13. **Mark Number as Used**
	```cpp
	        mp[nums[i]] = true;
	```
	This line marks the current number `nums[i]` as used in the `mp` map.

14. **Add Number to Current Permutation**
	```cpp
	        tmp.push_back(nums[i]);
	```
	This line adds the current number `nums[i]` to the current permutation `tmp`.

15. **Recursive Call**
	```cpp
	        bt(ans, tmp, nums, idx + 1, mp);
	```
	This line recursively calls the `bt` function with the updated `idx` to explore the next position in the permutation.

16. **Backtrack**
	```cpp
	        tmp.pop_back();
	```
	This line removes the last added number from the `tmp` permutation to backtrack to the previous state.

17. **Mark Number as Unused**
	```cpp
	        mp.erase(nums[i]);
	```
	This line removes the current number `nums[i]` from the `mp` map, indicating that it can be used again in other permutations.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n!)
- **Average Case:** O(n!)
- **Worst Case:** O(n!)

The time complexity is O(n!) due to the need to generate all possible permutations of n elements.

### Space Complexity 💾
- **Best Case:** O(n!)
- **Worst Case:** O(n!)

The space complexity is O(n!) due to the storage of all permutations and the recursive stack.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/permutations/description/)

---
{{< youtube s7AvT7cGdSo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
