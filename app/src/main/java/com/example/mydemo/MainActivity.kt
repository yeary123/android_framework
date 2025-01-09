package com.example.mydemo

import androidx.appcompat.app.AppCompatActivity
import android.os.Bundle
import android.widget.TextView
import com.example.mydemo.databinding.ActivityMainBinding

class MainActivity : AppCompatActivity() {

    private lateinit var binding: ActivityMainBinding

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)

        binding = ActivityMainBinding.inflate(layoutInflater)
        setContentView(binding.root)

        // Example of a call to a native method
        binding.sampleText.text = stringFromJNI()

        binding.sumText.text = "sum:" + summaryFromJNI(3, 5).toString()

        binding.flipText.text = flipString("hello")
    }

    /**
     * A native method that is implemented by the 'mydemo' native library,
     * which is packaged with this application.
     */
    external fun stringFromJNI(): String

    external fun summaryFromJNI(num1: Int, num2: Int): Int

    external fun flipString(str: String): String

    companion object {
        // Used to load the 'mydemo' library on application startup.
        init {
            System.loadLibrary("mydemo")
        }
    }
}