
package com.peter.opengldemo;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;

import javax.microedition.khronos.opengles.GL10;

import android.os.Bundle;
import android.util.Log;

public class DrawNew extends OpenGLESActivity implements IOpenGLDemo {

    float vArrayAxis[] = {
            -4, 0.0f, 4, 0.0f, 0.0f, -4.0f, 0.0f, 4.0f
    };
    int NUM = 500;
    float vArraynew[] = new float[2 * NUM];
    int index = 0;
    FloatBuffer vertexAxis, vertexNew;

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        createSinArray();
        ByteBuffer vbb2 = ByteBuffer.allocateDirect(vArraynew.length * 4);
        vbb2.order(ByteOrder.nativeOrder());
        vertexNew = vbb2.asFloatBuffer();
        vertexNew.put(vArraynew);
        vertexNew.position(0);

        ByteBuffer vbb = ByteBuffer.allocateDirect(vArrayAxis.length * 4);
        vbb.order(ByteOrder.nativeOrder());
        vertexAxis = vbb.asFloatBuffer();
        vertexAxis.put(vArrayAxis);
        vertexAxis.position(0);
    }

    public void createSinArray() {
        for (int i = 0; i < NUM; i++) {
            // suppose 0 map to -PI, NUM-1 map to PI
            double radian = 2 * Math.PI * (float) i / (NUM - 1);
            double x = 10+Math.sin(15*radian);
            double y = Math.sin(radian);
            vArraynew[2 * i] = (float) x;
            vArraynew[2 * i + 1] = (float) y;
            if (i == 0) {
                Log.i("HawkO", "sin(" + x + ")=" + y);
            }
        }
    }

    public void DrawAxis(GL10 gl)
    {
        gl.glVertexPointer(2, GL10.GL_FLOAT, 0, vertexAxis);

        gl.glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
        //gl.glLineWidth(8);
        gl.glDrawArrays(GL10.GL_LINES, 0, 4);
    }

    public void DrawNewArray(GL10 gl)
    {
        gl.glTranslatef(-10, 0, 0);
        //gl.glRotatex(-80, 0, 1, 0);
        gl.glVertexPointer(2, GL10.GL_FLOAT, 0, vertexNew);

        //gl.glScalex(1, 1, 1);
        gl.glColor4f(0.0f, 1.0f, 0.0f, 1.0f);
        // gl.glPointSize(8);
        //gl.glEnable (GL10.GL_POINT_SMOOTH);
        //gl.glHint (GL10.GL_POINT_SMOOTH, GL10.GL_NICEST);
        //gl.glLineWidth(4);
        gl.glDrawArrays(GL10.GL_LINE_STRIP, 0, NUM);
    }

    public void DrawScene(GL10 gl) {
        super.DrawScene(gl);

        gl.glMatrixMode(GL10.GL_MODELVIEW);
        gl.glLoadIdentity();
        gl.glTranslatef(0, 0, -14);

        gl.glEnableClientState(GL10.GL_VERTEX_ARRAY);

        DrawAxis(gl);
        DrawNewArray(gl);

        gl.glDisableClientState(GL10.GL_VERTEX_ARRAY);

    }
}
