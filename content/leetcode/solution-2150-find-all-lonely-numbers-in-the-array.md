
+++
authors = ["grid47"]
title = "Leetcode 2150: Find All Lonely Numbers in the Array"
date = "2024-04-06"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2150: Find All Lonely Numbers in the Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Counting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "oX00CiVJ00Q"
youtube_upload_date="2022-01-23"
youtube_thumbnail="https://i.ytimg.com/vi_webp/oX00CiVJ00Q/maxresdefault.webp"
comments = true
+++



---
You are given an integer array 'nums'. A number 'x' is lonely if it appears exactly once and neither 'x - 1' nor 'x + 1' exist in the array. Return all lonely numbers in the array.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array 'nums'.
- **Example:** `nums = [12, 6, 4, 8]`
- **Constraints:**
	- 1 <= nums.length <= 10^5
	- 0 <= nums[i] <= 10^6

{{< dots >}}
### Output Specifications 📤
- **Output:** Return all the lonely numbers in 'nums'. The result can be returned in any order.
- **Example:** `Output: [12, 8]`
- **Constraints:**
	- The array should contain numbers that are lonely by the definition provided.

{{< dots >}}
### Core Logic 🔍
**Goal:** Identify numbers that appear only once and do not have adjacent numbers in the array.

- Count the frequency of each number in the array.
- Check for each number if it appears exactly once and if its neighbors (x-1 and x+1) are not present in the array.
- Return the numbers that meet these conditions.
{{< dots >}}
### Problem Assumptions ✅
- The input array may contain repeated numbers, but the goal is to identify the lonely numbers based on the conditions given.
{{< dots >}}
## Examples 🧩
- **Input:** `Example 1: nums = [12, 6, 4, 8]`  \
  **Explanation:** The lonely numbers are 12 and 8 because they appear exactly once, and their adjacent numbers (11, 13, 7, and 9) are not present in the array.

- **Input:** `Example 2: nums = [2, 4, 6, 4]`  \
  **Explanation:** The lonely numbers are 2 and 6. The number 4 is not lonely because it appears twice.

{{< dots >}}
## Approach 🚀
The approach involves counting the occurrences of each number and checking for adjacency conditions to identify lonely numbers.

### Initial Thoughts 💭
- To find lonely numbers, we need to consider both frequency and the presence of adjacent numbers.
- A frequency map is useful to determine which numbers appear exactly once. Additionally, checking for adjacent numbers is crucial.
{{< dots >}}
### Edge Cases 🌐
- An empty input is not valid according to the constraints.
- The solution should handle large arrays up to the constraint of 10^5 elements efficiently.
- If there are no lonely numbers, the function should return an empty array.
- The input array contains valid integers within the given range.
{{< dots >}}
## Code 💻
```cpp
vector<int> findLonely(vector<int>& nums) {
    unordered_map<int, int> mp;
    for(int num: nums) mp[num]++;

    vector<int> res;
    for(auto [x, cnt]: mp) {
        if(cnt == 1 && !mp.count(x - 1) && !mp.count(x +1))
            res.push_back(x);
    }

    return res;
}
```

This function finds all numbers in the input array that are lonely, i.e., appear exactly once and do not have adjacent numbers in the array.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> findLonely(vector<int>& nums) {
	```
	Function declaration to find all lonely numbers in the given array. Lonely numbers appear exactly once and do not have adjacent numbers.

2. **Variable Initialization**
	```cpp
	    unordered_map<int, int> mp;
	```
	Create a hash map 'mp' to count the frequency of each number in the input 'nums' array.

3. **Counting Frequencies**
	```cpp
	    for(int num: nums) mp[num]++;
	```
	Iterate through the 'nums' array and update the frequency count of each number in the 'mp' hash map.

4. **Variable Initialization**
	```cpp
	    vector<int> res;
	```
	Initialize an empty vector 'res' to store the lonely numbers that will be found.

5. **Iteration**
	```cpp
	    for(auto [x, cnt]: mp) {
	```
	Iterate through each key-value pair in the 'mp' hash map, where 'x' is the number and 'cnt' is its frequency.

6. **Condition Check**
	```cpp
	        if(cnt == 1 && !mp.count(x - 1) && !mp.count(x +1))
	```
	Check if the current number 'x' appears exactly once ('cnt == 1') and does not have adjacent numbers ('x-1' and 'x+1') in the 'mp' map.

7. **Adding to Result**
	```cpp
	            res.push_back(x);
	```
	If the number 'x' is lonely, add it to the 'res' vector.

8. **Return Statement**
	```cpp
	    return res;
	```
	Return the 'res' vector containing all the lonely numbers found in the array.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) since we iterate over the array to build the frequency map and check each element's neighbors.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the frequency map of the array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/find-all-lonely-numbers-in-the-array/description/)

---
{{< youtube oX00CiVJ00Q >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
