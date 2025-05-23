class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int n1 = n / 2;
        int count = 1;
        int m = nums[0]; // initialize with the first element

        sort(nums.begin(), nums.end());

        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) {
                count++;
                if (count > n1) {
                    return nums[i]; // return immediately once found
                }
            } else {
                count = 1; // reset count
            }
        }

        return m; // fallback (in case majority is at the start)
    }
};
