#include <bits/stdc++.h>
using namespace std;

int firstOccurence(vector<int> &nums, int target)
{
  int left = 0, right = nums.size() - 1;
  int occ = -1;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target)
    {
      occ = mid;
      right = mid - 1;
    }
    else if (nums[mid] < target)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }
  return occ;
}

int lastOccurence(vector<int> &nums, int target)
{
  int left = 0, right = nums.size() - 1;
  int occ = -1;
  while (left <= right)
  {
    int mid = left + (right - left) / 2;
    if (nums[mid] == target)
    {
      occ = mid;
      left = mid + 1;
    }
    else if (nums[mid] < target)
    {
      left = mid + 1;
    }
    else
    {
      right = mid - 1;
    }
  }
  return occ;
}

vector<int> searchRange(vector<int> &nums, int target)
{
  return {firstOccurence(nums, target), lastOccurence(nums, target)};
}

int main()
{
  vector<int> nums = {5, 7, 7, 8, 8, 10};
  int target = 8;
  vector<int> result = searchRange(nums, target);
  cout << "FIRST OCC : " << result[0] << ", LAST OCC : " << result[1] << endl;
  return 0;
}
