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
      left = mid + 1; // keep searching right side
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

int countOccurrences(vector<int> &arr, int target)
{
  int first = firstOccurence(arr, target);
  int last = lastOccurence(arr, target);
  if (first == -1 || last == -1)
    return 0;
  return (last - first + 1);
}

int main()
{
  vector<int> nums = {0, 0, 1, 1, 1, 2, 3};
  int target = 1;
  int result = countOccurrences(nums, target);
  cout << result;
  return 0;
}
