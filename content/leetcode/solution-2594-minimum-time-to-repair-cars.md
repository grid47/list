
+++
authors = ["grid47"]
title = "Leetcode 2594: Minimum Time to Repair Cars"
date = "2024-02-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2594: Minimum Time to Repair Cars in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "yZ1o7WcAwxI"
youtube_upload_date="2023-03-18"
youtube_thumbnail="https://i.ytimg.com/vi_webp/yZ1o7WcAwxI/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    
    bool can(vector<int> &ranks, long long time, int cars) {
        long long cnt = 0;
        if(time == 0) return false;
        for(int i = 0; i < ranks.size(); i++) {
            cnt += (long long) sqrt(time/ranks[i]);
            
            if(cnt >= cars) return true;
        }
        
        return cnt >= cars;
    }
    
    long long repairCars(vector<int>& ranks, int cars) {
        sort(ranks.begin(), ranks.end());
        int mx = ranks[ranks.size() - 1];
        long long l = 0, r = LLONG_MAX - 100;
        long long ans = r;
        while(l <= r) {
            long long mid = l + (r - l + 1) / 2;
            if(can(ranks, mid, cars)) {
                ans= mid;
                r = mid - 1;
            } else l = mid + 1;
        }
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

Given an array of integers `ranks` representing the efficiency of workers (or mechanics), and an integer `cars` representing the number of cars to repair, the task is to find the minimum time required to repair all `cars`. Each worker can repair a car in a certain amount of time determined by their rank. The time for a worker to repair a car is inversely proportional to their rank (i.e., workers with smaller ranks are faster). The goal is to determine the minimum time required such that all cars can be repaired.

### Approach

1. **Binary Search on Time**: 
   The problem requires us to minimize the repair time. This suggests we can use a binary search on the "time" variable to efficiently find the minimum time that allows all cars to be repaired. The idea is to search for the smallest time `t` such that the total number of cars repaired by all workers at time `t` is at least `cars`.

2. **Determine Feasibility for a Given Time**:
   For each time value `t` during the binary search, we need to check how many cars can be repaired by all workers. The number of cars repaired by a worker with rank `r` at time `t` is given by \( \text{floor}(\sqrt{t / r}) \). We sum this over all workers to get the total number of cars repaired. If this number is greater than or equal to `cars`, then the time `t` is feasible.

3. **Binary Search Implementation**:
   - The lower bound (`l`) starts at 0, representing the case where no time has passed, and no cars are repaired.
   - The upper bound (`r`) is set to a very large value (approximated by `LLONG_MAX - 100`), representing the worst-case scenario.
   - Using binary search, we check the middle time value `mid` and use the helper function `can()` to determine if it's possible to repair all cars within that time. If it's possible, we try to reduce the time; otherwise, we increase the time.

4. **Efficiency Considerations**:
   The binary search is efficient because it reduces the search space logarithmically, and each check of whether the cars can be repaired in a given time takes linear time (i.e., checking each worker’s contribution).

### Code Breakdown (Step by Step)

#### 1. **Helper Function (`can()`)**:
   ```cpp
   bool can(vector<int> &ranks, long long time, int cars) {
       long long cnt = 0;
       if(time == 0) return false;
       for(int i = 0; i < ranks.size(); i++) {
           cnt += (long long) sqrt(time / ranks[i]);
           if(cnt >= cars) return true;
       }
       return cnt >= cars;
   }
   ```
   - This function checks whether it's possible to repair at least `cars` cars in `time` units.
   - **`sqrt(time / ranks[i])`**: For each worker with rank `ranks[i]`, the number of cars they can repair in `time` is determined by how many full repair cycles they can complete. The time to repair a car is inversely proportional to the worker's rank, and this is represented by the square root of `time / ranks[i]`.
   - We sum up the number of cars repaired by each worker, and if the total count exceeds or equals `cars`, we return `true`. Otherwise, we return `false`.

#### 2. **Binary Search to Find Minimum Time**:
   ```cpp
   long long repairCars(vector<int>& ranks, int cars) {
       sort(ranks.begin(), ranks.end());
       int mx = ranks[ranks.size() - 1];
       long long l = 0, r = LLONG_MAX - 100;
       long long ans = r;
       while(l <= r) {
           long long mid = l + (r - l + 1) / 2;
           if(can(ranks, mid, cars)) {
               ans = mid;
               r = mid - 1;
           } else l = mid + 1;
       }
       return ans;
   }
   ```
   - **Sorting the `ranks` array**: We sort the array of ranks to make it easier to calculate the repair capability of each worker efficiently.
   - **Binary Search Setup**: We set `l = 0` and `r = LLONG_MAX - 100`. This range is chosen because `LLONG_MAX` is the largest possible value for a `long long` type, and we adjust it slightly to avoid overflow.
   - **Binary Search Loop**: The while loop runs as long as `l <= r`. In each iteration, we calculate the middle point `mid = l + (r - l + 1) / 2` to check if it's possible to repair all cars in `mid` time units.
     - If it's possible (i.e., `can(ranks, mid, cars)` returns `true`), we update the answer (`ans = mid`) and try to find a smaller feasible time by setting `r = mid - 1`.
     - If it's not possible, we try to increase the time by setting `l = mid + 1`.

#### 3. **Return the Result**:
   ```cpp
   return ans;
   ```
   After the binary search loop completes, `ans` holds the minimum time required to repair all cars, and we return it as the final result.

### Complexity Analysis

- **Time Complexity**: 
  - Sorting the `ranks` array takes \(O(n \log n)\), where \(n\) is the number of workers (size of `ranks`).
  - The binary search operates on the time range, which has a logarithmic complexity. The number of iterations in the binary search is \(O(\log T)\), where \(T\) is the upper bound for time (`LLONG_MAX - 100`).
  - Inside each binary search iteration, the `can()` function performs a linear scan of the `ranks` array to compute the total number of cars repaired, which takes \(O(n)\).
  - Therefore, the overall time complexity is \(O(n \log n + n \log T)\), where \(n\) is the number of workers and \(T\) is the range of time.

- **Space Complexity**: 
  The space complexity is \(O(n)\) due to the space required for the `ranks` array and the operations performed in the binary search. There are no additional data structures used that grow with input size, so space complexity remains linear.

### Conclusion

This solution efficiently finds the minimum time to repair all cars by leveraging binary search and calculating the number of cars that can be repaired within a given time. Sorting the ranks ensures that we can quickly determine how many cars each worker can repair at each point in time. This approach provides a balance between accuracy and efficiency, making it suitable for large input sizes while still yielding correct results in a reasonable amount of time.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-time-to-repair-cars/description/)

---
{{< youtube yZ1o7WcAwxI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
