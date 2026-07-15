#include "DatabaseManager.h"

DatabaseManager::DatabaseManager()
    : driver(nullptr),
      connection(nullptr),
      host("127.0.0.1"),
      port(3306),
      username("root"),
      password("sara123sql"),
      databaseName("online_food_ordering_system") {
}

DatabaseManager::~DatabaseManager() {
    disconnect();
}



bool DatabaseManager::connect() {

    try {

        driver = sql::mysql::get_mysql_driver_instance();

        connection = driver->connect("tcp://" + host + ":" + std::to_string(port),
            username, password);

        connection->setSchema(databaseName);

        return true;
    }

    catch (sql::SQLException&) {
        connection = nullptr;

        return false;
    }
}

void DatabaseManager::disconnect() {

    if (connection != nullptr) {
        connection->close();
        delete connection;
        connection = nullptr;
    }
}

bool DatabaseManager::isConnected() const {
    return connection != nullptr;
}

sql::Connection* DatabaseManager::getConnection() {
    return connection;
}