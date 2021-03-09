import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n, k;
        n = in.nextInt();
        k = in.nextInt();
        int[] nums = new int[n];
        for (int i = 0; i < n; i++) nums[i] = in.nextInt();
        Deque<Integer> deque = new LinkedList<>();
        StringBuilder stringBuilder=new StringBuilder();
        for(int i=0;i<n;i++){
            if (!deque.isEmpty() && i-deque.peekFirst() +1>k)deque.removeFirst();
            while (!deque.isEmpty() && nums[deque.peekLast()] >= nums[i]) deque.removeLast();
            deque.addLast(i);
            if (i >= k-1)stringBuilder.append(nums[deque.peek()]+" ");
        }
        System.out.println(stringBuilder.toString());
        deque.clear();
        stringBuilder.setLength(0);
        for(int i=0;i<n;i++){
            if (!deque.isEmpty() && i-deque.peekFirst()+1 > k) deque.removeFirst();
            while (!deque.isEmpty() && nums[deque.peekLast()] <= nums[i]) deque.removeLast();
            deque.addLast(i);
            if (i >=k-1)stringBuilder.append(nums[deque.peek()]+" ");
        }
        System.out.println(stringBuilder.toString());
    }
}