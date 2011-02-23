
package com.inria;

public class BadThreads {

    static String message;

    private static class CorrectorThread extends Thread {
        public void run() {
            try {
                sleep(1000);

            } catch (InterruptedException e) {}
            //Key statement 1
            message = "Key statement 1";
        }

    }

    public static void main (String [] args) throws InterruptedException {
        //The key problem here is to guaratee a happens-before relationship !
        CorrectorThread corrector = new CorrectorThread();
        corrector.start();
        message = "Key statement 2";
        Thread.sleep(2000);
        //Key statement 2
        System.out.println(message);
    }
}
