

#ifndef APP2_H
#define APP2_H

#include <QMainWindow>
#include <QCloseEvent>

#include <QGraphicsScene>
#include <QGraphicsView>

class QAction;
class QMenu;
class QTextEdit;

class app2: public QMainWindow
{
        Q_OBJECT

    public:
        app2();
        ~app2();

    protected:
        void closeEvent(QCloseEvent *event);

    private slots:
        void newFile();
        void open();
        bool save();
        bool saveAs();
        void about();
        void documentWasModified();
    void zoomIn();
    void zoomOut();
       

    private:
        void createActions();
        void createMenus();
        void createToolBars();
        void createStatusBar();
        void readSettings();
        void writeSettings();
        bool maybeSave();
        void loadFile(const QString &fileName);
        bool saveFile(const QString &fileName);
        void setCurrentFile(const QString &fileName);
        QString strippedName(const QString &fullFileName);

        QTextEdit *textEdit;
        QString curFile;

        QMenu *fileMenu;
        QMenu *viewMenu;
        QMenu *helpMenu;
        QToolBar *fileToolBar;
        QToolBar *editToolBar;
        QAction *newAct;
        QAction *openAct;
        QAction *saveAct;
        QAction *saveAsAct;
        QAction *exitAct;
        QAction *aboutAct;
        QAction *aboutQtAct;

        QAction *zoomInAct;
        QAction *zoomOutAct;

        QGraphicsScene *scene;
    QGraphicsView *view;
    QImage *image;
    double minScale;

    void createZoomActions();
    void createAboutActions();
    void createFileActions();
    void fitViewToImage();
protected:
    double zoomFactor;
};

#endif
