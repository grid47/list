
+++
authors = ["grid47"]
title = "Leetcode 1573: Number of Ways to Split a String"
date = "2024-06-02"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1573: Number of Ways to Split a String in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "DVcHb_poT6E"
youtube_upload_date="2020-09-05"
youtube_thumbnail="https://i.ytimg.com/vi/DVcHb_poT6E/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numWays(string s) {
        
        long n = s.size();
        int one = 0;
        for(char x: s)
            one += (x == '0')? 0: 1;
        
        int mod = (int) 1e9 + 7;
        
        if(one == 0) return (int)((n - 2) * (n - 1) / 2 % mod);
        
            
        if(one % 3 != 0) return 0;
        
        long long waysOfFirstCut = 0, waysOfSecondCut = 0;
        int net = one / 3, tmp = 0;
        for(int i = 0; i < n; i++) {
            if(s[i] == '1') tmp++;
            if(tmp == net) waysOfFirstCut++;
            else if(tmp == 2 * net) waysOfSecondCut++;
        }
        
        return (int)(waysOfFirstCut *waysOfSecondCut % mod) ;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem at hand involves determining the number of ways to split a binary string into three non-empty parts such that each part contains an equal number of '1's. Given a binary string `s` consisting of '0's and '1's, the goal is to find the number of distinct ways to make two cuts in the string so that the resulting three substrings each have the same count of '1's. If it is not possible to split the string in this way, the function should return 0.

### Approach

To solve this problem, we can utilize a systematic approach that involves counting the number of '1's in the string and leveraging combinatorial mathematics:

1. **Count the Number of '1's**:
   - First, iterate through the string to count the total number of '1's. This count will determine how we can split the string.

2. **Handle Edge Cases**:
   - If the count of '1's is zero, calculate the number of ways to choose two cuts between the zeros. This can be done using combinatorial mathematics.
   - If the count of '1's is not divisible by three, it's impossible to split the string into three parts with equal '1's, so return 0.

3. **Calculate Possible Cuts**:
   - If the number of '1's is divisible by three, determine the number of ways to make the cuts. This is done by iterating through the string again, counting the occurrences of '1's up to the required divisions, and recording how many times we can make these cuts.

4. **Compute the Result**:
   - The total number of ways to split the string is the product of the number of ways to make the first cut and the number of ways to make the second cut.

### Code Breakdown (Step by Step)

Let's break down the code provided to understand its implementation in detail.

- **Class Declaration**: The solution is encapsulated within a class named `Solution`.

```cpp
class Solution {
public:
```

- **Function Definition**: The `numWays` function is defined to take a string `s` as input and returns an integer representing the number of ways to split the string.

```cpp
int numWays(string s) {
```

- **Variable Initialization**: 
   - We obtain the length of the string `n` and initialize a variable `one` to count the number of '1's in the string.

```cpp
long n = s.size();
int one = 0;
```

- **Count '1's**: A loop iterates through each character in the string to count the number of '1's.

```cpp
for(char x: s)
    one += (x == '0')? 0: 1;
```

- **Modulo Declaration**: We define a modulo variable to handle large numbers and prevent overflow.

```cpp
int mod = (int) 1e9 + 7;
```

- **Edge Case for Zero '1's**: If the total number of '1's is zero, we calculate the number of ways to select two cuts among the zeros. This is done using the formula for combinations.

```cpp
if(one == 0) return (int)((n - 2) * (n - 1) / 2 % mod);
```

- **Divisibility Check**: If the number of '1's is not divisible by three, return 0 as splitting is impossible.

```cpp
if(one % 3 != 0) return 0;
```

- **Calculate Possible Cuts**: We determine how many '1's should be present in each of the three parts and initialize counters for the number of ways to make the first and second cuts.

```cpp
long long waysOfFirstCut = 0, waysOfSecondCut = 0;
int net = one / 3, tmp = 0;
```

- **Counting Cuts**: Another loop iterates through the string, counting '1's and tracking how many times we can make the first and second cuts based on the required number of '1's in each part.

```cpp
for(int i = 0; i < n; i++) {
    if(s[i] == '1') tmp++;
    if(tmp == net) waysOfFirstCut++;
    else if(tmp == 2 * net) waysOfSecondCut++;
}
```

- **Return the Result**: Finally, the total number of ways to split the string is returned as the product of the ways to make the first and second cuts, modulo \(10^9 + 7\).

```cpp
return (int)(waysOfFirstCut * waysOfSecondCut % mod);
}
```

### Complexity

- **Time Complexity**: The time complexity of this algorithm is \(O(n)\), where \(n\) is the length of the string. This is due to the fact that we traverse the string multiple times, each requiring linear time.

- **Space Complexity**: The space complexity is \(O(1)\) since we use only a fixed number of additional variables for counting and calculations, independent of the input size.

### Conclusion

The `numWays` function efficiently calculates the number of distinct ways to split a binary string into three equal parts based on the number of '1's it contains. By leveraging combinatorial counting and systematic iteration, the function provides a clear and concise solution to the problem.

This solution exemplifies effective programming techniques, including early returns for edge cases, modular arithmetic to manage large numbers, and the use of simple loops to perform complex counting tasks. 

Understanding this approach equips developers with valuable insights into handling binary strings and combinatorial problems, making it a practical reference for similar challenges encountered in competitive programming or technical interviews.

In summary, the `numWays` function not only solves the problem at hand but also serves as an educational resource for mastering counting principles in programming. Its efficiency, clarity, and robust handling of edge cases make it an excellent example of algorithm design in action.

[`Link to LeetCode Lab`](https://leetcode.com/problems/number-of-ways-to-split-a-string/description/)

---
{{< youtube DVcHb_poT6E >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
