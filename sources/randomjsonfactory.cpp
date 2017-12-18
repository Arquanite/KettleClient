#include "randomjsonfactory.h"

RandomJSONFactory::RandomJSONFactory(){
    m_names_m = {"Adam", "Adrian", "Alfred", "August", "Bartosz", "Bożydar", "Bronisław",
                 "Czesław", "Edmund", "Edward", "Filip", "Hektor", "Henryk", "Igor", "Iwan",
                 "Jakub", "Jan", "Janusz", "Jędrzej", "Józef", "Julian", "Kacper", "Kamil",
                 "Karol", "Konrad", "Leon", "Lubomir", "Ludwik", "Maciej", "Marcel", "Marcin",
                 "Marian", "Mateusz", "Michał", "Patryk", "Paweł", "Piotr", "Radomir",
                 "Radosław", "Ronald", "Rudolf", "Stefan", "Szczepan", "Szymon", "Tobiasz",
                 "Tomasz", "Wacław", "Wiktor", "Władysław", "Zygmunt"};
    m_names_f = {"Agata", "Agnieszka", "Aleksandra", "Alicja", "Andżelika", "Aneta", "Barbara",
                 "Bogumiła", "Bogusława", "Bożena", "Celestyna", "Celina", "Dagmara", "Danuta",
                 "Daria", "Dominika", "Dorota", "Edyta", "Eliza", "Emilia", "Eugenia", "Ewelina",
                 "Felicja", "Gertruda", "Grażyna", "Helga", "Iga", "Iwona", "Izabela", "Joanna",
                 "Julia", "Kalina", "Karina", "Karolina", "Kinga", "Klara", "Klaudia", "Krystyna",
                 "Lena", "Magdalena", "Malwina", "Maria", "Milena", "Nikola", "Ola", "Patrycja",
                 "Sylwia", "Urszula", "Wiktoria", "Zuzanna"};
    m_surnames_m = {"Nowak", "Kowalski", "Wiśniewski", "Dąbrowski", "Lewandowski", "Wójcik",
                    "Kamiński", "Kowalczyk", "Zieliński", "Szymański", "Woźniak", "Kozłowski",
                    "Jankowski", "Wojciechowski", "Kwiatkowski", "Kaczmarek", "Mazur", "Krawczyk",
                    "Piotrowski", "Grabowski", "Nowakowski", "Pawłowski", "Michalski", "Nowicki",
                    "Adamczyk", "Dudek", "Zając", "Wieczorek", "Jabłoński", "Król", "Majewski",
                    "Olszewski", "Jaworski", "Wróbel", "Malinowski", "Pawlak", "Witkowski",
                    "Walczak", "Stępień", "Górski", "Rutkowski", "Michalak", "Sikora", "Ostrowski",
                    "Baran", "Duda", "Szewczyk", "Tomaszewski", "Pietrzak", "Marciniak"};
    m_surnames_f = {"﻿Nowak", "Kowalska", "Wiśniewska", "Dąbrowska", "Lewandowska", "Wójcik",
                    "Kamińska", "Kowalczyk", "Zielińska", "Szymańska", "Woźniak", "Kozłowska",
                    "Jankowska", "Wojciechowska", "Kwiatkowska", "Kaczmarek", "Mazur", "Krawczyk",
                    "Piotrowska", "Grabowska", "Nowakowska", "Pawłowska", "Michalska", "Nowicka",
                    "Adamczyk", "Dudek", "Zając", "Wieczorek", "Jabłońska", "Król", "Majewska",
                    "Olszewska", "Jaworska", "Wróbel", "Malinowska", "Pawlak", "Witkowska", "Walczak",
                    "Stępień", "Górska", "Rutkowska", "Michalak", "Sikora", "Ostrowska", "Baran",
                    "Duda", "Szewczyk", "Tomaszewska", "Pietrzak", "Marciniak"};
    m_colors = {"Czerwony", "Zielony", "Niebieski", "Żółty", "Biały", "Czarny", "Srebrny", "Złoty",
                "Pomarańczowy", "Błękitny", "Turkusowy", "Różowy", "Beżowy", "Fioletowy", "Szary"};
    m_departments = {"Rozwoju", "Wysyłki", "Klientów", "Dostaw", "Produkcji", "Międzynarodowych",
                     "Kontaktów", "Administracyjnych"};
}

QJsonObject RandomJSONFactory::randomProvider(){
    QJsonObject obj;
    obj.insert("id", randomID());
    obj.insert("name", randomProviderName());
    obj.insert("address", randomAddress());
    return obj;
}

QJsonObject RandomJSONFactory::randomCustomer(){
    QJsonObject obj;
    obj.insert("id", randomID());
    obj.insert("name", randomPersonName());
    obj.insert("address", randomAddress());;
    obj.insert("nip", randomNIP());
    return obj;
}

QJsonObject RandomJSONFactory::randomEmployee(){
    QJsonObject obj;
    obj.insert("id", randomID());
    obj.insert("name", randomPersonName());
    obj.insert("hourly_rate", qrand()%20+10);
    obj.insert("hour_count", (qrand()%3+2)*2);
    obj.insert("supervisor_id", randomID());
    obj.insert("department_id", randomID());
    return obj;
}

QJsonObject RandomJSONFactory::randomDepartment(){
    QJsonObject obj;
    obj.insert("id", randomID());
    obj.insert("name", randomDepartmentName());
    return obj;
}

QJsonObject RandomJSONFactory::randomPart(){
    QJsonObject obj;
    obj.insert("id", randomID());
    obj.insert("name", randomPartName());
    obj.insert("provider_id", randomID());
    return obj;
}

QJsonObject RandomJSONFactory::randomProduct(){
    QJsonObject obj;
    obj.insert("id", randomID());
    obj.insert("name", randomProductName());
    return obj;
}

QJsonObject RandomJSONFactory::randomState(){
    QJsonObject obj;
    obj.insert("id", randomID());
    obj.insert("name", randomStateName());
    obj.insert("department_id", randomID());
    return obj;
}

QJsonObject RandomJSONFactory::randomOrder(){
    QJsonObject obj;
    obj.insert("id", randomID());
    obj.insert("customer_id", randomID());
    obj.insert("date", randomDate());
    return obj;
}

QString RandomJSONFactory::randomPartName(){
    return "Sample part name";
}

QString RandomJSONFactory::randomPersonName(){
    if(qrand()%2) return m_names_f.get() + " " + m_surnames_f.get();
    return m_names_m.get() + " " + m_surnames_m.get();
}

QString RandomJSONFactory::randomDepartmentName(){
    return m_colors.get() + " departament ds. " + m_departments.get();
}

QString RandomJSONFactory::randomProviderName(){
    return m_names_m.get() + "ex sp. z o.o.";
}

QString RandomJSONFactory::randomProductName(){
    return "Czajnik elektryczny, model " + m_names_f.get() + ", " + m_colors.get();
}

QString RandomJSONFactory::randomStateName(){
    return "Sample state name";
}

QString RandomJSONFactory::randomAddress(){
    return "Sample address";
}

QString RandomJSONFactory::randomNIP(){
    return QString("%1%2%3-%4%5%6-%7%8-%9%10").arg(qrand()%10).arg(qrand()%10).arg(qrand()%10).arg(qrand()%10)
            .arg(qrand()%10).arg(qrand()%10).arg(qrand()%10).arg(qrand()%10).arg(qrand()%10).arg(qrand()%10);
}

QString RandomJSONFactory::randomDate(){
    return "Sample date";
}

int RandomJSONFactory::randomID(){
    return qrand()%9000+1000;
}
