import java.util.LinkedList;
import java.util.Scanner;

class Main {
    public static void main(String[] args) {
        Scanner in =new Scanner(System.in);
        int n=in.nextInt();
        int[] nums = new int[n];
        LinkedList<Integer> stack=new LinkedList<>();
        for(int i=0;i<n;i++) {
            nums[i] = in.nextInt();
        }
        for(int i=0;i<n;i++ ){
            while (!stack.isEmpty() && stack.peek()>=nums[i]){
                stack.pop();
            }
            if (stack.isEmpty() || stack.peek()>=nums[i]){
                System.out.print("-1 ");
            }else{
                System.out.print(stack.peek()+" ");
            }
            stack.push(nums[i]);
        }
    }
}
