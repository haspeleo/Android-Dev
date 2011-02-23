package com.inria;

public class BigO {

     static int compareToMax(int [] Tab) {
       int max = Tab[0];
       for (int i=0; i < Tab.length; i++) {
            if (Tab[i] > max)
                max = Tab[i];
                }
    return max;
    }
    
     static int compareToAll(int [] Tab) {
         boolean isMax = false;
         int i, j;

         for (i=0; i < Tab.length; i++) {
             for (j=0; j < Tab.length; j++) {
                     isMax = true;
                 if (Tab[j] > Tab[i])
                     isMax = false;
                }
         }
         
         if (isMax)
         return Tab[i];
     }
        
    public static void main (String [] args) {

         int [] Tab  = {11, 15, 71, 1, 10, 9, 2, 16, 1};

         int max1 = compareToMax(Tab);
         System.out.println("Compare to Max find MAX = "+max1);

         int max2 = compareToAll(Tab);
         System.out.println("Comprare to All find MAX = "+max2);
    }


}
