import java.util.Queue;

public class Producer implements Runnable{

    private Queue<Integer> queue;
    private int MAX_SIZE;
    int i = 1;

    public Producer(Queue queue, int MAX_SIZE) {
        this.queue = queue;
        this.MAX_SIZE = MAX_SIZE;
    }

    @Override
    public void run() {

            while (true) {
                synchronized (queue) {
                while (queue.size() >= MAX_SIZE){
                    try {
                        System.out.println("队列满,生产者进入休眠");
                        queue.wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
                System.out.println("生产者生产了第" + i + "个数据:" + i);
                queue.offer(i++);
                queue.notifyAll();

                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    e.printStackTrace();
                }
            }
        }
    }
}
