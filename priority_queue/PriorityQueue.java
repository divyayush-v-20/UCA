public class PriorityQueue{
    private Integer[] pq;
    private int n;

    PriorityQueue(int cap){
        this.pq = new Integer[cap + 1];
    }

    public void insert(int x){
        this.pq[++n] = x;
        swim(n);
    }

    public Integer pop(){
        int del = this.pq[1];
        swap(1, this.n--);
        sink(1);
        this.pq[n + 1] = null;
        return del;
    }

    public void sink(int k) {
        while (2 * k <= this.n) {  
            int j = 2 * k;  
            if (j < this.n && this.pq[j] < this.pq[j + 1]) {  
                j++;
            }
            if (this.pq[k] >= this.pq[j]) {  
                break;
            }
            swap(k, j);  
            k = j; 
        }
    }

    public void swim(int k){
        while(k > 1 && this.pq[k] > this.pq[k / 2]){
            swap(k, k / 2);
            k /= 2;
        }
    }

    public void swap(int i, int j){
        int tmp = this.pq[i];
        this.pq[i] = this.pq[j];
        this.pq[j] = tmp;
    }

    public boolean isEmpty(){
        return this.n == 0;
    }

    public Integer size(){
        return this.n;
    }


    public static void main(String[] args){
        PriorityQueue pq1 = new PriorityQueue(10);
        int array[] = {11, 12, 13, 14, 15, 16, 17};
        for(int i = 0; i < 7; ++i){
            pq1.insert(array[i]);
        }
        while(!pq1.isEmpty()){
            System.out.println(pq1.pop());
        }
    }
}