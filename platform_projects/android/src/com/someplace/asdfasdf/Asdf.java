package com.someplace.asdfasdf;

import com.someplace.asdf.OFActivity;

import android.app.Activity;
import android.os.Bundle;
import android.view.KeyEvent;
import android.view.Menu;
import android.view.MenuItem;

import android.content.Intent;


public class Asdf extends Activity {

	@Override
    public void onCreate(Bundle savedInstanceState){ 
        super.onCreate(savedInstanceState);
        Intent intent = new Intent(this, OFActivity.class);
		startActivity(intent);
    }
	
}



