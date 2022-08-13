#ifndef ITEMTABLEDISPLAY_H
#define ITEMTABLEDISPLAY_H

#include <QTableWidget>
#include <QSqlQuery>
#include <QObject>
#include <QScrollBar>
#include <QTableWidgetItem>
#include <QSqlError>
#include <QSqlRecord>
#include <QSqlField>

class ItemTableDisplay : public QObject
{
    Q_OBJECT
public:
    ItemTableDisplay();
    void setTable(QTableWidget *table);
    void setRowsDisplayedAtTime(int number);
    bool setQuery(QString stringQuery);

public slots:
    void addMoreItems(int value);
    void onAddMoreItems();

private:
    QSqlQuery qry;
    QTableWidget *table;
    int rowsDisplayAtTime;
    int tableNumberColumns;
};

#endif // ITEMTABLEDISPLAY_H
