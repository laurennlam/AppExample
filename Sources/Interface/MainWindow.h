#pragma once

// Forward Qt class declarations
class Ui_MainWindow;

#include <QMainWindow>
 
 
class MainWindow : public QMainWindow
{
  Q_OBJECT
public:
 
  // Constructor/Destructor
  MainWindow();
  ~MainWindow();
 
//public slots:
// 
//  virtual void slotExit();

private:
 
  // Designer form
  Ui_MainWindow *ui;
};
