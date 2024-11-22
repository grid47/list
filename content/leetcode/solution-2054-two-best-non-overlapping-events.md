
+++
authors = ["grid47"]
title = "Leetcode 2054: Two Best Non-Overlapping Events"
date = "2024-04-15"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2054: Two Best Non-Overlapping Events in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Dynamic Programming","Sorting","Heap (Priority Queue)"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "eC62DF5PW6E"
youtube_upload_date="2021-10-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/eC62DF5PW6E/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    vector<vector<int>> eve;
    vector<vector<unordered_map<int, int>>> memo;
    int n;
    
    int dp(int idx, int end, int k) {
        if(idx >= n || k == 0) return 0;
        
        if(memo[idx][k].count(end)) return memo[idx][k][end];
        
        int ans = dp(idx + 1, end, k);
        
        int l = idx + 1, r = n - 1, res = n;
        
        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            
            if(eve[mid][0] > eve[idx][1]) {
                res = mid;
                r = mid - 1;
            } else l = mid + 1;
            
        }
        
        ans = max(ans, eve[idx][2] + dp(res, eve[idx][1], k - 1));
        
        return memo[idx][k][end] = ans;
    }
    
    int ma(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        eve = events;
        n = eve.size();
        memo.resize(n, vector<unordered_map<int, int>>(3));
        return dp(0, 0, 2);        
    }
    
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        
        int ans = 0, mx = 0;
        map<int, int> mp;
        
        int size = events.size();
        
        while(size--) {
            auto it = mp.upper_bound(events[size][1]);
            mx = max(mx, events[size][2]);
            mp[events[size][0]] = mx;
            if(it == mp.end()) {
                ans = max(ans, mx);
            } else {
                ans = max(ans, events[size][2] + it->second);
            }
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

We are given a set of events, where each event has a start time, end time, and value. Our task is to select up to two non-overlapping events that maximize the total value obtained by attending them. Each event is represented as `[startTime, endTime, value]`.

### Approach

The solution leverages two approaches to maximize the value of attending up to two events:
1. **Dynamic Programming with Binary Search**: For more complex cases, this approach recursively computes the best possible value by either including or excluding the current event. A binary search helps find the next non-overlapping event.
2. **Optimized Iterative Approach with a Map**: This approach iterates backward through sorted events, updating the maximum values of events stored in a map to find the highest non-overlapping values efficiently.

### Code Breakdown (Step by Step)

The solution consists of two functions, `ma` and `maxTwoEvents`, each offering different strategies for maximizing the event values.

#### `ma` Function (Dynamic Programming with Binary Search Approach)

1. **Class Variables Setup**: The class has member variables `eve`, `memo`, and `n`:
   - `eve`: Stores the list of events, sorted by start time.
   - `memo`: A 3D vector for memoization, caching results to avoid redundant calculations.
   - `n`: Represents the number of events.

    ```cpp
    vector<vector<int>> eve;
    vector<vector<unordered_map<int, int>>> memo;
    int n;
    ```

2. **Recursive DP with Binary Search** (`dp` function): This function calculates the maximum value for attending up to two non-overlapping events:
   - **Base Case**: If there are no more events or if `k` (remaining events to select) is zero, return 0.
   - **Memoization**: If the result has been computed for the current state, return it from `memo`.
   - **Binary Search**: Using binary search, find the next non-overlapping event. The loop narrows down to the earliest event starting after the current one ends.
   - **Recursive Call**: The `dp` function calls itself for both the scenario where the event is skipped and where it is included.

    ```cpp
    int dp(int idx, int end, int k) {
        if(idx >= n || k == 0) return 0;
        
        if(memo[idx][k].count(end)) return memo[idx][k][end];
        
        int ans = dp(idx + 1, end, k);  // Skip the event
        
        int l = idx + 1, r = n - 1, res = n;
        
        while(l <= r) {
            int mid = l + (r - l + 1) / 2;
            if(eve[mid][0] > eve[idx][1]) {
                res = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        
        ans = max(ans, eve[idx][2] + dp(res, eve[idx][1], k - 1)); // Include the event
        
        return memo[idx][k][end] = ans;
    }
    ```

3. **Main Function `ma`**: This function sets up `eve` with sorted events and calls `dp` with the initial parameters.

    ```cpp
    int ma(vector<vector<int>>& events) {
        sort(events.begin(), events.end());
        eve = events;
        n = eve.size();
        memo.resize(n, vector<unordered_map<int, int>>(3));
        return dp(0, 0, 2);        
    }
    ```

#### `maxTwoEvents` Function (Optimized Iterative Approach)

The `maxTwoEvents` function uses a backward traversal and a map to optimize finding the maximum value of two non-overlapping events.

1. **Sort Events**: Events are sorted by their start times, allowing us to traverse from the last event to the first.

    ```cpp
    sort(events.begin(), events.end());
    ```

2. **Backward Traversal with Map**:
   - **Map Setup**: `mp` is a map that holds the maximum values for events that start after each event’s end time.
   - **Loop through Events**: For each event:
     - Use `upper_bound` to find the earliest starting event after the current event’s end time.
     - Update the result with the maximum of the current result or the sum of the current event’s value and the subsequent non-overlapping event's value.
   - The backward traversal ensures that each event only checks subsequent non-overlapping events, making this process efficient.

    ```cpp
    int ans = 0, mx = 0;
    map<int, int> mp;
    int size = events.size();
        
    while(size--) {
        auto it = mp.upper_bound(events[size][1]);
        mx = max(mx, events[size][2]);
        mp[events[size][0]] = mx;
        if(it == mp.end()) {
            ans = max(ans, mx);
        } else {
            ans = max(ans, events[size][2] + it->second);
        }
    }
    ```

3. **Return Result**: The function returns the maximum possible value for attending up to two non-overlapping events.

    ```cpp
    return ans;
    ```

### Complexity

- **Time Complexity**:
  - `ma`: O(N log N) due to sorting and binary search, plus O(N) for DP recursion.
  - `maxTwoEvents`: O(N log N) for sorting, with each map operation being O(log N).
- **Space Complexity**:
  - `ma`: O(N) for memoization and recursion stack.
  - `maxTwoEvents`: O(N) for the map storing event values.

### Conclusion

This solution provides two efficient methods for maximizing the value of attending up to two non-overlapping events. The first approach uses dynamic programming with memoization, while the second approach uses a map to store the maximum values of future events during a backward traversal. Both approaches optimize time and space to handle large inputs effectively, providing a robust solution to complex event selection problems. This solution is versatile and adaptable to a range of scheduling and value maximization scenarios.

[`Link to LeetCode Lab`](https://leetcode.com/problems/two-best-non-overlapping-events/description/)

---
{{< youtube eC62DF5PW6E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
