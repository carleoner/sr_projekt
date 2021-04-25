#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QImage DrawLetterA (int, int, QImage);
    QImage DrawLetterW (int, int, QImage);
    QImage DrawLetterN (int, int, QImage);
    QImage DrawLetterL (int, int, QImage);
    QImage DrawLetterC (int, int, QImage);
    QImage DrawLetterD (int, int, QImage);
    QImage DrawLine (int, int, int, int, QImage);
    QImage DrawCircle ( double, double, double, QImage);

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
