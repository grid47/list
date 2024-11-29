
+++
authors = ["grid47"]
title = "Leetcode 2909: Minimum Sum of Mountain Triplets II"
date = "2024-01-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2909: Minimum Sum of Mountain Triplets II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "PU5YZP1-uVA"
youtube_upload_date="2023-10-22"
youtube_thumbnail="https://i.ytimg.com/vi/PU5YZP1-uVA/maxresdefault.jpg"
comments = true
+++



---
You are given an array of integers called nums. A mountain triplet consists of three indices (i, j, k) such that i < j < k, nums[i] < nums[j], and nums[k] < nums[j]. Your task is to return the minimum possible sum of any such mountain triplet. If no such triplet exists, return -1.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given an integer array nums of length n.
- **Example:** `nums = [12, 7, 8, 15, 5]`
- **Constraints:**
	- 3 <= nums.length <= 10^5
	- 1 <= nums[i] <= 10^8

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum sum of a valid mountain triplet (i, j, k), or -1 if no such triplet exists.
- **Example:** `For the input [12, 7, 8, 15, 5], the output should be 22.`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to identify the minimum sum of a valid mountain triplet in the array.

- Create an array to store the smallest number to the right of each element.
- Iterate through the array and for each number, check if there is a smaller element on its left and right.
- Track the minimum sum of such valid mountain triplets.
- Return the minimum sum if any valid triplet is found, otherwise return -1.
{{< dots >}}
### Problem Assumptions ✅
- The input will always have at least three numbers.
- The solution should work for all values within the given constraints.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = [12, 7, 8, 15, 5]`  \
  **Explanation:** In this case, the mountain triplet (1, 2, 4) is valid because 7 < 8 and 5 < 8. The sum of this triplet is 7 + 8 + 5 = 22, which is the minimum sum.

{{< dots >}}
## Approach 🚀
The approach involves using a preprocessing step to determine the smallest elements on the right for each element, and then finding the minimum sum of valid mountain triplets.

### Initial Thoughts 💭
- We need to efficiently check for each element if there exists a valid mountain triplet using two conditions: a smaller element to its left and a smaller element to its right.
- We can optimize this problem using a linear pass to find the smallest right elements, and then another pass to find valid triplets.
{{< dots >}}
### Edge Cases 🌐
- The input array will always have at least three elements.
- The solution should be efficient enough to handle the upper constraint of nums.length up to 10^5.
- Consider arrays where no valid mountain triplets exist, such as arrays with strictly increasing or decreasing numbers.
- All values of nums will be between 1 and 10^8.
{{< dots >}}
## Code 💻
```cpp
int minimumSum(vector<int>& nums) {
    vector<int> smallestRight(nums.size(), nums.back());
    for(int i = nums.size()-2; i >= 0; i--){
        smallestRight[i] = min(smallestRight[i+1], nums[i]);
    }
    int smallestLeft = nums[0], ans = -1;
    for(int i = 1; i < nums.size(); i++){
        if(smallestLeft < nums[i] && smallestRight[i] < nums[i]){ 
            if(ans == -1) ans =  nums[i] + smallestRight[i] + smallestLeft;
            else ans = min(ans, nums[i] + smallestRight[i] + smallestLeft); 
        }
        smallestLeft = min(smallestLeft, nums[i]);
    }
    return ans;
}
```

The `minimumSum` function finds the minimum sum of three distinct elements where each element is part of a triplet that satisfies a certain condition. It uses two auxiliary arrays to track the smallest right and left elements for each element in the array to find the triplet with the smallest sum.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minimumSum(vector<int>& nums) {
	```
	Defines the `minimumSum` function, which takes a vector of integers `nums` and returns the minimum sum of a valid triplet satisfying certain conditions.

2. **Array Initialization**
	```cpp
	    vector<int> smallestRight(nums.size(), nums.back());
	```
	Initializes the `smallestRight` array, which will store the smallest value to the right of each element in `nums`. It starts with the last element of `nums`.

3. **Loop: Backward Traversal**
	```cpp
	    for(int i = nums.size()-2; i >= 0; i--){
	```
	Starts a loop that traverses the array `nums` from right to left (excluding the last element) to populate the `smallestRight` array.

4. **Updating Smallest Right Value**
	```cpp
	        smallestRight[i] = min(smallestRight[i+1], nums[i]);
	```
	For each element, updates `smallestRight[i]` to store the minimum of `smallestRight[i+1]` and `nums[i]`, which ensures it holds the smallest value to the right of `nums[i]`.

5. **Variable Initialization**
	```cpp
	    int smallestLeft = nums[0], ans = -1;
	```
	Initializes `smallestLeft` with the first element of `nums`, and `ans` to `-1` to represent that no valid triplet has been found yet.

6. **Loop: Forward Traversal**
	```cpp
	    for(int i = 1; i < nums.size(); i++){
	```
	Starts a loop that traverses the array `nums` from left to right (excluding the first element).

7. **Conditional Check: Triplet Validation**
	```cpp
	        if(smallestLeft < nums[i] && smallestRight[i] < nums[i]){ 
	```
	Checks if the current element `nums[i]` forms a valid triplet with the elements to the left and right by ensuring that `smallestLeft < nums[i]` and `smallestRight[i] < nums[i]`.

8. **Condition Met: Update Answer**
	```cpp
	            if(ans == -1) ans =  nums[i] + smallestRight[i] + smallestLeft;
	```
	If `ans` is still `-1`, this is the first valid triplet found, so it updates `ans` with the sum of the triplet.

9. **Condition Met: Update Answer (Min)**
	```cpp
	            else ans = min(ans, nums[i] + smallestRight[i] + smallestLeft); 
	```
	If a valid triplet is found and `ans` is not `-1`, it updates `ans` with the minimum sum of the current triplet and the previous smallest sum.

10. **Updating Smallest Left Value**
	```cpp
	        smallestLeft = min(smallestLeft, nums[i]);
	```
	Updates `smallestLeft` to the minimum of its current value and `nums[i]` to ensure it always holds the smallest value to the left of `nums[i]`.

11. **Return Statement**
	```cpp
	    return ans;
	```
	Returns the minimum sum found from the valid triplet, or `-1` if no valid triplet exists.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) because we only perform two passes over the array.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the additional array used to store the smallest elements to the right of each index.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-sum-of-mountain-triplets-ii/description/)

---
{{< youtube PU5YZP1-uVA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
