
+++
authors = ["grid47"]
title = "Leetcode 2511: Maximum Enemy Forts That Can Be Captured"
date = "2024-02-29"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2511: Maximum Enemy Forts That Can Be Captured in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers"]
categories = [
    "Easy"
]
series = ["Leetcode"]
img_src = ""
youtube = "y7BwYY4UFak"
youtube_upload_date="2022-12-24"
youtube_thumbnail="https://i.ytimg.com/vi_webp/y7BwYY4UFak/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
int captureForts(vector<int>& forts) {
    int res = 0;
    for (int i = 0, j = 0; i < forts.size(); ++i)
        if (forts[i] != 0) {
            if (forts[j] == -forts[i])
                res = max(res, i - j - 1);
            j = i;
        }
    return res;
}
};
{{< /highlight >}}
---

### Problem Statement

The problem asks us to find the maximum number of forts that can be captured in a sequence of forts. A fort is represented as an array of integers where:

- `1` represents a fort held by one side.
- `-1` represents a fort held by the opposite side.
- `0` represents an empty fort.

Our goal is to calculate the maximum number of forts that can be captured. A fort can be captured if it's located between two forts held by opposing sides (`1` and `-1`). Therefore, for each pair of opposing forts, the forts between them can be captured. We are asked to return the maximum number of forts that can be captured in such pairs.

### Approach

To solve this problem, we need to:
1. Traverse the `forts` array and find positions where a fort is held by one side (either `1` or `-1`).
2. For each such fort, check if there exists an opposing fort on the other side. If such a pair exists, calculate the number of empty forts (`0`s) between them.
3. Track the maximum number of forts that can be captured.

#### Key Observations:
1. A fort held by side `1` can only be captured by a fort held by side `-1` (or vice versa).
2. The forts between any two opposing forts can be captured. Hence, the goal is to maximize the distance between two opposing forts.
3. We only need to compute this for each pair of opposing forts as we traverse through the array.

The solution follows these steps:
1. Traverse through the array from left to right.
2. Keep track of the most recent fort held by either side (`1` or `-1`).
3. Whenever we encounter an opposing fort, calculate how many forts lie between them.
4. Update the maximum result.

### Code Breakdown (Step by Step)

The code is broken down into two main sections:

1. **Initialization**:
   - We initialize a variable `res` to store the result. This will keep track of the maximum number of forts that can be captured.
   - We also initialize a variable `j` to keep track of the index of the last encountered fort that was held by either `1` or `-1`.

2. **Iterating through the `forts` array**:
   - The loop runs through each fort in the array. For each fort, if it's not empty (`forts[i] != 0`), we check if it's held by one side and the previous fort was held by the opposing side.
   - If the fort held by `forts[j]` is the opposite of `forts[i]` (i.e., `forts[j] == -forts[i]`), we calculate how many forts lie between `j` and `i` by using the formula `i - j - 1`. This gives the number of `0`s between these two forts.
   - We then update `res` to be the maximum of `res` and the calculated number of forts between the two opposing forts.
   - Finally, we set `j = i`, meaning the current fort now becomes the last encountered fort for the next iteration.

3. **Return Result**:
   - After completing the loop, we return `res`, which contains the maximum number of forts that can be captured between two opposing forts.

### Code Implementation

```cpp
class Solution {
public:
    int captureForts(vector<int>& forts) {
        int res = 0;
        for (int i = 0, j = 0; i < forts.size(); ++i)
            if (forts[i] != 0) {
                if (forts[j] == -forts[i])
                    res = max(res, i - j - 1);
                j = i;
            }
        return res;
    }
};
```

### Detailed Explanation

- **Line 1**: The function `captureForts` is defined, which accepts a vector of integers `forts`.
  
- **Line 2**: We initialize `res` to zero, which will keep track of the maximum number of forts that can be captured.

- **Line 3**: We start a `for` loop with two variables:
  - `i` is the current index that we are iterating over in the `forts` array.
  - `j` is the index of the most recent non-empty fort we encountered (i.e., `forts[j]` is either `1` or `-1`).

- **Line 4-7**: Inside the loop, we check if `forts[i]` is not zero, meaning we've encountered a fort (either `1` or `-1`).
  - If `forts[j] == -forts[i]`, meaning `forts[i]` and `forts[j]` are opposing forts, we compute the number of forts between them by calculating `i - j - 1`.
  - We update `res` to be the maximum of the current `res` and the number of forts between `j` and `i`.

- **Line 8**: After processing `forts[i]`, we set `j = i`, so that the current fort becomes the new reference fort for the next iteration.

- **Line 9**: Finally, after completing the loop, we return `res` as the maximum number of forts that can be captured.

### Example Walkthrough

Let’s walk through an example to see how this works:

For the input:
```cpp
forts = {0, 1, 0, -1, 0, 0, 1, 0, -1}
```

1. Start with `i = 0` and `j = 0`. `forts[i] == 0`, so we skip.
2. At `i = 1`, `forts[i] = 1`, so `j = 1`. No result yet, continue.
3. At `i = 2`, `forts[i] == 0`, so we skip.
4. At `i = 3`, `forts[i] = -1`. Now, `forts[j] = 1` and `forts[i] = -1`. We compute the number of forts between `j` and `i`, which is `3 - 1 - 1 = 1`. Thus, `res = 1`.
5. Continue iterating through the array. At `i = 8`, `forts[i] = -1`, and `forts[j] = 1` again. Compute the number of forts between them, which is `8 - 6 - 1 = 1`.

Thus, the maximum number of forts that can be captured is `2`.

### Complexity Analysis

#### Time Complexity:
- We traverse the `forts` array once, so the time complexity is \(O(n)\), where `n` is the length of the `forts` array.

#### Space Complexity:
- The space complexity is \(O(1)\), as we only use a few integer variables (`res` and `j`) for computation, and the space used does not grow with the size of `n`.

### Conclusion

The solution efficiently solves the problem by iterating through the `forts` array once, checking for pairs of opposing forts, and calculating the number of forts between them. By maintaining a reference to the most recent fort, the algorithm avoids unnecessary recalculations and performs the task optimally.

- **Time Complexity**: \(O(n)\)
- **Space Complexity**: \(O(1)\)

This approach ensures that we can quickly and effectively find the maximum number of forts that can be captured in a sequence of forts.

[`Link to LeetCode Lab`](https://leetcode.com/problems/maximum-enemy-forts-that-can-be-captured/description/)

---
{{< youtube y7BwYY4UFak >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
