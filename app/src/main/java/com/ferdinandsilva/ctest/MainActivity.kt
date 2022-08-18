package com.ferdinandsilva.ctest

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView

class MainActivity : AppCompatActivity() {
    private var txt: TextView? = null
    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContentView(R.layout.activity_main)
        System.loadLibrary("test-lib")
        txt = findViewById(R.id.txt)
        txt?.text = testFunction()
    }

    external fun testFunction(): String
}