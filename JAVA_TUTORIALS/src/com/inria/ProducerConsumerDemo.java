
package com.inria;

public class ProducerConsumerDemo {

    public static void main(String [] args ) {

        final Drop drop = new Drop();

        (new Thread(new Producer(drop))).start();

        (new Thread(new Consumer(drop))).start();

    }
}
