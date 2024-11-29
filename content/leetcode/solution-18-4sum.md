
+++
authors = ["grid47"]
title = "Leetcode 18: 4Sum"
date = "2024-11-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 18: 4Sum in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/18.webp"
youtube = "EYeR-_1NRlQ"
youtube_upload_date="2022-03-08"
youtube_thumbnail="https://i.ytimg.com/vi_webp/EYeR-_1NRlQ/maxresdefault.webp"
comments = true
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/18.webp" 
    alt="Four soft light orbs orbiting around a central glowing point, signifying combination."
    caption="Solution to LeetCode 18: 4Sum Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
You are given an array of integers `nums` and a target value. Your task is to find all unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that the sum of the four numbers equals the target value. The indices a, b, c, and d should be distinct.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `nums` of size `n`, and an integer `target` representing the target sum.
- **Example:** `Input: nums = [-3, 0, 1, 2, -1, -4], target = 0`
- **Constraints:**
	- 1 <= nums.length <= 200
	- -10^9 <= nums[i] <= 10^9
	- -10^9 <= target <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a 2D array of all unique quadruplets that sum up to the given target.
- **Example:** `Output: [[-3, -1, 1, 2], [-4, 0, 1, 2]]`
- **Constraints:**
	- The quadruplets should be unique, and the answer can be returned in any order.

{{< dots >}}
### Core Logic 🔍
**Goal:** To find all unique quadruplets whose sum is equal to the target value.

- 1. Sort the input array to enable efficient two-pointer traversal.
- 2. Use two nested loops to fix the first two elements of the quadruplet.
- 3. Use two pointers to find the remaining two elements that together sum to the remaining target.
{{< dots >}}
### Problem Assumptions ✅
- The array will have at least 4 elements to form a quadruplet.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [-3, 0, 1, 2, -1, -4], target = 0`  \
  **Explanation:** The unique quadruplets that sum to 0 are: [-3, -1, 1, 2] and [-4, 0, 1, 2].

- **Input:** `Input: nums = [2, 2, 2, 2, 2], target = 8`  \
  **Explanation:** The only unique quadruplet that sums to 8 is [2, 2, 2, 2].

{{< dots >}}
## Approach 🚀
To solve this problem, we can use sorting and the two-pointer technique to efficiently find unique quadruplets that sum to the target.

### Initial Thoughts 💭
- The two-pointer technique helps to find pairs of numbers efficiently once two elements are fixed.
- Sorting the array allows us to avoid duplicates by skipping repeated elements.
- By sorting the array and using two nested loops to fix the first two numbers, we can use two pointers to find the other two numbers that sum up to the remaining target.
{{< dots >}}
### Edge Cases 🌐
- If the array has fewer than 4 elements, it's impossible to form a quadruplet, so the result should be an empty list.
- If the array has many elements, the solution should be optimized to handle large input sizes efficiently.
- If all elements in the array are the same, only one unique quadruplet should be returned.
- Ensure that the solution works within the time and space complexity limits, especially when handling larger inputs.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> fourSum(vector<int>& nums, int target) {
    int n = nums.size();
    sort(nums.begin(), nums.end());
    set<vector<int>> set;
    vector<vector<int>> output;
    for(int i=0; i<n-3; i++){
        for(int j=i+1; j<n-2; j++){
            long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
            int low = j+1, high = n-1;
            while(low < high){
                if(nums[low] + nums[high] < newTarget){
                    low++;
                }
                else if(nums[low] + nums[high] > newTarget){
                    high--;
                }
                else{
                    set.insert({nums[i], nums[j], nums[low], nums[high]});
                    low++; high--;
                }
            }
        }
    }
    for(auto it : set){
        output.push_back(it);
    }
    return output;
}
```

This code implements the `fourSum` function, which finds all unique quadruplets in the array `nums` that add up to the target value.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<vector<int>> fourSum(vector<int>& nums, int target) {
	```
	Declare the `fourSum` function, which takes a vector of integers `nums` and a target integer `target` as input and returns a vector of vectors representing the unique quadruplets.

2. **Variable Initialization**
	```cpp
	    int n = nums.size();
	```
	Store the size of the `nums` vector in `n` for efficient indexing.

3. **Sorting Operations**
	```cpp
	    sort(nums.begin(), nums.end());
	```
	Sort the `nums` vector in ascending order to facilitate the two-pointer approach.

4. **Set Initialization**
	```cpp
	    set<vector<int>> set;
	```
	Initialize a set `set` to store unique quadruplets to avoid duplicates.

5. **Variable Initialization**
	```cpp
	    vector<vector<int>> output;
	```
	Initialize a vector `output` to store the final result of unique quadruplets.

6. **Nested Loops**
	```cpp
	    for(int i=0; i<n-3; i++){
	```
	Start the first outer loop to iterate over the first element of the quadruplet.

7. **Nested Loops**
	```cpp
	        for(int j=i+1; j<n-2; j++){
	```
	Start the second outer loop to iterate over the second element of the quadruplet, ensuring `j` is greater than `i` to avoid duplicates.

8. **Calculations**
	```cpp
	            long long newTarget = (long long)target - (long long)nums[i] - (long long)nums[j];
	```
	Calculate the target sum for the remaining two numbers: `newTarget = target - nums[i] - nums[j]`. Cast to `long long` to avoid integer overflow.

9. **Variable Initialization**
	```cpp
	            int low = j+1, high = n-1;
	```
	Initialize two pointers `low` and `high` to start the two-pointer approach for the remaining two elements.

10. **Loop Iteration**
	```cpp
	            while(low < high){
	```
	Start the two-pointer loop to find pairs that add up to `newTarget`.

11. **Conditional Update**
	```cpp
	                if(nums[low] + nums[high] < newTarget){
	                    low++;
	                }
	```
	If the sum of `nums[low]` and `nums[high]` is less than `newTarget`, move `low` to the right to increase the sum.

12. **Conditional Update**
	```cpp
	                else if(nums[low] + nums[high] > newTarget){
	                    high--;
	                }
	```
	If the sum of `nums[low]` and `nums[high]` is greater than `newTarget`, move `high` to the left to decrease the sum.

13. **Set Operations**
	```cpp
	                else{
	                    set.insert({nums[i], nums[j], nums[low], nums[high]});
	                    low++; high--;
	                }
	```
	If the sum is equal to `newTarget`, insert the quadruplet into the `set` to avoid duplicates and move both pointers to find other potential quadruplets.

14. **Set Iteration**
	```cpp
	    for(auto it : set){
	```
	Iterate through the unique quadruplets in the `set`.

15. **Array Manipulation**
	```cpp
	        output.push_back(it);
	```
	Add each unique quadruplet to the `output` vector.

16. **Return Value**
	```cpp
	    return output;
	```
	Return the `output` vector containing all unique quadruplets.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n^3), where `n` is the length of the array. This occurs when no early exits happen.
- **Average Case:** O(n^3), as the solution involves three nested loops and two pointers.
- **Worst Case:** O(n^3), since the worst case happens when the algorithm must iterate over most combinations of elements.

The time complexity is cubic in the length of the array due to the three loops and the two-pointer technique.

### Space Complexity 💾
- **Best Case:** O(n), as the space used by the set is dependent on the number of unique quadruplets.
- **Worst Case:** O(n), where `n` is the number of unique quadruplets. This is the space used by the set to store unique quadruplets.

The space complexity depends on the number of unique quadruplets stored in the result set.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/4sum/description/)

---
{{< youtube EYeR-_1NRlQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
