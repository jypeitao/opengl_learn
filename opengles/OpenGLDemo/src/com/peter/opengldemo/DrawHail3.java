
package com.peter.opengldemo;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;
import java.util.ArrayList;

import javax.microedition.khronos.opengles.GL10;

import android.opengl.GLU;
import android.os.Bundle;
import android.util.Log;
import android.view.MotionEvent;

class HailVertex3 {
    public long x;
    public long y;
    public HailVertex3(long x,long y) {
        this.x = x;
        this.y = y;
    }
}
public class DrawHail3 extends OpenGLESActivity implements IOpenGLDemo {

    float dis = 16f;
    float near = 0.1f;
    float ang = 45f;
    double scaleX = 1.0f;
    double scaleY = 1.0f;
    double W = 0f;
    double H = (2*dis*Math.tan(Math.PI/8));
    
    int type = GL10.GL_LINE_STRIP;

    long mInit = 1000;
    long bigX = 0;
    long bigY = 0;
    float vArrayAxis[] = {
            -4, 0.0f, 4, 0.0f, 0.0f, -4.0f, 0.0f, 4.0f
    };
    int NUM = 500;
    float vArraynew[] = new float[2 * NUM];
    int index = 0;
    FloatBuffer vertexAxis, vertexHail;
    ArrayList<HailVertex> verterxHails = new ArrayList<HailVertex>();

    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        createSinArray();
//        ByteBuffer vbb2 = ByteBuffer.allocateDirect(vArraynew.length * 4);
//        vbb2.order(ByteOrder.nativeOrder());
//        vertexHail = vbb2.asFloatBuffer();
//        vertexHail.put(vArraynew);
//        vertexHail.position(0);

        ByteBuffer vbb = ByteBuffer.allocateDirect(vArrayAxis.length * 4);
        vbb.order(ByteOrder.nativeOrder());
        vertexAxis = vbb.asFloatBuffer();
        vertexAxis.put(vArrayAxis);
        vertexAxis.position(0);
        
//        calculateVertexs(mInit);
//        handleVertexs();
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
        gl.glLineWidth(8);
        gl.glDrawArrays(GL10.GL_LINES, 0, 4);
    }

    public void DrawHailArray(GL10 gl)
    {
        gl.glTranslatef(-(float)W/2, -(float)H/2, 0);
        //gl.glRotatex(-80, 0, 1, 0);
        gl.glVertexPointer(2, GL10.GL_FLOAT, 0, vertexHail);

        gl.glColor4f(1.0f, 0.0f, 0.0f, 1.0f);
        // gl.glPointSize(8);
        //gl.glEnable (GL10.GL_POINT_SMOOTH);
        //gl.glHint (GL10.GL_POINT_SMOOTH, GL10.GL_NICEST);
        //gl.glLineWidth(4);
        gl.glDrawArrays(type, 0, verterxHails.size());
    }

    public void DrawScene(GL10 gl) {
        super.DrawScene(gl);

 
        calculateVertexs(mInit);
        handleVertexs();
        gl.glMatrixMode(GL10.GL_MODELVIEW);
        gl.glLoadIdentity();
        gl.glTranslatef(0, 0, -dis);
        //gl.glTranslatef(0, 0, -16);
        
        

        gl.glEnableClientState(GL10.GL_VERTEX_ARRAY);

       // DrawAxis(gl);
        DrawHailArray(gl);

        gl.glDisableClientState(GL10.GL_VERTEX_ARRAY);

    }
    public boolean onTouchEvent(MotionEvent event) {
        if(event.getAction()==MotionEvent.ACTION_UP) {
            if(type == GL10.GL_LINE_STRIP) {
                type = GL10.GL_POINTS;
            }else {
                type = GL10.GL_LINE_STRIP;
            }
            mGLSurfaceView.requestRender();
        }
        return super.onTouchEvent(event);
    }

    long calculateValue(long x) {
        long ret = x >> 1;
        if ((x & 0x01) != 0)
        {
            ret = 3 * x + 1;
        }
        return ret;
    }

    void calculateVertexs(long s0) {
        long  t = s0;
        long x = 0;
        bigY = 0;
        verterxHails.clear();
        verterxHails.add(new HailVertex(0, s0));
        do
        {
            t = calculateValue(t);
            if(t > bigY)
            {
                bigY = t;
            }
            x++;
            verterxHails.add(new HailVertex(x,t));
        }while(t!=1);
        bigX = x;
        
//        scaleX = (double)OpenGLESActivity.w/bigX;
//        scaleY = (double)OpenGLESActivity.h/bigY;
        W = (double)OpenGLESActivity.w/(double)OpenGLESActivity.h*H;
        scaleX = W/bigX;
        scaleY = H/bigY;
        Log.e("peitao","OpenGLESActivity.h = " + OpenGLESActivity.h+"OpenGLESActivity.w = "+OpenGLESActivity.w);
        Log.e("peitao","bigX = " + bigX+"bigY = "+bigY);
        Log.e("peitao","scaleX = " + scaleX+"scaleY = "+scaleY);
    }
    
    void handleVertexs() {
        float vArraynew[] = new float[2 * verterxHails.size()];
        
        int j = 0;
         for(int i = 0;i < verterxHails.size();i++) {
             vArraynew[j++] = (float) (scaleX*verterxHails.get(i).x);
             vArraynew[j++] = (float) (scaleY*verterxHails.get(i).y);
             Log.i("peitao", scaleX*verterxHails.get(i).x+"#"+scaleX*verterxHails.get(i).y);
         }
         
         ByteBuffer vbb2 = ByteBuffer.allocateDirect(vArraynew.length * 4);
         vbb2.order(ByteOrder.nativeOrder());
         vertexHail = vbb2.asFloatBuffer();
         vertexHail.put(vArraynew);
         vertexHail.position(0);
    }

}
