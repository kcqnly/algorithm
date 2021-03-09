import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Deque;
import java.util.LinkedList;

class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(System.in));
        int m = Integer.parseInt(bufferedReader.readLine());
        Deque<Integer> deque =new LinkedList<>();
        for (int i = 0; i < m; i++) {
            int x;
            String temp = bufferedReader.readLine();
            String[] strings = temp.split(" ");
            switch (strings[0]) {
                case "push": {
                    x = Integer.parseInt(strings[1]);
                    deque.offer(x);
                }
                break;
                case "query": {
                    System.out.println(deque.peek());
                }
                break;
                case "pop": {
                    deque.poll();
                }
                break;
                case "empty": {
                    System.out.println(deque.isEmpty()?"YES":"NO");
                }
                break;
            }
        }
    }
}
