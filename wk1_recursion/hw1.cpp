class Solution {
public:
    // Leetcode 21 Merge Two sorted List
    /**
     * Definition for singly-linked list.
     * struct ListNode {
     *     int val;
     *     ListNode *next;
     *     ListNode() : val(0), next(nullptr) {}
     *     ListNode(int x) : val(x), next(nullptr) {}
     *     ListNode(int x, ListNode *next) : val(x), next(next) {}
     * };
     */
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if(list1 == nullptr || list2 == nullptr)
            return list1 == nullptr ? list2 : list1;
        if(list1 -> val < list2 -> val)
        {
            list1 -> next = mergeTwoLists(list1 -> next, list2);
            return list1;            
        }
        else
        {
            list2 -> next = mergeTwoLists(list1, list2 -> next);
            return list2;
        }
    }

    // Leetcode 231 Power of Two
    bool isPowerOfTwo(int n) {
        if (n <= 2)
            return n > 0 ? true: false;
        else
        {
            if (n % 2 != 0)
                return false;
            else
                return isPowerOfTwo( n / 2);
        }
    }
    // Leetcode 203 Remove Linked List Elements
    /**
     * Definition for singly-linked list.
     * struct ListNode {
     *     int val;
     *     ListNode *next;
     *     ListNode() : val(0), next(nullptr) {}
     *     ListNode(int x) : val(x), next(nullptr) {}
     *     ListNode(int x, ListNode *next) : val(x), next(next) {}
     * };
    */
    ListNode* removeElements(ListNode* head, int val) {
        if(head == nullptr)
            return head;
        ListNode tmp = ListNode(0);
        tmp.next = head;
        ListNode* current = &tmp;
        while(current->next != nullptr)
        {
            if(current->next->val == val)
            {
                current->next = current->next->next;
            }
            else
            {
                current = current->next;
            }
        }
        return tmp.next;


        // if (head == null) return null;
        // head.next = removeElements(head.next, val);
        // return head.val == val ? head.next : head;
        if(head == nullptr)
            return head;
        if(head->val == val)
            return removeElements(head->next, val);
        else
        {
            head->next = removeElements(head->next, val);
            return head;
        }
    }
    // Leetcode 698 Partition to K Equal Sum Subsets
    bool backtrack(vector <int> nums, vector<bool>& visited, int curr_sum, int index, int target_sum, int k)
    {
        if(k == 0)
            return true;
        if (curr_sum > target_sum)
            return false;
        if (curr_sum == target_sum)
            return backtrack(nums, visited, 0, 0, target_sum, k - 1);
        for(int i = index; i<nums.size(); ++i)
        {
            if(visited[i])
                continue;
            visited[i] = true;
            if(backtrack(nums, visited, curr_sum + nums[i], i + 1, target_sum, k))
                return true;
            visited[i] = false;
            if(curr_sum == 0)
                break;
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int n = nums.size();
        if (k > n)
            return false;
        int sum = 0;
        for (auto x : nums)
            sum += x;
        if(sum % k != 0)
            return false;
        int target_sum = sum / k;
        vector<bool> visited(n, false);
        sort(nums.begin(), nums.end(), greater<int>());
        return backtrack(nums, visited, 0, 0, target_sum, k);
    }
    // Leetcode 761 Special Binary String
        string makeLargestSpecial(string s) {
        vector <string> specials;
        int count = 0;
        for(int i = 0, j = 0; j < s.length(); ++j)
        {
            if(s[j] == '1')
                count += 1;
            else
                count -= 1;
            if(count == 0)
            {
                const string& inner = s.substr(i + 1, j - i - 1);
                specials.push_back('1' + makeLargestSpecial(inner) + '0');
                i = j + 1;
            }
        }
        sort(begin(specials), end(specials), greater<>());
        string joined;
        for (const string& special : specials)
            joined += special;
        return joined;
    }
    // Leetcode 794 Valid Tic-Tac-Toe State
    bool isWin(vector<string>& board, char player)
    {
        for(int i = 0; i < 3; ++i)
        {
            if(board[i][0] == player && board[i][1] == player && board[i][2] == player)
                return true;
        }
        for(int i = 0; i < 3; ++i)
        {
            if(board[0][i] == player && board[1][i] == player && board[2][i] == player)
                return true;
        }
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
            return true;
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
            return true;
        return false;
    }

    bool validTicTacToe(vector<string>& board) {
        int n = int(board.size());
        int count_x = 0, count_o = 0;
        for(auto row:board)
        {
            for(auto c:row)
            {
                if(c == 'X')
                    ++count_x;
                else if(c == 'O')
                    ++count_o;
            }
        }
        if(count_o > count_x || count_x - count_o > 1) 
            return false;
        bool is_x_win = isWin(board, 'X');
        bool is_o_win = isWin(board, 'O');
        if(is_x_win && is_o_win) return false;
        if(is_x_win && (count_x - count_o) != 1) return false;
        if(is_o_win && (count_x != count_o)) return false;
        return true;
    }

};
