#include "orderstate.h"
#include "typeconverter.h"
#include <QNetworkReply>
#include <QJsonDocument>

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
//        m_service->post(dialog->);
    }
}
