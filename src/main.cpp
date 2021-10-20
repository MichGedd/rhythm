#include <QWidget>

#include "Application.h"

#include "LoginPage.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    Application application;

    return app.exec();
}
