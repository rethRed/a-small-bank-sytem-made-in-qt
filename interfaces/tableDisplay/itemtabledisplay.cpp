#include "itemtabledisplay.h"

ItemTableDisplay::ItemTableDisplay()
{
    this->rowsDisplayAtTime = 30;
}

void ItemTableDisplay::setTable(QTableWidget *table)
{
    QObject::connect(table->verticalScrollBar(),&QScrollBar::valueChanged,this,&ItemTableDisplay::addMoreItems);
    this->table = table;
}

void ItemTableDisplay::setRowsDisplayedAtTime(int number)
{
    this->rowsDisplayAtTime = number;
}



bool ItemTableDisplay::setQuery(QString stringQuery)
{
    if(!this->table)
    {
        return false;
    }

    this->table->clearContents();
    this->table->setRowCount(0);

    if(qry.exec(stringQuery))
    {
        QSqlRecord record = qry.record();
        tableNumberColumns = record.count();
        table->setColumnCount(tableNumberColumns);

        for(int i=1; i < tableNumberColumns; i++)
        {
            QSqlField collumnField = record.field(i);
            QString CollumnName = collumnField.name();
            table->setHorizontalHeaderItem(i , new QTableWidgetItem(CollumnName));
        }
        onAddMoreItems();
        return true;
    }
    else{
        qDebug() << qry.lastError();
    }
    return false;


}

void ItemTableDisplay::addMoreItems(int value)
{
    QWidget *w = qobject_cast<QWidget *>(sender());

    if(w){
        QScrollBar *scrollBar = qobject_cast<QScrollBar*>(sender());

        if(scrollBar->maximum() <= value){
            onAddMoreItems();
        };

    }
}

void ItemTableDisplay::onAddMoreItems()
{
    int iterations = 0;
    for(int i=table->rowCount();this->qry.next();i++)
    {
        iterations++;

        this->table->setRowCount(table->rowCount()+1);

        for(int j = 0; j < this->tableNumberColumns; j++)
        {
            this->table->resizeColumnToContents(j);

            QString value = qry.value(j).toString();
            this->table->setItem(i,j, new QTableWidgetItem(value));

        }
        if(iterations > this->rowsDisplayAtTime ) break;
    }
}




