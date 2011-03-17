/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

package org.me.hellodroid;

import android.app.Activity;
import android.os.Bundle;
import android.widget.TextView;


public class HelloDroid extends Activity {

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle icicle) {
        super.onCreate(icicle);
        // ToDo add your GUI initialization code here
        TextView tv = new TextView(this);
        tv.setText("Hello android from netbeans ;-) ");
        setContentView(tv);
        setContentView(R.layout.main);
    }

}
