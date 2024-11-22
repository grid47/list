
+++
authors = ["grid47"]
title = "Leetcode 2335: Minimum Amount of Time to Fill Cups"
date = "2024-03-18"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2335: Minimum Amount of Time to Fill Cups in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Greedy","Sorting","Heap (Priority Queue)"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "jcfxf8gjVbE"
youtube_upload_date="2022-07-10"
youtube_thumbnail="https://i.ytimg.com/vi/jcfxf8gjVbE/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int fillCups(vector<int>& A) {
        int mx = 0, sum = 0;
        for(int& a: A) {
            mx = max(a, mx);
            sum += a;
        }
        return max(mx, (sum + 1) / 2);
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to determine the minimum number of moves required to fill a set of cups, where each cup has a certain number of liters to be filled. In each move, we can take one unit of water from two cups (if possible) and transfer it to the third. The goal is to compute the minimum number of moves to completely fill all cups, ensuring that we achieve the necessary volume in the fewest steps.

Given an array `A` representing the amount of water needed in each cup, we need to return the minimum number of moves required to fill all the cups. The number of moves is optimized by distributing the water between the cups efficiently.

### Approach

The task involves efficiently distributing the water between the three cups so that the maximum volume in any cup after all operations is minimized. To solve this, we need to take into account both the largest volume in a cup and the sum of all the volumes in the cups.

#### Key Insight:
- The minimum number of moves required to fill all cups is determined by two factors:
  1. The largest amount of water needed in any cup.
  2. The total amount of water distributed across all cups.
  
Since in each move, at most 2 liters of water can be moved (one unit from each of two cups), the minimum number of moves can be derived by looking at:
- The largest cup's current water requirement, which directly influences how many moves are required.
- The total amount of water in all cups, divided by 2, since we are transferring two units of water per move at most.

The answer is the larger value between:
- The maximum water needed in a single cup.
- The total water distributed across all cups, halved (because two cups can contribute to one move).

### Code Breakdown (Step by Step)

Let's break down the code to understand how the solution is implemented.

#### Step 1: Initializing Variables

```cpp
int mx = 0, sum = 0;
for(int& a: A) {
    mx = max(a, mx);
    sum += a;
}
```

- **mx**: This variable keeps track of the maximum water required by any single cup.
- **sum**: This variable holds the total amount of water across all cups.
- The loop iterates over the input array `A`, and for each element `a` (representing the water in a cup), we update `mx` to the larger of the current value of `mx` and `a`. We also accumulate the total amount of water (`sum`).

#### Step 2: Calculating Minimum Moves

```cpp
return max(mx, (sum + 1) / 2);
```

After calculating the `mx` and `sum`:
- **mx** is the maximum water in any single cup.
- **sum + 1 / 2** computes the ceiling value of half of the total water, ensuring that even if there's an odd number of units, the result is rounded up.
  
The `max()` function returns the greater of:
1. **mx**: The minimum number of moves required is at least as many as the largest volume in any cup, since we can only transfer at most 1 liter per cup in each move.
2. **(sum + 1) / 2**: This ensures that the total water is distributed efficiently across all cups. If the total amount of water is more than twice the size of the largest cup, we need at least that many moves.

Thus, the result is the maximum of these two values, as we need at least this many moves to either distribute the water or reduce the largest volume.

### Complexity

#### Time Complexity:
- **O(n)**: The time complexity is linear, where `n` is the size of the input array `A`. This is because we loop over the array once to compute the total sum and maximum value (`mx`). Each operation within the loop is constant time, making the overall complexity linear.

#### Space Complexity:
- **O(1)**: The space complexity is constant because we only use a few variables (`mx` and `sum`) to keep track of intermediate results, irrespective of the size of the input array.

### Conclusion

The problem of filling the cups in the minimum number of moves is solved optimally by considering two factors: 
1. The largest amount of water in any cup, which sets a lower bound on the number of moves.
2. The total water across all cups, divided by two, which accounts for the efficiency of moving water.

This approach ensures that we minimize the number of moves by balancing between the largest cup and the total amount of water in the system. The algorithm runs in linear time and uses constant space, making it efficient even for large inputs.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-amount-of-time-to-fill-cups/description/)

---
{{< youtube jcfxf8gjVbE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
