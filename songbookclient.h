#ifndef SONGBOOKCLIENT_H
#define SONGBOOKCLIENT_H

#include <QMainWindow>
#include <QSystemTrayIcon>
#include <QTimer>
#include "dialogsettings.h"
#include "requeststablemodel.h"
#include "okjsongbookapi.h"
#include "settings.h"
#include "dialogupdate.h"

namespace Ui {
class SongbookClient;
}

class SongbookClient : public QMainWindow
{
    Q_OBJECT

public:
    explicit SongbookClient(QWidget *parent = 0);
    ~SongbookClient();

private:
    Ui::SongbookClient *ui;
    QSystemTrayIcon *icon;
    DialogSettings *dlgSettings;
    DialogUpdate *dlgUpdate;
    RequestsTableModel *reqModel;
    OKJSongbookAPI *sbApi;
    Settings settings;
    QTimer *refreshTimer;
    QTimer *oneShot;
    QTimer *blinkTimer;
    QMenu *iconMenu;
    QAction *showAction;
    QAction *hideAction;
    QAction *exitAction;

private slots:
    void iconActivated(QSystemTrayIcon::ActivationReason reason);
    void on_btnHide_clicked();
    void closeProgram();
    void on_btnRefresh_clicked();
    void requestsChanged(OkjsRequests requests);
    void venuesChanged(OkjsVenues venues);
    void autoSizeCols();
    void synchronized(QTime updateTime);
    void on_tableView_clicked(const QModelIndex &index);
    void on_btnClear_clicked();
    void on_cbxVenue_currentIndexChanged(int index);
    void on_checkBoxAccepting_clicked(bool checked);
    void blinkTimerTimeout();

protected:
    void closeEvent(QCloseEvent *event);
    void resizeEvent(QResizeEvent *event);
};

#endif // SONGBOOKCLIENT_H
