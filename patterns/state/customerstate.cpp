#include "customerstate.h"
#include "typeconverter.h"
#include <QNetworkReply>
#include <QJsonDocument>
#include <QMessageBox>

#include "customerdialog.h"

CustomerState::CustomerState(NetworkService *service, JSONModel *model, QWidget *parent) : AbstractState(service, model, parent){

}

void CustomerState::getList(){
    QNetworkReply *reply = m_service->getCustomers();
    reply->connect(reply, &QNetworkReply::finished, [=](){
        m_model->setSourceData(TypeConverter::toJSONAble(TypeConverter::toCustomer(QJsonDocument::fromJson(reply->readAll()).array())));
    });
}

void CustomerState::add(){
    CustomerDialog *dialog = new CustomerDialog(m_parent);
    if(dialog->exec() == QDialog::Accepted){
        m_service->post(dialog->customer);
    }
}

void CustomerState::update(){
    CustomerDialog *dialog = new CustomerDialog(m_parent);
    dialog->customer.fromJSON(m_model->currentJSON()->toJSON());
    dialog->reload();
    if(dialog->exec() == QDialog::Accepted){
        m_service->update(dialog->customer);
    }
}

void CustomerState::remove(){
    if(QMessageBox::question(m_parent, "Are you sure?", "Do you really want to remove selected item?") == QMessageBox::Yes){
        Customer c(0, "", "", "");
        c.fromJSON(m_model->currentJSON()->toJSON());
        m_service->deleteResource(c);
    }
}
