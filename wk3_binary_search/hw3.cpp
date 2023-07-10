class Solution {
public:
    //167. Two Sum II - Input Array Is Sorted
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;
        while(l < r)
        {
            int sum = numbers[l] + numbers[r];
            if( sum == target)
                break;
            if (sum > target)
                -- r;
            else
                ++ l;
        }
        return vector<int>{l + 1, r + 1};
    }
    //278. First Bad Version
    int firstBadVersion(int n) {
        int l = 1, r = n;
        if (isBadVersion(l))
            return l;
        while(l < r - 1)
        {
            int mid = l + (r - l) / 2;
            if(isBadVersion(mid))
                r = mid;
            else
                l = mid;
        }
        return r;
    }
   //852. Peak Index in a Mountain Array
   int peakIndexInMountainArray(vector<int>& arr) {
        int left = 0, right = arr.size() - 1;
        while(left < right)
        {
            int mid = left + (right - left) / 2;
            // cout << left << right << mid << endl;
            if(arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1])
                return mid;
            else if (arr[mid] > arr[mid - 1] && arr[mid + 1] > arr[mid])
                left = mid;
            else
                right = mid;
        }
        return left;
    }
    //702. Search in a Sorted Array of Unknown Size
    int search(const ArrayReader& reader, int target) {
        int prev_index = 0, curr_index = 1;
        while(target > reader.get(curr_index))
        {
            prev_index = curr_index;
            curr_index = curr_index * 2;
        }
        
        if(target == reader.get(prev_index))
            return prev_index;
        while(prev_index <= curr_index)
        {
            int mid = prev_index + (curr_index - prev_index) / 2; 
            if(reader.get(mid) == target)
                return mid;
            else if (reader.get(mid) > target)
                curr_index = mid - 1;
            else
                prev_index = mid + 1;
        }
        return -1;
    }
    // 1201. Ugly Number III
    int nthUglyNumber(int n, int a1, int b1, int c1) {
        long a = a1, b = b1, c = c1;
        long min_val = min(min(a, b), c);
        long r = n * min_val;
        long l = min_val;
        long ab = lcm(a, b);
        long bc = lcm(b, c);
        long ac = lcm(a, c);
        long abc = lcm(ab, c);
        while(l < r)
        {
            long m = l + (r - l) / 2;
            long k = m / a + m / b + m / c - m / ab - m / bc - m / ac + m / abc;
            cout << k <<" "<< l << " " << r << endl;
            if(k >= n)
                r = m;
            else
                l = m + 1 ;
        }
        return l;
    }

};
