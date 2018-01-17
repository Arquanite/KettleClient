#include "productstate.h"
#include "typeconverter.h"
#include <QNetworkReply>
#include <QJsonDocument>
#include <QMessageBox>

#include "productdialog.h"

ProductState::ProductState(NetworkService *service, JSONModel *model, QWidget *parent) : AbstractState(service, model, parent){

}


void ProductState::getList(){
    QNetworkReply *reply = m_service->getProducts();
    reply->connect(reply, &QNetworkReply::finished, [=](){
        m_model->setSourceData(TypeConverter::toJSONAble(TypeConverter::toProduct(QJsonDocument::fromJson(reply->readAll()).array())));
    });
}

void ProductState::add(){
    ProductDialog *dialog = new ProductDialog(m_parent);
    if(dialog->exec() == QDialog::Accepted){
        m_service->post(dialog->product);
    }
}

void ProductState::update(){
    ProductDialog *dialog = new ProductDialog(m_parent);
    dialog->product.fromJSON(m_model->currentJSON()->toJSON());
    dialog->reload();
    if(dialog->exec() == QDialog::Accepted){
        m_service->update(dialog->product);
    }
}

void ProductState::remove(){
    if(QMessageBox::question(m_parent, "Are you sure?", "Do you really want to remove selected item?") == QMessageBox::Yes){
        Product p = Product::builder(0, "").build();
        p.fromJSON(m_model->currentJSON()->toJSON());
        m_service->deleteResource(p);
    }
}
