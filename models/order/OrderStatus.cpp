#include "OrderStatus.h"

std::string orderStatusToString(OrderStatus status) {
    if (status == PREPARING)
        return "Preparing";

    if (status == READY)
        return "Ready";

    if (status == DELIVERED)
        return "Delivered";

    return "Unknown";
}