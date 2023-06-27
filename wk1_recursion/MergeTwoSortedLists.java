package wk1_recursion;

public class MergeTwoSortedLists {
    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
        ListNode dummy = new ListNode(0);
        ListNode curr1 = list1, curr2 = list2, curr = dummy;
        helper(curr1, curr2, curr);
        return dummy.next;
    }

    private void helper(ListNode curr1, ListNode curr2, ListNode curr) {
        if (curr1 == null && curr2 == null) return ;
        if (curr1 != null && (curr2 == null || curr1.val <= curr2.val)) {
            curr.next = curr1;
            helper(curr1.next, curr2, curr.next);
        }
        else {
            curr.next = curr2;
            helper(curr1, curr2.next, curr.next);
        }
    }
}
