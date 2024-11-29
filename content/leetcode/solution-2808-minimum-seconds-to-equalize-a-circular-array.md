
+++
authors = ["grid47"]
title = "Leetcode 2808: Minimum Seconds to Equalize a Circular Array"
date = "2024-01-31"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2808: Minimum Seconds to Equalize a Circular Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "NgWw6HIyCWE"
youtube_upload_date="2023-08-06"
youtube_thumbnail="https://i.ytimg.com/vi/NgWw6HIyCWE/maxresdefault.jpg"
comments = true
+++



---
You are given a 0-indexed array nums containing n integers. At each second, replace every nums[i] with either nums[i], nums[(i-1+n)%n], or nums[(i+1)%n]. Return the minimum number of seconds required to make all elements in the array equal.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** You are given a list of integers nums where nums[i] represents the value at index i.
- **Example:** `Input: nums = [3, 5, 5, 3]`
- **Constraints:**
	- 1 <= n <= 10^5
	- 1 <= nums[i] <= 10^9

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the minimum number of seconds needed to make all the elements in the array equal.
- **Example:** `Output: 1`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine how many seconds are needed to transform the array such that all elements become the same.

- 1. Identify the indices of each distinct number in the array.
- 2. For each distinct number, calculate the maximum gap between its occurrences.
- 3. Compute the minimum number of seconds required to fill these gaps for all distinct numbers.
{{< dots >}}
### Problem Assumptions ✅
- The array will always have at least one element.
- The problem assumes that all elements are integers and the array can be very large.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: nums = [3, 5, 5, 3]`  \
  **Explanation:** In 1 second, we can replace elements so that the array becomes [5, 5, 5, 5], making all elements equal.

- **Input:** `Input: nums = [1, 3, 2, 3, 1]`  \
  **Explanation:** It takes 2 seconds to make all elements equal by first turning the array into [1, 3, 3, 3, 3] and then [3, 3, 3, 3, 3].

{{< dots >}}
## Approach 🚀
We will calculate how many seconds it takes to make all elements in the array equal by identifying the maximum gap for each distinct number and filling those gaps.

### Initial Thoughts 💭
- The problem requires efficiently tracking the occurrences of each number in the array.
- The key observation is to minimize the time it takes to fill the gaps between occurrences of each distinct number.
{{< dots >}}
### Edge Cases 🌐
- The array will not be empty.
- The solution should efficiently handle arrays of size up to 100,000 elements.
- If all elements are the same initially, the answer should be 0.
- Ensure the solution runs in O(n) time to handle large inputs efficiently.
{{< dots >}}
## Code 💻
```cpp
int minimumSeconds(vector<int>& nums) {
    
    int n = nums.size();
    map<int, vector<int>> pos;
    
    for(int i = 0; i < n; i++)
        pos[nums[i]].push_back(i);
    
    int res = INT_MAX;
    
    for(auto [key, val]: pos) {
        int sec = 0;
        val.push_back(val[0] + n);
        
        for(int i = 1; i < val.size(); i++) {
            sec = max(sec, (val[i] - val[i - 1])/ 2);
        }
        
        res = min(res, sec);
    }
    return res;
}
```

This function calculates the minimum number of seconds required for a certain condition to be satisfied in a circular list, based on the time differences between repeated numbers.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	int minimumSeconds(vector<int>& nums) {
	```
	The function definition that takes a vector of integers as input and returns the minimum number of seconds.

2. **Initialization**
	```cpp
	    int n = nums.size();
	```
	Initializes the variable 'n' to store the size of the input vector 'nums'.

3. **Data Structure Initialization**
	```cpp
	    map<int, vector<int>> pos;
	```
	Declares a map 'pos' that stores a vector of integers for each unique element in 'nums', representing the indices of each occurrence.

4. **Loop**
	```cpp
	    for(int i = 0; i < n; i++)
	```
	Starts a for loop to iterate through each element of the input vector.

5. **Data Insertion**
	```cpp
	        pos[nums[i]].push_back(i);
	```
	Inserts the current index 'i' into the 'pos' map for the current element 'nums[i]'.

6. **Variable Initialization**
	```cpp
	    int res = INT_MAX;
	```
	Initializes 'res' to the maximum possible integer value to track the minimum time required.

7. **Loop Through Map**
	```cpp
	    for(auto [key, val]: pos) {
	```
	Starts a for-each loop to iterate over the elements of the 'pos' map.

8. **Variable Initialization**
	```cpp
	        int sec = 0;
	```
	Initializes a variable 'sec' to track the maximum gap between repeated elements.

9. **Circular List Adjustment**
	```cpp
	        val.push_back(val[0] + n);
	```
	Adds a new element to 'val' to simulate a circular list by adding 'n' (the size of the list) to the first element.

10. **Gap Calculation**
	```cpp
	        for(int i = 1; i < val.size(); i++) {
	```
	Starts a loop to calculate the gap between consecutive indices in the 'val' vector.

11. **Max Gap Calculation**
	```cpp
	            sec = max(sec, (val[i] - val[i - 1])/ 2);
	```
	Updates 'sec' to the maximum gap between consecutive indices divided by 2.

12. **Update Result**
	```cpp
	        res = min(res, sec);
	```
	Updates 'res' to the minimum value between 'res' and 'sec'.

13. **Return**
	```cpp
	    return res;
	```
	Returns the minimum number of seconds calculated.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the number of elements in the array.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to storing the indices of each distinct number in a map.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-seconds-to-equalize-a-circular-array/description/)

---
{{< youtube NgWw6HIyCWE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
