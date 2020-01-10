#include "VTKOpenGLWidget.h"

#include <stdio.h>

VTKOpenGLWidget::VTKOpenGLWidget(QWidget* parent) :
  Superclass(parent)
{
  std::cout << "test" << std::endl;
}

VTKOpenGLWidget::~VTKOpenGLWidget()
{
}
