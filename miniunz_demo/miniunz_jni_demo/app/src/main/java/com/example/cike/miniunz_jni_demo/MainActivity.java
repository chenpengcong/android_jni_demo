package com.example.cike.miniunz_jni_demo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        String apkInstallPath = getApplicationContext().getPackageResourcePath();
        String unzipDstDir = getFilesDir().getPath();
        Log.d("MainActivity", "apkInstallPath:" + apkInstallPath);
        Log.d("MainActivity", "unzipDstDir:" + unzipDstDir);
        NativeClass.unzip(apkInstallPath, unzipDstDir);
    }
}
