#include <QApplication>
#include <QMainWindow>
#include <QLabel>
#include <QWidget>
#include <QBoxLayout>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QMainWindow window;
    Qwidget *centralWidget = new QWidget(&window);
    QBoxLayout *layout = new QVBoxLayout(centralWidget);
    window.setCentralWidget(centralWidget);
    window.setWindowTitle("Pickle Simulator");
    window.resize(600, 450);
    QLabel *label = new QLabel("Welcome to Your Pickle Store");
    label->setAlignment(Qt::AlignCenter);
    label->setStyleSheet("font-size: 12px; font-weight: bold; color: green;");

    layout->addWidget(label);

    window.show();
    return app.exec();
}