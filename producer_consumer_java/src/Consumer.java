import java.util.Queue;

public class Consumer implements Runnable {

    private Queue<Integer> queue;

    public Consumer(Queue queue) {
        this.queue = queue;
    }

    @Override
    public void run() {

        while (true){
            synchronized (queue){
                while (queue.isEmpty()){
                    try {
                        System.out.println("队列空,消费者线程进入休眠");
                        queue.wait();
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
                int i = queue.poll();
                System.out.println("消费者消费了第" + i + "个数据:" + i);
                queue.notifyAll();

//                try {
//                    Thread.sleep(1000);
//                } catch (InterruptedException e) {
//                    e.printStackTrace();
//                }
            }
        }

    }
}
