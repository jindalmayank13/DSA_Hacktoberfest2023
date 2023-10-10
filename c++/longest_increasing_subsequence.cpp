#include <iostream>
#include <vector>

using namespace std;

vector<int> findLongestIncreasingSubsequence(const vector<int>& arr) {
    int n = arr.size();
    vector<int> lis(n, 1);  // Initialize LIS values for all elements to 1
    vector<int> prev(n, -1); // Initialize previous index values as -1

    int maxLength = 1; // Length of the longest increasing subsequence
    int endIndex = 0;  // Index of the last element in LIS

    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
                prev[i] = j;
            }
        }
        if (lis[i] > maxLength) {
            maxLength = lis[i];
            endIndex = i;
        }
    }

    vector<int> longestSubsequence;
    while (endIndex != -1) {
        longestSubsequence.push_back(arr[endIndex]);
        endIndex = prev[endIndex];
    }

    reverse(longestSubsequence.begin(), longestSubsequence.end());

    return longestSubsequence;
}

int main() {
    vector<int> arr = {10, 22, 9, 33, 21, 50, 41, 60, 80};
    vector<int> longestSubsequence = findLongestIncreasingSubsequence(arr);

    cout << "Longest Increasing Subsequence: ";
    for (int num : longestSubsequence) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
