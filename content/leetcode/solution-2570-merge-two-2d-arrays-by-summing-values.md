
+++
authors = ["grid47"]
title = "Leetcode 2570: Merge Two 2D Arrays by Summing Values"
date = "2024-02-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2570: Merge Two 2D Arrays by Summing Values in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Two Pointers"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "Ou0KdT0OgV8"
youtube_upload_date="2023-02-19"
youtube_thumbnail="https://i.ytimg.com/vi_webp/Ou0KdT0OgV8/maxresdefault.webp"
comments = true
+++



---
You are given two 2D integer arrays nums1 and nums2. Each element in nums1 and nums2 is an array of two integers: an id and a value. The arrays are sorted in ascending order by the id. Your task is to merge the two arrays into a single array, sorted by id. Each id should appear only once, and if an id appears in both arrays, its value should be the sum of the values from both arrays. If an id is present in only one array, its value remains as it is.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of two arrays nums1 and nums2. Each array contains pairs of integers, where each pair represents an id and its corresponding value.
- **Example:** `For example, nums1 = [[1, 3], [2, 5], [4, 7]] and nums2 = [[1, 4], [3, 2], [4, 3]].`
- **Constraints:**
	- 1 <= nums1.length, nums2.length <= 200
	- nums1[i].length == nums2[i].length == 2
	- 1 <= idi, vali <= 1000
	- Both arrays contain unique ids.
	- Both arrays are sorted in strictly ascending order by id.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return the merged array where each id appears only once. If an id appears in both arrays, its value should be the sum of the values in both arrays. The array should be sorted in ascending order by id.
- **Example:** `For nums1 = [[1, 3], [2, 5], [4, 7]] and nums2 = [[1, 4], [3, 2], [4, 3]], the output is [[1, 7], [2, 5], [3, 2], [4, 10]].`
- **Constraints:**
	- The output should be a merged array sorted by id, with each id appearing only once.

{{< dots >}}
### Core Logic 🔍
**Goal:** To merge two arrays of ids and values into one array, summing the values for duplicate ids and sorting the array by id.

- 1. Use a map to store the id as the key and the sum of values as the value.
- 2. Traverse both nums1 and nums2, adding the values to the map based on the ids.
- 3. Convert the map to a vector of pairs, where each pair contains an id and its corresponding summed value.
- 4. Return the resulting vector sorted by id.
{{< dots >}}
### Problem Assumptions ✅
- The input arrays nums1 and nums2 are sorted in strictly ascending order by id.
- The arrays will not contain duplicate ids within each array.
{{< dots >}}
## Examples 🧩
- **Input:** `For nums1 = [[1, 3], [2, 5], [4, 7]] and nums2 = [[1, 4], [3, 2], [4, 3]], the output is [[1, 7], [2, 5], [3, 2], [4, 10]].`  \
  **Explanation:** In this case, the values for ids 1 and 4 are added because they appear in both arrays. The other ids are included as they are.

- **Input:** `For nums1 = [[3, 5], [7, 6]] and nums2 = [[2, 4], [5, 8]], the output is [[2, 4], [3, 5], [5, 8], [7, 6]].`  \
  **Explanation:** No ids overlap between the two arrays, so the result is a simple combination of the two arrays sorted by id.

{{< dots >}}
## Approach 🚀
The approach is based on using a map to accumulate the values for each unique id and then sorting the result by id.

### Initial Thoughts 💭
- The arrays are sorted by id, so we can efficiently traverse them and merge the values for each id.
- Use a map to store the sum of values for each id, then sort the results before returning.
{{< dots >}}
### Edge Cases 🌐
- Empty arrays are not possible, as the problem guarantees each array will have at least one element.
- Ensure that the solution can handle arrays of length up to 200 efficiently.
- The values can range from 1 to 1000, and ids are unique in each array.
- Both arrays are sorted, which helps with efficient merging.
{{< dots >}}
## Code 💻
```cpp
vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
    map<int,int> m;
    for(auto& itr : nums1){
        m[itr[0]] += itr[1]; 
    }
    for(auto& itr : nums2){
        m[itr[0]] += itr[1]; 
    }
    vector<vector<int> > v;
    for(auto& itr : m){
        v.push_back({itr.first,itr.second});
    }
    return v;
}
```

This code merges two arrays of pairs, sums the values for common keys, and returns a new array of pairs sorted by the keys.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Declaration**
	```cpp
	vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
	```
	Declares the function `mergeArrays` that takes two 2D vectors `nums1` and `nums2` and returns a 2D vector containing the merged and summed pairs.

2. **Map Initialization**
	```cpp
	    map<int,int> m;
	```
	Declares a map `m` that will store key-value pairs, where the key is an integer and the value is the sum of values from the input arrays.

3. **Loop**
	```cpp
	    for(auto& itr : nums1){
	```
	Starts a loop to iterate over each element (pair) in the first input array `nums1`.

4. **Map Insertion**
	```cpp
	        m[itr[0]] += itr[1]; 
	```
	For each pair, the first element (`itr[0]`) is used as the key, and the second element (`itr[1]`) is added to the corresponding value in the map.

5. **Loop**
	```cpp
	    for(auto& itr : nums2){
	```
	Starts a loop to iterate over each element (pair) in the second input array `nums2`.

6. **Map Insertion**
	```cpp
	        m[itr[0]] += itr[1]; 
	```
	For each pair in `nums2`, the value is added to the existing sum in the map for the key `itr[0]`.

7. **Vector Initialization**
	```cpp
	    vector<vector<int> > v;
	```
	Declares a 2D vector `v` which will store the final result.

8. **Loop**
	```cpp
	    for(auto& itr : m){
	```
	Starts a loop to iterate over each key-value pair in the map `m`.

9. **Vector Insertion**
	```cpp
	        v.push_back({itr.first,itr.second});
	```
	For each key-value pair in the map, a new pair is pushed into the vector `v`.

10. **Return Statement**
	```cpp
	    return v;
	```
	Returns the final 2D vector `v` containing the merged and summed pairs from `nums1` and `nums2`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n log n), where n is the number of unique ids in the final result.
- **Average Case:** O(n log n), due to sorting the result array.
- **Worst Case:** O(n log n), where n is the total number of ids from both arrays.

The time complexity is dominated by the sorting step, which takes O(n log n).

### Space Complexity 💾
- **Best Case:** O(n), where n is the number of unique ids.
- **Worst Case:** O(n), where n is the total number of ids from both arrays.

The space complexity is determined by the map and the result vector, both of which store ids and their values.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/description/)

---
{{< youtube Ou0KdT0OgV8 >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
