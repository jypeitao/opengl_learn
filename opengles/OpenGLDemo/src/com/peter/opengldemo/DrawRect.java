package com.peter.opengldemo;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;

import javax.microedition.khronos.opengles.GL10;

import android.os.Bundle;
import android.util.Log;

public class DrawRect extends OpenGLESActivity implements IOpenGLDemo {

	float vArrayAxis[] = { -4, 0.0f, 4, 0.0f, 0.0f, -4.0f, 0.0f, 4.0f };
	int NUM = 4;
	float vArrayRect[] = new float[2 * NUM];
	int index = 0;
	FloatBuffer vertexAxis, vertexRect;

	/** Called when the activity is first created. */
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		createRectArray();
		ByteBuffer vbb2 = ByteBuffer.allocateDirect(vArrayRect.length * 4);
		vbb2.order(ByteOrder.nativeOrder());
		vertexRect = vbb2.asFloatBuffer();
		vertexRect.put(vArrayRect);
		vertexRect.position(0);

		ByteBuffer vbb = ByteBuffer.allocateDirect(vArrayAxis.length * 4);
		vbb.order(ByteOrder.nativeOrder());
		vertexAxis = vbb.asFloatBuffer();
		vertexAxis.put(vArrayAxis);
		vertexAxis.position(0);
	}

	public void createRectArray() {		
			vArrayRect[0] = -2;
			vArrayRect[1] = 2;
			
			vArrayRect[2] = -2;				
			vArrayRect[3] = -2;
			
			vArrayRect[4] = 2;
			vArrayRect[5] = -2;
			
			vArrayRect[6] = 2;
			vArrayRect[7] = 2;			
	}

	public void DrawAxis(GL10 gl) {
		gl.glVertexPointer(2, GL10.GL_FLOAT, 0, vertexAxis);

		gl.glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		gl.glLineWidth(8);
		gl.glDrawArrays(GL10.GL_LINES, 0, 4);
	}

	public void DrawRectArray(GL10 gl) {
		gl.glVertexPointer(2, GL10.GL_FLOAT, 0, vertexRect);

		gl.glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
		// gl.glPointSize(8);
		gl.glLineWidth(4);
		gl.glDrawArrays(GL10.GL_TRIANGLE_FAN, 0, NUM);
	}

	public void DrawScene(GL10 gl) {
		super.DrawScene(gl);

		gl.glMatrixMode(GL10.GL_MODELVIEW);
		gl.glLoadIdentity();
		gl.glTranslatef(0, 0, -16);

		gl.glEnableClientState(GL10.GL_VERTEX_ARRAY);

		DrawAxis(gl);
		DrawRectArray(gl);

		gl.glDisableClientState(GL10.GL_VERTEX_ARRAY);

	}
}
