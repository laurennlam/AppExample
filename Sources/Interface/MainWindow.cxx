#include "MainWindow.h"

// This is included here because it is forward declared in
// RenderWindowUISingleInheritance.h
#include "ui_MainWindow.h"

#include <vtkGenericOpenGLRenderWindow.h>
#include <vtkNamedColors.h>
#include <vtkNew.h>
#include <vtkPolyDataMapper.h>
#include <vtkProperty.h>
#include <vtkRenderWindow.h>
#include <vtkRenderer.h>
#include <vtkSphereSource.h>

// Constructor
MainWindow::MainWindow() {
  this->ui = new Ui_MainWindow;
  this->ui->setupUi(this);

  vtkNew<vtkNamedColors> colors;

  vtkNew<vtkGenericOpenGLRenderWindow> renderWindow;
  this->ui->qvtkwidget->SetRenderWindow(renderWindow);

  // Sphere
  vtkNew<vtkSphereSource> sphereSource;
  sphereSource->Update();
  vtkNew<vtkPolyDataMapper> sphereMapper;
  sphereMapper->SetInputConnection(sphereSource->GetOutputPort());
  vtkNew<vtkActor> sphereActor;
  sphereActor->SetMapper(sphereMapper);
  sphereActor->GetProperty()->SetColor(colors->GetColor4d("Tomato").GetData());

  // VTK Renderer
  vtkNew<vtkRenderer> renderer;
  renderer->AddActor(sphereActor);
  renderer->SetBackground(colors->GetColor3d("SteelBlue").GetData());

  // VTK/Qt wedded
  this->ui->qvtkwidget->GetRenderWindow()->AddRenderer(renderer);
  this->ui->qvtkwidget->GetRenderWindow()->SetWindowName(
      "RenderWindowUISingleInheritance");
  //// Set up action signals and slots
  //connect(this->ui->actionExit, SIGNAL(triggered()), this, SLOT(slotExit()));
}

MainWindow::~MainWindow() {}

//void MainWindow::slotExit() { qApp->exit(); }
