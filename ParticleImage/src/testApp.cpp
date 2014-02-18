#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	img.loadImage("unstoppable-trex.jpg");
	ofSetBackgroundAuto(false);
    ofSetFrameRate(60);
    ofEnableAlphaBlending();
    ofBackground(0);
}

//--------------------------------------------------------------
void testApp::update(){
    for (int i=0; i<particles.size(); i++) {
        particles[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
	// draw all particle in our vector
    for (int i=0; i<particles.size(); i++) {
        Particle &p = particles[i];
        p.draw();        
    }
        
	// create n particles every frame
    for (int i=0; i<50; i++) {
        createParticle();
    }
    
	// kill particles for performance
    while (particles.size()>1000) {
        particles.erase(particles.begin());
    }
}

void testApp::createParticle() {
    Particle p;
    p.setup();
    p.pos.set(ofRandomWidth(), ofRandomHeight());
    p.color = img.getColor(p.pos.x,p.pos.y);
    particles.push_back(p);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if (key=='s') ofSaveFrame();
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
	ofSetColor(255);
	img.draw(0,0);
}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
