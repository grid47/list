
+++
authors = ["grid47"]
title = "Leetcode 2155: All Divisions With the Highest Score of a Binary Array"
date = "2024-04-05"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2155: All Divisions With the Highest Score of a Binary Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "jAn_1AC2VMo"
youtube_upload_date="2022-01-30"
youtube_thumbnail="https://i.ytimg.com/vi_webp/jAn_1AC2VMo/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    vector<int> maxScoreIndices(vector<int>& nums) {
        int n = nums.size();
        int ones = 0;
        for(int i = 0; i < n; i++)
        if (nums[i] == 1) ones++;
        
        int mx = ones;
        vector<int> mxx;
        mxx.push_back(0);

        int zeros = 0;
        
        int prv, cur = mx;
        for(int i = 1; i < n + 1; i++) {
            zeros += ((nums[i - 1] == 0)? 1 : 0);
            ones  -= ((nums[i - 1] == 1)? 1 : 0);

            prv = mx;
            cur = zeros + ones;
            mx  = max(mx, cur);

                 if (mx == cur && cur == prv) mxx.push_back(i);
            else if (mx >  prv) {
                mxx.clear();
                mxx.push_back(i);
            }
        }
        
        return mxx;
    }
};
{{< /highlight >}}
---

### Problem Statement
The task is to determine the index positions at which the maximum score can be obtained when splitting an array `nums` into two non-overlapping subarrays. The score at an index `i` is defined as the sum of the number of zeros in the left subarray (`nums[0]` to `nums[i-1]`) and the number of ones in the right subarray (`nums[i]` to `nums[n-1]`). The output should be a list of all such indices where the score is maximized.

### Approach
The solution uses a combination of prefix and suffix counting to efficiently find the optimal split points. The key idea is to traverse the array while maintaining counts of zeros on the left and ones on the right, computing the score at each split index.

### Code Breakdown (Step by Step)
1. **Initial Count of Total Ones:**
   ```cpp
   int ones = 0;
   for(int i = 0; i < n; i++)
       if (nums[i] == 1) ones++;
   ```
   - The total number of `1`s in the array is counted and stored in the variable `ones`. This helps calculate the number of `1`s in the right subarray as we iterate through the array.

2. **Initialization of Maximum Score and Result Vector:**
   ```cpp
   int mx = ones;
   vector<int> mxx;
   mxx.push_back(0);
   ```
   - `mx` is initialized to the score at index `0`, which only considers all `1`s in the right subarray.
   - `mxx` is initialized to store the index `0` as the starting maximum score position.

3. **Traverse Array to Calculate Scores at Each Split Index:**
   ```cpp
   int zeros = 0;
   int prv, cur = mx;
   for(int i = 1; i < n + 1; i++) {
       zeros += ((nums[i - 1] == 0) ? 1 : 0);
       ones  -= ((nums[i - 1] == 1) ? 1 : 0);

       prv = mx;
       cur = zeros + ones;
       mx  = max(mx, cur);

       if (mx == cur && cur == prv) mxx.push_back(i);
       else if (mx > prv) {
           mxx.clear();
           mxx.push_back(i);
       }
   }
   ```
   - As we iterate through the array from `1` to `n`, we update `zeros` (count of zeros on the left) and decrement `ones` (count of ones on the right).
   - The score at each index `i` is calculated as `cur = zeros + ones`.
   - If the current score `cur` equals `mx`, it implies that the score is maintained, so we add the index `i` to `mxx`.
   - If `cur` becomes greater than `mx`, a new maximum score is found, so `mxx` is cleared, and `i` is added as the new split point.

4. **Return the Result Vector:**
   ```cpp
   return mxx;
   ```
   - The function returns the vector `mxx` containing all indices where the maximum score is achieved.

### Complexity
- **Time Complexity**:
  - The solution runs in O(n) time, where `n` is the size of `nums`. The traversal of `nums` for counting ones and the single pass for finding the maximum score ensure linear time complexity.
- **Space Complexity**:
  - The space complexity is O(1) for auxiliary variables, while the result vector `mxx` could potentially store up to `n + 1` indices, making it O(n) in the worst case.

### Conclusion
This code provides an efficient approach to solve the problem of finding split indices with the maximum score. The use of prefix and suffix counters ensures the computation is done in a single traversal, leading to an O(n) solution. The logic is simple yet powerful, making it ideal for arrays with up to 10^5 elements. The algorithm's design balances clarity and performance, offering a robust solution for real-world data scenarios where large input sizes are common.

[`Link to LeetCode Lab`](https://leetcode.com/problems/all-divisions-with-the-highest-score-of-a-binary-array/description/)

---
{{< youtube jAn_1AC2VMo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
