
+++
authors = ["grid47"]
title = "Leetcode 40: Combination Sum II"
date = "2024-11-03"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 40: Combination Sum II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/40.webp"
youtube = "FAjCxGNlxgk"
youtube_upload_date="2024-01-01"
youtube_thumbnail="https://i.ytimg.com/vi/FAjCxGNlxgk/maxresdefault.jpg"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/40.webp" 
    alt="A more intricate set of glowing paths, representing different combinations, gently overlapping."
    caption="Solution to LeetCode 40: Combination Sum II Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given a collection of distinct candidate numbers and a target number. Your task is to find all unique combinations of the candidate numbers that sum up to the target. Each number in the candidates list may only be used once in each combination. The solution should exclude duplicate combinations.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an array of distinct integers 'candidates' and a target integer 'target'.
- **Example:** `Input: candidates = [8, 1, 4, 6, 7, 1, 5], target = 8`
- **Constraints:**
	- 1 <= candidates.length <= 100
	- 1 <= candidates[i] <= 50
	- 1 <= target <= 30

{{< dots >}}
### Output Specifications 📤
- **Output:** Return all unique combinations from the candidates where the sum equals the target.
- **Example:** `Output: [[1, 1, 6], [1, 4, 3], [1, 7], [4, 4]]`
- **Constraints:**
	- The result must not contain duplicate combinations.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to find all possible combinations where the sum equals the target, ensuring no duplicate combinations.

- Sort the candidates to help avoid duplicates.
- Use backtracking to explore all potential combinations, considering each candidate only once per combination.
{{< dots >}}
### Problem Assumptions ✅
- The candidates array contains only distinct integers.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: candidates = [8, 1, 4, 6, 7, 1, 5], target = 8`  \
  **Explanation:** In this example, the valid combinations that sum to 8 are: [1, 1, 6], [1, 4, 3], [1, 7], and [4, 4].

- **Input:** `Input: candidates = [3, 2, 7, 5, 2], target = 5`  \
  **Explanation:** For this case, the valid combinations are [2, 2] and [5].

{{< dots >}}
## Approach 🚀
We will use backtracking to generate combinations of candidates that sum to the target, while avoiding duplicate solutions.

### Initial Thoughts 💭
- Since each number in candidates can only be used once, we need to ensure that we do not reuse the same element multiple times in a combination.
- Sorting the candidates will help to avoid duplicate combinations, as we can skip over numbers that are the same as the previous ones.
{{< dots >}}
### Edge Cases 🌐
- If the candidate list is empty, return an empty list since no combinations can be formed.
- For large inputs (up to 100 candidates), the algorithm must be efficient enough to avoid excessive recursive calls.
- If the target is smaller than the smallest candidate, return an empty list since no combinations are possible.
- Ensure no duplicate combinations are included in the result.
{{< dots >}}
## Code 💻
```cpp
map<vector<int>, bool> mp;
vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
           
    vector<vector<int>> ans;
    vector<int> tmp;
    mp.clear();
    sort(cand.begin(), cand.end());
     bt(ans, cand, 0, target, tmp);
    return ans;
}

void bt(vector<vector<int>> &ans, vector<int> &nums, int idx,
        int sum, vector<int> &tmp) {
    if(sum == 0) {
        ans.push_back(tmp);
        return;
    }
    if(sum < 0 || idx == nums.size()) return;
    
    for(int i = idx; i < nums.size(); i++) {
        if(i && i > idx && nums[i] == nums[i-1]) continue;
        tmp.push_back(nums[i]);
        bt(ans, nums, i + 1, sum - nums[i], tmp);
        tmp.pop_back();
    }
    
}
```

This code finds all unique combinations of numbers from the given candidate numbers that add up to the target number, where each number in the candidate set may only be used once in the combination.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Map Initialization**
	```cpp
	map<vector<int>, bool> mp;
	```
	This line initializes a map `mp` to store already visited combinations to avoid duplicates.

2. **Function Declaration**
	```cpp
	vector<vector<int>> combinationSum2(vector<int>& cand, int target) {
	```
	This line declares a function named `combinationSum2` that takes a vector of candidate numbers `cand` and a target number `target` as input and returns a vector of vectors representing all unique combinations of numbers from `cand` that add up to `target`.

3. **Vector Initialization**
	```cpp
	    vector<vector<int>> ans;
	```
	This line initializes an empty 2D vector `ans` to store the resulting combinations.

4. **Vector Initialization**
	```cpp
	    vector<int> tmp;
	```
	This line initializes an empty vector `tmp` to store a temporary combination during the backtracking process.

5. **Map Clear**
	```cpp
	    mp.clear();
	```
	This line clears the `mp` map to ensure it's empty before starting the backtracking process.

6. **Sorting**
	```cpp
	    sort(cand.begin(), cand.end());
	```
	This line sorts the `cand` vector in ascending order to optimize the backtracking process and avoid duplicate combinations.

7. **Function Call**
	```cpp
	     bt(ans, cand, 0, target, tmp);
	```
	This line calls the helper function `bt` to perform the backtracking process. The `ans`, `tmp`, `0`, `target`, and `cand` are passed as arguments.

8. **Return**
	```cpp
	    return ans;
	```
	This line returns the `ans` vector containing all the unique combinations.

9. **Function End**
	```cpp
	}
	```
	This line closes the `combinationSum2` function.

10. **Function Declaration**
	```cpp
	void bt(vector<vector<int>> &ans, vector<int> &nums, int idx,
	        int sum, vector<int> &tmp) {
	```
	This line declares a recursive backtracking function `bt` that takes the following parameters: `ans` to store the result, `tmp` to store the current combination, `idx` to track the current index in the `nums` vector, `sum` representing the remaining target sum, and `nums` the vector of candidate numbers.

11. **Base Case and Result Addition**
	```cpp
	    if(sum == 0) {
	        if(!mp[tmp]) {
	            ans.push_back(tmp);
	            mp[tmp] = true;
	        }
	        return;
	    }
	```
	This block checks the base case: 1. If the `sum` becomes 0, it means we've reached a valid combination. 2. We check if the current combination `tmp` is already present in the `mp` map. If not, we add it to the `ans` vector and mark it as visited in the `mp` map. 3. In either case, the function returns to the previous recursive call.

12. **Pruning**
	```cpp
	    if(sum < 0 || idx == nums.size()) return;
	```
	This line prunes the search space by checking if the `sum` becomes negative or the index `idx` reaches the end of the `nums` vector. If so, it means the current path cannot lead to a valid combination, so the function returns early.

13. **Loop Iteration**
	```cpp
	    for(int i = idx; i < nums.size(); i++) {
	```
	This line starts a `for` loop to iterate over the remaining candidate numbers, starting from the current index `idx`.

14. **Skip Duplicate Candidates**
	```cpp
	        if(i && i > idx && nums[i] == nums[i-1]) continue;
	```
	This line skips duplicate candidates. If the current candidate is the same as the previous one and we're not at the beginning of the loop, we skip this iteration to avoid duplicate combinations.

15. **Include the Current Candidate**
	```cpp
	        tmp.push_back(nums[i]);
	```
	This line adds the current candidate number `nums[i]` to the `tmp` combination.

16. **Recursive Call (Include)**
	```cpp
	        bt(ans, nums, i + 1, sum - nums[i], tmp);
	```
	This line recursively calls the `bt` function with the updated `sum` (reduced by the current candidate) and the next index `i + 1` to explore the possibility of including the current candidate in the combination.

17. **Backtrack**
	```cpp
	        tmp.pop_back();
	```
	This line removes the last added candidate from the `tmp` combination to backtrack to the previous state.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(N^2)
- **Average Case:** O(2^N)
- **Worst Case:** O(2^N)

The time complexity arises from generating all possible combinations using backtracking. The worst case occurs when all combinations need to be checked.

### Space Complexity 💾
- **Best Case:** O(1)
- **Worst Case:** O(N)

Space complexity depends on the depth of the recursion and the space used for storing the combinations.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/combination-sum-ii/description/)

---
{{< youtube FAjCxGNlxgk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
