
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
comments = true
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
Given a collection of numbers that may contain duplicates, generate and return all possible unique permutations of the numbers.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array of integers that may contain duplicates.
- **Example:** `[1, 1, 2]`
- **Constraints:**
	- 1 <= nums.length <= 8
	- -10 <= nums[i] <= 10
	- Duplicates are allowed in the input array.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return all unique permutations of the input list.
- **Example:** `[[1, 1, 2], [1, 2, 1], [2, 1, 1]]`
- **Constraints:**
	- The output must contain only unique permutations.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to generate all unique permutations of the given collection of numbers, ensuring that duplicates are not repeated.

- 1. Use a backtracking approach to explore all possible permutations of the input list.
- 2. Track the numbers that have already been used in the current permutation to avoid generating duplicate permutations.
- 3. Once a unique permutation is formed, add it to the result list.
{{< dots >}}
### Problem Assumptions ✅
- The integers in the input array can be duplicated.
{{< dots >}}
## Examples 🧩
- **Input:** `[1, 1, 2]`  \
  **Explanation:** For the input [1, 1, 2], the unique permutations are [1, 1, 2], [1, 2, 1], and [2, 1, 1]. The repeated [1, 1, 2] permutation is avoided.

- **Input:** `[1, 2, 3]`  \
  **Explanation:** For the input [1, 2, 3], all permutations are unique, and the result includes [1, 2, 3], [1, 3, 2], [2, 1, 3], [2, 3, 1], [3, 1, 2], and [3, 2, 1].

{{< dots >}}
## Approach 🚀
The approach to solving this problem is using backtracking to generate permutations while avoiding duplicates.

### Initial Thoughts 💭
- The number of permutations grows factorially with the size of the input array.
- To avoid duplicate permutations, we need to track previously visited elements during the backtracking process.
- A backtracking approach works well for this problem, but we must ensure that we don't revisit numbers that have already been used in the current permutation.
{{< dots >}}
### Edge Cases 🌐
- The input will never be empty as per the given constraints (minimum array length is 1).
- The maximum input size is 8, so the factorial growth of the number of permutations will not exceed manageable limits.
- The input array can contain duplicates, so we need to be mindful of handling them in the backtracking process.
- Ensure to handle duplicate numbers properly to avoid generating the same permutation multiple times.
{{< dots >}}
## Code 💻
```cpp
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
```

This code generates all unique permutations of a given array of integers using backtracking and a hash map to avoid duplicates.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	void f(vector<int>&nums,vector<vector<int>>&ans,int ind){
	```
	This line declares a recursive backtracking function `f` that takes three arguments: `nums` (the input array), `ans` (a 2D vector to store the permutations), and `ind` (the current index).

2. **Base Case**
	```cpp
	    if(ind==nums.size()){
	```
	This line checks if the current index `ind` has reached the end of the array. If so, it means a complete permutation has been formed.

3. **Add Permutation to Result**
	```cpp
	        ans.push_back(nums);
	```
	If the base case is true, the current permutation `nums` is added to the `ans` vector.

4. **Return from Base Case**
	```cpp
	        return;
	```
	The function returns after adding the permutation to the result.

5. **Map Initialization**
	```cpp
	    unordered_map<int,int>mp;
	```
	An unordered map `mp` is initialized to keep track of the frequency of each number in the current permutation. This is used to avoid duplicate permutations.

6. **Loop Iteration**
	```cpp
	    for(int i=ind;i<nums.size();i++){
	```
	This loop iterates through the elements of the array starting from the current index `ind`.

7. **Skip Duplicate Numbers**
	```cpp
	        if(mp.find(nums[i])!=mp.end()){
	```
	This condition checks if the current number `nums[i]` has already been used in the current permutation. If so, it skips to the next iteration.

8. **Skip Duplicate Numbers**
	```cpp
	            continue;
	```
	The `continue` statement skips to the next iteration of the loop.

9. **Mark Number as Used**
	```cpp
	        }else{
	```
	If the current number is not a duplicate, it is marked as used in the `mp` map.

10. **Mark Number as Used**
	```cpp
	            mp[nums[i]]++;
	```
	The frequency of the current number `nums[i]` is incremented in the `mp` map.

11. **Swap Elements**
	```cpp
	            swap(nums[i],nums[ind]);
	```
	The current number `nums[i]` is swapped with the number at the current index `ind` to explore a new permutation.

12. **Recursive Call**
	```cpp
	            f(nums,ans,ind+1);
	```
	The `f` function is recursively called with the updated `ind` to explore the next position in the permutation.

13. **Backtrack**
	```cpp
	            swap(nums[i],nums[ind]);
	```
	After the recursive call, the swap operation is reversed to backtrack and explore other possibilities.

14. **Main Function**
	```cpp
	vector<vector<int>> permuteUnique(vector<int>& nums) {
	```
	This line declares the main function `permuteUnique` that takes a vector of integers `nums` as input and returns a vector of vectors containing all unique permutations.

15. **Result Vector Initialization**
	```cpp
	    vector<vector<int>>ans;
	```
	A 2D vector `ans` is initialized to store the unique permutations.

16. **Backtracking Function Call**
	```cpp
	    f(nums,ans,0);
	```
	The `f` function is called with the `nums` array, `ans` vector, and starting index `0` to initiate the backtracking process.

17. **Return Result**
	```cpp
	    return ans;
	```
	The `ans` vector containing all unique permutations is returned.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n!)
- **Average Case:** O(n!)
- **Worst Case:** O(n!)

The time complexity is O(n!) due to the need to generate all possible permutations of n elements, where n is the length of the input array.

### Space Complexity 💾
- **Best Case:** O(n!)
- **Worst Case:** O(n!)

The space complexity is O(n!) because we need to store all unique permutations, and the recursive stack may also reach this depth.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/permutations-ii/description/)

---
{{< youtube qhBVWf0YafA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
