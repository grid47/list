class Solution {
public:
    int findMinFibonacciNumbers(int k) {
        vector<int> arr = {1, 1};
        while(arr[arr.size() - 1] + arr[arr.size() - 2] <= k) {
            arr.push_back(arr[arr.size() - 1] + arr[arr.size() - 2]);
        }

        set<int> cnt;
        int i = arr.size() -1;
        while(k > 0) {
            while(i >= 0 && arr[i] > k) i--;
            if(i == -1) break;
            k -= arr[i];
            cnt.insert(arr[i]);
        }
        return cnt.size();
    }
};