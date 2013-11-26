
package com.peter.opengldemo;

import java.nio.ByteBuffer;
import java.nio.ByteOrder;
import java.nio.FloatBuffer;
import java.util.ArrayList;

import javax.microedition.khronos.opengles.GL10;

import android.app.Activity;
import android.opengl.GLES10;
import android.opengl.GLSurfaceView;
import android.opengl.GLU;
import android.os.Bundle;
import android.util.Log;
import android.view.MotionEvent;
import android.view.View;
import android.view.View.OnClickListener;
import android.view.Window;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.EditText;
import android.widget.RelativeLayout;
import android.widget.Toast;

class HailVertex2 {
    public long x;
    public long y;
    public HailVertex2(long x,long y) {
        this.x = x;
        this.y = y;
    }
}
public class DrawHail2 extends  Activity implements IOpenGLDemo {

    double scaleX = 1.0f;
    double scaleY = 1.0f;
    
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
    RelativeLayout main;
    EditText eText;
    Button button;
    /** Called when the activity is first created. */
    @Override
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        super.onCreate(savedInstanceState);
        this.requestWindowFeature(Window.FEATURE_NO_TITLE);
        getWindow().setFlags(WindowManager.LayoutParams.FLAG_FULLSCREEN,
                WindowManager.LayoutParams.FLAG_FULLSCREEN);

        mGLSurfaceView = new GLSurfaceView(this);
        mGLSurfaceView.setRenderer(new OpenGLRenderer(this));
        mGLSurfaceView.setRenderMode(GLSurfaceView.RENDERMODE_WHEN_DIRTY);
        setContentView(R.layout.activity_main);
        main = (RelativeLayout) findViewById(R.id.main);
        eText = (EditText) findViewById(R.id.editText1);
        button = (Button) findViewById(R.id.button1);
        button.setOnClickListener(new OnClickListener() {
            
            @Override
            public void onClick(View v) {
                // TODO Auto-generated method stub
                Log.i("peter", "num = "+eText.getText().toString());
                String num = eText.getText().toString();
                boolean err = false;
                long input = 0;
                try {
                    input = Long.valueOf(num);
                } catch (Exception e) {
                    err = true;
                    Toast.makeText(DrawHail2.this, "乱来，不按套路出牌！", Toast.LENGTH_SHORT).show();
                }
                if(err) return;
                
                if(input > 400000000) {
                    Toast.makeText(DrawHail2.this, "天啊，太大了，崩溃中...", Toast.LENGTH_SHORT).show();
                    return;
                }
                if(input == 0) {
                    Toast.makeText(DrawHail2.this, "0还要我算！鄙视你！", Toast.LENGTH_SHORT).show();
                    return;
                }
                
                mInit = input;
                mGLSurfaceView.requestRender();
                
                
            }
        });
        
        main.addView(mGLSurfaceView,0);
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
    @Override
    protected void onResume() {
        // Ideally a game should implement onResume() and onPause()
        // to take appropriate action when the activity looses focus
        super.onResume();
        mGLSurfaceView.onResume();
    }

    @Override
    protected void onPause() {
        // Ideally a game should implement onResume() and onPause()
        // to take appropriate action when the activity looses focus
        super.onPause();
        mGLSurfaceView.onPause();
    }

    protected GLSurfaceView mGLSurfaceView;
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
        gl.glTranslatef(-OpenGLESActivity.w/2, -OpenGLESActivity.h/2, 0);
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
        GLES10.glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
        // Clears the screen and depth buffer.
        GLES10.glClear(GL10.GL_COLOR_BUFFER_BIT | GL10.GL_DEPTH_BUFFER_BIT);

        gl.glMatrixMode(GL10.GL_PROJECTION);
        // Reset the projection matrix
        gl.glLoadIdentity();
        // Calculate the aspect ratio of the window
      GLU.gluPerspective(gl, 90.0f, (float) OpenGLESActivity.w / (float) OpenGLESActivity.h, (float)OpenGLESActivity.h/2,
              OpenGLESActivity.h);
 
        calculateVertexs(mInit);
        handleVertexs();
        gl.glMatrixMode(GL10.GL_MODELVIEW);
        gl.glLoadIdentity();
        gl.glTranslatef(0, 0, -OpenGLESActivity.h/2);
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
        
        scaleX = (double)OpenGLESActivity.w/bigX;
        scaleY = (double)OpenGLESActivity.h/bigY;
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
