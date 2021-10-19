#include <iostream>
#include <QtWidgets>

#include "LoginPage.h"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    /*QWidget window;
    window.resize(320, 240);
    window.show();
    window.setWindowTitle(QApplication::translate("toplevel", "Top Level Widget"));
    return app.exec();*/

    LoginPage loginPage;
    loginPage.resize(400, 400);
    loginPage.show();
    return app.exec();
}
