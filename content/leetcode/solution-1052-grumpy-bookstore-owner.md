
+++
authors = ["grid47"]
title = "Leetcode 1052: Grumpy Bookstore Owner"
date = "2024-07-24"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1052: Grumpy Bookstore Owner in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Array","Sliding Window"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "pXFbNuEIn8Q"
youtube_upload_date="2024-06-21"
youtube_thumbnail="https://i.ytimg.com/vi_webp/pXFbNuEIn8Q/maxresdefault.webp"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int maxSatisfied(vector<int>& cust, vector<int>& gm, int min) {

        int res = 0;
        int n = cust.size();
        vector<int> mins(n, 0), cs(n, 0);
            
        for(int i = 0; i < n; i++) {
            if(i < min)
            mins[0] += cust[i];
            else
            mins[i - min + 1] = mins[i - min] - cust[i - min] + cust[i];
            
            if(i == 0) cs[i] = gm[i] == 0 ? cust[i]: 0;
            else cs[i] = cs[i - 1] + (gm[i] == 0 ? cust[i]:0);
        }
        // for(int i = 0; i < n; i++)
        //     cout << mins[i] << " ";
        // cout << "\n";
        // for(int i = 0; i < n; i++)
        //     cout << cs[i] << " ";
        for(int i = 0; i <= n - min; i++) {
            int ans = (i > 0? cs[i - 1] : 0) + mins[i] + (cs[n - 1] - cs[i + min - 1]);                
            res = max(res, ans); 
        }
        
        return res;
    }
};
{{< /highlight >}}
---


### Problem Statement
In a scenario where customers arrive at a shop and can be satisfied based on their presence and a given number of free minutes, the goal is to determine the maximum number of satisfied customers. The function takes three parameters:
1. `cust`: An array representing the number of customers arriving each minute.
2. `gm`: An array indicating if a given minute is free (`0` for free, `1` for not free).
3. `min`: An integer specifying the number of consecutive minutes for which customers can be satisfied for free.

The objective is to calculate the maximum number of satisfied customers considering both free and paid minutes.

### Approach
To solve this problem, we can use the following steps:
1. Maintain two arrays: one to track the number of customers who can be satisfied during the free minutes (`mins`) and another to keep a cumulative sum of satisfied customers during the paid minutes (`cs`).
2. Loop through the customer array, populating these arrays based on the conditions provided.
3. Calculate the total satisfaction for each possible starting point of the free minutes.
4. Return the maximum satisfaction achieved.

### Code Breakdown (Step by Step)

1. **Function Declaration**:
   The function `maxSatisfied` takes three parameters: a vector of integers `cust`, a vector `gm`, and an integer `min`.

   ```cpp
   int maxSatisfied(vector<int>& cust, vector<int>& gm, int min) {
   ```

2. **Variable Initialization**:
   We initialize `res` to store the maximum number of satisfied customers, `n` to hold the size of the customer array, and two vectors `mins` and `cs` for tracking customer satisfaction counts.

   ```cpp
   int res = 0;
   int n = cust.size();
   vector<int> mins(n, 0), cs(n, 0);
   ```

3. **Calculating `mins` and `cs` Arrays**:
   We iterate through the customer array to populate the `mins` and `cs` arrays.

   - If the index `i` is less than `min`, we accumulate the total customers in the first segment of free minutes.
   - Once `i` reaches `min`, we start calculating the rolling sum of customers that can be satisfied during the free minutes.
   - The `cs` array keeps track of cumulative satisfied customers only when the minute is not free.

   ```cpp
   for(int i = 0; i < n; i++) {
       if(i < min)
           mins[0] += cust[i];
       else
           mins[i - min + 1] = mins[i - min] - cust[i - min] + cust[i];

       if(i == 0) cs[i] = gm[i] == 0 ? cust[i]: 0;
       else cs[i] = cs[i - 1] + (gm[i] == 0 ? cust[i]: 0);
   }
   ```

4. **Calculating Maximum Satisfaction**:
   After populating the `mins` and `cs` arrays, we determine the maximum satisfaction by iterating over the starting points for the free minutes. 

   - We calculate `ans` for each possible starting index of the free minutes and update the maximum satisfaction found so far.

   ```cpp
   for(int i = 0; i <= n - min; i++) {
       int ans = (i > 0? cs[i - 1] : 0) + mins[i] + (cs[n - 1] - cs[i + min - 1]);                
       res = max(res, ans); 
   }
   ```

5. **Returning the Result**:
   Finally, we return the maximum number of satisfied customers calculated.

   ```cpp
   return res;
   }
   ```

### Complexity Analysis
- **Time Complexity**: The time complexity of the solution is \(O(n)\), where \(n\) is the length of the `cust` array. This is because we make a single pass through the array to compute the `mins` and `cs` arrays, and then another pass to compute the maximum satisfaction.

- **Space Complexity**: The space complexity is also \(O(n)\) due to the additional space used for the `mins` and `cs` arrays.

### Conclusion
The `maxSatisfied` function efficiently computes the maximum number of satisfied customers based on their arrival and the availability of free minutes. By utilizing two auxiliary arrays for tracking customer satisfaction, the solution avoids unnecessary sorting or additional data structures, making it optimal for large inputs.

This approach is particularly effective in scenarios where customer behavior must be analyzed under different conditions, providing a scalable solution for determining satisfaction in various business settings. 

In conclusion, this function serves as a robust solution to the problem of maximizing customer satisfaction during specified free periods, leveraging clear logic and efficient algorithm design.


[`Link to LeetCode Lab`](https://leetcode.com/problems/grumpy-bookstore-owner/description/)

---
{{< youtube pXFbNuEIn8Q >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
