#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

namespace Ui {
class Widget;
}

class QMediaPlayer;

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void on_openButton_clicked();

    void on_playButton_clicked();

    void on_pauseButton_clicked();

    void on_stopButton_clicked();

    void on_muteButton_clicked();

    void on_horizontalSlider_valueChanged(int value);

private:
    Ui::Widget *ui;
    QMediaPlayer *mMediaPlayer;
};

#endif // WIDGET_H
