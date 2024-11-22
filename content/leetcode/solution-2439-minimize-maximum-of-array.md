
+++
authors = ["grid47"]
title = "Leetcode 2439: Minimize Maximum of Array"
date = "2024-03-08"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2439: Minimize Maximum of Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Binary Search","Dynamic Programming","Greedy","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "AeHMvcKuR0Y"
youtube_upload_date="2023-04-05"
youtube_thumbnail="https://i.ytimg.com/vi/AeHMvcKuR0Y/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        long sum = 0, res = 0;
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];
            res = max(res, (sum + i) / (i + 1));
        }
        return res;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem asks to minimize the maximum value of an array after performing some operations. Specifically, you are given an integer array `nums` and can perform the following operation:

- You can increment or decrement any element of the array by 1.

The goal is to minimize the maximum value of the array after performing any number of such operations. The output should be the smallest possible value of the largest element in the array that can be achieved by these operations.

For example:
- Input: `[3, 1, 5, 2, 4]`
- Output: `3`

Here, the minimum possible value for the maximum element is `3`. After performing the operations, the array becomes `[3, 3, 3, 3, 3]`, and the maximum value is `3`.

### Approach

To solve this problem efficiently, the key is to focus on minimizing the largest value in the array after performing the operations. This can be done by considering the average of the elements in the array at each step and gradually adjusting the array such that the difference between the maximum and minimum values is minimized.

Here's the thought process behind the solution:

1. **Calculate the Running Sum**: As we iterate through the array, we can maintain a running sum of the elements. This helps in understanding how the sum of the first `i` elements behaves and allows us to calculate the potential value for the maximum element at each index.

2. **Calculate the Average at Each Step**: For any element `nums[i]`, the average of the elements up to that index is calculated by dividing the running sum by `(i + 1)`. The reasoning behind this is that the smallest possible value for the maximum element, if the values were distributed evenly, would be the average. By adjusting the elements towards this average, we can minimize the maximum value.

3. **Update the Result**: The maximum value we want to minimize is the highest average seen up to any index. This is because the average gives us a threshold for balancing the array and minimizing the largest value. At each step, we update the result with the maximum of the current result and the average of the elements up to that index.

4. **Final Result**: The final result will be the smallest value that represents the largest element after performing all possible operations.

### Code Breakdown (Step by Step)

#### Step 1: Initialize Variables
We start by initializing two variables:
- `sum`: This variable will store the running sum of the elements as we iterate through the array.
- `res`: This variable will store the result, which represents the smallest possible value of the largest element.

```cpp
long sum = 0, res = 0;
```

#### Step 2: Iterate Through the Array
Next, we iterate through the array `nums` using a `for` loop. For each element `nums[i]`, we perform the following steps:
- **Update the Running Sum**: Add the current element to the running sum (`sum`).
- **Calculate the Current Average**: The average of the first `i+1` elements is `(sum + i) / (i + 1)`. This value represents the potential maximum element if we balance the array based on the current prefix.
- **Update the Result**: We update the result `res` with the maximum of the current value of `res` and the calculated average. This ensures that we are keeping track of the minimum possible largest value.

```cpp
for(int i = 0; i < nums.size(); i++) {
    sum += nums[i];
    res = max(res, (sum + i) / (i + 1));
}
```

Here, `(sum + i)` accounts for the total sum of elements from `nums[0]` to `nums[i]`, and dividing it by `(i + 1)` gives the average. The `max` function ensures that we store the largest of the averages seen so far, which gives us the minimum possible maximum value after all operations.

#### Step 3: Return the Result
Once the loop completes, the result `res` will hold the smallest possible value for the largest element in the array after balancing the elements. We then return this value.

```cpp
return res;
```

### Complexity

#### Time Complexity
The time complexity of the solution is **O(n)**, where `n` is the size of the array `nums`. This is because we only iterate over the array once, and for each element, we perform constant-time operations (sum and max calculations).

#### Space Complexity
The space complexity is **O(1)** because we are only using a fixed amount of extra space (`sum` and `res`), regardless of the size of the input array.

### Conclusion

The solution efficiently computes the smallest possible maximum value in an array after performing any number of increment and decrement operations. By maintaining a running sum and calculating the average at each step, we can determine the minimum possible maximum value. The approach runs in **O(n)** time and uses **O(1)** space, making it well-suited for large input sizes.

This approach ensures that we find the optimal solution in a single pass through the array, making it both time-efficient and space-efficient. The key idea is to minimize the largest element by leveraging the concept of averages and balancing the array as we progress through it.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimize-maximum-of-array/description/)

---
{{< youtube AeHMvcKuR0Y >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
