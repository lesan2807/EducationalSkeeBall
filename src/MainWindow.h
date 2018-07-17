#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_DISABLE_COPY(MainWindow)

  private:


  public:
    explicit MainWindow(QWidget* parent = nullptr);
    ~MainWindow();
    void buildInterface();

  public slots:
    void showGameMenu();
    void showLevelsMenu();
};

#endif // MAINWINDOW_H
