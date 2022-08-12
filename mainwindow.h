#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    class QA{
    public:
        QString Question;
        QString Answer;
        };

    QA questionBank[14];
    int saniye=59;
    int dakika=3;
    quint32 *randomTypeSetter(int range); //Returns pointer of 10 element array which include all numbers 0 to given range but in random mixed order

public slots:
    void timerfunction();
    void questionBankImporter(QString filePath);
private slots:
   void on_startButton_clicked();

    void on_box_1_textChanged(const QString &arg1);

    void on_box_2_textChanged(const QString &arg1);

    void on_box_3_textChanged(const QString &arg1);

    void on_box_4_textChanged(const QString &arg1);

    void on_box_6_textChanged(const QString &arg1);

    void on_box_7_textChanged(const QString &arg1);

    void on_box_8_textChanged(const QString &arg1);

    void on_box_9_textChanged(const QString &arg1);

    void on_box_10_textChanged(const QString &arg1);

    void on_box_5_textChanged(const QString &arg1);

    void on_pauseButton_clicked();
    void on_confirmButton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
//    QTimer *timer2;
};
#endif // MAINWINDOW_H
