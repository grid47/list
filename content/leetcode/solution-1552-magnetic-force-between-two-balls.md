
+++
authors = ["grid47"]
title = "Leetcode 1552: Magnetic Force Between Two Balls"
date = "2024-06-04"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1552: Magnetic Force Between Two Balls in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "uixgQ1tejRs"
youtube_upload_date="2020-08-17"
youtube_thumbnail="https://i.ytimg.com/vi_webp/uixgQ1tejRs/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(), pos.end());
        int n = pos.size();
        int l = 0;
        int r = pos[n - 1]-pos[0];
        while(l < r) {
            int mid = r - (r - l) / 2;
            if(isValid(pos, mid, m)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        return l;
    }
    bool isValid(vector<int> &nums, int mid, int cnt) {
        int res = 1, cur = nums[0];
        for(int i = 1; i < nums.size(); i ++) {
            if(nums[i] - cur >= mid) {
                res++;
                cur = nums[i];
            }
        }
        return res >= cnt;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to maximize the minimum distance between `m` cows that are to be placed in a series of positions represented by a vector of integers. Given a sorted list of positions, the goal is to find the largest possible minimum distance between any two cows placed in those positions.

### Approach

To solve this problem, we can employ a binary search strategy combined with a greedy approach. The primary idea is to search for the maximum distance while checking for the feasibility of placing cows with that distance apart.

1. **Sorting Positions**: Begin by sorting the positions of the cows. This helps in easily calculating the distance between cows as we can iterate through the sorted list.

2. **Binary Search**: Implement binary search on the distance. The search space is defined between `0` (minimum possible distance) and `pos[n - 1] - pos[0]` (the maximum possible distance between the first and last positions).

3. **Greedy Feasibility Check**: For each midpoint distance during the binary search, we use a helper function `isValid` to determine if it is possible to place all `m` cows such that the minimum distance between any two cows is at least `mid`.

### Code Breakdown (Step by Step)

Let's dissect the code into manageable pieces for better understanding:

```cpp
class Solution {
public:
    int maxDistance(vector<int>& pos, int m) {
        sort(pos.begin(), pos.end()); // Step 1: Sort the positions
        int n = pos.size(); // Step 2: Get the number of positions
        int l = 0; // Step 3: Initialize the left boundary of the search space
        int r = pos[n - 1] - pos[0]; // Step 4: Initialize the right boundary of the search space
        
        while(l < r) { // Step 5: Begin binary search
            int mid = r - (r - l) / 2; // Step 6: Calculate mid point
            if(isValid(pos, mid, m)) { // Step 7: Check if placing cows with distance mid is valid
                l = mid; // Step 8: If valid, move left boundary to mid
            } else {
                r = mid - 1; // Step 9: If not valid, move right boundary to mid - 1
            }
        }
        return l; // Step 10: Return the maximum valid distance
    }
```

#### Function `isValid`

This function checks if it's possible to place the cows with at least `mid` distance apart:

```cpp
    bool isValid(vector<int> &nums, int mid, int cnt) {
        int res = 1; // Step 1: Start with one cow placed at the first position
        int cur = nums[0]; // Step 2: Current position of the last placed cow
        
        for(int i = 1; i < nums.size(); i++) { // Step 3: Iterate through the positions
            if(nums[i] - cur >= mid) { // Step 4: Check if the distance is at least mid
                res++; // Step 5: Place another cow
                cur = nums[i]; // Step 6: Update current position
            }
        }
        return res >= cnt; // Step 7: Return true if we can place at least cnt cows
    }
```

### Complexity

#### Time Complexity
- **O(n log d)**: The binary search runs in \(O(\log d)\) time, where \(d\) is the maximum distance, and for each distance check, we may iterate through the list of positions in \(O(n)\). Thus, the total time complexity becomes \(O(n \log d)\).

#### Space Complexity
- **O(1)**: The algorithm only uses a fixed amount of space for variables, and the input positions array is modified in place. Therefore, the space complexity is \(O(1)\).

### Conclusion

The `maxDistance` function provides an efficient way to solve the problem of maximizing the minimum distance between cows placed at given positions. By leveraging binary search and a greedy approach, this solution is optimal for larger datasets.

**Key Insights**:
- **Binary Search**: This technique allows for efficiently narrowing down the possible maximum minimum distances by checking feasible placements iteratively.
- **Greedy Algorithm**: The placement of cows is handled in a greedy manner, ensuring that we always try to place the next cow in the first available position that satisfies the distance constraint.
- **Practical Application**: This problem is commonly encountered in scenarios involving resource allocation, scheduling, or spatial arrangement where constraints must be met.

In summary, this solution not only illustrates the power of combining binary search with a greedy algorithm but also highlights the importance of clear problem analysis and strategic thinking in algorithm design.

[`Link to LeetCode Lab`](https://leetcode.com/problems/magnetic-force-between-two-balls/description/)

---
{{< youtube uixgQ1tejRs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
