#include "orderstate.h"
#include "typeconverter.h"
#include <QNetworkReply>
#include <QJsonDocument>
#include <QMessageBox>

#include "orderdialog.h"

OrderState::OrderState(NetworkService *service, JSONModel *model, QWidget *parent) : AbstractState(service, model, parent){

}


void OrderState::getList(){
    QNetworkReply *reply = m_service->getOrders();
    reply->connect(reply, &QNetworkReply::finished, [=](){
        m_model->setSourceData(TypeConverter::toJSONAble(TypeConverter::toOrder(QJsonDocument::fromJson(reply->readAll()).array())));
    });
}

void OrderState::add(){
    OrderDialog *dialog = new OrderDialog(m_parent);
    if(dialog->exec() == QDialog::Accepted){
        m_service->post(dialog->order);
    }
}

void OrderState::update(){
    OrderDialog *dialog = new OrderDialog(m_parent);
    dialog->order.fromJSON(m_model->currentJSON()->toJSON());
    dialog->reload();
    if(dialog->exec() == QDialog::Accepted){
        m_service->update(dialog->order);
    }
}

void OrderState::remove(){
    if(QMessageBox::question(m_parent, "Are you sure?", "Do you really want to remove selected item?") == QMessageBox::Yes){
        Order o = Order::builder(0, 0, "").build();
        o.fromJSON(m_model->currentJSON()->toJSON());
        m_service->deleteResource(o);
    }
}
