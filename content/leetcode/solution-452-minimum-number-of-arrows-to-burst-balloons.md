
+++
authors = ["grid47"]
title = "Leetcode 452: Minimum Number of Arrows to Burst Balloons"
date = "2024-09-22"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 452: Minimum Number of Arrows to Burst Balloons in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/452.webp"
youtube = "lPmkKnvNPrw"
youtube_upload_date="2024-03-18"
youtube_thumbnail="https://i.ytimg.com/vi/lPmkKnvNPrw/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/452.webp" 
    alt="A sequence of balloons gently bursting with each arrow, showing the optimal number of arrows needed."
    caption="Solution to LeetCode 452: Minimum Number of Arrows to Burst Balloons Problem"
    width="900px"
    borderRadius="8px"
    align="center" 
    captionColor="#555"
>}}
---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    static bool cmp(vector<int> &a, vector<int> &b){
        return a[1] < b[1];
    }
    int findMinArrowShots(vector<vector<int>>& pts) {
        sort(pts.begin(), pts.end(), cmp);
        int cnt = 1, arp = pts[0][1];
        for(int i = 1; i < pts.size(); i++) {
            
            if(pts[i][0]<=arp) continue;
            cnt++;
            arp = pts[i][1];
        }
        return cnt;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to determine the minimum number of arrows needed to burst all balloons, where each balloon is represented by an interval `[start, end]`, denoting the horizontal range it occupies. The goal is to find the smallest number of arrows that can be shot such that each balloon is hit by at least one arrow. A balloon is considered hit if the arrow is shot at any point within its range.

### Approach

To solve this problem, we can approach it using a greedy algorithm. The idea is to shoot arrows in such a way that we minimize the number of arrows used. A balloon can be hit by an arrow if the arrow is shot within the balloon's horizontal range. If we shoot an arrow at the right end of one balloon, it may also hit other overlapping balloons. Therefore, by sorting the balloons by their right endpoint, we can decide the optimal arrow placement in an efficient manner.

Here’s the approach broken down step by step:

1. **Sort the Balloons by Their Right Endpoint**: 
   - If we shoot an arrow at the rightmost possible position that can still cover the first balloon, it will potentially cover the maximum number of subsequent balloons. This is because any balloon that starts before or at the position of the current arrow will be hit.
   - Sorting the balloons by their right endpoints ensures that we always aim to shoot the arrow as late as possible, which allows us to hit as many overlapping balloons as possible.

2. **Greedy Arrow Placement**:
   - Start by shooting the first arrow at the right endpoint of the first balloon after sorting.
   - For each subsequent balloon, check if it can be hit by the current arrow (i.e., if the balloon’s start position is less than or equal to the current arrow’s position).
   - If the balloon cannot be hit by the current arrow, shoot a new arrow at the right endpoint of that balloon.

3. **Count the Arrows**:
   - Each time a new arrow is required (i.e., when the current balloon cannot be hit by the last arrow), increase the count of arrows.

### Code Breakdown (Step by Step)

#### Step 1: Sort the Balloons by Their Right Endpoint

```cpp
static bool cmp(vector<int> &a, vector<int> &b) {
    return a[1] < b[1];
}
sort(pts.begin(), pts.end(), cmp);
```

- First, we define a comparison function `cmp`, which compares two balloons (represented by intervals) based on their right endpoint (i.e., `a[1]` and `b[1]`).
- We then sort the `pts` vector of balloon intervals in ascending order based on the right endpoint. This allows us to efficiently select the arrow placement in the next steps.

#### Step 2: Greedy Arrow Placement

```cpp
int cnt = 1, arp = pts[0][1];
for(int i = 1; i < pts.size(); i++) {
    if(pts[i][0] <= arp) continue;
    cnt++;
    arp = pts[i][1];
}
```

- We start by assuming that at least one arrow is needed. Thus, we initialize the count `cnt` to 1 and set `arp` (the position of the last shot arrow) to the right endpoint of the first balloon (`pts[0][1]`).
- We then loop through the remaining balloons (`i = 1` to `pts.size() - 1`).
    - If the start of the current balloon `pts[i][0]` is less than or equal to `arp`, it means this balloon can be hit by the last arrow. Therefore, we continue to the next balloon.
    - If the current balloon cannot be hit by the last arrow (i.e., `pts[i][0] > arp`), we need to shoot a new arrow. We increment the arrow count `cnt` and update the arrow position `arp` to the right endpoint of the current balloon (`pts[i][1]`).

#### Step 3: Return the Result

```cpp
return cnt;
```

- Finally, after looping through all the balloons, we return the count of arrows required to burst all the balloons.

### Complexity

#### Time Complexity:
- **Sorting**: The main time-consuming operation is the sorting of the `pts` vector, which has a time complexity of `O(n log n)`, where `n` is the number of balloons.
- **Iterating Through the Balloons**: The subsequent iteration over the balloons to count the arrows takes linear time, i.e., `O(n)`.
- **Overall Time Complexity**: The overall time complexity is dominated by the sorting step, so the total time complexity is `O(n log n)`.

#### Space Complexity:
- **Space for the Balloons**: The space complexity depends on the input size. We store the `pts` vector of size `n`, so the space complexity is `O(n)`.
- **Auxiliary Space**: We do not use any additional significant space aside from a few integer variables. Thus, the space complexity is `O(1)` for auxiliary space.

### Conclusion

This solution is optimal in terms of time complexity, with an `O(n log n)` time complexity due to sorting, followed by a linear scan of the balloons. The greedy algorithm ensures that we are placing arrows in the most efficient positions, minimizing the number of arrows required to burst all the balloons.

By sorting the intervals based on the right endpoints and shooting arrows at the latest possible positions, we ensure that we maximize the number of balloons hit by each arrow. This approach is both intuitive and efficient for solving the "minimum number of arrows" problem.

In terms of scalability, this solution should work efficiently for large input sizes, as the time complexity is well-suited to handle scenarios where the number of balloons is large. The solution is easy to implement, and the greedy strategy is a well-known and effective approach for interval-based problems like this one.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/)

---
{{< youtube lPmkKnvNPrw >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
