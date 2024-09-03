import java.util.Scanner;

class ListNode{
    int val;
    ListNode next;
    ListNode(int x){
        this.val = x;
        this.next = null;
    }
}
public class LinkedList{
    public ListNode reverseList(ListNode cur, ListNode prev){
        if(cur == null) return prev;
        ListNode fwd = cur.next;
        cur.next = prev;
        return reverseList(fwd, cur);
    }
    public static void main(String args[]){
        LinkedList list = new LinkedList();
        ListNode head = new ListNode(-1);
        Scanner sc = new Scanner(System.in);
        ListNode tmp = head;
        while(true){
            int x;
            x = sc.nextInt();
            if(x == -1) break;
            tmp.next = new ListNode(x);
            tmp = tmp.next;
        }
        sc.close();
        head = head.next;
        ListNode cur = head;
        ListNode prev = null;
        head = list.reverseList(cur, prev);
        while(head != null){
            System.out.print(head.val + " ");
            head = head.next;
        }
    }
}