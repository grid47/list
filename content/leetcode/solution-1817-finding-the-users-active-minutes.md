
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
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
        unordered_map<int, unordered_set<int>> m;
        vector<int> res(k);
        for(auto &l : logs) 
        m[l[0]].insert(l[1]);
        for(auto &p: m)
        ++res[p.second.size() - 1];
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires us to determine the number of users who have a specific number of active minutes in a given set of logs. Each log entry contains two pieces of information: a user ID and a timestamp representing the minute the user was active. The goal is to compute how many users had exactly `i` active minutes for each minute from 1 to `k`, where `k` is the maximum number of active minutes we are interested in.

### Approach

To solve this problem, we will use the following approach:

1. **Data Structure**: We will utilize a hash map to store user activity. Each user ID will map to a set of unique minutes they were active in. This will allow us to easily count the unique active minutes for each user.

2. **Process Logs**: For each log entry, we will insert the timestamp (minute) into the user's corresponding set in the hash map. This ensures that we only count unique active minutes.

3. **Count Active Minutes**: Once we have processed all logs, we will iterate over the hash map to count how many users have `i` active minutes, for all `i` from 1 to `k`.

4. **Prepare the Result**: Finally, we will create a result vector to store the count of users for each number of active minutes.

### Code Breakdown (Step by Step)

Here’s a detailed breakdown of the code implementation:

```cpp
class Solution {
public:
```
- We define a class named `Solution` to encapsulate the function that will solve our problem.

```cpp
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& logs, int k) {
```
- The method `findingUsersActiveMinutes` takes two parameters: a vector of log entries (`logs`), where each entry is itself a vector containing a user ID and a timestamp, and an integer `k`, which indicates the maximum number of active minutes we are interested in.

```cpp
        unordered_map<int, unordered_set<int>> m;
```
- We declare a hash map `m`, where each key is an integer representing a user ID, and each value is an unordered set of integers representing the unique minutes that user was active. The unordered set is used to automatically handle duplicates.

```cpp
        vector<int> res(k);
```
- We initialize a result vector `res` of size `k` to zero. This vector will hold the count of users who have exactly `i` active minutes, with `i` ranging from 1 to `k`.

```cpp
        for(auto &l : logs) 
            m[l[0]].insert(l[1]);
```
- We iterate over each log entry `l` in `logs`. For each log, we extract the user ID `l[0]` and the active minute `l[1]`, and we insert the minute into the unordered set corresponding to that user ID in our hash map `m`. This way, we ensure that each user ID only keeps track of unique active minutes.

```cpp
        for(auto &p: m)
            ++res[p.second.size() - 1];
```
- We iterate over each entry `p` in the hash map `m`. For each user, we check the size of their set of active minutes (`p.second.size()`), which gives us the count of unique active minutes for that user. We increment the corresponding index in the result vector `res` by one. Since `res` is zero-indexed and counts from 1 to `k`, we subtract 1 from the size to place the count in the correct position.

```cpp
        return res;
    }
};
```
- Finally, we return the result vector `res`, which contains the counts of users with exactly `i` active minutes.

### Complexity

- **Time Complexity**: The time complexity of this solution is \(O(n)\), where \(n\) is the number of log entries. This is because we process each log entry once to populate the hash map.

- **Space Complexity**: The space complexity is \(O(m)\), where \(m\) is the number of unique users times the average number of unique active minutes per user. This is due to storing active minutes in the unordered set for each user.

### Conclusion

The `findingUsersActiveMinutes` function effectively counts the number of users based on their unique active minutes in a structured and efficient manner. By utilizing a hash map and unordered sets, we ensure that our solution remains efficient and straightforward, allowing for easy handling of duplicates and quick lookups.

This implementation demonstrates the power of hash maps and sets in managing and counting unique data in programming. It provides a solid foundation for tackling similar problems involving user activity tracking, logging systems, and statistical analyses of user engagement.

In conclusion, this solution not only meets the problem's requirements but also showcases good practices in algorithm design, such as using appropriate data structures and maintaining clarity in the code. This makes it an excellent reference for anyone looking to understand how to manage user activity data efficiently.

[`Link to LeetCode Lab`](https://leetcode.com/problems/finding-the-users-active-minutes/description/)

---
{{< youtube pE6qW1KRl4A >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
