#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int> &nums)
{
  int left = 0;
  int right = nums.size() - 1;
  int ans = INT_MAX;

  while (left <= right)
  {
    int mid = left + (right - left) / 2;

    // If the array between left and right is already sorted
    if (nums[left] <= nums[right])
    {
      ans = min(ans, nums[left]);
      break;
    }

    // Left part is sorted
    if (nums[left] <= nums[mid])
    {
      ans = min(ans, nums[left]);
      left = mid + 1;
    }
    // Right part is sorted
    else
    {
      ans = min(ans, nums[mid]);
      right = mid - 1;
    }
  }

  return ans;
}

int main()
{
  vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
  cout << findMin(nums);
  return 0;
}
