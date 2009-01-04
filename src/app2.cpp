

#include <QtGui>
#include "app2.h"

#include <QTextEdit>
#include <QTextStream>
#include <QCloseEvent>
#include <QFileDialog>

app2::app2()
{
    scene = new QGraphicsScene;

    view = new QGraphicsView(scene);
    //view->setRenderHint(QPainter::Antialiasing);
    view->setAlignment(Qt::AlignLeft | Qt::AlignTop);    
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOn);

    setCentralWidget(view);


    createActions();
    createMenus();
    createToolBars();
    createStatusBar();

    readSettings();

    setCurrentFile("");
}

void app2::closeEvent(QCloseEvent *event)
{
    if (maybeSave()) {
        writeSettings();
        event->accept();
    } else {
        event->ignore();
    }
}

void app2::newFile()
{
    if (maybeSave()) {
        setCurrentFile("");
    }
}

void app2::open()
{
    if (maybeSave()) {
        QString fileName = QFileDialog::getOpenFileName(this);
        if (!fileName.isEmpty())
            loadFile(fileName);
    }
}

bool app2::save()
{
    if (curFile.isEmpty()) {
        return saveAs();
    } else {
        return saveFile(curFile);
    }
}

bool app2::saveAs()
{
    QString fileName = QFileDialog::getSaveFileName(this);
    if (fileName.isEmpty())
        return false;

    return saveFile(fileName);
}

void app2::about()
{
    QMessageBox::about(this, tr("About Application"),
                       tr("The <b>Application</b> example demonstrates how to "
                          "write modern GUI applications using Qt, with a menu bar, "
                          "toolbars, and a status bar."));
}

void app2::documentWasModified()
{
    setWindowModified(true);
}

void app2::createActions()
{
    createFileActions();
    createAboutActions();
    createZoomActions();
}

void app2::createMenus()
{
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(saveAsAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);

    viewMenu = menuBar()->addMenu(tr("&View"));
    viewMenu->addAction(zoomInAct);
    viewMenu->addAction(zoomOutAct);

    menuBar()->addSeparator();

    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
    helpMenu->addAction(aboutQtAct);
}

void app2::createToolBars()
{
    fileToolBar = addToolBar(tr("File"));
    fileToolBar->addAction(newAct);
    fileToolBar->addAction(openAct);
    fileToolBar->addAction(saveAct);

    editToolBar = addToolBar(tr("View"));
}

void app2::createStatusBar()
{
    statusBar()->showMessage(tr("Ready"));
}

void app2::readSettings()
{
    QSettings settings("cjd", "App2");
    QPoint pos = settings.value("pos", QPoint(100, 100)).toPoint();
    QSize size = settings.value("size", QSize(450, 450)).toSize();
    resize(size);
    move(pos);
    zoomFactor = settings.value("zoomFactor", 1.2).toDouble();
}

void app2::writeSettings()
{
    QSettings settings("cjd", "App2");
    settings.setValue("pos", pos());
    settings.setValue("size", size());
    settings.setValue("zoomFactor", zoomFactor);
}

bool app2::maybeSave()
{
/*
    if (textEdit->document()->isModified()) {
        int ret = QMessageBox::warning(this, tr("Application"),
                                       tr("The document has been modified.\n"
                                          "Do you want to save your changes?"),
                                       QMessageBox::Yes | QMessageBox::Default,
                                       QMessageBox::No,
                                       QMessageBox::Cancel | QMessageBox::Escape);
        if (ret == QMessageBox::Yes)
            return save();
        else if (ret == QMessageBox::Cancel)
            return false;
    }
*/
    return true;
}

void app2::loadFile(const QString &fileName)
{
    QApplication::setOverrideCursor(Qt::WaitCursor);
    image = new QImage(fileName);
    QApplication::restoreOverrideCursor();

    if (image->isNull()) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot read image file %1.")
                             .arg(fileName));
        return;
    }

    QApplication::setOverrideCursor(Qt::WaitCursor);
    scene->setBackgroundBrush(*image);
    fitViewToImage();
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File loaded"), 2000);
}

bool app2::saveFile(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QFile::WriteOnly | QFile::Text)) {
        QMessageBox::warning(this, tr("Application"),
                             tr("Cannot write file %1:\n%2.")
                             .arg(fileName)
                             .arg(file.errorString()));
        return false;
    }

    QTextStream out(&file);
    QApplication::setOverrideCursor(Qt::WaitCursor);
    //out << textEdit->toPlainText();
    QApplication::restoreOverrideCursor();

    setCurrentFile(fileName);
    statusBar()->showMessage(tr("File saved"), 2000);
    return true;
}

void app2::setCurrentFile(const QString &fileName)
{
    curFile = fileName;
    //textEdit->document()->setModified(false);
    setWindowModified(false);

    QString shownName;
    if (curFile.isEmpty())
        shownName = "untitled";
    else
        shownName = strippedName(curFile);

    setWindowTitle(tr("%1[*] - %2").arg(shownName).arg(tr("Application")));
}

QString app2::strippedName(const QString &fullFileName)
{
    return QFileInfo(fullFileName).fileName();
}

app2::~app2()
{

}



/*!
    \fn app2::zoomIn()
 */
void app2::zoomIn()
{
    view->scale(zoomFactor, zoomFactor);
    statusBar()->showMessage(tr("Zoomed in"), 2000);
}


/*!
    \fn app2::zoomOut()
 */
void app2::zoomOut()
{
    view->scale(1/zoomFactor, 1/zoomFactor);
    if(view->matrix().m11() < minScale)
        fitViewToImage();
    statusBar()->showMessage(tr("Zoomed out"), 2000);
}


/*!
    \fn app2::createZoomActions()
 */
void app2::createZoomActions()
{
    zoomInAct = new QAction(tr("Zoom &In"), this);
    zoomInAct->setShortcut(tr("Ctrl++"));
    zoomInAct->setStatusTip(tr("Zooms In"));
    connect(zoomInAct, SIGNAL(triggered()), this, SLOT(zoomIn()));

    zoomOutAct = new QAction(tr("Zoom &Out"), this);
    zoomOutAct->setShortcut(tr("Ctrl+-"));
    zoomOutAct->setStatusTip(tr("Zooms Out"));
    connect(zoomOutAct, SIGNAL(triggered()), this, SLOT(zoomOut()));
}


/*!
    \fn app2::createAboutActions()
 */
void app2::createAboutActions()
{
    aboutAct = new QAction(tr("&About"), this);
    aboutAct->setStatusTip(tr("Show the application's About box"));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

    aboutQtAct = new QAction(tr("About &Qt"), this);
    aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
    connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}


/*!
    \fn app2::createFileActions()
 */
void app2::createFileActions()
{
    newAct = new QAction(QIcon(":/filenew.xpm"), tr("&New"), this);
    newAct->setShortcut(tr("Ctrl+N"));
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

    openAct = new QAction(QIcon(":/fileopen.xpm"), tr("&Open..."), this);
    openAct->setShortcut(tr("Ctrl+O"));
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

    saveAct = new QAction(QIcon(":/filesave.xpm"), tr("&Save"), this);
    saveAct->setShortcut(tr("Ctrl+S"));
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

    saveAsAct = new QAction(tr("Save &As..."), this);
    saveAsAct->setStatusTip(tr("Save the document under a new name"));
    connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcut(tr("Ctrl+Q"));
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
}


/*!
    \fn app2::FitViewToImage()
 */
void app2::fitViewToImage()
{
    scene->setSceneRect(image->rect());
    view->setSceneRect(image->rect());
    view->fitInView(image->rect());
    minScale = view->matrix().m11();
}
