package com.peter.opengldemo;

import javax.microedition.khronos.egl.EGLConfig;
import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLSurfaceView.Renderer;
import android.opengl.GLU;

public class OpenGLRenderer implements Renderer {

	private final IOpenGLDemo openGLDemo;

	public OpenGLRenderer(IOpenGLDemo demo) {
		openGLDemo = demo;
	}

	@Override
	public void onDrawFrame(GL10 gl) {
		if (openGLDemo != null) {
			openGLDemo.DrawScene((GL10) gl);
		}
	}

	@Override
	public void onSurfaceChanged(GL10 gl, int width, int height) {
		// Sets the current view port to the new size.
		gl.glViewport(0, 0, width, height);
		OpenGLESActivity.w = width;
		OpenGLESActivity.h = height;
		// Select the projection matrix
		gl.glMatrixMode(GL10.GL_PROJECTION);
		// Reset the projection matrix
		gl.glLoadIdentity();
		// Calculate the aspect ratio of the window
//		GLU.gluPerspective(gl, 90.0f, (float) width / (float) height, (float)height/2,
//		        height);
	      GLU.gluPerspective(gl, 45.0f, (float) width / (float) height, 0.1f,
	                1000);
		
		// Select the modelview matrix
		gl.glMatrixMode(GL10.GL_MODELVIEW);
		// Reset the modelview matrix
		gl.glLoadIdentity();
	}

	@Override
	public void onSurfaceCreated(GL10 gl, EGLConfig config) {
		// Set the background color to black ( rgba ).
		gl.glClearColor(0.0f, 1.0f, 0.0f, 0.0f);
		// Enable Smooth Shading, default not really needed.
		// gl.glShadeModel(GL10.GL_SMOOTH);
		// // Depth buffer setup.
		 //gl.glClearDepthf(1.0f);
		// // Enables depth testing.
		 //gl.glEnable(GL10.GL_DEPTH_TEST);
		// // The type of depth testing to do.
		// gl.glDepthFunc(GL10.GL_LEQUAL);
		// // Really nice perspective calculations.
		// gl.glHint(GL10.GL_PERSPECTIVE_CORRECTION_HINT, GL10.GL_NICEST);
	}

}
