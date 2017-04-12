#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QAction>
#include <QLabel>
#include <QMainWindow>
#include <QMenu>
#include <QActionGroup>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
protected:
  #ifndef QT_NO_CONTEXTMENU
      void contextMenuEvent(QContextMenuEvent *event) override;
  #endif // QT_NO_CONTEXTMENU
    
private:
    Ui::MainWindow *ui;
    
private slots:
      void newFile();
      void open();
      void close();
      void saveAs();
      void save();
      void print();
      void exit();
      void undo();
      void redo();
      void cut();
      void copy();
      void paste();
      void bold();
      void italic();
      void leftAlign();
      void rightAlign();
      void justify();
      void center();
      void setLineSpacing();
      void setParagraphSpacing();
      
private:
      void createActions();
      void createMenus();
      
      QMenu *fileMenu;
      QMenu *editMenu;
      QMenu *formatMenu;
      QActionGroup *alignmentGroup;
      QAction *newAct;
      QAction *openAct;
      QAction *saveAsAct;
      QAction *saveAct;
      QAction *closeAct;
      QAction *printAct;
      QAction *exitAct;
      QAction *undoAct;
      QAction *redoAct;
      QAction *cutAct;
      QAction *copyAct;
      QAction *pasteAct;
      QAction *boldAct;
      QAction *italicAct;
      QAction *leftAlignAct;
      QAction *rightAlignAct;
      QAction *justifyAct;
      QAction *centerAct;
      QAction *setLineSpacingAct;
      QAction *setParagraphSpacingAct;
      QLabel *infoLabel;
};

#endif // MAINWINDOW_H
