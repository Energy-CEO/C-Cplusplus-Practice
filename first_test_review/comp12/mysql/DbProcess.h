//
// Created by eddi on 23. 12. 18.
//

#ifndef COMP12_DBPROCESS_H
#define COMP12_DBPROCESS_H


#include <mysql/mysql.h>
#include <string>
#include <optional>
#include <memory>
#include <list>

#include "../velocity/entity/Velocity.h"

class DbProcess {

private:
    // unique_ptr 은 어떤 객체의 유일한 소유권을 나타내는 포인터
    // 소멸 시 가리키던 객체 역시 소멸
    static std::unique_ptr<DbProcess> instance;

    MYSQL *conn;
    const char* DB_HOST;
    const char* DB_USER;
    const char* DB_PASS;
    const char* DB_NAME;

public:
    DbProcess(const char* host, const char* user, const char* pass, const char* dbName);
    ~DbProcess();

    static DbProcess& getInstance(const char* host, const char* user, const char* pass, const char* dbName);
    static DbProcess& getInstance();

    bool connect();
    bool insertData(const Velocity&);
    std::list<Velocity> findAll();

    bool executeQuery(const std::string& query);
    bool deleteAll(const char* tableName);

    MYSQL *getConn();

};


#endif //COMP12_DBPROCESS_H
