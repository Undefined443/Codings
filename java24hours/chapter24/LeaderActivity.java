// A program from Chapter 24 of Sams Teach Yourself Java in 24 Hours
// by Rogers Cadenhead, http://www.java24hours.com/

package org.cadenhead.android;

import org.cadenhead.android.util.SystemUiHider;

import android.annotation.TargetApi;
import android.app.Activity;
import android.content.Intent;
import android.net.Uri;
import android.os.Build;
import android.os.Bundle;
import android.os.Handler;
import android.view.MotionEvent;
import android.view.View;

public class LeaderActivity extends Activity {
	final String TAG = "Leader";
	
    private static final boolean AUTO_HIDE = true;
    private static final int AUTO_HIDE_DELAY_MILLIS = 3000;
    private static final boolean TOGGLE_ON_CLICK = true;
    private static final int HIDER_FLAGS = SystemUiHider.FLAG_HIDE_NAVIGATION;
    private SystemUiHider mSystemUiHider;

    public void processClicks(View display) {
         Intent action;
         int id = display.getId();
         switch (id) {
             case (R.id.phonebutton):
                 // making call
                 action = new Intent(Intent.ACTION_DIAL,
                     Uri.parse("tel:202-456-1111"));
                 startActivity(action);
                 break;
             case (R.id.webbutton):
                 // loading browser
                 action = new Intent(Intent.ACTION_VIEW,
                     Uri.parse("http://whitehouse.gov"));
                 startActivity(action);
                 break;
             case (R.id.mapbutton):
                 // loading map
                 action = new Intent(Intent.ACTION_VIEW,
                     Uri.parse("geo:0,0?q=White House, Washington, DC"));
                 startActivity(action);
                 break;
             default:
                 break;
        }
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.activity_leader);

        final View controlsView = findViewById(R.id.fullscreen_content_controls);
        final View contentView = findViewById(R.id.fullscreen_content);

        // Set up an instance of SystemUiHider to control the system UI for
        // this activity.
        mSystemUiHider = SystemUiHider.getInstance(this, contentView, HIDER_FLAGS);
        mSystemUiHider.setup();
        mSystemUiHider
            .setOnVisibilityChangeListener(new SystemUiHider.OnVisibilityChangeListener() {
                // Cached values.
                int mControlsHeight;
                int mShortAnimTime;

                @Override
                @TargetApi(Build.VERSION_CODES.HONEYCOMB_MR2)
                public void onVisibilityChange(boolean visible) {
                    if (Build.VERSION.SDK_INT >= Build.VERSION_CODES.HONEYCOMB_MR2) {
                        // If the ViewPropertyAnimator API is available
                        // (Honeycomb MR2 and later), use it to animate the
                        // in-layout UI controls at the bottom of the
                        // screen.
                        if (mControlsHeight == 0) {
                            mControlsHeight = controlsView.getHeight();
                        }
                        if (mShortAnimTime == 0) {
                            mShortAnimTime = getResources().getInteger(
                                android.R.integer.config_shortAnimTime);
                        }
                        controlsView.animate()
                            .translationY(visible ? 0 : mControlsHeight)
                            .setDuration(mShortAnimTime);
                    } else {
                        // If the ViewPropertyAnimator APIs aren't
                        // available, simply show or hide the in-layout UI
                        // controls.
                        controlsView.setVisibility(visible ? View.VISIBLE : View.GONE);
                    }

                    if (visible && AUTO_HIDE) {
                        // Schedule a hide().
                        delayedHide(AUTO_HIDE_DELAY_MILLIS);
                    }
                }
            });

        // Set up the user interaction to manually show or hide the system UI.
        contentView.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (TOGGLE_ON_CLICK) {
                    mSystemUiHider.toggle();
                } else {
                    mSystemUiHider.show();
                }
            }
        });

        // Upon interacting with UI controls, delay any scheduled hide()
        // operations to prevent the jarring behavior of controls going away
        // while interacting with the UI.
        // findViewById(R.id.dummy_button).setOnTouchListener(mDelayHideTouchListener);
    }

    @Override
    protected void onPostCreate(Bundle savedInstanceState) {
        super.onPostCreate(savedInstanceState);

        // Trigger the initial hide() shortly after the activity has been
        // created, to briefly hint to the user that UI controls
        // are available.
        delayedHide(100);
    }


    /**
     * Touch listener to use for in-layout UI controls to delay hiding the
     * system UI. This is to prevent the jarring behavior of controls going away
     * while interacting with activity UI.
     */
    View.OnTouchListener mDelayHideTouchListener = new View.OnTouchListener() {
        @Override
        public boolean onTouch(View view, MotionEvent motionEvent) {
            if (AUTO_HIDE) {
                delayedHide(AUTO_HIDE_DELAY_MILLIS);
            }
            return false;
        }
    };

    Handler mHideHandler = new Handler();
    Runnable mHideRunnable = new Runnable() {
        @Override
        public void run() {
            mSystemUiHider.hide();
        }
    };

    /**
     * Schedules a call to hide() in [delay] milliseconds, canceling any
     * previously scheduled calls.
     */
    private void delayedHide(int delayMillis) {
        mHideHandler.removeCallbacks(mHideRunnable);
        mHideHandler.postDelayed(mHideRunnable, delayMillis);
    }
}
