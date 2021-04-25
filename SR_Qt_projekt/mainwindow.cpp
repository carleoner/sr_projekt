#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    int sizeX = 600;
    int sizeY = 600;

    QImage image = QImage(sizeX, sizeY, QImage::Format_RGB32);
    image.fill(QColor(255, 255, 255));

    for(int i=1;i<12;i++){
    image = DrawLetterA(70, 50*i, image);
    image = DrawLetterW(110, 50*i, image);
    image = DrawLetterN(160, 50*i, image);
    image = DrawLetterL(200, 50*i, image);
    image = DrawLetterC(265, 50*i, image);
    image = DrawLetterD(285, 50*i, image);
    }

    //image = DrawCircle(300,300,50, image);

    QGraphicsScene *graphic = new QGraphicsScene(this);

    graphic->addPixmap(QPixmap::fromImage(image));

    ui->graphicsView->setScene(graphic);
}

MainWindow::~MainWindow()
{
    delete ui;
}

QImage MainWindow::DrawLetterA (int x, int y, QImage image)
{
    image = DrawLine(x, y, x+20, y-45, image);
    image = DrawLine(x+20, y-45, x+40, y, image);
    image = DrawLine(x+5, y-25, x+35, y-25, image);
    return image;
}

QImage MainWindow::DrawLetterW (int x, int y, QImage image)
{
    image = DrawLine(x, y-25, x+10, y, image);
    image = DrawLine(x+10, y, x+20, y-20, image);
    image = DrawLine(x+20, y-20, x+30, y, image);
    image = DrawLine(x+30, y, x+40, y-25, image);
    return image;
}

QImage MainWindow::DrawLetterN (int x, int y, QImage image)
{
    image = DrawLine(x, y-25, x, y, image);
    image = DrawLine(x, y-25, x+15, y, image);
    image = DrawLine(x+15, y, x+15, y-25, image);
    return image;
}

QImage MainWindow::DrawLetterL (int x, int y, QImage image)
{
    image = DrawLine(x, y, x, y-45, image);
    image = DrawLine(x, y, x+30, y, image);
    return image;
}

QImage MainWindow::DrawLetterC (int x_pos, int y_pos, QImage image)
{
    y_pos = y_pos - 23;

    double promien = 24;

    double x = 0;
    double y = promien;

    double c = 2*(1 - promien);

    while(x<=y){
        image.setPixel(x_pos + -x,y_pos + y, qRgb(0, 0, 0));
        image.setPixel(x_pos + -x,y_pos + -y, qRgb(0, 0, 0));

        image.setPixel(x_pos + -y,y_pos + x, qRgb(0, 0, 0));
        image.setPixel(x_pos + -y,y_pos + -x, qRgb(0, 0, 0));
        if(2*c > 1-2*y){
            y--;
            c -= 2*y-1;
        }
        x++;
        c+=2*x+1;
    }
    return image;
}

QImage MainWindow::DrawLetterD (int x_pos, int y_pos, QImage image)
{
    image = DrawLine(x_pos, y_pos, x_pos, y_pos-45, image);

    x_pos = (double)x_pos;
    y_pos = (double)(y_pos - 23);
    double promien = 24;
    double x = 0;
    double y = promien;
    double c = 2*(1 - promien);

    while(x<=y)
    {
        image.setPixel(x_pos + x, y_pos + y, qRgb(0, 0, 0));
        image.setPixel(x_pos + x,y_pos + -y, qRgb(0, 0, 0));

        image.setPixel(x_pos + y,y_pos + x, qRgb(0, 0, 0));
        image.setPixel(x_pos + y,y_pos + -x, qRgb(0, 0, 0));
        if(2*c > 1-2*y){
            y--;
            c -= 2*y-1;
        }
        x++;
        c+=2*x+1;
    }
    return image;
}

QImage MainWindow::DrawLine ( int x1, int y1, int x2, int y2, QImage image )
{
    int delta_x, delta_y, g, h, c;

    delta_x = x2-x1;
    if (delta_x > 0)
        g = +1;
    else
        g = -1;
    delta_x = abs(delta_x);
    delta_y = y2-y1;
    if (delta_y > 0)
        h = +1;
    else
        h = -1;
    delta_y = abs(delta_y);
    if (delta_x > delta_y)
    {
        c = -delta_x;
        while (x1 != x2) {
        image.setPixel(x1,y1, qRgb(0, 0, 0));
        c += 2*delta_y;
        if (c > 0)
        {
            y1 += h;
            c -= 2*delta_x;
        }
        x1 += g;
        }
    }
    else
    {
        c = -delta_y;
        while (y1 != y2)
        {
            image.setPixel(x1,y1, qRgb(0, 0, 0));
            c += 2*delta_x;
            if (c > 0)
            {
                x1 += g;
                c -= 2*delta_y;
            }
            y1 += h;
        }
    }
    return image;
}


QImage MainWindow::DrawCircle ( double x_pos, double y_pos, double promien, QImage image )
{
    double x = 0;
    double y = promien;

    double c = 2*(1 - promien);

    while(x<=y){
        image.setPixel(x_pos + x, y_pos + y, qRgb(0, 0, 0));
        image.setPixel(x_pos + -x,y_pos + y, qRgb(0, 0, 0));
        image.setPixel(x_pos + -x,y_pos + -y, qRgb(0, 0, 0));
        image.setPixel(x_pos + x,y_pos + -y, qRgb(0, 0, 0));

        image.setPixel(x_pos + y,y_pos + x, qRgb(0, 0, 0));
        image.setPixel(x_pos + -y,y_pos + x, qRgb(0, 0, 0));
        image.setPixel(x_pos + -y,y_pos + -x, qRgb(0, 0, 0));
        image.setPixel(x_pos + y,y_pos + -x, qRgb(0, 0, 0));
        if(2*c > 1-2*y){
            y--;
            c -= 2*y-1;
        }
        x++;
        c+=2*x+1;
    }
    return image;
}

