package com.peter.opengldemo;

import android.app.Activity;
import android.opengl.GLES10;
import javax.microedition.khronos.opengles.GL10;
import android.opengl.GLSurfaceView;
import android.os.Bundle;
import android.view.Window;
import android.view.WindowManager;

public class HelloWorld extends Activity implements IOpenGLDemo {

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		this.requestWindowFeature(Window.FEATURE_NO_TITLE);
		getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
				WindowManager.LayoutParams.FLAG_FULLSCREEN);

		mGLSurfaceView = new GLSurfaceView(this);
		mGLSurfaceView.setRenderer(new OpenGLRenderer(this));
		setContentView(mGLSurfaceView);

	}

	public void DrawScene(GL10 gl) {
		GLES10.glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
		// Clears the screen and depth buffer.
		GLES10.glClear(GL10.GL_COLOR_BUFFER_BIT | GL10.GL_DEPTH_BUFFER_BIT);
	}

	@Override
	protected void onResume() {
		super.onResume();
		mGLSurfaceView.onResume();
	}

	@Override
	protected void onPause() {
		super.onPause();
		mGLSurfaceView.onPause();
	}

	private GLSurfaceView mGLSurfaceView;

}
