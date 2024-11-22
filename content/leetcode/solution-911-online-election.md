
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
+++



---
**Code:**

{{< highlight cpp >}}
class TopVotedCandidate {
public:
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
 */
{{< /highlight >}}
---

### Problem Statement

In this problem, we are given two lists: `persons` and `times`. The `persons` list represents the votes cast in favor of each candidate at specific times represented by the `times` list. Each entry `persons[i]` and `times[i]` denotes that candidate `persons[i]` received a vote at time `times[i]`. The goal is to implement a `TopVotedCandidate` class with two main functionalities:

1. **Constructor**: `TopVotedCandidate(vector<int>& persons, vector<int>& times)` - Initializes the class with voting records.
2. **q(int t)** - Returns the person who was leading in votes at time `t`.

### Approach

To solve this problem efficiently, we use a **map** to keep track of the leading candidate at each voting time. A **leader** in this context is the candidate who has received the most votes at any specific time. Given that votes are cast in chronological order, we can build this map once during the initialization and then perform quick lookups in response to queries.

Here's a breakdown of the approach:

1. **Count Votes Using a Hash Map**:
   - We use an `unordered_map` named `cnt` to keep a running count of votes for each candidate.
   - Each time a vote is cast, we update the count for that candidate.
   
2. **Track the Leading Candidate**:
   - After updating the vote count, we check if the current candidate has more or equal votes than the current leader. If so, we update the leader to the current candidate.
   
3. **Store the Leader at Each Time**:
   - We use a `map<int, int> mp` to store the leader at each time in `times`. This map allows us to quickly determine the leader at any queried time `t`.

4. **Binary Search for Efficient Querying**:
   - In the `q(t)` function, we use `upper_bound` on the `mp` map to quickly find the leader at the nearest time ≤ `t`. This operation leverages the binary search capabilities of the `map` and ensures an efficient lookup.

### Code Breakdown (Step by Step)

#### **Constructor**: Building the Leader Map

```cpp
TopVotedCandidate(vector<int>& persons, vector<int>& times) {
    int n = persons.size(), lead = -1;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i++) {
        lead = ++cnt[persons[i]] >= cnt[lead] ? persons[i] : lead;
        mp[times[i]] = lead;
    }
}
```

1. **Initialization**: 
   - We initialize `lead` to `-1` to indicate no current leader.
   - We also initialize `cnt` as an `unordered_map<int, int>` to keep a count of votes for each candidate.

2. **Vote Counting and Leader Tracking**:
   - For each vote, we update the count of the current candidate using `++cnt[persons[i]]`.
   - We compare this candidate’s updated vote count with the current leader's vote count:
     - If the current candidate has an equal or greater count, they become the new leader.
   - We store this leader in `mp[times[i]]`, mapping the time to the current leader.

#### **Query Method**: Finding the Leader at Time `t`

```cpp
int q(int t) {
    return (--mp.upper_bound(t))->second;
}
```

1. **Upper Bound Search**:
   - We use `upper_bound(t)` to locate the smallest key in `mp` that is greater than `t`.
   - We then decrement the iterator to get the last entry that is ≤ `t`.
   
2. **Return the Leader**:
   - The result of `(--mp.upper_bound(t))` is the leader at the most recent time ≤ `t`, stored in `mp[t]`.

### Complexity

#### **Time Complexity**

- **Constructor (`TopVotedCandidate`)**: 
  - **O(n)** for processing each vote, where `n` is the length of `persons`.
  - Each vote requires a constant-time update to `cnt` and a logarithmic-time update to `mp` due to insertion into a `map`.
  
- **Query (`q`)**:
  - **O(log n)** for each query, as `upper_bound` is a logarithmic operation in a `map`.

#### **Space Complexity**

- **O(n)**: We use extra space to store the vote counts in `cnt` and the leader mapping in `mp`, both of which can grow up to size `n`.

### Conclusion

The `TopVotedCandidate` class efficiently tracks the leader at each voting time and can quickly retrieve the leader at any queried time. By using a map and an upper bound search, we optimize both the initialization and query processes to handle large datasets efficiently. This approach provides an effective solution for tracking and querying the leading candidate at any given time based on past voting records.

[`Link to LeetCode Lab`](https://leetcode.com/problems/online-election/description/)

---
{{< youtube 6lmMcTr9gbo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
