// Qt includes
#include <QApplication>
#include <QSurfaceFormat>
#include <QVTKOpenGLWidget.h>
#include <QMainWindow>

//// VTK includes
//#include <vtkGenericOpenGLRenderWindow.h>
//#include <vtkNew.h>

// Project includes
#include "Interface/MainWindow.h"
//#include "Interface/MAUIStyle.h"


int main( int argc, char** argv )
{
  QApplication app(argc, argv);
  //MAUIStyle::applyStyle(app);

  MainWindow mw;

  std::string windowTitle = "Cosy - Viewy";
  windowTitle += std::to_string(APP_VERSION_MAJOR);
  windowTitle += "."+ std::to_string(APP_VERSION_MINOR);
  mw.setWindowTitle(windowTitle.c_str());
  mw.show();
  return app.exec();
}
