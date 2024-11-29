
+++
authors = ["grid47"]
title = "Leetcode 2343: Query Kth Smallest Trimmed Number"
date = "2024-03-17"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2343: Query Kth Smallest Trimmed Number in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","String","Divide and Conquer","Sorting","Heap (Priority Queue)","Radix Sort","Quickselect"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "E93-thIrUgA"
youtube_upload_date="2022-07-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/E93-thIrUgA/maxresdefault.webp"
comments = true
+++



---
You are given a list `nums` where each string contains digits of the same length. Additionally, you are provided a list of queries, where each query is represented by two integers `[ki, trimi]`. For each query, trim each number in `nums` to its rightmost `trimi` digits, then find the index of the `ki`th smallest trimmed number. If two numbers are identical after trimming, the one with the lower index is considered smaller. Reset the numbers in `nums` for the next query.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `nums` of strings and an array `queries` of queries, where each query is a pair `[ki, trimi]`.
- **Example:** `nums = ["203", "102", "114", "319"], queries = [[2, 1], [1, 3], [3, 2]]`
- **Constraints:**
	- 1 <= nums.length <= 100
	- 1 <= nums[i].length <= 100
	- 1 <= queries.length <= 100
	- 1 <= ki <= nums.length
	- 1 <= trimi <= nums[i].length

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array `answer` where each element corresponds to the answer of the respective query. Each answer should be the index of the `ki`th smallest number in the trimmed list.
- **Example:** `[1, 2, 0]`
- **Constraints:**

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to trim the numbers in `nums` according to the query's specification, sort the trimmed numbers, and return the index of the `ki`th smallest number.

- For each query, trim all numbers in `nums` to the rightmost `trimi` digits.
- Sort the numbers based on the trimmed version, with ties broken by the original index.
- Find the index of the `ki`th smallest number in the sorted list and add it to the result.
{{< dots >}}
### Problem Assumptions ✅
- The input `nums` consists of valid strings representing numbers.
- Each query consists of two integers: `ki` and `trimi`.
{{< dots >}}
## Examples 🧩
- **Input:** `nums = ["203", "102", "114", "319"], queries = [[2, 1], [1, 3], [3, 2]]`  \
  **Explanation:** For the first query, after trimming the numbers to the last digit, we get ["3", "2", "4", "9"]. The second smallest number is 2, which is at index 1.

{{< dots >}}
## Approach 🚀
We trim each number based on the `trimi` value, sort the trimmed numbers along with their original indices, and then return the index of the `ki`th smallest number.

### Initial Thoughts 💭
- Trimming the numbers to the rightmost digits involves string manipulation.
- Sorting the trimmed numbers requires careful handling of ties based on the original indices.
- The problem can be solved efficiently by trimming, sorting, and then mapping the smallest `ki`th values to their original indices.
{{< dots >}}
### Edge Cases 🌐
- The problem does not allow empty inputs for `nums` or `queries`.
- The solution must handle the upper limit of inputs efficiently.
- Consider cases where trimmed numbers may have leading zeros or be equal to other numbers.
- The solution must handle arrays of numbers with varying digit lengths and ensure correctness under all constraints.
{{< dots >}}
## Code 💻
```cpp
vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
    vector<int> res;
    for(auto &v : q) {
        
        vector<pair<string, int>> fk;
        for(int i = 0; i < nums.size(); i++) {
            fk.push_back({nums[i].substr(nums[i].size() - v[1]), i});
        }
        sort(fk.begin(), fk.end());
        res.push_back(fk[v[0] - 1].second);
        
    }
    
    return res;
}
```

This function takes a list of strings and a list of queries. Each query specifies a trim length and an index. The function trims each string based on the length, sorts them, and returns the index of the specified smallest trimmed number from each query.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& q) {
	```
	Function definition begins, where 'nums' is a list of strings and 'q' contains multiple queries.

2. **Variable Initialization**
	```cpp
	    vector<int> res;
	```
	Initialize an empty vector 'res' that will store the results for each query.

3. **For Loop**
	```cpp
	    for(auto &v : q) {
	```
	Start a loop over each query in 'q'. Each query is a vector containing two integers: the trim length and the index.

4. **Vector of Pairs**
	```cpp
	        vector<pair<string, int>> fk;
	```
	Initialize a vector of pairs 'fk' to store pairs of trimmed string and original index.

5. **For Loop**
	```cpp
	        for(int i = 0; i < nums.size(); i++) {
	```
	Start a loop to iterate over all strings in 'nums'.

6. **String Manipulation**
	```cpp
	            fk.push_back({nums[i].substr(nums[i].size() - v[1]), i});
	```
	For each string in 'nums', take a substring starting from the end, based on the trim length 'v[1]', and store the pair of substring and its index.

7. **Sorting**
	```cpp
	        sort(fk.begin(), fk.end());
	```
	Sort the vector of pairs 'fk' based on the trimmed strings.

8. **Result Assignment**
	```cpp
	        res.push_back(fk[v[0] - 1].second);
	```
	Add the index of the smallest trimmed number from the sorted list to the 'res' vector. The index is based on the query value 'v[0]'.

9. **Return Statement**
	```cpp
	    return res;
	```
	Return the vector 'res', which contains the result for each query.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n)
- **Average Case:** O(n log n)
- **Worst Case:** O(n log n)

The time complexity is dominated by the sorting step, where n is the length of the array `nums`.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) due to the space required to store the trimmed numbers and their indices.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/query-kth-smallest-trimmed-number/description/)

---
{{< youtube E93-thIrUgA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
