class Hi implements Runnable {

    public void run() {

        for (int i = 0; i < 5; i++) {
            System.out.println("hi");
            try {
                Thread.sleep(500);
            } catch (Exception e) {
            }
            ;
        }
    }
};

class Hello implements Runnable {

    public void run() {

        for (int i = 0; i < 5; i++) {
            System.out.println("hello");
            try {
                Thread.sleep(500);
            } catch (Exception e) {
            }
            ;
        }
    }
};

public class J013_MultiThreading_using_Interface {

    public static void main(String[] args) {

        Hi obj1 = new Hi(); // or Runnable obj1 = new Hi();
        Hello obj2 = new Hello(); // or Runnable obj2 = new Hello();

        Thread t1 = new Thread(obj1); // we need to create objects of thread class as interface does not have the
                                      // start method.
        Thread t2 = new Thread(obj2); // we can pass the objects of the classes that implements interface

        t1.start();
        try {
            Thread.sleep(10);
        } catch (Exception e) {
        }
        ;
        t2.start();

        t1.join(); // This connects the thread to the main thread.
        t2.join(); // first , these two threads are completed then the main thread is executed.

        System.out.println("end");
    }
}

// Watch lambda expression - https://youtu.be/8cm1x4bC610?t=19470