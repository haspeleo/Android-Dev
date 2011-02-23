package com.inria;

public final class ImmutableRGB {

    private final int red;
    private final int green;
    private final int blue;
    private final String name;

    public void check(int red, int green, int blue) {
        if (red > 256 | red < 0 | green > 256 |
                green < 0 | blue > 256 | blue < 0 )
            throw new IllegalArgumentException();
    }

    public ImmutableRGB (int red, int green, int blue, String name) {
        check(red, green, blue);
        this.red = red;
        this.green = green;
        this.blue = blue;
        this.name = name;
    }

    public ImmutableRGB invert() {
        
        return (new ImmutableRGB(
                256 - red, 256 - green, 256 - blue, "Inverted "+name));
    }

    public synchronized int getRGB() {
        return ((red << 16) | (green << 8) | blue);
    }

    public String getName() {
        return name;
    }


    public static void main (String [] args) {

        ImmutableRGB immcolor = new ImmutableRGB(0, 0, 0,"Black Pitch");

        int myColorInt = immcolor.getRGB();//Statement 1
        String myColorName = immcolor.getName(); //Statement 2

        ImmutableRGB immcolorInverted = immcolor.invert();
        
        System.out.println("RGB value = "+myColorInt+" ; ColorName = "+myColorName);

    }
}
