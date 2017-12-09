#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //creating the Scene

    QGraphicsScene *scene = new QGraphicsScene();

    //Creating the tank

    QGraphicsRectItem *tank = new QGraphicsRectItem();
    tank->setRect(0,0,100,100);

    //add the Tank to the scene
    scene->addItem(tank);

    //Create a view
    QGraphicsView *view = new QGraphicsView();
    view->setScene(scene);

    //Displaying the View
    view->show();




    return a.exec();
}
