#include <QWidget>
#include <Application.h>

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Application application;
    return app.exec();
}
