
+++
authors = ["grid47"]
title = "Leetcode 1904: The Number of Full Rounds You Have Played"
date = "2024-04-30"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 1904: The Number of Full Rounds You Have Played in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Math","String"]
categories = [
    "Medium"
]
series = ["Leetcode"]
img_src = ""
youtube = "kwvB82HHvoQ"
youtube_upload_date="2021-06-20"
youtube_thumbnail="https://i.ytimg.com/vi/kwvB82HHvoQ/maxresdefault.jpg"
+++



---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int numberOfRounds(string login, string logout) {
        
        int in = (((login[0] - '0') * 10 + (login[1]- '0')) * 60) + ((login[3] - '0') * 10 + (login[4] - '0'));
        int out = (((logout[0] - '0') * 10 + (logout[1]- '0')) * 60) + ((logout[3] - '0') * 10 + (logout[4] - '0'));
        // cout << in << " " << out;
        int cnt = 0;
        if(in > out) {
            for(int i = 0; i < 24 * 60; i += 15) {
                if(i + 15 <= out || i >= in) cnt++;
            }
            return cnt;
        }

        for(int i = 0; i < 24 * 60; i += 15) {
            // cout << "\n" << i; 
            if(i >= in && (i + 15) <= out) cnt++;
        }
        return cnt;
        
        
    }
};
{{< /highlight >}}
---

### Problem Statement

The problem is to determine the number of complete 15-minute rounds that a user is active based on their login and logout times. The login and logout times are provided in a `HH:MM` format (24-hour clock), and the solution must account for scenarios where the logout time could be on the following day if the login occurs late in the day.

### Approach

To solve this problem, we will:

1. **Convert Time to Minutes**: Convert the login and logout times from `HH:MM` format into total minutes since the start of the day. This makes it easier to perform arithmetic calculations.

2. **Calculate Active Rounds**: Count how many complete 15-minute rounds fall within the active time from login to logout. A complete round is defined as a time interval that starts and ends within the active period.

3. **Handle Overnight Scenarios**: If the login time is greater than the logout time, it indicates that the user logged in before midnight and logged out after. We need to account for the full 24-hour cycle.

4. **Return the Result**: Finally, return the count of the complete 15-minute rounds.

### Code Breakdown (Step by Step)

Let's break down the code to understand how these steps are implemented:

1. **Class Definition**: The solution is encapsulated in a class named `Solution`.

   ```cpp
   class Solution {
   public:
   ```

2. **Function Signature**: The function `numberOfRounds` is defined, which takes two strings, `login` and `logout`, as input and returns an integer.

   ```cpp
       int numberOfRounds(string login, string logout) {
   ```

3. **Time Conversion**: The login and logout times are converted into total minutes. This is done by multiplying the hour part by 60 and adding the minute part.

   ```cpp
           int in = (((login[0] - '0') * 10 + (login[1]- '0')) * 60) + ((login[3] - '0') * 10 + (login[4] - '0'));
           int out = (((logout[0] - '0') * 10 + (logout[1]- '0')) * 60) + ((logout[3] - '0') * 10 + (logout[4] - '0'));
   ```

4. **Counter Initialization**: A counter `cnt` is initialized to zero to keep track of the number of complete rounds.

   ```cpp
           int cnt = 0;
   ```

5. **Overnight Handling**: The first `if` condition checks if the login time is greater than the logout time, indicating an overnight scenario. If so, it counts rounds for the time between the login time and the end of the day, and then from the start of the day to the logout time.

   ```cpp
           if(in > out) {
               for(int i = 0; i < 24 * 60; i += 15) {
                   if(i + 15 <= out || i >= in) cnt++;
               }
               return cnt;
           }
   ```

6. **Regular Case**: If the login time is less than or equal to the logout time, it counts the complete rounds that fall strictly within the active time.

   ```cpp
           for(int i = 0; i < 24 * 60; i += 15) {
               if(i >= in && (i + 15) <= out) cnt++;
           }
           return cnt;
       }
   };
   ```

### Complexity

- **Time Complexity**: The time complexity of this algorithm is O(1) since the loop will iterate a fixed number of times (96 times for the 15-minute intervals in a day). The overall complexity does not depend on the input size.

- **Space Complexity**: The space complexity is also O(1) because we are using a fixed amount of space for the variables, regardless of the input size.

### Conclusion

The `numberOfRounds` function effectively calculates the number of complete 15-minute rounds that fall within a user's active time, taking into account both day transitions and the specifics of time calculation. The approach is efficient and straightforward, utilizing basic arithmetic and conditional checks.

### Use Cases

The `numberOfRounds` function can be applied in various domains, such as:

- **Workforce Management**: In applications that track employee work hours, it can be used to calculate active working time blocks, which can help in payroll calculations or productivity assessments.

- **Time Tracking Applications**: For applications that require time logging and reporting, this function can help in generating reports based on active time spent.

- **Game Development**: In online gaming, where player activity is logged, this function could be used to calculate active playtime in specific intervals, helping in reward systems or player engagement metrics.

By implementing this function, developers can ensure their applications effectively handle time tracking, while maintaining clarity and performance in their code. The simple yet effective approach makes it an ideal candidate for integration into larger systems that require time-based calculations.

[`Link to LeetCode Lab`](https://leetcode.com/problems/the-number-of-full-rounds-you-have-played/description/)

---
{{< youtube kwvB82HHvoQ >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / [Course Catalog](https://grid47.xyz/courses/) |
| --- |
