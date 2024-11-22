
+++
authors = ["grid47"]
title = "Leetcode 2134: Minimum Swaps to Group All 1's Together II"
date = "2024-04-07"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2134: Minimum Swaps to Group All 1's Together II in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "BueoreUIkcE"
youtube_upload_date="2024-08-02"
youtube_thumbnail="https://i.ytimg.com/vi/BueoreUIkcE/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ones = 0, x = 0, onesInWindows = 0, i = 0, n = nums.size();
        ones = count(nums.begin(), nums.end(), 1);
        vector<int> nums2(2 *n);
        for(int i = 0; i < 2 * n; i++)
        nums2[i] = nums[i%n];
        for(int i = 0; i < 2 *n ; i++) {
            if(i >= ones && nums2[i - ones] == 1) x--;
            if(nums2[i] == 1) x++;
            onesInWindows = max(x, onesInWindows);
        }
        return ones - onesInWindows;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to determine the minimum number of swaps required to group all `1`s in a given binary array (`nums`). The output should reflect how many times elements must be swapped so that all `1`s are contiguous in the array. 

### Approach

To solve this problem efficiently, we utilize a sliding window technique combined with the concept of circular arrays. By extending the original array into a virtual double-length array, we can simulate the circular behavior without complex logic. This way, we can easily track how many `1`s can fit into any window of the same size as the number of `1`s present in the original array. The number of swaps required will then be determined by subtracting the maximum number of `1`s that can fit in any window from the total number of `1`s.

### Code Breakdown (Step by Step)

Here's a step-by-step breakdown of the provided code:

1. **Class Declaration**:
   ```cpp
   class Solution {
   public:
   ```
   - This defines the `Solution` class, which contains the method to compute the minimum number of swaps.

2. **Function Definition**:
   ```cpp
   int minSwaps(vector<int>& nums) {
   ```
   - The `minSwaps` function is defined as a public member of the `Solution` class. It takes a reference to a vector of integers (`nums`), which represents a binary array.

3. **Variable Initialization**:
   ```cpp
   int ones = 0, x = 0, onesInWindows = 0, i = 0, n = nums.size();
   ```
   - Here, we declare and initialize several variables:
     - `ones`: To count the total number of `1`s in the array.
     - `x`: To keep track of the current count of `1`s in the sliding window.
     - `onesInWindows`: To store the maximum count of `1`s in any sliding window of size equal to `ones`.
     - `i`: Used as an index in loops.
     - `n`: The size of the input array.

4. **Count the Number of Ones**:
   ```cpp
   ones = count(nums.begin(), nums.end(), 1);
   ```
   - This line counts the total number of `1`s in the `nums` array using the `count` algorithm and assigns it to `ones`.

5. **Create a Double-Length Array**:
   ```cpp
   vector<int> nums2(2 * n);
   for(int i = 0; i < 2 * n; i++)
       nums2[i] = nums[i % n];
   ```
   - We create a new vector `nums2` that is double the length of the original array. This simulates the circular nature of the array. The elements are filled using modulo indexing, allowing us to wrap around the original array as needed.

6. **Sliding Window Logic**:
   ```cpp
   for(int i = 0; i < 2 * n; i++) {
   ```
   - This loop iterates over the doubled array to apply the sliding window technique.

7. **Adjust the Window Size**:
   ```cpp
   if(i >= ones && nums2[i - ones] == 1) x--;
   if(nums2[i] == 1) x++;
   ```
   - If the current index `i` is greater than or equal to the total number of `1`s (`ones`), we check if the element that is exiting the window (`nums2[i - ones]`) is a `1`. If so, we decrement `x` (the count of `1`s in the current window).
   - If the current element `nums2[i]` is a `1`, we increment `x`.

8. **Update Maximum `1`s in Window**:
   ```cpp
   onesInWindows = max(x, onesInWindows);
   ```
   - We update `onesInWindows` to be the maximum count of `1`s found in any window of size `ones`.

9. **Calculate Minimum Swaps**:
   ```cpp
   return ones - onesInWindows;
   ```
   - The final step returns the minimum number of swaps needed, which is calculated by subtracting the maximum number of `1`s in any window (`onesInWindows`) from the total count of `1`s (`ones`).

10. **End of Class**:
    ```cpp
    };
    ```
    - This closing brace signifies the end of the `Solution` class.

### Complexity Analysis

- **Time Complexity**: \( O(n) \)
  - The algorithm iterates over the array a couple of times (counting `1`s and sliding the window), leading to a linear time complexity relative to the size of the input array.

- **Space Complexity**: \( O(n) \)
  - The space complexity is primarily due to the additional `nums2` vector, which holds twice the size of the input array.

### Conclusion

The `minSwaps` function effectively determines the minimum number of swaps required to group all `1`s together in a binary array. By using a sliding window approach and a circular array representation, the solution is both efficient and straightforward. This implementation showcases a practical application of fundamental data structures and algorithms in competitive programming and technical interviews.

By iterating through the virtual double-length array and counting the number of `1`s that can fit in a sliding window, the algorithm efficiently calculates the necessary swaps. The solution is robust, and its clarity and efficiency make it an excellent example for those looking to deepen their understanding of array manipulation and sliding window techniques in C++. 

The code demonstrates a thorough understanding of the problem and provides an optimal solution with clear and logical steps, making it suitable for presentation in coding interviews or competitive programming contexts.

[`Link to LeetCode Lab`](https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/)

---
{{< youtube BueoreUIkcE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
