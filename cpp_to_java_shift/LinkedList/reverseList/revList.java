public class revList{

    class ListNode{
        int val;
        ListNode next;

        ListNode(int x){
            this.val = x;
            this.next = null;
        }
    }

    public ListNode reverseList(ListNode cur, ListNode prev){
        if(cur == null) return prev;
        ListNode fwd = cur.next;
        cur.next = prev;
        return reverseList(fwd, cur);
    }

    public static void main(String[] args){
        revList list = new revList();
        ListNode head = list.new ListNode(1);
        head.next = list.new ListNode(2);
        head.next.next = list.new ListNode(3);
        head.next.next.next = list.new ListNode(4);
        head.next.next.next.next = list.new ListNode(5);

        head = list.reverseList(head, null);

        while(head != null){
            System.out.print(head.val + " ");
            head = head.next;
        }
    }
}