package com.someplace.asdfasdf;

import com.someplace.asdf.OFActivity;

import android.app.Activity;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;

import android.content.Intent;


public class Asdf extends Activity {

	@Override
    public void onCreate(Bundle savedInstanceState){ 
        super.onCreate(savedInstanceState);
		setContentView(R.layout.content_main);
    }
	
	
	public void doActivity(View v){
		Intent intent = new Intent(this, OFActivity.class);
		startActivity(intent);
	}
}



