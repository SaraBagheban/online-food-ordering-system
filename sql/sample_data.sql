USE online_food_ordering_system;

INSERT INTO users (
    name,
    phone,
    role,
    loyalty_points,
    membership_level,
    successful_orders,
    coupon_count
)
VALUES
(
    'Mark Amber',
    '09123456781',
    'Customer',
    0,
    'Normal',
    0,
    0
),
(
    'Sara Navid',
    '09123456782',
    'RestaurantAdmin',
    0,
    'Normal',
    0,
    0
),
(
    'Ali Babaei',
    '09123456783',
    'Customer',
    350,
    'Gold',
    17,
    1
),
(
    'Jadi Miri',
    '09123456784',
    'SystemAdmin',
    0,
    'Normal',
    0,
    0
),
(
    'Amir Hosseini',
    '09123456785',
    'RestaurantAdmin',
    0,
    'Normal',
    0,
    0
),
(
    'Niloofar Karimi',
    '09123456786',
    'RestaurantAdmin',
    0,
    'Normal',
    0,
    0
);


INSERT INTO restaurants (
    owner_id,
    name,
    address,
    phone,
    description,
    prep_time,
    is_active
)
VALUES
(
    2,
    'Green House',
    'Valiasr St.',
    '02188551234',
    'Traditional Food',
    25,
    TRUE
),
(
    5,
    'Aurora',
    'Shariati St.',
    '02188765432',
    'International Food',
    35,
    TRUE
),
(
    6,
    'Rock & Roll',
    'Jordan St.',
    '02188997766',
    'Fast Food',
    20,
    TRUE
);


INSERT INTO menu_items (
    restaurant_id,
    name,
    description,
    price,
    available,
    special_item,
    type,
    cook_time,
    volume
)
VALUES

-- Green House (4 Items)

(
    1,
    'Kebab',
    'Grilled Meat',
    420,
    TRUE,
    FALSE,
    'Food',
    30,
    NULL
),

(
    1,
    'Chicken',
    'Grilled Chicken',
    360,
    TRUE,
    FALSE,
    'Food',
    25,
    NULL
),

(
    1,
    'Doogh',
    'Yogurt Drink',
    200,
    TRUE,
    FALSE,
    'Drink',
    NULL,
    330
),

(
    1,
    'Sushi',
    'Fresh Sushi',
    650,
    TRUE,
    TRUE,
    'Food',
    40,
    NULL
),

-- Aurora (5 Items)

(
    2,
    'Pizza',
    'Cheese Pizza',
    520,
    TRUE,
    FALSE,
    'Food',
    20,
    NULL
),

(
    2,
    'Pasta',
    'Cream Sauce',
    470,
    TRUE,
    FALSE,
    'Food',
    25,
    NULL
),

(
    2,
    'Fish',
    'Grilled Fish',
    610,
    TRUE,
    FALSE,
    'Food',
    35,
    NULL
),

(
    2,
    'Orange Juice',
    'Fresh Juice',
    220,
    TRUE,
    FALSE,
    'Drink',
    NULL,
    300
),

(
    2,
    'Shrimp',
    'Fried Shrimp',
    690,
    TRUE,
    TRUE,
    'Food',
    35,
    NULL
),

-- Rock & Roll (7 Items)

(
    3,
    'Burger',
    'Beef Burger',
    480,
    TRUE,
    FALSE,
    'Food',
    18,
    NULL
),

(
    3,
    'Pizza',
    'Pepperoni',
    560,
    TRUE,
    TRUE,
    'Food',
    20,
    NULL
),

(
    3,
    'Fries',
    'French Fries',
    210,
    FALSE,
    FALSE,
    'Food',
    10,
    NULL
),

(
    3,
    'Cola',
    'Soft Drink',
    200,
    TRUE,
    FALSE,
    'Drink',
    NULL,
    330
),

(
    3,
    'Cola',
    'Soft Drink',
    260,
    TRUE,
    FALSE,
    'Drink',
    NULL,
    500
),

(
    3,
    'Water',
    'Mineral Water',
    200,
    FALSE,
    FALSE,
    'Drink',
    NULL,
    500
),

(
    3,
    'Steak',
    'Grilled Beef',
    700,
    TRUE,
    TRUE,
    'Food',
    45,
    NULL
);


INSERT INTO cart (
    customer_id
)
VALUES
(1),
(3);


INSERT INTO orders (
    customer_id,
    restaurant_id,
    status,
    membership_level,
    subtotal,
    discount,
    shipping_cost,
    total_price,
    earned_points
)
VALUES
(
    3,
    3,
    'DELIVERED',
    'Gold',
    960,
    96,
    40,
    904,
    90
),
(
    1,
    2,
    'PREPARING',
    'Normal',
    740,
    0,
    40,
    780,
    15
);


INSERT INTO order_items (
    order_id,
    menu_item_id,
    quantity,
    price
)
VALUES

-- Order 1 (Ali Babaei - Rock & Roll)

(
    1,
    10,
    1,
    480
),

(
    1,
    11,
    1,
    560
),

-- Order 2 (Mark Amber - Aurora)

(
    2,
    5,
    1,
    520
),

(
    2,
    8,
    1,
    220
);


INSERT INTO badges (
    name,
    description
)
VALUES
(
    'Frequent Buyer',
    'Completed many successful orders'
),
(
    'Night Customer',
    'Placed several late-night orders'
),
(
    'Loyal Customer',
    'High loyalty points or long membership'
),
(
    'Big Spender',
    'Spent a large amount on orders'
);


INSERT INTO customer_badges (
    customer_id,
    badge_id
)
VALUES
(
    3,
    1
),
(
    3,
    3
),
(
    3,
    4
),
(
    1,
    2
);


INSERT INTO level_history (
    customer_id,
    old_level,
    new_level,
    points,
    successful_orders
)
VALUES
(
    3,
    'Normal',
    'Silver',
    150,
    8
),
(
    3,
    'Silver',
    'Gold',
    350,
    17
);


INSERT INTO coupons (
    customer_id,
    discount_amount,
    is_used
)
VALUES
(
    3,
    100,
    FALSE
);