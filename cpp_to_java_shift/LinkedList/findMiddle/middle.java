public class middle{

    class ListNode{
        int val;
        ListNode next;

        ListNode(int x){
            this.val = x;
            this.next = null;
        }
    }

    public ListNode middleNode(ListNode head){
        ListNode live = head;
        ListNode die = head;
        while(die != null && die.next != null){
            live = live.next;
            die = die.next.next;
        }
        return live;
    }

    public static void main(String[] args){
        middle list = new middle();
        ListNode head = list.new ListNode(1);
        head.next = list.new ListNode(2);
        head.next.next = list.new ListNode(3);
        head.next.next.next = list.new ListNode(4);
        head.next.next.next.next = list.new ListNode(5);

        System.out.println(list.middleNode(head).val);
    }
}