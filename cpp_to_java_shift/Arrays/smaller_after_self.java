// count of smaller numbers after self - Leetcode 315
/*
 
Given an integer array nums, return an integer array counts where counts[i] is the 
number of smaller elements to the right of nums[i].

 

Example 1:

Input: nums = [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

 */

import java.util.*;
public class smaller_after_self{

    public int sorted_posi(ArrayList<Integer> array, int x){
        int left = 0, right = array.size();
        while(left < right){
            int mid = left + (right - left) / 2;
            if(array.get(mid) < x){
                left = mid + 1;
            }
            else right = mid;
        }
        return left;
    }

    public int[] solve(int[] array){
        int n = array.length;
        ArrayList<Integer> posi = new ArrayList <>();
        int[] ans  = new int[n];

        smaller_after_self f = new smaller_after_self();

        for(int i = n - 1; i >= 0; i--){
            int pos = f.sorted_posi(posi, array[i]);
            ans[i] = pos;
            posi.add(pos, array[i]);
        }
        return ans;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        int[] array = new int[n];
        for(int i = 0; i < n; i++){
            array[i] = sc.nextInt();
        }
        sc.close();
        smaller_after_self func = new smaller_after_self();
        int[] ans = func.solve(array);
        for(int i = 0; i < n; i++){
            System.out.print(ans[i] + " ");
        }
    }
}