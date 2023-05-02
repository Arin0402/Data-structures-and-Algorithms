
class counter {

    int count = 0;

    // synchronised specifies that this method will be used by one thread at a time.
    public synchronized void increment() {
        count++;
    }
}

public class J014_Synchronising_in_threading {

    public static void main(String[] args) throws Exception {

        counter c = new counter();

        Thread t1 = new Thread(() -> { // lambda expression - Lec 54 - Telusko. https://youtu.be/8cm1x4bC610?t=19470

            for (int i = 1; i <= 1000; i++)
                c.increment();
        });

        Thread t2 = new Thread(() -> {

            for (int i = 1; i <= 1000; i++)
                c.increment();
        });

        t1.start();
        t2.start();

        t1.join();
        t2.join();

        System.out.println(c.count);
    }
}
