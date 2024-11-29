
+++
authors = ["grid47"]
title = "Leetcode 851: Loud and Rich"
date = "2024-08-13"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 851: Loud and Rich in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Depth-First Search","Graph","Topological Sort"]
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
You are given a group of `n` people, each with a unique amount of money and quietness. An array `richer` specifies the relationships between people where `richer[i] = [ai, bi]` indicates that person `ai` has more money than person `bi`. You are also given an array `quiet` where `quiet[i]` represents the quietness of person `i`. Your task is to return an array `answer` where `answer[x]` is the person `y` who has the least quietness among all people who have equal or more money than person `x`.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an array `richer`, where each element `richer[i] = [ai, bi]` represents a richer relationship between two people, and an array `quiet` where `quiet[i]` gives the quietness level of person `i`.
- **Example:** `Input: richer = [[2, 1], [3, 0], [4, 2]], quiet = [2, 3, 1, 0]`
- **Constraints:**
	- 1 <= n <= 500
	- quiet.length == n
	- All values of quiet are unique.
	- 0 <= richer.length <= n * (n - 1) / 2
	- 0 <= ai, bi < n
	- ai != bi
	- All pairs in richer are unique and logically consistent.

{{< dots >}}
### Output Specifications 📤
- **Output:** Return an array `answer` where each `answer[x]` represents the person with the least quietness among all people who have equal or more money than person `x`.
- **Example:** `Output: [3, 3, 2, 3]`
- **Constraints:**
	- The array `answer` must be of the same length as the input `quiet` array.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to determine, for each person, the least quiet person who is either richer or equally rich.

- Step 1: Build a graph of richer relationships, where each person points to those they are richer than.
- Step 2: Use Depth First Search (DFS) to find the least quiet person among all people who have more money or are equally rich as the current person.
- Step 3: Fill the result array with the index of the quietest person for each person in the group.
{{< dots >}}
### Problem Assumptions ✅
- All relationships in `richer` are logically consistent.
- The input arrays `quiet` contain unique quietness values.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: richer = [[2, 1], [3, 0], [4, 2]], quiet = [2, 3, 1, 0]`  \
  **Explanation:** Here, person 0 is richer than 1, person 1 is richer than 2, and person 2 is richer than 3. By following the richer relationships and quietness values, we determine that for each person, the person with the least quietness among those richer or equally rich is as follows: [3, 3, 2, 3].

- **Input:** `Input: richer = [], quiet = [0]`  \
  **Explanation:** In this case, there is only one person. Since there are no richer relationships, the only answer is person 0 themselves. The output is [0].

{{< dots >}}
## Approach 🚀
The solution leverages a depth-first search (DFS) approach to explore the richer relationships and determine the quietest person who is richer or equally rich.

### Initial Thoughts 💭
- We need to efficiently search for the quietest person who is richer or equally rich.
- Using DFS will allow us to traverse the graph of relationships and propagate the quietest person for each person based on their richer relationships.
{{< dots >}}
### Edge Cases 🌐
- When there are no richer relationships, each person is only compared to themselves.
- Ensure the solution handles the case where `n` is large (up to 500) and all possible richer relationships are included.
- If a person is the richest (or tied for the richest), their answer will be themselves.
- The function must handle cases where no richer relationships exist.
{{< dots >}}
## Code 💻
```cpp
unordered_map<int, vector<int>> richer2;
vector<int> res;
vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
    for(auto v: richer) richer2[v[1]].push_back(v[0]);
    res = vector<int> (quiet.size(), -1);
    for(int i = 0; i < quiet.size(); i++) dfs(i, quiet);
    return res;
}

int dfs(int i, vector<int> &quiet) {
    if(res[i] >= 0) return res[i];
    res[i] = i;
    for(int j : richer2[i])
        if(quiet[res[i]] > quiet[dfs(j, quiet)]) res[i] = res[j];
    return res[i];
}
```

This function `loudAndRich` determines the richest and least quiet person for each individual in the `quiet` array, based on the relationships in the `richer` matrix. The helper function `dfs` is used to perform a depth-first search and update the result.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Variable Initialization**
	```cpp
	unordered_map<int, vector<int>> richer2;
	```
	Declare a hash map `richer2` to store relationships of richer individuals for each person.

2. **Variable Initialization**
	```cpp
	vector<int> res;
	```
	Declare a vector `res` to store the final results for each person.

3. **Function Declaration**
	```cpp
	vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
	```
	Declare the function `loudAndRich`, which accepts the `richer` matrix and `quiet` vector to determine the least quiet richest person for each individual.

4. **Populate Richer Relationships**
	```cpp
	    for(auto v: richer) richer2[v[1]].push_back(v[0]);
	```
	Populate the `richer2` map where for each person, the list of people they are richer than is stored.

5. **Initialize Result Vector**
	```cpp
	    res = vector<int> (quiet.size(), -1);
	```
	Initialize the `res` vector with the same size as the `quiet` vector, filled with -1.

6. **Iterate Over Quiet Array**
	```cpp
	    for(int i = 0; i < quiet.size(); i++) dfs(i, quiet);
	```
	Iterate through each person in the `quiet` array and call the `dfs` function to calculate the least quiet richest person for each.

7. **Return Result**
	```cpp
	    return res;
	```
	Return the populated `res` vector containing the answers for each individual.

8. **Helper Function Declaration**
	```cpp
	int dfs(int i, vector<int> &quiet) {
	```
	Declare the helper function `dfs`, which performs a depth-first search to find the quietest and richest individual for person `i`.

9. **Base Case Check**
	```cpp
	    if(res[i] >= 0) return res[i];
	```
	Check if the result for person `i` has already been calculated. If so, return the result.

10. **Initialize Current Person**
	```cpp
	    res[i] = i;
	```
	Initially, assume that the least quiet richest person for `i` is themselves.

11. **Depth-First Search**
	```cpp
	    for(int j : richer2[i])
	```
	For each person `j` who is richer than `i`, perform a depth-first search to find their least quiet richest person.

12. **Update Result**
	```cpp
	        if(quiet[res[i]] > quiet[dfs(j, quiet)]) res[i] = res[j];
	```
	If the quietness of the current person is greater than the quietness of the person found through DFS, update the result to the quieter person.

13. **Return Result**
	```cpp
	    return res[i];
	```
	Return the result for person `i`.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n + r)
- **Worst Case:** O(n + r)

The time complexity is O(n + r), where `n` is the number of people and `r` is the number of richer relationships. Each person is processed once, and we perform a DFS to explore all relationships.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n + r)

The space complexity is O(n + r), which accounts for the graph of richer relationships and the storage for the result array.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/loud-and-rich/description/)

---

| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
