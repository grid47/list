
+++
authors = ["grid47"]
title = "Leetcode 1409: Queries on a Permutation With Key"
date = "2024-06-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1409: Queries on a Permutation With Key in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Indexed Tree","Simulation"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = ""
youtube_upload_date=""
youtube_thumbnail=""
comments = true
+++



---
You are given a list of positive integers called `queries`, each between 1 and `m`. You need to process each element in `queries` sequentially according to the following rules:

1. Initially, the permutation `P` is `[1, 2, 3, ..., m]`.
2. For each `queries[i]`, find the index of `queries[i]` in the permutation `P`.
3. After locating `queries[i]` in `P`, move it to the beginning of the list.
4. Return the list of indices (positions) for each element in `queries` as they are processed.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer `m` and an array `queries` of positive integers between 1 and `m`.
- **Example:** `queries = [3, 1, 2, 1], m = 5`
- **Constraints:**
	- 1 <= m <= 10^3
	- 1 <= queries.length <= m
	- 1 <= queries[i] <= m

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array containing the result for the given queries. The result array consists of the indices of each element in `queries` after processing according to the rules described.
- **Example:** `[2, 1, 2, 1]`
- **Constraints:**
	- The output array will have the same length as `queries`.

{{< dots >}}
### Core Logic 🔍
**Goal:** Process each query and return the resulting list of indices after adjusting the permutation.

- 1. Initialize the permutation `P` as `[1, 2, ..., m]`.
- 2. For each element in `queries`, find its position in `P` and store the result.
- 3. Move the current element to the beginning of `P` after finding its position.
{{< dots >}}
### Problem Assumptions ✅
- The `queries` array will always have positive integers between 1 and `m`.
{{< dots >}}
## Examples 🧩
- **Input:** `queries = [3, 1, 2, 1], m = 5`  \
  **Explanation:** The processing steps for each query are explained, and the final result `[2, 1, 2, 1]` is derived.

{{< dots >}}
## Approach 🚀
The approach involves simulating the movement of elements in the permutation after each query.

### Initial Thoughts 💭
- We can maintain the permutation using an array or list and keep track of the position of each element.
- Since we need to frequently shift elements to the beginning of the permutation, an efficient way to track positions and update them is essential.
{{< dots >}}
### Edge Cases 🌐
- The `queries` array will not be empty, so this case does not need to be considered.
- When `m` is large (near 10^3), ensure that the approach is efficient enough to handle the maximum constraints.
- Handle cases where `queries` consists of repetitive or sequential queries.
- The number of queries is always between 1 and `m`, and each query is a valid integer within this range.
{{< dots >}}
## Code 💻
```cpp
vector<int> processQueries(vector<int>& q, int m) {
    vector<int> ans;
    for(int i = 1; i <= m; i++)
        ans.push_back(i);
    map<int, int> mp;
    for(int i = 0; i < ans.size(); i++)
        mp[ans[i]] = i;
    
    vector<int> res;
    for(int i = 0; i < q.size(); i++) {
        int x = mp[q[i]];
        res.push_back(x);
        for(auto it: mp) {
            if(it.second < x)
            mp[it.first]++; // shift to right
        }
        mp[q[i]] = 0;
    }
    return res;
}
```

This function, `processQueries`, processes a list of queries and returns a list of positions of each query in a sequence. It also adjusts the sequence positions after each query is processed.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Method Definition**
	```cpp
	vector<int> processQueries(vector<int>& q, int m) {
	```
	Defines the method `processQueries` which takes a vector `q` of queries and an integer `m` representing the size of the sequence. It returns a vector of integers representing the positions of each query in the sequence.

2. **Vector Initialization**
	```cpp
	    vector<int> ans;
	```
	Initializes a vector `ans` to hold the sequence from 1 to `m`.

3. **Loop to Initialize Sequence**
	```cpp
	    for(int i = 1; i <= m; i++)
	```
	Starts a `for` loop to iterate from 1 to `m` and populate the `ans` vector with integers.

4. **Push Values to Vector**
	```cpp
	        ans.push_back(i);
	```
	Adds each integer `i` from 1 to `m` to the `ans` vector.

5. **Map Initialization**
	```cpp
	    map<int, int> mp;
	```
	Initializes a map `mp` to store each element in `ans` along with its index.

6. **Map Population**
	```cpp
	    for(int i = 0; i < ans.size(); i++)
	```
	Starts a loop to populate the map `mp` where the key is the element from `ans` and the value is its corresponding index.

7. **Insert into Map**
	```cpp
	        mp[ans[i]] = i;
	```
	Inserts each element from the `ans` vector along with its index into the map `mp`.

8. **Vector Initialization for Result**
	```cpp
	    vector<int> res;
	```
	Initializes an empty vector `res` to store the results of the query processing.

9. **Loop through Queries**
	```cpp
	    for(int i = 0; i < q.size(); i++) {
	```
	Starts a loop to process each query in the `q` vector.

10. **Get Position from Map**
	```cpp
	        int x = mp[q[i]];
	```
	Gets the position of the current query element `q[i]` from the map `mp`.

11. **Push Result Position**
	```cpp
	        res.push_back(x);
	```
	Adds the position `x` of the current query to the result vector `res`.

12. **Loop through Map**
	```cpp
	        for(auto it: mp) {
	```
	Starts a loop to iterate through each key-value pair in the map `mp`.

13. **Shift Elements in Map**
	```cpp
	            if(it.second < x)
	```
	Checks if the current index in the map is less than the position of the query element. If so, shifts that element to the right.

14. **Update Map Values**
	```cpp
	            mp[it.first]++; // shift to right
	```
	Increases the index of the element in the map to shift it to the right.

15. **Update Position for Query**
	```cpp
	        mp[q[i]] = 0;
	```
	Sets the position of the processed query element `q[i]` to 0 in the map, as it has been processed.

16. **Return Result**
	```cpp
	    return res;
	```
	Returns the `res` vector which contains the positions of each query after processing.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(m) - when queries only refer to elements already at the beginning of the permutation.
- **Average Case:** O(m * n) - for typical cases where each query results in a shift in the permutation.
- **Worst Case:** O(m * n) - when every query requires a major shift in the permutation.

Time complexity depends on the number of elements in the permutation and the number of queries.

### Space Complexity 💾
- **Best Case:** O(m) - the space usage is proportional to the size of the permutation.
- **Worst Case:** O(m) - space used by the permutation and the mapping of positions.

Space complexity is dominated by the space needed to store the permutation and auxiliary data structures.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/queries-on-a-permutation-with-key/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
