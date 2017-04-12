#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QContextMenuEvent>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    QWidget *widget = new QWidget;
          setCentralWidget(widget);
          
    infoLabel = new QLabel(tr("<i>Choose a menu option, or right-click to "
                                         "invoke a context menu</i>"));
    infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    infoLabel->setAlignment(Qt::AlignCenter);
               
    createActions();
    createMenus();
               
    QString message = tr("A context menu is available by right-clicking");
    statusBar()->showMessage(message);
               
    setWindowTitle(tr("Jiblets"));
    setMinimumSize(320, 320);
    resize(640, 640);          
}

#ifndef QT_NO_CONTEXTMENU
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(cutAct);
    menu.addAction(copyAct);
    menu.addAction(pasteAct);
    menu.exec(event->globalPos());
}
#endif // QT_NO_CONTEXTMENU

void MainWindow::newFile()
{
    infoLabel->setText(tr("Invoked <b>File|New</b>"));
}

void MainWindow::open()
{
    infoLabel->setText(tr("Invoked <b>File|Open</b>"));
}

void MainWindow::close()
{
    infoLabel->setText(tr("Invoked <b>File|Close</b>"));
}

void MainWindow::save()
{
    infoLabel->setText(tr("Invoked <b>File|Save</b>"));
}

void MainWindow::saveAs()
{
    infoLabel->setText(tr("Invoked <b>File|Save As</b>"));
}

void MainWindow::print()
{
    infoLabel->setText(tr("Invoked <b>File|Print</b>"));
}

void MainWindow::exit()
{
    infoLabel->setText(tr("Invoked <b>File|Exit</b>"));
}

void MainWindow::undo()
{
    infoLabel->setText(tr("Invoked <b>Edit|Undo</b>"));
}

void MainWindow::redo()
{
    infoLabel->setText(tr("Invoked <b>Edit|Redo</b>"));
}

void MainWindow::cut()
{
    infoLabel->setText(tr("Invoked <b>Edit|Cut</b>"));
}

void MainWindow::copy()
{
    infoLabel->setText(tr("Invoked <b>Edit|Copy</b>"));
}

void MainWindow::paste()
{
    infoLabel->setText(tr("Invoked <b>Edit|Paste</b>"));
}

void MainWindow::bold()
{
    infoLabel->setText(tr("Invoked <b>Edit|Format|Bold</b>"));
}

void MainWindow::italic()
{
    infoLabel->setText(tr("Invoked <b>Edit|Format|Italic</b>"));
}

void MainWindow::leftAlign()
{
    infoLabel->setText(tr("Invoked <b>Edit|Format|Left Align</b>"));
}

void MainWindow::rightAlign()
{
    infoLabel->setText(tr("Invoked <b>Edit|Format|Right Align</b>"));
}

void MainWindow::justify()
{
    infoLabel->setText(tr("Invoked <b>Edit|Format|Justify</b>"));
}

void MainWindow::center()
{
    infoLabel->setText(tr("Invoked <b>Edit|Format|Center</b>"));
}

void MainWindow::setLineSpacing()
{
    infoLabel->setText(tr("Invoked <b>Edit|Format|Set Line Spacing</b>"));
}

void MainWindow::setParagraphSpacing()
{
    infoLabel->setText(tr("Invoked <b>Edit|Format|Set Paragraph Spacing</b>"));
}

void MainWindow::createActions()
  {
      newAct = new QAction(tr("&New"), this);
      newAct->setShortcuts(QKeySequence::New);
      newAct->setStatusTip(tr("Create a new file"));
      connect(newAct, &QAction::triggered, this, &MainWindow::newFile);
      
      openAct = new QAction(tr("&Open"), this);
      openAct->setShortcuts(QKeySequence::Open);
      openAct->setStatusTip(tr("Open an existing file"));
      connect(openAct, &QAction::triggered, this, &MainWindow::open);
      
      saveAsAct = new QAction(tr("&Save As.."), this);
      saveAsAct->setStatusTip(tr("Save File As.."));
      connect(saveAsAct, &QAction::triggered, this, &MainWindow::saveAs);
      
      saveAct = new QAction(tr("&Save"), this);
      saveAct->setShortcuts(QKeySequence::Save);
      saveAct->setStatusTip(tr("Save File"));
      connect(saveAct, &QAction::triggered, this, &MainWindow::save);
      
      closeAct = new QAction(tr("&Close"), this);
      closeAct->setShortcuts(QKeySequence::Close);
      closeAct->setStatusTip(tr("Close File"));
      connect(closeAct, &QAction::triggered, this, &MainWindow::close);
      
      printAct = new QAction(tr("&Print"), this);
      printAct->setShortcuts(QKeySequence::Print);
      printAct->setStatusTip(tr("Print File"));
      connect(printAct, &QAction::triggered, this, &MainWindow::print);
      
      exitAct = new QAction(tr("&Exit"), this);
      exitAct->setShortcuts(QKeySequence::Quit);
      exitAct->setStatusTip(tr("Exit the application"));
      connect(exitAct, &QAction::triggered, this, &QWidget::exit);
      
      undoAct = new QAction(tr("&Undo"), this);
      undoAct->setShortcuts(QKeySequence::Undo);
      undoAct->setStatusTip(tr("Undo the last operation"));
      connect(undoAct, &QAction::triggered, this, &MainWindow::undo);
      
      redoAct = new QAction(tr("&Redo"), this);
      redoAct->setShortcuts(QKeySequence::Redo);
      redoAct->setStatusTip(tr("Redo the last operation"));
      connect(redoAct, &QAction::triggered, this, &MainWindow::redo);
      
      cutAct = new QAction(tr("Cu&t"), this);
      cutAct->setShortcuts(QKeySequence::Cut);
      cutAct->setStatusTip(tr("Cut selection to clipboard"));
      connect(cutAct, &QAction::triggered, this, &MainWindow::cut);
      
      copyAct = new QAction(tr("&Copy"), this);
      copyAct->setShortcuts(QKeySequence::Copy);
      copyAct->setStatusTip(tr("Copy selection to clipboard"));
      connect(copyAct, &QAction::triggered, this, &MainWindow::copy);
      
      pasteAct = new QAction(tr("&Paste"), this);
      pasteAct->setShortcuts(QKeySequence::Paste);
      pasteAct->setStatusTip(tr("Paste the selection"));
      connect(pasteAct, &QAction::triggered, this, &MainWindow::paste);
      
      boldAct = new QAction(tr("&Bold"), this);
      boldAct->setCheckable(true);
      boldAct->setShortcut(QKeySequence::Bold);
      boldAct->setStatusTip(tr("Make the text bold"));
      connect(boldAct, &QAction::triggered, this, &MainWindow::bold);
      
      QFont boldFont = boldAct->font();
      boldFont.setBold(true);
      boldAct->setFont(boldFont);
      
      italicAct = new QAction(tr("&Italic"), this);
      italicAct->setCheckable(true);
      italicAct->setShortcut(QKeySequence::Italic);
      italicAct->setStatusTip(tr("Make the text italic"));
      connect(italicAct, &QAction::triggered, this, &MainWindow::italic);
      
      QFont italicFont = italicAct->font();
      italicFont.setItalic(true);
      italicAct->setFont(italicFont);
      
      leftAlignAct = new QAction(tr("&Left Align"), this);
      leftAlignAct->setCheckable(true);
      leftAlignAct->setShortcut(tr("Ctrl+L"));
      leftAlignAct->setStatusTip(tr("Left align the selected text"));
      connect(leftAlignAct, &QAction::triggered, this, &MainWindow::leftAlign);
      
      rightAlignAct = new QAction(tr("&Right Align"), this);
      rightAlignAct->setCheckable(true);
      rightAlignAct->setShortcut(tr("Ctrl+R"));
      rightAlignAct->setStatusTip(tr("Right align the selected text"));
      connect(rightAlignAct, &QAction::triggered, this, &MainWindow::rightAlign);
      
      justifyAct = new QAction(tr("&Justify"), this);
      justifyAct->setCheckable(true);
      justifyAct->setShortcut(tr("Ctrl+J"));
      justifyAct->setStatusTip(tr("Justify the selected text"));
      connect(justifyAct, &QAction::triggered, this, &MainWindow::justify);
      
      centerAct = new QAction(tr("&Center"), this);
      centerAct->setCheckable(true);
      centerAct->setShortcut(tr("Ctrl+E"));
      centerAct->setStatusTip(tr("Center the selected text"));
      connect(centerAct, &QAction::triggered, this, &MainWindow::center);
      
      alignmentGroup = new QActionGroup(this);
      alignmentGroup->addAction(leftAlignAct);
      alignmentGroup->addAction(rightAlignAct);
      alignmentGroup->addAction(justifyAct);
      alignmentGroup->addAction(centerAct);
      leftAlignAct->setChecked(true);
      
      setLineSpacingAct = new QAction(tr("Set &Line Spacing..."), this);
      setLineSpacingAct->setStatusTip(tr("Change the gap between the lines of a "
                                               "paragraph"));
      connect(setLineSpacingAct, &QAction::triggered, this, &MainWindow::setLineSpacing);
      
      setParagraphSpacingAct = new QAction(tr("Set &Paragraph Spacing..."), this);
      setParagraphSpacingAct->setStatusTip(tr("Change the gap between paragraphs"));
      connect(setParagraphSpacingAct, &QAction::triggered,
                  this, &MainWindow::setParagraphSpacing);
      
  }

void MainWindow::createMenus()
  {
      fileMenu = menuBar()->addMenu(tr("&File"));
      fileMenu->addAction(newAct);
      fileMenu->addAction(openAct);
      fileMenu->addAction(saveAct);
      fileMenu->addAction(saveAsAct);
      fileMenu->addSeparator();
      fileMenu->addAction(printAct);
      fileMenu->addSeparator();
      fileMenu->addAction(closeAct);
      fileMenu->addAction(exitAct);

      editMenu = menuBar()->addMenu(tr("&Edit"));
      editMenu->addAction(undoAct);
      editMenu->addAction(redoAct);
      editMenu->addSeparator();
      editMenu->addAction(cutAct);
      editMenu->addAction(copyAct);
      editMenu->addAction(pasteAct);
      editMenu->addSeparator();
      
      formatMenu = editMenu->addMenu(tr("&Format"));
      formatMenu->addAction(boldAct);
      formatMenu->addAction(italicAct);
      formatMenu->addSeparator()->setText(tr("Alignment"));
      formatMenu->addAction(leftAlignAct);
      formatMenu->addAction(rightAlignAct);
      formatMenu->addAction(justifyAct);
      formatMenu->addAction(centerAct);
      formatMenu->addSeparator();
      formatMenu->addAction(setLineSpacingAct);
      formatMenu->addAction(setParagraphSpacingAct);
  }

MainWindow::~MainWindow()
{
    delete ui;
}


            
