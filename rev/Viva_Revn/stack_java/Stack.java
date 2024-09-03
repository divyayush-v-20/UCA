import java.util.Scanner;

class ListNode{
    int val;
    ListNode next;
    
    ListNode(int item){
        this.val = item;
        this.next = null;
    }
}

class Stack{

    ListNode top = null;
    int n;

    public void push(int item){
        ListNode oldHead = this.top;
        this.top = new ListNode(item);
        this.top.next = oldHead;
        this.n++;
    }

    public Integer pop(){
        int item = this.top.val;
        this.top = top.next;
        this.n--;
        return item;
    }

    public Integer size(){
        return this.n;
    }

    public boolean isEmpty(){
        return this.n == 0;
    }

    public Integer getTop(){
        return this.top.val;
    }

    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        Stack s1 = new Stack();
        while(true){
            int x;
            x = sc.nextInt();
            if(x == -1) {
                break;
            }
            s1.push(x);
        }
        sc.close();
        while(!s1.isEmpty()){
            System.out.println(s1.getTop());
            s1.pop();
        }
    }

}