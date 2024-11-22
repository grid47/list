
+++
authors = ["grid47"]
title = "Leetcode 739: Daily Temperatures"
date = "2024-08-25"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 739: Daily Temperatures in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Stack","Monotonic Stack"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = "https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/739.webp"
youtube = "_ZEvmycwXHs"
youtube_upload_date="2024-02-27"
youtube_thumbnail="https://i.ytimg.com/vi/_ZEvmycwXHs/maxresdefault.jpg"
+++


{{< rmtimg 
    src="https://raw.githubusercontent.com/grid47/list-images/refs/heads/main/list/739.webp" 
    alt="A series of temperatures with the next warmer day highlighted, glowing softly as it is identified."
    caption="Solution to LeetCode 739: Daily Temperatures Problem"
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
    vector<int> dailyTemperatures(vector<int>& temp) {
        stack<pair<int,int>> stk;
        vector<int> ans(temp.size(), 0);
        for(int i = 0; i < temp.size(); i++) {
            // cout << temp[i] << " " ;
            while(!stk.empty() && temp[i] > stk.top().first) {
                // cout << temp[i] << " " ;
                pair<int, int> x = stk.top();

                // cout << temp[i] << " " ;                
                stk.pop();
                
                // cout << temp[i] << " " << x.first << x.second; 
                ans[x.second] = i-x.second;
                // cout << temp[i] << " " ;
            }
            stk.push(make_pair(temp[i], i));
        }
        
        while(!stk.empty()) {
            auto x = stk.top();
            stk.pop();
            ans[x.second] = 0;
        }
        
        return ans;
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem requires finding the number of days you have to wait until a warmer temperature for each day in a given list of temperatures. Given an array of daily temperatures `temp`, the task is to return an array `ans` such that each element `ans[i]` is the number of days you have to wait until a warmer temperature for the `i`-th day. If there is no future day with a warmer temperature, the corresponding entry in `ans[i]` will be `0`.

For example, given the array `temp = [73, 74, 75, 71, 69, 72, 76, 73]`, the output should be `[1, 1, 4, 2, 1, 1, 0, 0]`. This is because:
- On day 0 (temperature 73), the next day with a warmer temperature is day 1 (74), so `ans[0] = 1`.
- On day 1 (temperature 74), the next day with a warmer temperature is day 2 (75), so `ans[1] = 1`.
- On day 2 (temperature 75), the next warmer temperature is on day 6 (76), so `ans[2] = 4`.

### Approach

This problem can be solved efficiently using a **stack-based approach**:
- We will maintain a stack that stores pairs of the form `(temperature, index)`.
- For each day's temperature:
  - If the current temperature is greater than the temperature stored at the top of the stack, we know that the current temperature is the next warmer temperature for the day at the top of the stack.
  - We then calculate the difference between the current day and the day at the top of the stack, which gives us the number of days to wait for a warmer temperature for that day.
  - We pop the stack and repeat the process until the stack is either empty or the current temperature is not greater than the temperature at the top of the stack.
- After processing all the temperatures, we return the `ans` array where each entry represents the number of days to wait for a warmer temperature.

### Code Breakdown (Step by Step)

1. **Initialize the stack and the answer array**:
   - We initialize a stack `stk` to store pairs of the form `(temperature, index)`.
   - We initialize the `ans` array with the same size as the input `temp` array, filled with zeros. The `ans[i]` will represent the number of days to wait until a warmer temperature for the `i`-th day.

   ```cpp
   stack<pair<int, int>> stk;
   vector<int> ans(temp.size(), 0);
   ```

2. **Iterate through the `temp` array**:
   - For each temperature `temp[i]` on day `i`, we check if the stack is not empty and if the current temperature is greater than the temperature at the top of the stack. If so, it means we have found a warmer day for the day stored at the top of the stack.
   - We pop the stack and calculate the difference between the current day and the day stored in the stack. This gives us the number of days to wait until a warmer temperature for that day.
   
   ```cpp
   for (int i = 0; i < temp.size(); i++) {
       while (!stk.empty() && temp[i] > stk.top().first) {
           pair<int, int> x = stk.top();
           stk.pop();
           ans[x.second] = i - x.second;
       }
       stk.push(make_pair(temp[i], i));
   }
   ```

3. **Handle the remaining days in the stack**:
   - After processing all days, there may still be some days left in the stack for which we didn’t find a warmer temperature. For these days, we set `ans[i]` to `0`, which is the default value already initialized in the array.

   ```cpp
   while (!stk.empty()) {
       auto x = stk.top();
       stk.pop();
       ans[x.second] = 0;
   }
   ```

4. **Return the result**:
   - Finally, we return the `ans` array that contains the number of days to wait for a warmer temperature for each day.

   ```cpp
   return ans;
   ```

### Complexity

#### Time Complexity:
- **O(n)**, where `n` is the number of days (length of the `temp` array). We traverse the `temp` array once, and each element is pushed and popped from the stack at most once. Hence, the total time complexity is linear.

#### Space Complexity:
- **O(n)**, where `n` is the number of days. We use the `stk` stack to store the temperatures and their corresponding indices, and the `ans` array to store the results.

Thus, the space complexity is also linear due to the usage of the stack and the result array.

### Conclusion

This stack-based approach efficiently calculates the number of days to wait for a warmer temperature for each day in the input array. By using a stack to keep track of temperatures and their indices, we ensure that each day is processed in constant time. This solution provides an optimal way to solve the problem with a time complexity of **O(n)**, making it scalable even for large input sizes.

The key advantage of using a stack here is that it allows us to efficiently find the next warmer temperature for each day, reducing the need for nested loops and making the algorithm significantly faster than brute-force solutions.

[`Link to LeetCode Lab`](https://leetcode.com/problems/daily-temperatures/description/)

---
{{< youtube _ZEvmycwXHs >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
