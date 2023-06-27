package wk1_recursion;

import java.util.Arrays;

public class PartitionToKEqualSumSubsets {

    public boolean canPartitionKSubsets(int[] nums, int k) {
        if (k == 1) return true;
        int sum = validateSumDivisibleByK(nums, k);
        if (sum == 1 || sum < k) return false;
        Arrays.sort(nums);
        if (nums[nums.length - 1] > sum / k) return false;
        boolean[] visited = new boolean[nums.length];
        return dfs(nums, visited, k, sum / k, nums.length - 1, 0);
    }

    private int validateSumDivisibleByK(int[] nums, int k) {
        int sum = 0;
        for (int num: nums) sum += num;
        if (sum % k != 0) return 1;
        return sum;
    }

    private boolean dfs(int[] nums, boolean[] visited, int k, int target, int idx, int currSum) {
        if (k == 1) return true;
        if (currSum == target) return dfs(nums, visited, k - 1, target, nums.length - 1, 0);
        for (int i = idx; i >= 0; i--) {
            if (!visited[i] && currSum + nums[i] <= target) {
                visited[i] = true;
                if (dfs(nums, visited, k, target, i - 1, currSum + nums[i])) return true;
                visited[i] = false;
            }
        }
        return false;
    }
}
