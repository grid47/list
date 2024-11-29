
+++
authors = ["grid47"]
title = "Leetcode 911: Online Election"
date = "2024-08-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 911: Online Election in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","Binary Search","Design"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "6lmMcTr9gbo"
youtube_upload_date="2020-09-01"
youtube_thumbnail="https://i.ytimg.com/vi/6lmMcTr9gbo/maxresdefault.jpg"
comments = true
+++



---
You are given two integer arrays: `persons` and `times`. The `i`-th vote was cast for `persons[i]` at time `times[i]`. For each query at a given time `t`, you need to return the person who was leading the election at time `t`. If there is a tie between candidates, the most recent vote wins.
<!--more-->
{{< dots >}}
### Input Representations 📥
- **Input:** The input consists of an integer array `persons` and an integer array `times`.
- **Example:** `Input: persons = [0, 1, 1, 0, 0, 1, 0], times = [0, 5, 10, 15, 20, 25, 30]`
- **Constraints:**
	- 1 <= persons.length <= 5000
	- times.length == persons.length
	- 0 <= persons[i] < persons.length
	- 0 <= times[i] <= 10^9
	- times is sorted in strictly increasing order
	- times[0] <= t <= 10^9
	- At most 10^4 queries will be made

{{< dots >}}
### Output Specifications 📤
- **Output:** For each query at time `t`, return the person who was leading the election at that time, based on the most recent vote or tie-breaking rules.
- **Example:** `Output: [null, 0, 1, 1, 0, 0, 1]`
- **Constraints:**
	- The output should be the person leading the election at the specified query time.

{{< dots >}}
### Core Logic 🔍
**Goal:** The goal is to track the current leader after each vote and quickly determine the leader at any given query time `t`.

- Iterate through the `persons` array to record the vote counts for each person, and track the leader at each time point.
- For each query, find the most recent time that is less than or equal to the query time `t` and return the person who was leading at that time.
{{< dots >}}
### Problem Assumptions ✅
- The times array is strictly increasing, meaning that each query time will be greater than or equal to the previous query time.
{{< dots >}}
## Examples 🧩
- **Input:** `Input: persons = [0, 1, 1, 0, 0, 1, 0], times = [0, 5, 10, 15, 20, 25, 30]`  \
  **Explanation:** At time 0, person 0 is leading. At time 5, person 1 takes the lead. At time 10, person 1 is still leading. At time 15, person 0 takes the lead again. At time 20, person 0 is leading. At time 25, person 1 is leading. At time 30, person 1 is still leading.

{{< dots >}}
## Approach 🚀
The solution involves recording the votes at each time and tracking the leader as the votes are cast. For each query, we need to efficiently find the leader at the queried time.

### Initial Thoughts 💭
- Each vote is associated with a specific time, and as time progresses, the leader may change.
- We need to efficiently answer multiple queries about the leader at different times.
- We can maintain a record of the leader for each vote time, so that each query can be answered in constant time by looking up the most recent time less than or equal to the query.
{{< dots >}}
### Edge Cases 🌐
- The arrays will never be empty based on the problem constraints.
- The solution needs to handle up to 5000 persons and 10^4 queries efficiently.
- If a query time corresponds to the exact time a vote was cast, the most recent vote will determine the leader.
- The times array is sorted, so the binary search approach is feasible for efficient queries.
{{< dots >}}
## Code 💻
```cpp
map<int, int> mp;
TopVotedCandidate(vector<int>& persons, vector<int>& times) {
    int n = persons.size(), lead = -1;
    unordered_map<int, int> cnt;
    for(int i = 0; i < n; i++) {
        lead = ++cnt[persons[i]] >= cnt[lead]? persons[i] : lead;
        mp[times[i]] = lead;
    }
        
}

int q(int t) {
    return (--mp.upper_bound(t))->second;
}
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
```

This is the implementation of the TopVotedCandidate class that tracks the person with the most votes at any given time and allows querying the current top voted candidate at a specific time.

{{< dots >}}
### Step-by-Step Breakdown 🛠️
1. **Code Declaration**
	```cpp
	map<int, int> mp;
	```
	Declare a map `mp` to store the mapping between times and the leading candidate at those times.

2. **Constructor**
	```cpp
	TopVotedCandidate(vector<int>& persons, vector<int>& times) {
	```
	Constructor for the TopVotedCandidate class, which initializes the votes and times arrays.

3. **Initialization**
	```cpp
	    int n = persons.size(), lead = -1;
	```
	Initialize the number of persons `n` and a variable `lead` to track the current leading candidate, initialized to -1.

4. **Vote Counting**
	```cpp
	    unordered_map<int, int> cnt;
	```
	Declare an unordered map `cnt` to store the count of votes for each candidate.

5. **Vote Update**
	```cpp
	    for(int i = 0; i < n; i++) {
	```
	Iterate over each vote and update the leading candidate.

6. **Lead Calculation**
	```cpp
	        lead = ++cnt[persons[i]] >= cnt[lead]? persons[i] : lead;
	```
	Update the `lead` based on the current vote count of the person at index `i`.

7. **Mapping Vote Times**
	```cpp
	        mp[times[i]] = lead;
	```
	Map the current time `times[i]` to the leading candidate at that time.

8. **Query Function**
	```cpp
	int q(int t) {
	```
	Define the query function `q` that returns the leading candidate at a specific time `t`.

9. **Query Logic**
	```cpp
	    return (--mp.upper_bound(t))->second;
	```
	Use the `upper_bound` method to find the first entry in the map where the time is greater than `t`, and return the corresponding leading candidate.

{{< dots >}}
## Complexity Analysis 📊
### Time Complexity ⏳
- **Best Case:** O(log n) for each query due to binary search
- **Average Case:** O(log n) for each query
- **Worst Case:** O(log n) for each query

The time complexity per query is O(log n) due to the binary search on the times array, where n is the number of votes.

### Space Complexity 💾
- **Best Case:** O(n)
- **Worst Case:** O(n)

The space complexity is O(n) because we store the leader for each vote time.

**Happy Coding! 🎉**


[`Link to LeetCode Lab`](https://leetcode.com/problems/online-election/description/)

---
{{< youtube 6lmMcTr9gbo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
