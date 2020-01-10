#pragma once

// Qt includes
#include <QVTKOpenGLWidget.h>

class VTKOpenGLWidget : public QVTKOpenGLWidget
{
  Q_OBJECT
    typedef QVTKOpenGLWidget Superclass;
public:

  /**
   * Constructor
   */
  explicit VTKOpenGLWidget(QWidget* parent = nullptr);

  /**
   * Destructor
   */
  ~VTKOpenGLWidget();

};
