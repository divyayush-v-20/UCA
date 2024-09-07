public class PriorityQueue{
    	private Integer[] pq;
    	int n;

	PriorityQueue(int cap){
        	this.pq = new Integer[cap + 1];
    	}

	public void push(int item){
		this.pq[++n] = item;
		swim(n);
	}

	public Integer pop(){
		int top = this.pq[1];
		exch(1, n--);
		sink(1);
		this.pq[n + 1] = null;
		return top;
	}

	public boolean isEmpty(){
		return this.n == 0;
	}

	public Integer size(){
		return this.n;
	}

	private void swim(int k){
		while(k > 1 && this.pq[k/2] > this.pq[k]){
			exch(k, k/2);
			k = k / 2;
		}
	}

	private void sink(int k){
		while(2*k <= n){
			int j = 2*k;
			if(j < n && this.pq[j] > this.pq[j + 1]) j++;
			if(this.pq[k] <= this.pq[j]) break;
			exch(k, j);
			k = j;
		}
	}

	public void exch(int a, int b){
		int temp = this.pq[a];
		this.pq[a] = this.pq[b];
		this.pq[b] = temp;
	}
  	  

    	public static void main(String args[]){
		int array[] = {7, 1, 3, 4, 8, 2, 6, 9, 5};
		PriorityQueue pq = new PriorityQueue(9);
		for(int i = 0; i < 9; i++){
			pq.push(array[i]);
		}
		while(!pq.isEmpty()){
			System.out.print(pq.pop() + " ");
		}
    	}
}
