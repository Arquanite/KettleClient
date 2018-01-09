#include "randomaccesslist.h"

RandomAccessList::RandomAccessList(){

}

RandomAccessList::RandomAccessList(std::initializer_list<QString> init){
    m_list = QList<QString>(init);
}

QString RandomAccessList::get(){
    return m_list.at(qrand()%m_list.size());
}
