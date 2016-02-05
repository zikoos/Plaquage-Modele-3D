#include "viewer.h"
#include <objet.h>
#include <mnt.h>

/***********************   Affichage du MNT  ********************************/

ViewerMNT::ViewerMNT(QWidget *parent) : QGLViewer(parent)
{
    restoreStateFromFile();
}

void ViewerMNT::init()
{
  setSceneBoundingBox(qglviewer::Vec (900000,1900020,318.8), qglviewer::Vec(999975,1944980,3270));
  showEntireScene();

}

void ViewerMNT::draw(){

    mntteste.drawMnt();
    objetteste.drawobjetfinal();

}

void ViewerMNT::postDraw(){

    //if(!((mntteste.getxmax() == 0 && mntteste.getymax() == 0) && mntteste.getzmax() == 0)){
      //  setSceneBoundingBox(qglviewer::Vec (mntteste.getxmin(),mntteste.getymin(),mntteste.getzmin()), qglviewer::Vec(mntteste.getxmax(),mntteste.getymax(),mntteste.getzmax()));
        //showEntireScene();
    //}

}

/***********************   Affichage de L'objet  ********************************/

ViewerObjet::ViewerObjet(QWidget *parent) : QGLViewer(parent)
{
    restoreStateFromFile();

}


void ViewerObjet::init()
{


}

void ViewerObjet::draw(){

    objetteste.drawobjet();
}

void ViewerObjet:: postDraw(){

    if(!((objetteste.getxMax() ==0 && objetteste.getyMax() == 0) && objetteste.getzMax() == 0)){

        setSceneBoundingBox(qglviewer::Vec(objetteste.getxMin()*2,objetteste.getyMin()*2,objetteste.getzMin()*2), qglviewer::Vec(objetteste.getxMax()*1.5,objetteste.getyMax()*1.5,objetteste.getzMax()*1.5));
        showEntireScene();
    }

 }

/***********************   Affichage de L'objet final ********************************/

ViewerObjetF::ViewerObjetF(QWidget *parent) : QGLViewer(parent)
{

}

void ViewerObjetF::init()
{
    setSceneBoundingBox(qglviewer::Vec(900000, 1944980, 1073), qglviewer::Vec(900000+100,1944980+100,1073+1600));
    showEntireScene();

}

void ViewerObjetF::draw(){
   objetteste.drawobjetfinal();
   //glColor3b(1,0,0);
}

void ViewerObjetF:: postDraw(){


 }
