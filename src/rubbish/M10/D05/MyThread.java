package M10.D05;

public class MyThread extends Thread {
    @Override
    public void run(){
        for(int i = 0 ; i < 10 ; i ++)
        {
            System.err.println(i);
                try {
                    Thread.sleep(1000);
                } catch (InterruptedException e) {
                    // TOD Auto-generated catch block
                    e.printStackTrace();
                }
        }
    }

    public MyThread(int priority) {
        this.setPriority(priority);
        System.err.println(
                "Thread " + "\"" + this.getName() + "\" " + "is RUNING at the priority of " + this.getPriority() + "!");
    }

    public MyThread() {
        System.err.println(
                "Thread " + "\"" + this.getName() + "\" " + "is RUNING at the priority of " + this.getPriority() + "!");
    }
}
