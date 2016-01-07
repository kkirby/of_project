package com.someplace.asdf;

import android.content.Context;
import cc.openframeworks.OFAndroid;
import android.view.WindowManager;
import android.view.Surface;

public class Util {
	public static int GetScreenRotation(){
		int rotation = ((WindowManager)OFAndroid.getContext().getSystemService(Context.WINDOW_SERVICE)).getDefaultDisplay().getRotation();
		if(rotation == Surface.ROTATION_0){
			return 0;
		}
		else if(rotation == Surface.ROTATION_90){
			return 90;
		}
		else if(rotation == Surface.ROTATION_180){
			return 180;
		}
		else if(rotation == Surface.ROTATION_270){
			return 270;
		}
		else {
			return 0;
		}
	}
}