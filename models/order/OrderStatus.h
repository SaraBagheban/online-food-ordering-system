#ifndef ORDERSTATUS_H
#define ORDERSTATUS_H

#include <string>

enum OrderStatus {PREPARING, READY, DELIVERED, CANCELLED, UNKNOWN};
std::string orderStatusToString(OrderStatus status);

#endif