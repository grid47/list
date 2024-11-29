
+++
authors = ["grid47"]
title = "Leetcode 1817: Finding the Users Active Minutes"
date = "2024-05-09"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1817: Finding the Users Active Minutes in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "pE6qW1KRl4A"
youtube_upload_date="2021-04-04"
youtube_thumbnail="https://i.ytimg.com/vi_webp/pE6qW1KRl4A/maxresdefault.webp"
comments = true
+++



---
Given the logs of users' actions on a platform, calculate the number of users with each possible User Active Minutes (UAM) from 1 to k.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of a 2D array where each log entry is a pair of [ID, time], and an integer k.
- **Example:** `logs = [[0, 3], [1, 1], [0, 1], [0, 3], [1, 2]], k = 3`
- **Constraints:**
	- 1 <= logs.length <= 10^4
	- 0 <= IDi <= 10^9
	- 1 <= timei <= 10^5
	- k is in the range [1, 100000].

{{< dots >}}
### Output Specifications 📤
- **Output:** Return a 1-indexed array where each index j corresponds to the number of users with exactly j User Active Minutes (UAM).
- **Example:** `Output: [0, 2, 0]`
- **Constraints:**
	- The output array should have length k.

{{< dots >}}
### Core Logic 🔍
**Goal:** Count the number of users who have UAM equal to each value from 1 to k.

- Use a hashmap to track unique action times for each user.
- Calculate the UAM for each user (the size of the unique action times).
- Count the occurrences of each UAM and store them in the result array.
{{< dots >}}
### Problem Assumptions ✅
- The logs will contain valid user IDs and times within the given ranges.
- Multiple actions at the same minute by the same user are counted as a single active minute.
{{< dots >}}
## Examples 🧩
- **Input:** `logs = [[0, 3], [1, 1], [0, 1], [0, 3], [1, 2]], k = 3`  \
  **Explanation:** User 0 has a UAM of 2, User 1 has a UAM of 2, so the result is [0, 2, 0].

- **Input:** `logs = [[2, 10], [1, 1], [1, 2], [2, 10], [2, 12]], k = 4`  \
  **Explanation:** User 1 has UAM of 2, User 2 has UAM of 2, the result is [1, 1, 0, 1].

{{< dots >}}
## Approach 🚀
We can solve this problem using a hashmap to store the unique action times for each user and then calculate the UAM for each user.

### Initial Thoughts 💭
- We need to process each log entry and track the times when users perform actions.
- The total number of unique minutes for each user is their UAM.
- Once we have the UAM for each user, we can count how many users have a particular UAM.
{{< dots >}}
### Edge Cases 🌐
- If the logs array is empty, the result should be an array of zeros.
- Ensure the solution handles the maximum input size efficiently.
- If all users have the same UAM, the result should reflect this distribution.
- The solution must operate within time limits for input sizes up to the maximum allowed.
{{< dots >}}
## Code 💻
```cpp
vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
    unordered_map<int, unordered_set<int>> m;
    vector<int> res(k);
    for(auto &l : logs) 
    m[l[0]].insert(l[1]);
    for(auto &p: m)
    ++res[p.second.size() - 1];
    return res;
}
```

The function `findingUsersActiveMinutes` takes in a vector of logs, where each log contains a user ID and a minute they were active, and an integer `k`. It returns a vector where the value at index `i` is the number of users who were active exactly `i + 1` distinct minutes.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Function Definition**
	```cpp
	vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
	```
	This is the function definition of `findingUsersActiveMinutes`. It takes a vector of vectors `logs`, where each log contains a user ID and a minute they were active, and an integer `k`. The function will return a vector of integers of size `k`.

2. **Variable Initialization**
	```cpp
	    unordered_map<int, unordered_set<int>> m;
	```
	A hashmap `m` is initialized to store the distinct active minutes for each user. The key is the user ID, and the value is an unordered set of distinct minutes.

3. **Variable Initialization**
	```cpp
	    vector<int> res(k);
	```
	A vector `res` of size `k` is initialized with all elements set to 0. This vector will store the number of users who were active in exactly `i + 1` distinct minutes.

4. **Loop Over Logs**
	```cpp
	    for(auto &l : logs) 
	```
	This loop iterates over each log in the `logs` vector. Each log `l` contains a user ID and an active minute.

5. **Update User Activity**
	```cpp
	    m[l[0]].insert(l[1]);
	```
	For each log, the user's ID `l[0]` is used as the key in the map `m`. The corresponding minute `l[1]` is inserted into the unordered set of distinct active minutes for that user.

6. **Loop Over Map**
	```cpp
	    for(auto &p: m)
	```
	This loop iterates over each key-value pair `p` in the map `m`. Each pair represents a user and the set of distinct minutes they were active.

7. **Update Result**
	```cpp
	    ++res[p.second.size() - 1];
	```
	The size of the set `p.second` represents the number of distinct minutes the user was active. This value is used to increment the appropriate index in the result vector `res`.

8. **Return Statement**
	```cpp
	    return res;
	```
	The function returns the result vector `res`, which contains the number of users who were active in exactly `i + 1` distinct minutes.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(n)
- **Average Case:** O(n)
- **Worst Case:** O(n)

The time complexity is O(n) where n is the number of log entries, as we process each log once.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) for storing the unique action times for each user.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/finding-the-users-active-minutes/description/)

---
{{< youtube pE6qW1KRl4A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
