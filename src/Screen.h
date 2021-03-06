
#pragma once
#include "Camera.h"
#include "Effect.h"
#include "ColorFilterEffect.h"
#include "AppEvent.h"
#include "ofxOpenCv.h"

struct Display {
    int width;
    int height;
};

class Screen
{
	public:
    
		Screen(int id, int cameraId);
        Screen(int id, int cameraId, vector< Effect* > effects);
    
		int						id;
        bool                    active;
    
		Camera*                 camera;
		bool					cameraReady;

		void					draw();
		void					update();
    
        void                    predrawEffects();
        void                    drawEffects();
        void                    clearEffects();
        void                    addEffects(vector< Effect* > effects);

		unsigned char*          pixels;
		unsigned char*          overlay;
		ofTexture				texture;

		unsigned char*			getPixels();
		void                    setPixels(unsigned char* pixels);
        ofImage                 getVideoFrame();
    
        int                     getDisplayWidth();
        int                     getDisplayHeight();
        Display                 getDisplaySize();
        void                    setDisplaySize(int w, int h);
    
        int                     getHorizontalOffset();
    
    private:
        void                    onPressureEvent(AppEvent::PressureData &e);
    
        vector< Effect* >       effects;
    
        static struct Display display;
    
        int hOffset;
    
//        static int              displayWidth;
//        static int              displayHeight;

};

