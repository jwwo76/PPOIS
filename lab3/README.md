# Система управления рестораном и доставкой

- **Классы**: 54
- **Поля**: 236
- **Уникальные поведения**: 295
- **Ассоциации**: 93
- **Исключения**: 14

## Исключения (14)

Все в классе Exceptions (статические методы для throw):

- `throwInvalidArgument("Недопустимый аргумент")`
- `throwInvalidPayment("Недопустимый метод оплаты")`
- `throwCapacityExceeded("Пропускная способность превышена")`
- `throwOrderNotFound("Заказ не найден")`
- `throwVehicleUnavailable("Транспорт недоступен")`
- `throwClientNotFound("Клиент не найден")`
- `throwDriverNotFound("Водитель не найден")`
- `throwRouteNotFound("Маршрут не найден")`
- `throwHubFull("Хаб переполнен")`
- `throwPaymentFailed("Оплата не удалась")`
- `throwInvalidCard("Некорректная карта")`
- `throwInsufficientFunds("Недостаточно средств")`
- `throwDuplicateOrder("Дубликат заказа")`
- `throwInvalidWeight("Недопустимый вес груза")`

Исключения используются в классах Order, Payment, MenuItem, Vehicle, Delivery, Restaurant, Stock и других для валидации данных.

## Классы

Формат: Класс Поля Методы → Ассоциации

### Persons (10 классов)

Person 2 4 →

Employee 2 6 → Person

Customer 3 6 → Person, Order

DeliveryPerson 2 6 → Employee, Vehicle

RestaurantOwner 2 4 → Person, Restaurant

Manager 1 4 → Employee, Restaurant

Cook 2 5 → Employee, Restaurant, Order

Cashier 2 4 → Employee, Restaurant

Driver 2 5 → Employee, Vehicle

SupportAgent 1 4 → Employee

### Restaurants (6 классов)

Restaurant 6 10 → RestaurantOwner, Menu, Order

Menu 3 4 → MenuItem

MenuItem 4 5 → Category

Category 4 9 → MenuItem

Cuisine 5 6 → Restaurant

Branch 6 7 → Restaurant, Address

### Orders (6 классов)

Order 6 10 → Customer, Restaurant, OrderItem

OrderItem 6 5 → MenuItem

OrderStatus 5 10 → Order

Cart 4 10 → Customer, OrderItem, Restaurant

OrderHistory 4 9 → Customer, Order

OrderTracking 6 7 → Order, Delivery

### Delivery (6 классов)

Delivery 9 6 → Order, DeliveryPerson, Address, Vehicle

DeliveryRoute 6 6 → Address, Delivery

Vehicle 4 5 →

DeliveryZone 5 6 → Address, Delivery

DeliveryTime 6 6 → Delivery

DeliveryStatus 5 10 → Delivery

### Payments (5 классов)

Payment 4 6 → Order

PaymentMethod 5 4 →

Invoice 8 8 → Order, Customer

Receipt 5 6 → Payment, Order

Transaction 6 4 → Payment

### Reviews (4 класса)

Review 6 6 → Customer, Restaurant, Order

Rating 6 4 → Restaurant, DeliveryPerson, Customer

Feedback 6 5 → Customer, Order

Complaint 7 6 → Customer, Order

### Inventory (5 классов)

Ingredient 4 4 → Supplier

Stock 5 5 → Ingredient, Warehouse

Supplier 6 5 → Address, Ingredient

Warehouse 5 8 → Address, Stock

InventoryItem 7 4 → Warehouse

### Operations (5 классов)

Shift 3 5 → Employee

Schedule 4 4 → Employee

Task 7 14 → Employee

WorkLog 6 4 → Employee

Performance 5 6 → Employee

### Locations (3 класса)

Address 3 4 →

Zone 5 9 → Address

City 5 9 → Zone

### Promotions (3 класса)

Promotion 4 5 → Restaurant

Discount 6 4 → Order

Coupon 7 4 → Customer, Restaurant

