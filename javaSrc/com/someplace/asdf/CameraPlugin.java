package com.someplace.asdf;

import android.hardware.Camera;
import android.media.MediaRecorder;
import cc.openframeworks.OFAndroid;
import cc.openframeworks.OFAndroidVideoGrabber;
import android.media.CamcorderProfile;
import java.io.IOException;

public class CameraPlugin {
	Camera camera;
	OFAndroidVideoGrabber videoGrabber;
	MediaRecorder recorder;
	int refid;
	
	CameraPlugin(int refid){
		this.refid = refid;
	}
		
	void setCamera(Camera camera){
		this.camera = camera;
	}
	
	void setVideoGrabber(OFAndroidVideoGrabber grabber){
		this.videoGrabber = grabber;
	}
	
	void takePhoto(){
		camera.takePicture(null,null,null,new Camera.PictureCallback(){
			public void onPictureTaken(byte[] data,Camera camera){
				onPhotoCb(data);
			}
		});
	}
	
	void startRecording(){
		System.out.println("Record: Recording Started");
		System.out.println("Record: File " + OFAndroid.getAppDataDirectory()+"/output.mp4");
		recorder = new MediaRecorder();
		
		camera.unlock();
		recorder.setCamera(camera);
		
		recorder.setAudioSource(MediaRecorder.AudioSource.MIC);
		recorder.setVideoSource(MediaRecorder.VideoSource.CAMERA);
		CamcorderProfile profile = CamcorderProfile.get(CamcorderProfile.QUALITY_HIGH);
		recorder.setProfile(profile);
		System.out.printf(
			"Record: audioBitRate(%d) audioChannels(%d) audioCodec(%d) audioSampleRate(%d) duration(%d) quality(%d) videoBitRate(%d) videoCodec(%d) videoFrameHeight(%d) videoFrameWidth(%d) videoFrameRate(%d)\n",
			profile.audioBitRate,
			profile.audioChannels,
			profile.audioCodec,
			profile.audioSampleRate,
			profile.duration,
			profile.quality,
			profile.videoBitRate,
			profile.videoCodec,
			profile.videoFrameHeight,
			profile.videoFrameWidth,
			profile.videoFrameRate);
		recorder.setOutputFile(OFAndroid.getAppDataDirectory()+"/output.mp4");
		
		try {
			recorder.prepare();
		}
		catch(IOException e){
			e.printStackTrace();
			return;
		}
		
		recorder.start();
		
		try {
			camera.reconnect();
		}
		catch(IOException e){
			e.printStackTrace();
			return;
		}
		camera.setPreviewCallback(videoGrabber);
		
	}
	
	void stopRecording(){
		System.out.println("Record: Recording Stopped");
		recorder.stop();
		recorder.reset();
		recorder.release();
		try {
			camera.reconnect();
		}
		catch(IOException e){
			e.printStackTrace();
			return;
		}
		camera.startPreview();
	}
	
	public native void onPhotoCb(byte[] data);
}