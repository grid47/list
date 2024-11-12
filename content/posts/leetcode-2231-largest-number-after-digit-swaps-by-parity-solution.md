
+++
authors = ["grid47"]
title = "Leetcode 2231: Largest Number After Digit Swaps by Parity"
date = "2024-03-28"
lastmod = "2024-11-06"
description = "In-depth solution and explanation for Leetcode 2231: Largest Number After Digit Swaps by Parity in C++. Includes clear intuition, step-by-step example walkthrough, and detailed complexity analysis."
tags = ["Sorting","Heap (Priority Queue)"]
categories = [
    "Easy"
]
series = ["Leetcode"]
+++



[`Problem Link`](https://leetcode.com/problems/largest-number-after-digit-swaps-by-parity/description/)

---
**Code:**

{{< highlight cpp >}}
class Solution {
public:
    int largestInteger(int num) {
        priority_queue<int> p; // priority queue to store odd digits in descending order
        priority_queue<int> q; // priority queue to store even digits in descending order
        string nums=to_string(num); // converting num to a string for easy access of the digits
        int n=nums.size(); // n stores the number of digits in num
        
        for(int i=0;i<n;i++){
            int digit=nums[i]-'0'; 
            if((digit)%2) // if digit is odd, push it into priority queue p
                p.push(digit);
            else
                q.push(digit); // if digit is even, push it into priority queue q
        }
        
        int answer=0;
        for(int i=0; i<n; i++){
            answer=answer*10;
            if((nums[i]-'0')%2) // if the digit is odd, add the largest odd digit of p into the answer
                {answer+=p.top();p.pop();}
            else
                {answer+=q.top();q.pop();} // if the digit is even, add the largest even digit of q into the answer
        }
        return answer;
    }
};
{{< /highlight >}}

{{< ghcode "https://raw.githubusercontent.com/grid47/list/refs/heads/main/exp/2231.md" >}}
---
{{< youtube UNbggCsJ6LE >}}
| [LeetCode Solutions Library](https://grid47.xyz/leetcode/) / [DSA Sheets](https://grid47.xyz/sheets/) / Next : [LeetCode #2232: Minimize Result by Adding Parentheses to Expression](https://grid47.xyz/posts/leetcode-2232-minimize-result-by-adding-parentheses-to-expression-solution/) |
| --- |
{{< notice tip >}}
Unlock the power of patterns! Mastering one problem builds a pathway to solve many more. Dive into practice, and let each problem sharpen your skills. [Check out my Momentum Learning course at Udemy! 🚀 ](https://www.udemy.com/course/algorithms-and-data-structures-in-cpp/)
{{< /notice >}}
Coupen: {{< clip "coupen" >}}
