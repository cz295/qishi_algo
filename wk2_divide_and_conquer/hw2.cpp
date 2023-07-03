/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // 108. Convert Sorted Array to Binary Search Tree
    TreeNode *sortedArrayToBSTHelper(vector<int>& nums, int start, int end)
    {
        if(start > end)
            return nullptr;
        int mid = start + (end - start) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = sortedArrayToBSTHelper(nums, start, mid - 1);
        root->right = sortedArrayToBSTHelper(nums, mid + 1, end);
        return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return sortedArrayToBSTHelper(nums, 0, nums.size() - 1);
    }
    // 169. Majority Element
    int countOccurence(vector<int>& nums, int val, int left, int right)
    {
        int count;
        for(int i = left; i <= right; ++i)
            if(nums[i] == val)
                count ++;
        return count;
    }

    int findMajority(vector<int>& nums, int left, int right)
    {
        if(left == right)
            return nums[left];
        int mid = left + (right - left) / 2;
        int left_majority = findMajority(nums, left, mid);
        int right_majority = findMajority(nums, mid + 1, right);
        if(left_majority == right_majority)
            return left_majority;
        int left_count = countOccurence(nums, left_majority, left, right);
        int right_count = countOccurence(nums, right_majority, left, right);
        if(left_count > right_count)
            return left_majority;
        else
            return right_majority;
    }

    int majorityElement(vector<int>& nums) {
        return findMajority(nums, 0, nums.size() - 1);
    }
    // 240. Search a 2D Matrix II
        bool searchMatrixPart(vector<vector<int>>& matrix, int left, int right, int top, int bottom, int target)
    {
        cout << left << right << top << bottom << endl;
        if(left > right || top > bottom)
            return false;
        if(target < matrix[top][left] || target > matrix[bottom][right])
            return false;
        
        int h_mid = left + (right - left) / 2;
        int v_mid = top + (bottom - top) / 2;
        if(matrix[h_mid][v_mid] == target)
            return true;

        if(left == right || top == bottom)
        {
            if(left != right)
                return searchMatrixPart(matrix, left, h_mid, top, bottom, target) ||
                        searchMatrixPart(matrix, h_mid + 1, right, top, bottom, target);
            else if(top != bottom) 
                return searchMatrixPart(matrix, left, right, top, v_mid, target) ||
                        searchMatrixPart(matrix, left, right, v_mid + 1, bottom, target);
            else if (matrix[left][top] != target)
                return false;
            else
                return true;
        }
        else
            return searchMatrixPart(matrix, left, h_mid, top, v_mid, target) ||
                searchMatrixPart(matrix, left, h_mid, v_mid + 1, bottom, target) ||
                searchMatrixPart(matrix, h_mid + 1, right, top, v_mid, target) ||
                searchMatrixPart(matrix, h_mid + 1, right, v_mid + 1, bottom, target);
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(m == 0)
            return false;
        int n = matrix[0].size();
        return searchMatrixPart(matrix, 0, n - 1, 0, m - 1, target);
    }

    // 973. K Closest Points to Origin
    int distance(vector<int> & point)
    {
        int x = point[0], y = point[1];
        return x * x + y * y;
    }

    int partition(vector<vector<int>>& points, int left, int right) {
        int pivotDist = distance(points[right]);
        
        int smol = left, huge = left;
        while (huge < right) {
            if (distance(points[huge]) < pivotDist) {
                swap(points[huge], points[smol]);
                smol += 1;
            }
            huge += 1;
        }
        swap(points[smol], points[right]);
        return smol;
    }

    void quickSelect(vector<vector<int>>& points, int k, int left, int right, vector<vector<int>>& closestPoints) {
        if (left == right)
            return;
        int p = partition(points, left, right);
        if (p == k)
            return;
        else if (p < k)
            quickSelect(points, k, p + 1, right, closestPoints);
        else
            quickSelect(points, k, left, p - 1, closestPoints);
    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> closestPoints;
        quickSelect(points, k, 0, points.size() - 1, closestPoints);
        closestPoints.insert(closestPoints.end(), points.begin(), points.begin() + k);
        return closestPoints;
    }
 
    // 932. Beautiful Array
    vector<int> beautifulArray(int n) {
        if(n == 1)
            return {1};
        vector<int> arr = beautifulArray(n-1);

        vector<int> res;
        for (auto i: arr)
            if (2*i - 1 <= n) 
                res.push_back(2*i-1);

        for (auto i: arr)
            if (2*i <= n) 
                res.push_back(2*i);

        return res;
    }
    // 23. Merge k Sorted Lists
    ListNode* merge(ListNode *left, ListNode *right) {
        ListNode *dummy = new ListNode(-1);
        ListNode *temp = dummy;
        while (left != nullptr && right != nullptr) {
            if (left -> val < right -> val) {
                temp -> next = left;
                temp = temp -> next;
                left = left -> next;
            }
            else {
                temp -> next = right;
                temp = temp -> next;
                right = right -> next;
            }
        }
        while (left != nullptr) {
            temp -> next = left;
            temp = temp -> next;
            left = left -> next;
        }
        while (right != nullptr) {
            temp -> next = right;
            temp = temp -> next;
            right = right -> next;
        }
        return dummy -> next;
    }
    ListNode* mergeSort(vector<ListNode*>& lists, int start, int end) {
        if (start == end)
            return lists[start];
        int mid = start + (end - start) / 2;
        ListNode *left = mergeSort(lists, start, mid);
        ListNode *right = mergeSort(lists, mid + 1, end);
        return merge(left, right);
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;
        return mergeSort(lists, 0, lists.size() - 1);

    }
};
