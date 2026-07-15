#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <string>
#include <mysql/jdbc.h>

class DatabaseManager {
private:
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* connection;

    std::string host;
    int port;
    std::string username;
    std::string password;
    std::string databaseName;

public:
    DatabaseManager();
    ~DatabaseManager();

    bool connect();
    void disconnect();
    bool isConnected() const;

    sql::Connection* getConnection();
};

#endif