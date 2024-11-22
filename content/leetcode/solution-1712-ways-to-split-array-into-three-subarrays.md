
+++
authors = ["grid47"]
title = "Leetcode 1712: Ways to Split Array Into Three Subarrays"
date = "2024-05-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1712: Ways to Split Array Into Three Subarrays in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Two Pointers","Binary Search","Prefix Sum"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "u5GIK6GaNWk"
youtube_upload_date="2021-01-03"
youtube_thumbnail="https://i.ytimg.com/vi/u5GIK6GaNWk/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
    int mod = 1000000007;
public:
    int waysToSplit(vector<int>& nums) {
        
        int n = nums.size(), res=0;

        partial_sum(nums.begin(), nums.end(), nums.begin());
        
        for(int i = 0, j = 0, k = 0; i < n - 2; i++) {

            j = max(i + 1, j);
            while(j < n - 1 && 2 * nums[i] > nums[j]) j++;

            k = max(j, k);
            while(k < n - 1 && nums[k] - nums[i] <= nums[n - 1] - nums[k]) k++;

            res = (res + (k - j)) % mod;
        }
        return res;            
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to determine the number of ways to split an array `nums` into three contiguous parts such that the sum of the first part is less than or equal to the sum of the second part, and the sum of the second part is less than or equal to the sum of the third part. This can be visualized as finding indices \(i\), \(j\), and \(k\) that satisfy the conditions:

- \( \text{sum}(nums[0:i]) \leq \text{sum}(nums[i:j]) \)
- \( \text{sum}(nums[i:j]) \leq \text{sum}(nums[j:n]) \)

Where \(n\) is the size of the array, and we need to find all such valid splits.

For example, given an array `[1, 2, 2, 3, 5]`, the valid splits could be identified, and the task is to count how many such splits exist.

### Approach

To solve the problem, we can use the following approach:

1. **Prefix Sum Calculation**: First, compute the prefix sums for the input array. This allows us to easily calculate the sum of any subarray in constant time.

2. **Two-Pointer Technique**: Use a two-pointer approach to efficiently find valid positions for the split:
   - Iterate through potential starting indices for the first part (denoted by \(i\)).
   - For each \(i\), find the appropriate indices for \(j\) and \(k\):
     - \(j\) should point to the first index where the sum of the first part exceeds half of the total sum, i.e., \(2 \times \text{sum}(nums[0:i]) > \text{sum}(nums)\).
     - \(k\) should point to the first index where the sum of the second part is less than or equal to the sum of the third part.

3. **Counting Valid Splits**: For each valid \(i\), the valid positions for \(j\) and \(k\) give the range of possible splits, and we can count how many valid splits exist between these two pointers.

4. **Modulo Operation**: Since the number of ways can be large, we will return the result modulo \(10^9 + 7\).

### Code Breakdown (Step by Step)

Now, let’s delve into the provided code to understand its implementation:

1. **Class Declaration**: The solution is encapsulated within a class named `Solution`.

    ```cpp
    class Solution {
        int mod = 1000000007;
    ```

2. **Method Declaration**: The public method `waysToSplit` takes a reference to a vector of integers and returns an integer representing the number of valid ways to split the array.

    ```cpp
    public:
    int waysToSplit(vector<int>& nums) {
    ```

3. **Variable Initialization**: We initialize variables for the size of the array \(n\), a result counter \(res\), and the modulo constant.

    ```cpp
    int n = nums.size(), res = 0;
    ```

4. **Prefix Sum Calculation**: We calculate the prefix sum using the `partial_sum` function, which modifies the original `nums` array to contain cumulative sums.

    ```cpp
    partial_sum(nums.begin(), nums.end(), nums.begin());
    ```

5. **Main Loop**: The outer loop iterates through potential starting indices \(i\) for the first part, going up to \(n - 2\) since we need at least two more elements for parts two and three.

    ```cpp
    for(int i = 0, j = 0, k = 0; i < n - 2; i++) {
    ```

6. **Finding j**: We increment the pointer \(j\) to find the first index such that \(2 \times \text{sum}(nums[0:i]) > \text{sum}(nums[j:n])\).

    ```cpp
    j = max(i + 1, j);
    while(j < n - 1 && 2 * nums[i] > nums[j]) j++;
    ```

7. **Finding k**: We increment the pointer \(k\) to find the first index that maintains the condition for the sum of the second part being less than or equal to the sum of the third part.

    ```cpp
    k = max(j, k);
    while(k < n - 1 && nums[k] - nums[i] <= nums[n - 1] - nums[k]) k++;
    ```

8. **Count Valid Splits**: The number of valid splits for the current \(i\) is given by the range between \(j\) and \(k\), and we add this count to \(res\).

    ```cpp
    res = (res + (k - j)) % mod;
    ```

9. **Return the Result**: After processing all indices, we return the total count of valid splits.

    ```cpp
    return res;
    }
    ```

### Complexity

- **Time Complexity**: The time complexity of this solution is \(O(n)\) because each pointer \(j\) and \(k\) is incremented at most \(n\) times during the entire iteration of the outer loop.
  
- **Space Complexity**: The space complexity is \(O(1)\) beyond the input storage, as we are only using a fixed amount of extra space for variables.

### Conclusion

In conclusion, this solution efficiently counts the number of ways to split an array into three contiguous parts with specific sum conditions using a combination of prefix sums and a two-pointer approach. The use of cumulative sums allows for rapid sum calculations, while the two-pointer technique optimally finds valid split points without unnecessary iterations. The algorithm is designed to handle larger inputs within the constraints typically expected in competitive programming, ensuring performance and correctness. Overall, the code is cleanly structured, demonstrating a solid understanding of array manipulation and efficient algorithm design.

[`Link to LeetCode Lab`](https://leetcode.com/problems/ways-to-split-array-into-three-subarrays/description/)

---
{{< youtube u5GIK6GaNWk >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
