
+++
authors = ["grid47"]
title = "Leetcode 2012: Sum of Beauty in the Array"
date = "2024-04-19"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2012: Sum of Beauty in the Array in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "pOb_fN_-rzo"
youtube_upload_date="2021-09-19"
youtube_thumbnail="https://i.ytimg.com/vi/pOb_fN_-rzo/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> left(n), right(n);

        left[0] = make_pair(nums[0], 0);
        for(int i = 1; i < n; i++)
            if(nums[i] >= left[i - 1].first) {
                left[i] = make_pair(nums[i], i);
            } else left[i] = left[i - 1];
        
        right[n-1] = make_pair(nums[n - 1], n - 1);
        for(int i = n - 2; i >= 0; i--)
            if(nums[i] <= right[i + 1].first) {
                right[i] = make_pair(nums[i], i);
            } else right[i] = right[i + 1];
        
        int sum = 0;
        for(int i = 1; i < n - 1; i++) {
            if(left[i - 1].first < nums[i] && right[i + 1].first > nums[i])
                sum += 2;
            else if(nums[i-1] < nums[i] && nums[i + 1] > nums[i])
                sum += 1;
            else sum += 0;
        }
        return sum;
    }
};
{{< /highlight >}}
---

### Problem Statement

The objective of this problem is to compute the sum of "beauties" of an array of integers, where the beauty of each element (except for the first and last elements) is defined based on its relationship with its neighbors. 

The beauty conditions are as follows:

- An element \( nums[i] \) has a beauty of 2 if it is greater than both its immediate neighbors (\( nums[i-1] \) and \( nums[i+1] \)).
- It has a beauty of 1 if it is greater than one neighbor but less than the other.
- It has a beauty of 0 if it does not satisfy any of the above conditions.

Given an integer array `nums`, the goal is to return the total sum of beauties of the array.

### Approach

To efficiently calculate the sum of beauties, we can use a two-pass technique with auxiliary arrays to keep track of the necessary comparisons:

1. **Initialize Arrays**: Create two vectors, `left` and `right`, which will store pairs representing the maximum values to the left and minimum values to the right of each index, respectively.

2. **First Pass (Left to Right)**: Populate the `left` vector:
   - Iterate through the `nums` array from left to right, maintaining the maximum value encountered so far. For each index \( i \), store the maximum value up to that point and its index.

3. **Second Pass (Right to Left)**: Populate the `right` vector:
   - Iterate through the `nums` array from right to left, maintaining the minimum value encountered so far. For each index \( i \), store the minimum value from that point to the end of the array.

4. **Calculate the Sum of Beauties**: Iterate through the `nums` array from the second element to the second-to-last element:
   - Check the beauty conditions using the `left` and `right` vectors and accumulate the beauty values accordingly.

### Code Breakdown (Step by Step)

Let’s take a closer look at the code and its components:

1. **Class Definition**: We define a class named `Solution` that will house our method.

    ```cpp
    class Solution {
    public:
    ```

2. **Method Declaration**: The method `sumOfBeauties` takes a vector of integers and returns an integer representing the total sum of beauties.

    ```cpp
    int sumOfBeauties(vector<int>& nums) {
    ```

3. **Initialization**: We start by obtaining the size of the input array and declaring two vectors to hold the left and right maximum/minimum values.

    ```cpp
    int n = nums.size();
    vector<pair<int,int>> left(n), right(n);
    ```

4. **Populating the Left Vector**: We initialize the first element of `left` and loop through the `nums` array to fill the `left` vector with the maximum values.

    ```cpp
    left[0] = make_pair(nums[0], 0);
    for(int i = 1; i < n; i++)
        if(nums[i] >= left[i - 1].first) {
            left[i] = make_pair(nums[i], i);
        } else left[i] = left[i - 1];
    ```

5. **Populating the Right Vector**: Similarly, we initialize the last element of `right` and loop through the `nums` array in reverse to fill the `right` vector with the minimum values.

    ```cpp
    right[n-1] = make_pair(nums[n - 1], n - 1);
    for(int i = n - 2; i >= 0; i--)
        if(nums[i] <= right[i + 1].first) {
            right[i] = make_pair(nums[i], i);
        } else right[i] = right[i + 1];
    ```

6. **Calculating the Sum of Beauties**: We initialize a variable `sum` to store the total beauty and iterate from the second element to the second-to-last element to compute the beauty based on the conditions provided.

    ```cpp
    int sum = 0;
    for(int i = 1; i < n - 1; i++) {
        if(left[i - 1].first < nums[i] && right[i + 1].first > nums[i])
            sum += 2;
        else if(nums[i-1] < nums[i] && nums[i + 1] > nums[i])
            sum += 1;
        else sum += 0;
    }
    ```

7. **Returning the Result**: Finally, we return the accumulated sum of beauties.

    ```cpp
    return sum;
    }
    ```

### Complexity

The time complexity of this solution is O(n) because we traverse the input array three times: once to populate the `left` vector, once to populate the `right` vector, and once to calculate the sum of beauties. The space complexity is O(n) due to the auxiliary vectors used.

### Conclusion

In conclusion, this solution effectively computes the sum of beauties in an integer array by utilizing a two-pass strategy. The use of auxiliary arrays allows for efficient comparisons while maintaining clarity in logic. This problem not only demonstrates the application of array traversal techniques but also emphasizes the importance of understanding the relationships between elements in an array.

The clarity and efficiency of this implementation make it an excellent reference for similar problems involving comparisons and conditional logic in arrays. Whether you are a student learning the fundamentals of algorithms or a developer looking to refine your skills, this example illustrates key programming concepts that can be applied to a variety of challenges in computer science.

[`Link to LeetCode Lab`](https://leetcode.com/problems/sum-of-beauty-in-the-array/description/)

---
{{< youtube pOb_fN_-rzo >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
