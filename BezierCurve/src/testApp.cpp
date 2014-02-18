#include "testApp.h"
#include <math.h>

//--------------------------------------------------------------
void testApp::setup()
{
	// Private Member Initialization
	winWidth = ofGetWindowWidth();
	winHeight = ofGetWindowHeight();

	amplitude = 2;
	theta = 0.0;
	
	// Scene Setup
	ofSetWindowTitle("Bezier Example");
	ofSetFrameRate(60);
	ofBackground(255,255,255);

	// Draw Defaults
	ofSetCurveResolution(50);
	ofSetLineWidth(5);
	ofNoFill();
}

//--------------------------------------------------------------
void testApp::update()
{
	theta = theta + .02;
	cy1 = ofMap(sin(theta)*amplitude,-1,1,0,winHeight) ;
	cy2 = ofMap(sin(theta + PI)*amplitude,-1,1,0,winHeight);
}

//--------------------------------------------------------------
void testApp::draw()
{
	// Draw Curve
	ofSetColor(ofMap(sin(theta),-1,1,0,255), ofMap(sin(theta+(PI/2)),-1,1,0,255), ofMap(sin(theta+PI),-1,1,0,255)); // taste the rainbow!
	ofBezier(0, winHeight / 2,
			 winWidth / 2, cy1,
			 winWidth / 2, cy2,
			 winWidth, winHeight / 2);

	ofSetColor(0,0,0);
	
	// Theta GUI text
	std::ostringstream sTheta;
	sTheta << "theta: " << theta;
	ofDrawBitmapString(sTheta.str(),25,25);

	// Amplitude GUI text
	std::ostringstream sAmplitude;
	sAmplitude << "amplitude: " << amplitude;
	ofDrawBitmapString(sAmplitude.str(),25,50);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key)
{
	if (key == 'f')
		ofToggleFullscreen();

	if (key == 'j')
		amplitude -= 1;

	if (key == 'k')
		amplitude += 1;
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){
	winWidth = w;
	winHeight = h;
}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
