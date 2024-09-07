import java.util.*;

class QuickSort{
    public void quickSort(int array[], int left, int right){
        if(left >= right){
            return;
        }
        int pivot = array[left];
        int i = left + 1;
        for(int j = left + 1; j <= right; ++j){
            if(array[j] < pivot){
                swap(array, j, i++);
            }
        }
        swap(array, left, --i);
        quickSort(array, left, i - 1);
        quickSort(array, i + 1, right);
    }

    public void qsort(int array[], int n){
        quickSort(array, 0, n - 1);
    }

    public void swap(int array[], int i, int j){
        int temp = array[i];
        array[i] = array[j];
        array[j] = temp;
    }

    public static void main(String args[]){
        QuickSort q1 = new QuickSort();
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();

        int[] array = new int[size];
        for(int i = 0; i < size; i++) array[i] = sc.nextInt();

        sc.close();

        q1.qsort(array, size);

        for(int i = 0; i < size; ++i) System.out.print(array[i] + " ");
    }

}