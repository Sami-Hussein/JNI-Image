package com.example.jnisample;

import android.content.res.Configuration;
import android.os.Bundle;
import android.util.Log;

//import androidx.activity.EdgeToEdge;
import org.qtproject.qt.android.bindings.QtActivity;
import androidx.core.graphics.Insets;
import androidx.core.view.ViewCompat;
import androidx.core.view.WindowInsetsCompat;

public class MainActivity extends QtActivity {
    @Override
    public void onCreate(Bundle savedInstanceState) {
        Log.i("test", "hello world");
        super.onCreate(savedInstanceState);
    }
    public int sumOfNumbers(int a, int b){
        return a+b;
    }
    public static native void sendOrientationChange(int orientation);


    public String upperCase(String text){
        return text.toUpperCase();
    }
    @Override
    public void onConfigurationChanged(Configuration newConfig) {
        super.onConfigurationChanged(newConfig);

        int orientation;
        if (newConfig.orientation == Configuration.ORIENTATION_LANDSCAPE) {
            orientation = 1; // Landscape
        } else if (newConfig.orientation == Configuration.ORIENTATION_PORTRAIT) {
            orientation = 0; // Portrait
        } else {
            orientation = -1; // Unknown
        }

        sendOrientationChange(orientation);
    }

}


