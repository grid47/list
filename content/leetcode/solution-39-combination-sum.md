
+++
authors = ["grid47"]
title = "Leetcode 39: Combination Sum"
date = "2024-11-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 39: Combination Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/39.webp"
youtube = "utBw5FbYswk"
youtube_upload_date="2024-04-29"
youtube_thumbnail="https://i.ytimg.com/vi_webp/utBw5FbYswk/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/39.webp" 
    alt="A sequence of glowing paths merging together, forming a combination with a gentle light."
    caption="Solution to LeetCode 39: Combination Sum Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order. The same number can be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of distinct integers candidates and a target integer target.
- **Example:** `Input: candidates = [1, 2, 3], target = 4`
- **Constraints:**
	- 1 <= candidates.length <= 30
	- 2 <= candidates[i] <= 40
	- All elements of candidates are distinct.
	- 1 <= target <= 40

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a list of all unique combinations of candidates where the chosen numbers sum to the target.
- **Example:** `Output: [[1, 1, 2], [1, 3], [2, 2]]`
- **Constraints:**
	- The output should be a list of lists containing valid combinations.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find all possible combinations where the numbers sum to the target, allowing repeated numbers.

- Sort the candidates array (optional for optimization).
- Use backtracking to explore all possible combinations of candidates that sum up to the target.
- During the backtracking process, allow repetition of numbers but avoid using the same combination multiple times.
{{< dots >}}
### Problem Assumptions ✅
- The input will always be valid, with distinct integers in candidates and a target value of at least 1.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: candidates = [1, 2, 3], target = 4`  \
  **Explanation:** In this example, the target is 4, and we can form the following unique combinations: [1, 1, 2], [1, 3], and [2, 2].

- **Input:** `Input: candidates = [5, 7, 10], target = 15`  \
  **Explanation:** For this example, the unique combinations that sum to 15 are: [5, 5, 5], [7, 7], and [5, 10].

{{< dots >}}
## Approach 🚀
We can use backtracking to explore all possible combinations, while ensuring we don’t use the same combination more than once.

### Initial Thoughts 💭
- We can use recursion to explore all combinations, adding numbers to a temporary list and checking if we’ve reached the target sum.
- Using backtracking will allow us to explore all possible combinations and backtrack if the sum exceeds the target.
{{< dots >}}
### Edge Cases 🌐
- If the input array is empty, return an empty result since no combinations can be formed.
- Even with the upper limit of input size (candidates.length <= 30), the problem ensures fewer than 150 unique combinations, so performance should be manageable.
- If the target is smaller than the smallest candidate, return an empty list.
- Ensure no duplicate combinations are added to the result.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> combinationSum(vector<int>& cand, int target) {
    vector<vector<int>> ans;
    vector<int> tmp;
    bt(ans, tmp, 0, target, cand);
    return ans;
}

void bt(vector<vector<int>> &ans, vector<int> &tmp, int idx, int sum, vector<int> &cand) {
    if(idx == cand.size() || sum == 0) {
        if(sum == 0) ans.push_back(tmp);
        return;
    }
    if(sum < 0) return;
    tmp.push_back(cand[idx]);
    bt(ans, tmp, idx, sum - cand[idx], cand);
    tmp.pop_back();
    
    bt(ans, tmp, idx + 1, sum, cand);
}
```

This code finds all possible combinations of numbers from the given candidate numbers that add up to the target number.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<vector<int>> combinationSum(vector<int>& cand, int target) {
	```
	This line declares a function named `combinationSum` that takes a vector of candidate numbers `cand` and a target number `target` as input and returns a vector of vectors representing all possible combinations of numbers from `cand` that add up to `target`.

2. **Vector Initialization**
	```cpp
	    vector<vector<int>> ans;
	```
	This line initializes an empty 2D vector `ans` to store the resulting combinations.

3. **Vector Initialization**
	```cpp
	    vector<int> tmp;
	```
	This line initializes an empty vector `tmp` to store a temporary combination during the backtracking process.

4. **Function Call**
	```cpp
	    bt(ans, tmp, 0, target, cand);
	```
	This line calls the helper function `bt` to perform the backtracking process. The `ans`, `tmp`, `0`, `target`, and `cand` are passed as arguments.

5. **Return**
	```cpp
	    return ans;
	```
	This line returns the `ans` vector containing all the valid combinations.

6. **Function Declaration**
	```cpp
	void bt(vector<vector<int>> &ans, vector<int> &tmp, int idx, int sum, vector<int> &cand) {
	```
	This line declares a recursive backtracking function `bt` that takes the following parameters: `ans` to store the result, `tmp` to store the current combination, `idx` to track the current index in the `cand` vector, `sum` representing the remaining target sum, and `cand` the vector of candidate numbers.

7. **Base Case and Result Addition**
	```cpp
	    if(idx == cand.size() || sum == 0) {
	        if(sum == 0) ans.push_back(tmp);
	        return;
	    }
	```
	This block checks the base cases: 1. If the index `idx` reaches the end of the `cand` vector or the `sum` becomes 0, it means we've reached a valid combination. If `sum` is 0, the current `tmp` combination is added to the `ans` vector. 2. In either case, the function returns to the previous recursive call.

8. **Pruning**
	```cpp
	    if(sum < 0) return;
	```
	This line prunes the search space by checking if the `sum` becomes negative. If so, it means the current path cannot lead to a valid combination, so the function returns early.

9. **Include the Current Candidate**
	```cpp
	    tmp.push_back(cand[idx]);
	```
	This line adds the current candidate number `cand[idx]` to the `tmp` combination.

10. **Recursive Call (Include)**
	```cpp
	    bt(ans, tmp, idx, sum - cand[idx], cand);
	```
	This line recursively calls the `bt` function with the updated `sum` (reduced by the current candidate) to explore the possibility of including the current candidate in the combination.

11. **Backtrack**
	```cpp
	    tmp.pop_back();
	```
	This line removes the last added candidate from the `tmp` combination to backtrack to the previous state.

12. **Recursive Call (Exclude)**
	```cpp
	    bt(ans, tmp, idx + 1, sum, cand);
	```
	This line recursively calls the `bt` function with the same `sum` but the next index `idx + 1` to explore the possibility of excluding the current candidate from the combination.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(N^2)
- **Average Case:** O(N^2)
- **Worst Case:** O(2^N)

The worst case complexity arises from the backtracking approach, where each number is considered in each recursive step.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(N)

Space complexity depends on the depth of the recursion tree and the size of the temporary storage used for combinations.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/combination-sum/description/)

---
{{< youtube utBw5FbYswk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
