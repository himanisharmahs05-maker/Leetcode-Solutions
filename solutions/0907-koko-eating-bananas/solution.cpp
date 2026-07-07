class Solution {
public:
    long long findHours(vector<int>& piles, int speed) {
        long long hours = 0;

        for (int bananas : piles) {
            hours += ((long long)bananas + speed - 1) / speed;
        }

        return hours;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;

        while (low <= high) {
            int mid = low + (high - low) / 2;

            long long hours = findHours(piles, mid);

            if (hours > h)
                low = mid + 1;
            else {
                ans = mid;
                high = mid - 1;
            }
        }

        return ans;
    }
};
