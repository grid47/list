
+++
authors = ["grid47"]
title = "Leetcode 698: Partition to K Equal Sum Subsets"
date = "2024-08-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 698: Partition to K Equal Sum Subsets in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Dynamic Programming","Backtracking","Bit Manipulation","Memoization","Bitmask"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/698.webp"
youtube = "mBk4I0X46oI"
youtube_upload_date="2021-10-30"
youtube_thumbnail="https://i.ytimg.com/vi/mBk4I0X46oI/maxresdefault.jpg"
+++



[`Problem Link`](https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/)
{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/698.webp" 
    alt="A set of numbers where they are partitioned into equal sum subsets, with each valid partition softly glowing."
    caption="Solution to LeetCode 698: Partition to K Equal Sum Subsets Problem"
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
        bool canPartitionKSubsets(vector<int>& nums, int K) {
        int N = nums.size();
        if (K == 1) return true;
        if (N < K) return false;
        int sum = 0;
        for (int i = 0; i < N; i++) sum += nums[i];
        if (sum % K != 0) return false;

        int subset = sum / K;
        int subsetSum[K];
        bool taken[N];

        for (int i = 0; i < K; i++) subsetSum[i] = 0;
        for (int i = 0; i < N; i++) taken[i] = false;

        subsetSum[0] = nums[N - 1];
        taken[N - 1] = true;

        return canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, 0, N - 1);
    }

    bool canPartitionKSubsets(vector<int>& nums, int subsetSum[], bool taken[], int subset, int K, int N, int curIdx, int limitIdx) {
        if (subsetSum[curIdx] == subset) {
            if (curIdx == K - 2) return true;
            return canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, curIdx + 1, N - 1);
        }

        for (int i = limitIdx; i >= 0; i--) {
            if (taken[i]) continue;
            int tmp = subsetSum[curIdx] + nums[i];

            if (tmp <= subset) {
                taken[i] = true;
                subsetSum[curIdx] += nums[i];
                bool nxt = canPartitionKSubsets(nums, subsetSum, taken, subset, K, N, curIdx, i - 1);
                taken[i] = false;
                subsetSum[curIdx] -= nums[i];
                if (nxt) return true;
            }
        }
        return false;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/698.md" >}}
---
{{< youtube mBk4I0X46oI >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) / Next : [LeetCode #703: Kth Largest Element in a Stream](https://grid47.xyz/leetcode/solution-703-kth-largest-element-in-a-stream/) |
| --- |