package com.peter.opengldemo;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;

import javax.microedition.khronos.opengles.GL10;

import android.os.Bundle;
import android.util.Log;

public class DrawSin extends OpenGLESActivity implements IOpenGLDemo {

	float vArrayAxis[] = { -4, 0.0f, 4, 0.0f, 0.0f, -4.0f, 0.0f, 4.0f };
	int NUM = 100;
	float vArraySin[] = new float[2 * NUM];
	int index = 0;
	FloatBuffer vertexAxis, vertexSin;
	
	/** Called when the activity is first created. */
	@Override
	public void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		createSinArray();
		ByteBuffer vbb2 = ByteBuffer.allocateDirect(vArraySin.length * 4);
		vbb2.order(ByteOrder.nativeOrder());
		vertexSin = vbb2.asFloatBuffer();
		vertexSin.put(vArraySin);
		vertexSin.position(0);

		ByteBuffer vbb = ByteBuffer.allocateDirect(vArrayAxis.length * 4);
		vbb.order(ByteOrder.nativeOrder());
		vertexAxis = vbb.asFloatBuffer();
		vertexAxis.put(vArrayAxis);
		vertexAxis.position(0);
	}
	
	public void createSinArray() {
		for (int i = 0; i < NUM; i++) {
			// suppose 0 map to -PI, NUM-1 map to PI
			double x = (2 * Math.PI * (float) i / (NUM - 1) - Math.PI);
			double y = Math.sin(x);
			vArraySin[2 * i] = (float) x;
			vArraySin[2 * i + 1] = (float) y;
			if (i == 0) {
				Log.i("HawkO", "sin(" + x + ")=" + y);
			}
		}
	}

	public void DrawAxis(GL10 gl)
	{
		gl.glVertexPointer(2, GL10.GL_FLOAT, 0, vertexAxis);

		gl.glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
		gl.glLineWidth(8);
		gl.glDrawArrays(GL10.GL_LINES, 0, 4);		
	}
	
	public void DrawSinArray(GL10 gl)
	{
	   
		gl.glVertexPointer(2, GL10.GL_FLOAT, 0, vertexSin);

		gl.glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
		// gl.glPointSize(8);
		gl.glLineWidth(4);
		gl.glDrawArrays(GL10.GL_LINES, 0, NUM);
	}
	
	public void DrawScene(GL10 gl) {
		super.DrawScene(gl);

		gl.glMatrixMode(GL10.GL_MODELVIEW);
		gl.glLoadIdentity();
		gl.glTranslatef(0, 0, -16);

		gl.glEnableClientState(GL10.GL_VERTEX_ARRAY);
	
		DrawAxis(gl);
		DrawSinArray(gl);
		
		gl.glDisableClientState(GL10.GL_VERTEX_ARRAY);

	}
}
