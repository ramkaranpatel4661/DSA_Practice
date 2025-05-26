class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        
        // Step 1: Find the pivot, the largest i such that nums[i] < nums[i + 1]
        int pivot = -1;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                pivot = i;
                break;  // Break early once we find the pivot
            }
        }

        // If pivot is not found, it means the sequence is in descending order, reverse it
        if (pivot == -1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        // Step 2: Find the smallest element larger than nums[pivot] from the right side
        for (int i = n - 1; i > pivot; i--) {
            if (nums[i] > nums[pivot]) {
                swap(nums[i], nums[pivot]);
                break;  // Only swap once
            }
        }

        // Step 3: Reverse the sequence from pivot + 1 to the end
        reverse(nums.begin() + pivot + 1, nums.end());
    }
};
