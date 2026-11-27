Find the minimum possible maximum time needed for k painters to paint n contiguous boards of given lengths (assuming 1 unit of time per unit of board)


Search Space

• low = max(boards): No single board can be split, so the busiest painter must take at least the longest board.
• high = sum(boards): If there is only 1 painter, they paint all boards in total sum time.

#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

bool canPaint(const vector<int>& boards, int k, long long maxTime) {
    int painters = 1;
    long long currentSum = 0;

    for (int len : boards) {
        if (currentSum + len <= maxTime) {
            currentSum += len;
        } else {
            painters++;
            currentSum = len;
            if (painters > k) return false;
        }
    }
    return true;
}

long long minPainterTime(const vector<int>& boards, int k) {
    long long low = *max_element(boards.begin(), boards.end());
    long long high = accumulate(boards.begin(), boards.end(), 0LL);
    long long ans = high;

    while (low <= high) {
        long long mid = low + (high - low) / 2;
        if (canPaint(boards, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
