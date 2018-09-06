package com.example.cike.curl_jni_demo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        int res = NativeClass.curlGet("http://example.com");
        Log.d("MainActivity", "res:" + res);
    }
}
