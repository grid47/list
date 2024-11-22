
+++
authors = ["grid47"]
title = "Leetcode 1980: Find Unique Binary String"
date = "2024-04-23"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1980: Find Unique Binary String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Hash Table","String","Backtracking"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "aHqn4Dynd1k"
youtube_upload_date="2021-08-22"
youtube_thumbnail="https://i.ytimg.com/vi/aHqn4Dynd1k/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        string ans = "";
        int n = nums.size();
        for(int i = 0; i < n; i++)
        ans += nums[i][i] == '0'? '1':'0';
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand is to find a binary string that differs from all the strings in a given list of binary strings. Each string in the list has the same length as the number of strings in the list, which creates a unique situation. The goal is to construct a binary string that is guaranteed to be different from each string at least in one position.

### Approach

To solve this problem efficiently, we can use a technique inspired by the diagonal argument. By constructing a new binary string based on the diagonal elements of the binary strings provided, we ensure that the newly created string will differ from each string at least at one corresponding index. This approach guarantees that we will always find a unique binary string, irrespective of the provided input.

### Code Breakdown (Step by Step)

```cpp
class Solution {
public:
```
The code begins with the definition of the `Solution` class, which encapsulates the function needed to solve the problem.

```cpp
    string findDifferentBinaryString(vector<string>& nums) {
```
Here, we define a public method named `findDifferentBinaryString`, which takes a vector of strings (`nums`) as an argument. This vector contains the binary strings from which we need to find a different binary string.

```cpp
        string ans = "";
        int n = nums.size();
```
We initialize an empty string `ans`, which will hold the resultant binary string. The variable `n` is set to the size of the `nums` vector, indicating the number of strings we are working with.

```cpp
        for(int i = 0; i < n; i++)
```
A loop is initiated that will iterate `n` times, allowing us to process each string in the input vector.

```cpp
        ans += nums[i][i] == '0' ? '1' : '0';
```
Within the loop, we construct the binary string `ans`. For each index `i`, we check the `i`-th character of the `i`-th string in the `nums` vector. If this character is `'0'`, we append `'1'` to `ans`; if it is `'1'`, we append `'0'`. This guarantees that the constructed binary string differs from each corresponding string at the `i`-th position.

```cpp
        return ans;
    }
};
```
After constructing the binary string, we return it. The method completes and the `Solution` class is closed.

### Complexity

- **Time Complexity**: The time complexity of this algorithm is \(O(n)\), where \(n\) is the number of strings in the `nums` vector. This is because we are simply iterating through the list once to construct our output string.

- **Space Complexity**: The space complexity is \(O(n)\) as well, as the output string `ans` will hold a binary string of length \(n\).

### Conclusion

This solution effectively constructs a binary string that is guaranteed to be different from all provided strings by utilizing a straightforward and elegant approach. The diagonal construction method ensures uniqueness by modifying characters based on their positions, thus providing a quick and efficient way to meet the problem's requirements.

### Example Usage

Here's how you can utilize the `findDifferentBinaryString` method from the `Solution` class:

```cpp
#include <vector>
#include <iostream>
using namespace std;

int main() {
    Solution sol;
    vector<string> nums = {"00", "01"};
    string result = sol.findDifferentBinaryString(nums);
    cout << "The different binary string is: " << result << endl; // Output: The different binary string is: "11"
    return 0;
}
```

### Potential Improvements and Variations

1. **Handling Edge Cases**: Although the current implementation handles the expected inputs well, one could enhance the function to gracefully handle unexpected inputs or edge cases, such as an empty list or strings of varying lengths.
   
2. **Expanding to Non-Binary Strings**: If the problem were to allow characters other than binary digits, the approach could be generalized by adapting the construction logic.

3. **Optimizing for Large Inputs**: In scenarios with very large input sizes, it might be beneficial to explore memory-efficient string construction techniques or parallel processing.

By following this approach, the solution remains clear, efficient, and adaptable for further extensions or variations in requirements.

[`Link to LeetCode Lab`](https://leetcode.com/problems/find-unique-binary-string/description/)

---
{{< youtube aHqn4Dynd1k >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
