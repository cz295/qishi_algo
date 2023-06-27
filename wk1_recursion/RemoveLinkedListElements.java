package wk1_recursion;

public class RemoveLinkedListElements {
    public ListNode removeElements(ListNode head, int val) {
        if (head == null) return head;
        ListNode dummy = new ListNode(0);
        dummy.next = head;
        removeElementHelper(head, dummy, val);
        return dummy.next;
    }

    private void removeElementHelper(ListNode curr, ListNode prev, int val) {
        if (curr == null) return ;
        if (curr.val != val) {
            prev = prev.next;
        }
        else {
            prev.next = curr.next;
        }
        curr = curr.next;
        removeElementHelper(curr, prev, val);
    }
}
