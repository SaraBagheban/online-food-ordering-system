CREATE DATABASE IF NOT EXISTS online_food_ordering_system;

USE online_food_ordering_system;


CREATE TABLE users (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    phone VARCHAR(20) NOT NULL UNIQUE,

    role ENUM(
        'Customer','RestaurantAdmin','SystemAdmin'
    ) NOT NULL,

    loyalty_points INT NOT NULL DEFAULT 0,

    membership_level ENUM(
        'Normal','Silver','Gold','VIP'
    ) NOT NULL DEFAULT 'Normal',

    successful_orders INT NOT NULL DEFAULT 0,
    coupon_count INT NOT NULL DEFAULT 0
);


CREATE TABLE restaurants (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL,
    address VARCHAR(255) NOT NULL,
    phone VARCHAR(20) NOT NULL,
    description TEXT,
    prep_time INT NOT NULL,
    is_active BOOLEAN NOT NULL DEFAULT TRUE
);


CREATE TABLE menu_items (
    id INT AUTO_INCREMENT PRIMARY KEY,
    restaurant_id INT NOT NULL,
    name VARCHAR(100) NOT NULL,
    description TEXT,
    price DOUBLE NOT NULL,
    available BOOLEAN NOT NULL DEFAULT TRUE,
    special_item BOOLEAN NOT NULL DEFAULT FALSE,

    type ENUM(
        'Food','Drink'
    ) NOT NULL,

    cook_time INT,
    volume INT,

    FOREIGN KEY (restaurant_id)
        REFERENCES restaurants(id)
        ON DELETE CASCADE
);


CREATE TABLE cart (
    id INT AUTO_INCREMENT PRIMARY KEY,
    customer_id INT NOT NULL UNIQUE,

    FOREIGN KEY (customer_id)
        REFERENCES users(id)
        ON DELETE CASCADE
);


CREATE TABLE orders (
    id INT AUTO_INCREMENT PRIMARY KEY,
    customer_id INT NOT NULL,
    restaurant_id INT NOT NULL,

    status ENUM(
        'PREPARING','READY','DELIVERED','CANCELLED','UNKNOWN'
    ) NOT NULL DEFAULT 'Unknown',

    membership_level ENUM(
        'Normal','Silver','Gold','VIP'
    ) NOT NULL,

    subtotal DOUBLE NOT NULL,
    discount DOUBLE NOT NULL,
    shipping_cost DOUBLE NOT NULL,
    total_price DOUBLE NOT NULL,

    earned_points INT NOT NULL,

    order_date DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,

    FOREIGN KEY (customer_id)
        REFERENCES users(id),

    FOREIGN KEY (restaurant_id)
        REFERENCES restaurants(id)
);


CREATE TABLE order_items (
    id INT AUTO_INCREMENT PRIMARY KEY,
    order_id INT NOT NULL,
    menu_item_id INT NOT NULL,
    quantity INT NOT NULL,
    price DOUBLE NOT NULL,

    FOREIGN KEY (order_id)
        REFERENCES orders(id)
        ON DELETE CASCADE,

    FOREIGN KEY (menu_item_id)
        REFERENCES menu_items(id)
);


CREATE TABLE badges (
    id INT AUTO_INCREMENT PRIMARY KEY,
    name VARCHAR(100) NOT NULL UNIQUE,
    description VARCHAR(255) NOT NULL
);


CREATE TABLE customer_badges (
    customer_id INT NOT NULL,
    badge_id INT NOT NULL,
    earned_date DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,

    PRIMARY KEY (
        customer_id,
        badge_id
    ),

    FOREIGN KEY (customer_id)
        REFERENCES users(id)
        ON DELETE CASCADE,

    FOREIGN KEY (badge_id)
        REFERENCES badges(id)
        ON DELETE CASCADE
);


CREATE TABLE level_history (
    id INT AUTO_INCREMENT PRIMARY KEY,
    customer_id INT NOT NULL,

    old_level ENUM(
        'Normal','Silver','Gold','VIP'
    ) NOT NULL,

    new_level ENUM(
        'Normal','Silver','Gold','VIP'
    ) NOT NULL,

    points INT NOT NULL,
    successful_orders INT NOT NULL,
    change_date DATETIME NOT NULL DEFAULT CURRENT_TIMESTAMP,

    FOREIGN KEY (customer_id)
        REFERENCES users(id)
        ON DELETE CASCADE
);


CREATE TABLE coupons (
    id INT AUTO_INCREMENT PRIMARY KEY,
    customer_id INT NOT NULL,
    discount_amount DOUBLE NOT NULL,
    is_used BOOLEAN NOT NULL DEFAULT FALSE,

    FOREIGN KEY (customer_id)
        REFERENCES users(id)
        ON DELETE CASCADE
);