package com.inria;

public class SynchronizedRGB {

    private int red;
    private int green;
    private int blue;
    String name;


    public void check(int red, int green, int blue) {
        if (red > 256 | green > 256 | blue > 256 |
            red < 0 | green < 0 | blue < 0)
               throw new IllegalArgumentException();
    }

    public SynchronizedRGB(int red, int green, int blue, String name) {
        
        check(red, green, blue);
        this.red = red;
        this.green = green;
        this.blue = blue;
        this.name = name;
    }

    public void set(int red, int green, int blue) {
      check(red, green, blue);
      synchronized(this) {
        this.red = red;
        this.green = green;
        this.blue = blue;
        this.name = name;
      }
  }

    public synchronized int getRGB() {
        return ((red << 16) | (green << 8) | blue);
    }

    public synchronized String getName() {
        return name;
    }

    public synchronized void invert(int red, int green, int blue, String name) {
        red = 256 -red;
        green = 256 - green;
        blue = 256 - blue;
        name = "Invert of "+name;
    }

    public static void main (String [] args) {

        SynchronizedRGB color = new SynchronizedRGB(0, 0, 0, "Pitch Black");
        //synchronize here because may be between Statement 1 and Statement 2
        //a thread try to invoke color.set => bound the statements together
        synchronized (color) {
            int myColorInt = color.getRGB(); //Statement 1
            String myColorName = color.getName(); //Statement 2
             System.out.println("RGB value = "+myColorInt+" ; ColorName = "+myColorName);
        }
    }

}

