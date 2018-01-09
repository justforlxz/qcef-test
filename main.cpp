#include "mainwindow.h"
#include <DApplication>
#include <qcef_context.h>
#include <qcef_util.h>

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    QCefGlobalSettings settings;

    // Do not use sandbox.
    settings.setNoSandbox(true);

    // Disable GPU process.
    settings.addCommandLineSwitch("--disable-gpu", "");

    const int exit_code = QCefInit(argc, argv, settings);
    if (exit_code >= 0) {
      return exit_code;
    }

    DApplication::loadDXcbPlugin();
    DApplication a(argc, argv);
    a.setTheme("light");

    MainWindow w;
    w.show();

    QCefBindApp(&a);

    return a.exec();
}
