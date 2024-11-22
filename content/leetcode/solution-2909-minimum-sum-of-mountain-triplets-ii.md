
+++
authors = ["grid47"]
title = "Leetcode 2909: Minimum Sum of Mountain Triplets II"
date = "2024-01-21"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2909: Minimum Sum of Mountain Triplets II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "PU5YZP1-uVA"
youtube_upload_date="2023-10-22"
youtube_thumbnail="https://i.ytimg.com/vi/PU5YZP1-uVA/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimumSum(vector<int>& nums) {
        vector<int> smallestRight(nums.size(), nums.back());
        for(int i = nums.size()-2; i >= 0; i--){
            smallestRight[i] = min(smallestRight[i+1], nums[i]);
        }
        int smallestLeft = nums[0], ans = -1;
        for(int i = 1; i < nums.size(); i++){
            if(smallestLeft < nums[i] && smallestRight[i] < nums[i]){ 
                if(ans == -1) ans =  nums[i] + smallestRight[i] + smallestLeft;
                else ans = min(ans, nums[i] + smallestRight[i] + smallestLeft); 
            }
            smallestLeft = min(smallestLeft, nums[i]);
        }
        return ans;
    }
};
{{< /highlight >}}
---

The problem at hand requires finding the smallest possible sum of three numbers from the given array `nums`, where the conditions for selecting these numbers are that they must form a strictly increasing subsequence. Specifically, we need to find three elements in the array such that the first number is smaller than the second, and the second is smaller than the third. The goal is to minimize the sum of these three numbers.

### Approach

The key idea in solving this problem is to break it down into manageable steps while maintaining the smallest possible values for the subsequence. We can achieve this through dynamic comparisons and optimizations as we iterate through the array. The approach makes use of two arrays:
- **`smallestRight`**: This array helps to track the smallest number encountered to the right of each element in the input array.
- **`smallestLeft`**: This variable keeps track of the smallest number encountered to the left of the current element.

The solution then proceeds by iterating over the array while keeping track of the smallest possible values that can form a strictly increasing subsequence of three numbers.

### Code Breakdown (Step by Step)

#### Step 1: Initialize `smallestRight` Array

```cpp
vector<int> smallestRight(nums.size(), nums.back());
for(int i = nums.size()-2; i >= 0; i--){
    smallestRight[i] = min(smallestRight[i+1], nums[i]);
}
```

- **Objective**: The `smallestRight` array stores, for each element in the array, the smallest number to the right of that element.
- The last element of the array (`nums.back()`) is trivially the smallest on its own, so it is initialized as such.
- Starting from the second last element and moving towards the first, we update each element of `smallestRight` by taking the minimum of the current element in `nums` and the corresponding value in the `smallestRight` array.

For example, if `nums = [5, 2, 9, 7, 1]`, after filling `smallestRight`, it will look like `[1, 1, 1, 1, 1]`.

#### Step 2: Track the `smallestLeft` and Compute the Result

```cpp
int smallestLeft = nums[0], ans = -1;
for(int i = 1; i < nums.size(); i++){
    if(smallestLeft < nums[i] && smallestRight[i] < nums[i]){ 
        if(ans == -1) ans =  nums[i] + smallestRight[i] + smallestLeft;
        else ans = min(ans, nums[i] + smallestRight[i] + smallestLeft); 
    }
    smallestLeft = min(smallestLeft, nums[i]);
}
```

- **Objective**: As we move through the array from left to right, we maintain the smallest number on the left (`smallestLeft`). For each element, we check if it can form an increasing subsequence with the values in `smallestLeft` (to the left of it) and `smallestRight` (to the right of it).
- If the current element can form a valid subsequence (`smallestLeft < nums[i]` and `smallestRight[i] < nums[i]`), we compute the sum of the three numbers (`nums[i]`, `smallestRight[i]`, and `smallestLeft`).
- The result (`ans`) is updated to the minimum sum found so far.
- After checking the current element, we update `smallestLeft` to be the minimum of the current element and `smallestLeft`, ensuring that it always holds the smallest value encountered from the left side up to the current index.

For example, given `nums = [5, 2, 9, 7, 1]`, during the iteration:
- We calculate possible subsequences like `5 + 1 + 2`, and update the answer to track the minimum sum.

#### Step 3: Return the Result

```cpp
return ans;
```

- After iterating over all elements and checking possible subsequences, the smallest sum is stored in `ans`, which is then returned.
- If no valid subsequence was found, `ans` would remain `-1`, indicating no solution.

### Complexity

#### Time Complexity:
- **`O(n)`**: We iterate through the array twice:
  - The first pass to compute the `smallestRight` array takes `O(n)`, where `n` is the length of the array.
  - The second pass to compute the minimum sum and update `smallestLeft` also takes `O(n)`.
- Hence, the overall time complexity is linear, i.e., `O(n)`.

#### Space Complexity:
- **`O(n)`**: We use two extra arrays (`smallestRight` and `nums`) to store information, both of which take linear space.
- Therefore, the space complexity is `O(n)`.

### Conclusion

This solution efficiently solves the problem by using dynamic tracking of the smallest elements to the left and right of each element in the array. By iterating through the array once, we can compute the smallest possible sum of a valid subsequence of three elements that form a strictly increasing order. The solution has a linear time complexity, which ensures that it can handle larger input sizes efficiently. By using simple comparisons and updates, the approach achieves an optimal result while maintaining clarity and simplicity in implementation.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-sum-of-mountain-triplets-ii/description/)

---
{{< youtube PU5YZP1-uVA >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
