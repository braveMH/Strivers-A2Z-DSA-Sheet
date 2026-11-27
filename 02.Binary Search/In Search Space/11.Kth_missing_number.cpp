/*
Question: Given a sorted array arr of positive integers and an integer k, find the kth positive integer that is missing from the array.

Example:
Input: arr = [2,3,4,7,11], k = 5
Output: 9
Explanation: The missing positive integers are [1,5,6,8,9,10,12,13,...]. The 5th missing positive integer is 9.

If no numbers were missing, index i would hold the value i + 1 (since it's 1-indexed: 1, 2, 3...).

Therefore, the count of missing positive numbers before arr[i] is:
missing(i) = arr[i] - (i+1)

Example: arr = [2, 3, 4, 7, 11], k = 5
• At i = 3 (arr[3] = 7): missing = 7 - (3 + 1) = 3 (missing: 1, 5, 6).

• At i = 4 (arr[4] = 11): missing = 11 - (4 + 1) = 6 (missing: 1, 5, 6, 8, 9, 10).

Since missing(3) < 5 and missing(4) >= 5, the 5th missing number lies between arr[3] and arr[4].

Approach:
- We can solve this problem by finding the position in the array where the count of missing positive integers becomes greater than or equal to k.
- Initialize a variable `low` to 0 to represent the start of the array.
- Initialize a variable `high` to the size of the array minus 1 to represent the end of the array.
- Initialize a variable `pos` to -1 to store the position of the missing integer.
- Perform a binary search on the array:
  - Calculate the middle index `mid` using the formula `low + (high - low) / 2`.
  - If the count of missing positive integers in the subarray from the start to `mid` is less than k, update `low` to `mid + 1`.
  - Otherwise, update `pos` to `mid` and update `high` to `mid - 1`.
- After the binary search, check if a missing integer was found:
  - If `pos` is still -1, it means that the missing integer should be after the last element in the array. Return the sum of the size of the array and k.
  - Otherwise, return `pos + k` as the kth missing positive integer.

Time Complexity: O(log n), where n is the size of the array.
Space Complexity: O(1)

*/

int findKthPositive(vector<int>& arr, int k) {
    int low = 0, high = arr.size() - 1;
    int pos = -1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if ((arr[mid] - (mid + 1)) < k)
            low = mid + 1;
        else {
            pos = mid;
            high = mid - 1;
        }
    }

    if (pos == -1)
        return arr.size() + k;

    return pos + k;
}
