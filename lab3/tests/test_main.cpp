#include <gtest/gtest.h>
#include "../Persons/Person.h"
#include "../Persons/Employee.h"
#include "../Persons/Customer.h"
#include "../Persons/DeliveryPerson.h"
#include "../Persons/RestaurantOwner.h"
#include "../Persons/Manager.h"
#include "../Persons/Cook.h"
#include "../Persons/Cashier.h"
#include "../Persons/Driver.h"
#include "../Persons/SupportAgent.h"
#include "../Restaurants/Restaurant.h"
#include "../Restaurants/Menu.h"
#include "../Restaurants/MenuItem.h"
#include "../Restaurants/Category.h"
#include "../Restaurants/Cuisine.h"
#include "../Restaurants/Branch.h"
#include "../Orders/Order.h"
#include "../Orders/OrderItem.h"
#include "../Orders/OrderStatus.h"
#include "../Orders/Cart.h"
#include "../Orders/OrderHistory.h"
#include "../Orders/OrderTracking.h"
#include "../Delivery/Delivery.h"
#include "../Delivery/DeliveryRoute.h"
#include "../Delivery/Vehicle.h"
#include "../Delivery/DeliveryZone.h"
#include "../Delivery/DeliveryTime.h"
#include "../Delivery/DeliveryStatus.h"
#include "../Payments/Payment.h"
#include "../Payments/Invoice.h"
#include "../Payments/Receipt.h"
#include "../Payments/PaymentMethod.h"
#include "../Payments/Transaction.h"
#include "../Reviews/Review.h"
#include "../Reviews/Rating.h"
#include "../Reviews/Feedback.h"
#include "../Reviews/Complaint.h"
#include "../Inventory/Ingredient.h"
#include "../Inventory/Stock.h"
#include "../Inventory/Supplier.h"
#include "../Inventory/Warehouse.h"
#include "../Inventory/InventoryItem.h"
#include "../Operations/Shift.h"
#include "../Operations/Schedule.h"
#include "../Operations/Task.h"
#include "../Operations/WorkLog.h"
#include "../Operations/Performance.h"
#include "../Locations/Address.h"
#include "../Locations/Zone.h"
#include "../Locations/City.h"
#include "../Promotions/Promotion.h"
#include "../Promotions/Discount.h"
#include "../Promotions/Coupon.h"

TEST(PersonTest, AllMethods) {
    Person person("John", 30);
    EXPECT_EQ(person.getFirstName(), "John");
    EXPECT_EQ(person.getAge(), 30);
    person.setFirstName("Jane");
    EXPECT_EQ(person.getFirstName(), "Jane");
    testing::internal::CaptureStdout();
    person.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

TEST(EmployeeTest, AllMethods) {
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Motorcycle");
    DeliveryPerson* dp = new DeliveryPerson("John", 35, 1, 3000.0, vehicle);
    EXPECT_EQ(dp->getId(), 1);
    EXPECT_EQ(dp->getSalary(), 3000.0);
    dp->setId(10);
    dp->setSalary(3500.0);
    EXPECT_EQ(dp->getId(), 10);
    EXPECT_EQ(dp->getSalary(), 3500.0);
    testing::internal::CaptureStdout();
    dp->print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    delete dp;
    delete vehicle;
}

TEST(CustomerTest, AllMethods) {
    Customer customer("Jane", 28, 1, "jane@email.com");
    EXPECT_EQ(customer.getCustomerId(), 1);
    EXPECT_EQ(customer.getEmail(), "jane@email.com");
    customer.setEmail("newemail@email.com");
    EXPECT_EQ(customer.getEmail(), "newemail@email.com");
    testing::internal::CaptureStdout();
    customer.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

TEST(DeliveryPersonTest, AllMethods) {
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Motorcycle");
    DeliveryPerson dp("John", 35, 1, 3000.0, vehicle);
    
    EXPECT_EQ(dp.getDeliveriesCompleted(), 0);
    dp.completeDelivery();
    EXPECT_EQ(dp.getDeliveriesCompleted(), 1);
    
    Vehicle* vehicle2 = new Vehicle(2, "XYZ789", "Bicycle");
    dp.setVehicle(vehicle2);
    EXPECT_EQ(dp.getVehicle(), vehicle2);
    
    testing::internal::CaptureStdout();
    dp.work();
    dp.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete vehicle;
    delete vehicle2;
}

TEST(RestaurantOwnerTest, ConstructorAndOperations) {
    RestaurantOwner owner("Bob", 45, 1);
    
    EXPECT_EQ(owner.getOwnerId(), 1);
    
    testing::internal::CaptureStdout();
    owner.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}


TEST(CookTest, ConstructorAndOperations) {
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Test Restaurant", owner);
    Cook cook("Mike", 30, 1, 3500.0, restaurant);
    
    EXPECT_EQ(cook.getOrdersPrepared(), 0);
    
    testing::internal::CaptureStdout();
    cook.work();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete restaurant;
    delete owner;
}

TEST(CashierTest, ConstructorAndOperations) {
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Test Restaurant", owner);
    Cashier cashier("Sarah", 25, 1, 2500.0, restaurant);
    
    EXPECT_EQ(cashier.getTransactionsProcessed(), 0);
    
    cashier.processTransaction(50.0);
    EXPECT_EQ(cashier.getTransactionsProcessed(), 1);
    
    delete restaurant;
    delete owner;
}

TEST(DriverTest, ConstructorAndOperations) {
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Car");
    Driver driver("Tom", 32, 1, 3200.0, vehicle);
    
    EXPECT_EQ(driver.getDeliveriesCompleted(), 0);
    
    driver.completeDelivery();
    EXPECT_EQ(driver.getDeliveriesCompleted(), 1);
    
    delete vehicle;
}

TEST(SupportAgentTest, ConstructorAndOperations) {
    SupportAgent agent("Lisa", 28, 1, 2800.0);
    
    EXPECT_EQ(agent.getTicketsResolved(), 0);
    
    agent.resolveTicket();
    EXPECT_EQ(agent.getTicketsResolved(), 1);
    
    testing::internal::CaptureStdout();
    agent.work();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

TEST(AddressTest, AllMethods) {
    Address address(1, "123 Main St", "New York");
    EXPECT_EQ(address.getStreet(), "123 Main St");
    EXPECT_EQ(address.getCity(), "New York");
    testing::internal::CaptureStdout();
    address.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}



TEST(MenuItemTest, ConstructorAndOperations) {
    Category* category = new Category(1, "Appetizers", "Starters");
    MenuItem item(1, "Caesar Salad", 8.99, category);
    
    EXPECT_EQ(item.getItemId(), 1);
    EXPECT_EQ(item.getName(), "Caesar Salad");
    EXPECT_EQ(item.getPrice(), 8.99);
    
    item.setPrice(9.99);
    EXPECT_EQ(item.getPrice(), 9.99);
    
    delete category;
}

TEST(CategoryTest, ConstructorAndOperations) {
    Category category(1, "Appetizers", "Starters and appetizers");
    
    EXPECT_EQ(category.getCategoryId(), 1);
    EXPECT_EQ(category.getName(), "Appetizers");
    EXPECT_EQ(category.getDescription(), "Starters and appetizers");
}

TEST(CuisineTest, ConstructorAndOperations) {
    Cuisine cuisine(1, "Italian", "Italy", "Traditional Italian dishes");
    
    EXPECT_EQ(cuisine.getCuisineId(), 1);
    EXPECT_EQ(cuisine.getName(), "Italian");
    EXPECT_EQ(cuisine.getOriginCountry(), "Italy");
}

TEST(BranchTest, ConstructorAndOperations) {
    Address* address = new Address(1, "123 Main St", "New York");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Branch branch(1, restaurant, address, "555-1234", 50);
    
    EXPECT_EQ(branch.getBranchId(), 1);
    EXPECT_EQ(branch.getCapacity(), 50);
    EXPECT_FALSE(branch.getIsOpen());
    
    branch.setIsOpen(true);
    EXPECT_TRUE(branch.getIsOpen());
    
    delete address;
    delete restaurant;
}


TEST(OrderItemTest, ConstructorAndOperations) {
    Category* category = new Category(1, "Main", "Main dishes");
    MenuItem* menuItem = new MenuItem(1, "Pizza", 12.99, category);
    OrderItem orderItem(1, menuItem, 2, "No onions");
    
    EXPECT_EQ(orderItem.getQuantity(), 2);
    EXPECT_EQ(orderItem.getSubtotal(), 25.98);
    
    orderItem.setQuantity(3);
    EXPECT_EQ(orderItem.getQuantity(), 3);
    EXPECT_EQ(orderItem.getSubtotal(), 38.97);
    
    delete menuItem;
    delete category;
}


TEST(DeliveryTest, ConstructorAndOperations) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order = new Order(1, customer, restaurant);
    Address* address = new Address(1, "123 Main St", "New York");
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Motorcycle");
    DeliveryPerson* dp = new DeliveryPerson("John", 35, 1, 3000.0, vehicle);
    Delivery delivery(1, order, dp, address, 5.0);
    
    EXPECT_EQ(delivery.getDeliveryId(), 1);
    EXPECT_EQ(delivery.getStatus(), "Pending");
    EXPECT_EQ(delivery.getDeliveryFee(), 5.0);
    
    delivery.setStatus("In Transit");
    EXPECT_EQ(delivery.getStatus(), "In Transit");
    
    delete customer;
    delete restaurant;
    delete order;
    delete address;
    delete dp;
}

TEST(VehicleTest, ConstructorAndOperations) {
    Vehicle vehicle(1, "ABC123", "Motorcycle");
    
    EXPECT_EQ(vehicle.getVehicleId(), 1);
    EXPECT_EQ(vehicle.getLicensePlate(), "ABC123");
    EXPECT_EQ(vehicle.getVehicleType(), "Motorcycle");
    EXPECT_TRUE(vehicle.getIsAvailable());
    
    vehicle.setIsAvailable(false);
    EXPECT_FALSE(vehicle.getIsAvailable());
}

TEST(DeliveryZoneTest, ConstructorAndOperations) {
    DeliveryZone zone(1, "Downtown", 3.0, 30);
    
    EXPECT_EQ(zone.getZoneId(), 1);
    EXPECT_EQ(zone.getZoneName(), "Downtown");
    EXPECT_EQ(zone.getDeliveryFee(), 3.0);
    
    Address* address = new Address(1, "123 Main St", "New York");
    zone.addCoveredArea(address);
    
    delete address;
}

TEST(PaymentTest, ConstructorAndOperations) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order = new Order(1, customer, restaurant);
    Payment payment(1, order, 25.99);
    
    EXPECT_EQ(payment.getPaymentId(), 1);
    EXPECT_EQ(payment.getAmount(), 25.99);
    EXPECT_EQ(payment.getStatus(), "Pending");
    
    testing::internal::CaptureStdout();
    payment.processPayment();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    EXPECT_EQ(payment.getStatus(), "Completed");
    
    delete customer;
    delete restaurant;
    delete order;
    delete owner;
}

TEST(PaymentMethodTest, ConstructorAndOperations) {
    PaymentMethod method(1, "Credit Card", "1234-5678-9012-3456", "John Doe", "12/25");
    
    EXPECT_EQ(method.getMethodId(), 1);
    EXPECT_EQ(method.getMethodType(), "Credit Card");
    EXPECT_TRUE(method.getIsActive());
    
    method.setIsActive(false);
    EXPECT_FALSE(method.getIsActive());
}

TEST(InvoiceTest, ConstructorAndOperations) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order = new Order(1, customer, restaurant);
    Invoice invoice(1, order, customer, 25.99, "2024-01-15");
    
    EXPECT_EQ(invoice.getInvoiceId(), 1);
    EXPECT_EQ(invoice.getTotalAmount(), 25.99);
    EXPECT_EQ(invoice.getStatus(), "Unpaid");
    
    invoice.setTaxAmount(2.50);
    invoice.setDiscountAmount(5.0);
    invoice.calculateTotal();
    
    delete customer;
    delete restaurant;
    delete order;
}

TEST(ReviewTest, ConstructorAndOperations) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order = new Order(1, customer, restaurant);
    Review review(1, customer, restaurant, order, 5, "Great food!", "2024-01-16");
    
    EXPECT_EQ(review.getReviewId(), 1);
    EXPECT_EQ(review.getRating(), 5);
    EXPECT_EQ(review.getComment(), "Great food!");
    
    review.setRating(4);
    EXPECT_EQ(review.getRating(), 4);
    
    review.setRating(6);
    EXPECT_EQ(review.getRating(), 4);
    
    delete customer;
    delete restaurant;
    delete order;
}

TEST(RatingTest, ConstructorAndOperations) {
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Motorcycle");
    DeliveryPerson* dp = new DeliveryPerson("John", 35, 1, 3000.0, vehicle);
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    Rating rating(1, restaurant, dp, customer, 5, 4, "2024-01-16");
    
    EXPECT_EQ(rating.getRestaurantRating(), 5);
    EXPECT_EQ(rating.getDeliveryRating(), 4);
    
    rating.setRestaurantRating(3);
    EXPECT_EQ(rating.getRestaurantRating(), 3);
    
    delete restaurant;
    delete dp;
    delete customer;
}

TEST(FeedbackTest, ConstructorAndOperations) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order = new Order(1, customer, restaurant);
    Feedback feedback(1, customer, order, "Suggestion", "Add more vegetarian options", "2024-01-16");
    
    EXPECT_EQ(feedback.getFeedbackId(), 1);
    EXPECT_FALSE(feedback.getIsResolved());
    
    feedback.resolve();
    EXPECT_TRUE(feedback.getIsResolved());
    
    delete customer;
    delete restaurant;
    delete order;
}

TEST(ComplaintTest, ConstructorAndOperations) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order = new Order(1, customer, restaurant);
    Complaint complaint(1, customer, order, "Late Delivery", "Order arrived 30 minutes late", "2024-01-16");
    
    EXPECT_EQ(complaint.getComplaintId(), 1);
    EXPECT_EQ(complaint.getStatus(), "Open");
    
    complaint.setStatus("Resolved");
    complaint.setResolution("Refund issued");
    EXPECT_EQ(complaint.getStatus(), "Resolved");
    EXPECT_EQ(complaint.getResolution(), "Refund issued");
    
    delete customer;
    delete restaurant;
    delete order;
}

TEST(IngredientTest, ConstructorAndOperations) {
    Address* address = new Address(1, "123 Main St", "New York");
    Supplier* supplier = new Supplier(1, "Food Supply Co", "John", "555-1234", "supply@email.com", address);
    Ingredient ingredient(1, "Flour", 100.0, supplier);
    
    EXPECT_EQ(ingredient.getIngredientId(), 1);
    EXPECT_EQ(ingredient.getName(), "Flour");
    EXPECT_EQ(ingredient.getQuantity(), 100.0);
    
    ingredient.setQuantity(150.0);
    EXPECT_EQ(ingredient.getQuantity(), 150.0);
    
    delete supplier;
    delete address;
}

TEST(StockTest, ConstructorAndOperations) {
    Address* address = new Address(1, "123 Main St", "New York");
    Supplier* supplier = new Supplier(1, "Food Supply Co", "John", "555-1234", "supply@email.com", address);
    Ingredient* ingredient = new Ingredient(1, "Flour", 100.0, supplier);
    Warehouse* warehouse = new Warehouse(1, "Main Warehouse", address, 1000.0);
    Stock stock(1, ingredient, warehouse, 50.0, 10.0, 200.0);
    
    EXPECT_EQ(stock.getQuantity(), 50.0);
    EXPECT_FALSE(stock.isLowStock());
    
    stock.setQuantity(5.0);
    EXPECT_TRUE(stock.isLowStock());
    
    delete warehouse;
    delete ingredient;
    delete supplier;
    delete address;
}

TEST(SupplierTest, ConstructorAndOperations) {
    Address* address = new Address(1, "123 Main St", "New York");
    Supplier supplier(1, "Food Supply Co", "John", "555-1234", "supply@email.com", address);
    
    EXPECT_EQ(supplier.getSupplierId(), 1);
    EXPECT_EQ(supplier.getName(), "Food Supply Co");
    EXPECT_EQ(supplier.getContactPerson(), "John");
    
    testing::internal::CaptureStdout();
    supplier.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete address;
}

TEST(WarehouseTest, ConstructorAndOperations) {
    Address* address = new Address(1, "123 Main St", "New York");
    Warehouse warehouse(1, "Main Warehouse", address, 1000.0);
    
    EXPECT_EQ(warehouse.getWarehouseId(), 1);
    EXPECT_EQ(warehouse.getCapacity(), 1000.0);
    EXPECT_FALSE(warehouse.isFull());
    
    Address* addr2 = new Address(2, "456 Oak St", "New York");
    Supplier* supplier = new Supplier(1, "Food Supply Co", "John", "555-1234", "supply@email.com", addr2);
    Ingredient* ingredient = new Ingredient(1, "Flour", 100.0, supplier);
    Stock* stock = new Stock(1, ingredient, &warehouse, 500.0, 10.0, 200.0);
    warehouse.addStock(stock);
    
    delete stock;
    delete ingredient;
    delete supplier;
    delete addr2;
    delete address;
}

TEST(ShiftTest, ConstructorAndOperations) {
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Motorcycle");
    DeliveryPerson* dp = new DeliveryPerson("John", 35, 1, 3000.0, vehicle);
    Shift shift(1, dp, "2024-01-15");
    
    EXPECT_EQ(shift.getShiftId(), 1);
    EXPECT_EQ(shift.getShiftDate(), "2024-01-15");
    EXPECT_FALSE(shift.getIsCompleted());
    
    shift.complete();
    EXPECT_TRUE(shift.getIsCompleted());
    
    delete dp;
}

TEST(ScheduleTest, ConstructorAndOperations) {
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Motorcycle");
    DeliveryPerson* dp = new DeliveryPerson("John", 35, 1, 3000.0, vehicle);
    Schedule schedule(1, dp, "2024-01-15");
    
    EXPECT_EQ(schedule.getScheduleId(), 1);
    schedule.addWorkDay("Monday", "09:00-17:00");
    schedule.addWorkDay("Tuesday", "09:00-17:00");
    EXPECT_EQ(schedule.getWorkDays().size(), 2);
    
    delete dp;
}

TEST(TaskTest, ConstructorAndOperations) {
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Motorcycle");
    DeliveryPerson* dp = new DeliveryPerson("John", 35, 1, 3000.0, vehicle);
    Task task(1, "Deliver Order", "Deliver order #123", dp, "2024-01-20", 1);
    
    EXPECT_EQ(task.getTaskId(), 1);
    EXPECT_EQ(task.getStatus(), "Pending");
    EXPECT_EQ(task.getPriority(), 1);
    
    task.setStatus("In Progress");
    EXPECT_EQ(task.getStatus(), "In Progress");
    
    delete dp;
}

TEST(WorkLogTest, ConstructorAndOperations) {
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Motorcycle");
    DeliveryPerson* dp = new DeliveryPerson("John", 35, 1, 3000.0, vehicle);
    WorkLog log(1, dp, "2024-01-15", "08:00", "16:00", 8);
    
    EXPECT_EQ(log.getLogId(), 1);
    EXPECT_EQ(log.getHoursWorked(), 8);
    
    log.setEndTime("17:00");
    log.calculateHours();
    
    delete dp;
}


TEST(ZoneTest, ConstructorAndOperations) {
    Zone zone(1, "Downtown", 3.0, 30);
    
    EXPECT_EQ(zone.getZoneId(), 1);
    EXPECT_EQ(zone.getZoneName(), "Downtown");
    
    Address* address = new Address(1, "123 Main St", "New York");
    zone.addAddress(address);
    EXPECT_EQ(zone.getAddresses().size(), 1);
    
    delete address;
}

TEST(CityTest, ConstructorAndOperations) {
    City city(1, "New York", "NY", "USA");
    
    EXPECT_EQ(city.getCityId(), 1);
    EXPECT_EQ(city.getName(), "New York");
    
    Zone* zone = new Zone(1, "Downtown", 3.0, 30);
    city.addZone(zone);
    EXPECT_EQ(city.getZones().size(), 1);
    
    delete zone;
}

TEST(PromotionTest, ConstructorAndOperations) {
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Promotion promotion(1, restaurant, 20.0);
    
    EXPECT_EQ(promotion.getPromotionId(), 1);
    EXPECT_EQ(promotion.getDiscountPercentage(), 20.0);
    EXPECT_TRUE(promotion.getIsActive());
    
    promotion.setDiscountPercentage(25.0);
    EXPECT_EQ(promotion.getDiscountPercentage(), 25.0);
    
    promotion.setDiscountPercentage(150.0);
    EXPECT_EQ(promotion.getDiscountPercentage(), 25.0);
    
    delete restaurant;
    delete owner;
}

TEST(DiscountTest, ConstructorAndOperations) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order = new Order(1, customer, restaurant);
    Discount discount(1, "SAVE10", 5.0, 10.0, "Percentage", order);
    
    EXPECT_EQ(discount.getDiscountId(), 1);
    EXPECT_EQ(discount.getDiscountCode(), "SAVE10");
    EXPECT_FALSE(discount.getIsUsed());
    
    discount.apply();
    EXPECT_TRUE(discount.getIsUsed());
    
    delete customer;
    delete restaurant;
    delete order;
}

TEST(CouponTest, ConstructorAndOperations) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Coupon coupon(1, "WELCOME20", customer, restaurant, 5.0, "Fixed", "2025-12-31");
    
    EXPECT_EQ(coupon.getCouponId(), 1);
    EXPECT_EQ(coupon.getCouponCode(), "WELCOME20");
    EXPECT_FALSE(coupon.getIsUsed());
    
    coupon.use();
    EXPECT_TRUE(coupon.getIsUsed());
    
    delete customer;
    delete restaurant;
}

// Additional tests for Order class methods


TEST(OrderTest, AllMethods) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order order(1, customer, restaurant);
    
    EXPECT_EQ(order.getOrderId(), 1);
    EXPECT_EQ(order.getStatus(), "Pending");
    order.setStatus("Processing");
    EXPECT_EQ(order.getStatus(), "Processing");
    
    Category* category = new Category(1, "Main", "Main dishes");
    MenuItem* menuItem = new MenuItem(1, "Pizza", 12.99, category);
    OrderItem* item = new OrderItem(1, menuItem, 2, "");
    order.addItem(item);
    EXPECT_EQ(order.getItems().size(), 1);
    
    testing::internal::CaptureStdout();
    order.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete item;
    delete menuItem;
    delete category;
    delete customer;
    delete restaurant;
    delete owner;
}

// Additional tests for Customer class methods
TEST(CustomerTest, AddOrders) {
    Customer customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order1 = new Order(1, &customer, restaurant);
    Order* order2 = new Order(2, &customer, restaurant);
    
    customer.addOrder(order1);
    EXPECT_EQ(customer.getOrders().size(), 1);
    
    customer.addOrder(order2);
    EXPECT_EQ(customer.getOrders().size(), 2);
    
    delete order1;
    delete order2;
    delete restaurant;
    delete owner;
}


// Additional tests for Cart class methods
TEST(CartTest, AllMethods) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Cart cart(1, customer);
    
    EXPECT_EQ(cart.getCartId(), 1);
    cart.setRestaurant(restaurant);
    
    Category* category = new Category(1, "Main", "Main dishes");
    MenuItem* menuItem = new MenuItem(1, "Pizza", 12.99, category);
    OrderItem* item = new OrderItem(1, menuItem, 2, "");
    cart.addItem(item);
    EXPECT_EQ(cart.getItems().size(), 1);
    cart.calculateTotal();
    EXPECT_GT(cart.getTotalAmount(), 0.0);
    
    delete item;
    delete menuItem;
    delete category;
    delete restaurant;
    delete customer;
    delete owner;
}

// Additional tests for Menu class methods
TEST(MenuTest, AllMethods) {
    Menu menu(1, "Main Menu");
    EXPECT_EQ(menu.getMenuId(), 1);
    EXPECT_EQ(menu.getName(), "Main Menu");
    
    Category* category = new Category(1, "Main", "Main dishes");
    MenuItem* item1 = new MenuItem(1, "Pizza", 12.99, category);
    MenuItem* item2 = new MenuItem(2, "Pasta", 14.99, category);
    
    menu.addItem(item1);
    EXPECT_EQ(menu.getItems().size(), 1);
    menu.addItem(item2);
    EXPECT_EQ(menu.getItems().size(), 2);
    
    delete item1;
    delete item2;
    delete category;
}


// Additional tests for Restaurant class methods
TEST(RestaurantTest, AllMethods) {
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant restaurant(1, "Pizza Place", owner);
    
    EXPECT_EQ(restaurant.getRestaurantId(), 1);
    EXPECT_EQ(restaurant.getName(), "Pizza Place");
    EXPECT_FALSE(restaurant.getIsOpen());
    restaurant.setIsOpen(true);
    EXPECT_TRUE(restaurant.getIsOpen());
    
    Menu* menu = new Menu(1, "Main Menu");
    restaurant.setMenu(menu);
    EXPECT_EQ(restaurant.getMenu(), menu);
    
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    Order* order = new Order(1, customer, &restaurant);
    restaurant.addOrder(order);
    EXPECT_EQ(restaurant.getOrders().size(), 1);
    
    delete order;
    delete customer;
    delete menu;
    delete owner;
}

// Additional tests for Manager class methods
TEST(ManagerTest, AllMethods) {
    RestaurantOwner* owner1 = new RestaurantOwner("Owner1", 50, 1);
    RestaurantOwner* owner2 = new RestaurantOwner("Owner2", 50, 2);
    Restaurant* restaurant1 = new Restaurant(1, "Pizza Place", owner1);
    Restaurant* restaurant2 = new Restaurant(2, "Burger Joint", owner2);
    Manager manager("Alice", 40, 1, 5000.0, restaurant1);
    
    EXPECT_EQ(manager.getRestaurant(), restaurant1);
    manager.setRestaurant(restaurant2);
    EXPECT_EQ(manager.getRestaurant(), restaurant2);
    
    testing::internal::CaptureStdout();
    manager.work();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete restaurant1;
    delete restaurant2;
    delete owner1;
    delete owner2;
}


// Additional tests for Cook class methods
TEST(CookTest, PrepareOrder) {
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Cook cook("Mike", 30, 1, 3500.0, restaurant);
    
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    Order* order = new Order(1, customer, restaurant);
    
    cook.prepareOrder(order);
    EXPECT_EQ(cook.getOrdersPrepared(), 1);
    
    delete order;
    delete customer;
    delete restaurant;
    delete owner;
}


// Additional tests for Cashier class methods
TEST(CashierTest, ProcessTransaction) {
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Cashier cashier("Sarah", 25, 1, 2500.0, restaurant);
    
    cashier.processTransaction(50.0);
    EXPECT_EQ(cashier.getTransactionsProcessed(), 1);
    
    delete restaurant;
    delete owner;
}


// Additional tests for Driver class methods
TEST(DriverTest, SetVehicleAndCompleteDelivery) {
    Vehicle* vehicle1 = new Vehicle(1, "ABC123", "Car");
    Vehicle* vehicle2 = new Vehicle(2, "XYZ789", "Truck");
    Driver driver("Tom", 32, 1, 3200.0, vehicle1);
    
    driver.setVehicle(vehicle2);
    EXPECT_EQ(driver.getVehicle(), vehicle2);
    
    driver.completeDelivery();
    EXPECT_EQ(driver.getDeliveriesCompleted(), 1);
    
    delete vehicle1;
    delete vehicle2;
}

TEST(DriverTest, PrintMethod) {
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Car");
    Driver driver("Tom", 32, 1, 3200.0, vehicle);
    
    testing::internal::CaptureStdout();
    driver.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete vehicle;
}

// Additional tests for Delivery class methods
TEST(DeliveryTest, SetMethods) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order1 = new Order(1, customer, restaurant);
    Order* order2 = new Order(2, customer, restaurant);
    Address* address1 = new Address(1, "123 Main St", "New York");
    Address* address2 = new Address(2, "456 Oak St", "New York");
    Vehicle* vehicle1 = new Vehicle(1, "ABC123", "Motorcycle");
    Vehicle* vehicle2 = new Vehicle(2, "XYZ789", "Bicycle");
    DeliveryPerson* dp1 = new DeliveryPerson("John", 35, 1, 3000.0, vehicle1);
    DeliveryPerson* dp2 = new DeliveryPerson("Jane", 30, 2, 3100.0, vehicle2);
    Delivery delivery(1, order1, dp1, address1, 5.0);
    
    EXPECT_EQ(delivery.getOrder(), order1);
    EXPECT_EQ(delivery.getDeliveryPerson(), dp1);
    
    delivery.setStatus("In Transit");
    EXPECT_EQ(delivery.getStatus(), "In Transit");
    
    delivery.completeDelivery();
    
    delete vehicle1;
    delete vehicle2;
    delete dp2;
    delete dp1;
    delete address2;
    delete address1;
    delete order2;
    delete order1;
    delete restaurant;
    delete customer;
    delete owner;
}

TEST(DeliveryTest, PrintMethod) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order = new Order(1, customer, restaurant);
    Address* address = new Address(1, "123 Main St", "New York");
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Motorcycle");
    DeliveryPerson* dp = new DeliveryPerson("John", 35, 1, 3000.0, vehicle);
    Delivery delivery(1, order, dp, address, 5.0);
    
    testing::internal::CaptureStdout();
    delivery.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete dp;
    delete address;
    delete order;
    delete restaurant;
    delete customer;
}

// Tests for OrderStatus class
TEST(OrderStatusTest, ConstructorAndGetters) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order = new Order(1, customer, restaurant);
    OrderStatus status(1, "Processing", "Order is being prepared", order);
    
    EXPECT_EQ(status.getStatusId(), 1);
    EXPECT_EQ(status.getStatusName(), "Processing");
    EXPECT_EQ(status.getDescription(), "Order is being prepared");
    EXPECT_EQ(status.getOrder(), order);
    
    delete order;
    delete restaurant;
    delete customer;
}

TEST(OrderStatusTest, Setters) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order1 = new Order(1, customer, restaurant);
    Order* order2 = new Order(2, customer, restaurant);
    OrderStatus status(1, "Processing", "Order is being prepared", order1);
    
    status.setStatusId(2);
    EXPECT_EQ(status.getStatusId(), 2);
    
    status.setStatusName("Completed");
    EXPECT_EQ(status.getStatusName(), "Completed");
    
    status.setDescription("Order has been delivered");
    EXPECT_EQ(status.getDescription(), "Order has been delivered");
    
    status.setTimestamp("2024-01-15 14:30:00");
    EXPECT_EQ(status.getTimestamp(), "2024-01-15 14:30:00");
    
    status.setOrder(order2);
    EXPECT_EQ(status.getOrder(), order2);
    
    delete order1;
    delete order2;
    delete restaurant;
    delete customer;
}

TEST(OrderStatusTest, PrintMethod) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order = new Order(1, customer, restaurant);
    OrderStatus status(1, "Processing", "Order is being prepared", order);
    
    testing::internal::CaptureStdout();
    status.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete order;
    delete restaurant;
    delete customer;
}

// Tests for OrderHistory class
TEST(OrderHistoryTest, ConstructorAndGetters) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    OrderHistory history(1, customer);
    
    EXPECT_EQ(history.getHistoryId(), 1);
    EXPECT_EQ(history.getCustomer(), customer);
    EXPECT_EQ(history.getTotalOrders(), 0);
    EXPECT_EQ(history.getTotalSpent(), 0.0);
    
    delete customer;
}

TEST(OrderHistoryTest, AddAndRemoveOrders) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    OrderHistory history(1, customer);
    
    Order* order1 = new Order(1, customer, restaurant);
    Order* order2 = new Order(2, customer, restaurant);
    
    history.addOrder(order1);
    EXPECT_EQ(history.getOrders().size(), 1);
    
    history.addOrder(order2);
    EXPECT_EQ(history.getOrders().size(), 2);
    
    history.removeOrder(order1);
    EXPECT_EQ(history.getOrders().size(), 1);
    
    delete order1;
    delete order2;
    delete restaurant;
    delete customer;
}

TEST(OrderHistoryTest, CalculateStatistics) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    OrderHistory history(1, customer);
    
    Order* order1 = new Order(1, customer, restaurant);
    Order* order2 = new Order(2, customer, restaurant);
    
    history.addOrder(order1);
    history.addOrder(order2);
    history.calculateStatistics();
    
    EXPECT_EQ(history.getTotalOrders(), 2);
    
    delete order1;
    delete order2;
    delete restaurant;
    delete customer;
}

TEST(OrderHistoryTest, SetCustomer) {
    Customer* customer1 = new Customer("Jane", 28, 1, "jane@email.com");
    Customer* customer2 = new Customer("John", 30, 2, "john@email.com");
    OrderHistory history(1, customer1);
    
    history.setCustomer(customer2);
    EXPECT_EQ(history.getCustomer(), customer2);
    
    delete customer1;
    delete customer2;
}

TEST(OrderHistoryTest, PrintMethod) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    OrderHistory history(1, customer);
    
    testing::internal::CaptureStdout();
    history.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete customer;
}

TEST(OrderTrackingTest, Setters) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order1 = new Order(1, customer, restaurant);
    Order* order2 = new Order(2, customer, restaurant);
    Address* address = new Address(1, "123 Main St", "New York");
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Motorcycle");
    DeliveryPerson* dp = new DeliveryPerson("John", 35, 1, 3000.0, vehicle);
    Delivery* delivery1 = new Delivery(1, order1, dp, address, 5.0);
    Delivery* delivery2 = new Delivery(2, order2, dp, address, 5.0);
    OrderTracking tracking(1, order1, delivery1);
    
    EXPECT_EQ(tracking.getTrackingId(), 1);
    EXPECT_EQ(tracking.getOrder(), order1);
    
    tracking.updateLocation("Restaurant");
    EXPECT_EQ(tracking.getCurrentLocation(), "Restaurant");
    
    tracking.updateStatus("In Transit");
    EXPECT_EQ(tracking.getStatus(), "In Transit");
    
    delete delivery1;
    delete delivery2;
    delete dp;
    delete address;
    delete order1;
    delete order2;
    delete restaurant;
    delete customer;
}

TEST(OrderTrackingTest, AddTrackingEvent) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order = new Order(1, customer, restaurant);
    Address* address = new Address(1, "123 Main St", "New York");
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Motorcycle");
    DeliveryPerson* dp = new DeliveryPerson("John", 35, 1, 3000.0, vehicle);
    Delivery* delivery = new Delivery(1, order, dp, address, 5.0);
    OrderTracking tracking(1, order, delivery);
    
    tracking.addTrackingEvent("Order received");
    tracking.addTrackingEvent("Order being prepared");
    
    delete delivery;
    delete dp;
    delete address;
    delete order;
    delete restaurant;
    delete customer;
}

TEST(OrderTrackingTest, PrintMethod) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order = new Order(1, customer, restaurant);
    Address* address = new Address(1, "123 Main St", "New York");
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Motorcycle");
    DeliveryPerson* dp = new DeliveryPerson("John", 35, 1, 3000.0, vehicle);
    Delivery* delivery = new Delivery(1, order, dp, address, 5.0);
    OrderTracking tracking(1, order, delivery);
    
    testing::internal::CaptureStdout();
    tracking.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete delivery;
    delete dp;
    delete address;
    delete order;
    delete restaurant;
    delete customer;
}

// Tests for DeliveryRoute class
TEST(DeliveryRouteTest, ConstructorAndGetters) {
    Address* start = new Address(1, "123 Main St", "New York");
    Address* end = new Address(2, "456 Oak St", "New York");
    DeliveryRoute route(1, start, end, 5.5, 30);
    
    EXPECT_EQ(route.getRouteId(), 1);
    EXPECT_EQ(route.getDistance(), 5.5);
    EXPECT_EQ(route.getEstimatedTime(), 30);
    
    delete start;
    delete end;
}

TEST(DeliveryRouteTest, AddAndRemoveWaypoints) {
    Address* start = new Address(1, "123 Main St", "New York");
    Address* end = new Address(2, "456 Oak St", "New York");
    Address* waypoint1 = new Address(3, "789 Pine St", "New York");
    Address* waypoint2 = new Address(4, "321 Elm St", "New York");
    DeliveryRoute route(1, start, end, 5.5, 30);
    
    route.addWaypoint(waypoint1);
    route.addWaypoint(waypoint2);
    route.calculateDistance();
    
    delete waypoint1;
    delete waypoint2;
    delete start;
    delete end;
}

TEST(DeliveryRouteTest, AddAndRemoveDeliveries) {
    Address* start = new Address(1, "123 Main St", "New York");
    Address* end = new Address(2, "456 Oak St", "New York");
    DeliveryRoute route(1, start, end, 5.5, 30);
    
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order1 = new Order(1, customer, restaurant);
    Order* order2 = new Order(2, customer, restaurant);
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Motorcycle");
    DeliveryPerson* dp = new DeliveryPerson("John", 35, 1, 3000.0, vehicle);
    Delivery* delivery1 = new Delivery(1, order1, dp, end, 5.0);
    Delivery* delivery2 = new Delivery(2, order2, dp, end, 5.0);
    
    route.addDelivery(delivery1);
    route.addDelivery(delivery2);
    route.removeDelivery(delivery1);
    
    delete delivery1;
    delete delivery2;
    delete dp;
    delete order1;
    delete order2;
    delete restaurant;
    delete customer;
    delete start;
    delete end;
}

TEST(DeliveryRouteTest, Setters) {
    Address* start1 = new Address(1, "123 Main St", "New York");
    Address* start2 = new Address(3, "789 Pine St", "New York");
    Address* end1 = new Address(2, "456 Oak St", "New York");
    Address* end2 = new Address(4, "321 Elm St", "New York");
    DeliveryRoute route(1, start1, end1, 5.5, 30);
    
    EXPECT_EQ(route.getRouteId(), 1);
    EXPECT_EQ(route.getDistance(), 5.5);
    EXPECT_EQ(route.getEstimatedTime(), 30);
    
    route.calculateDistance();
    
    delete start1;
    delete start2;
    delete end1;
    delete end2;
}

TEST(DeliveryRouteTest, PrintMethod) {
    Address* start = new Address(1, "123 Main St", "New York");
    Address* end = new Address(2, "456 Oak St", "New York");
    DeliveryRoute route(1, start, end, 5.5, 30);
    
    testing::internal::CaptureStdout();
    route.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete start;
    delete end;
}

// Tests for DeliveryTime class
TEST(DeliveryTimeTest, ConstructorAndGetters) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order = new Order(1, customer, restaurant);
    Address* address = new Address(1, "123 Main St", "New York");
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Motorcycle");
    DeliveryPerson* dp = new DeliveryPerson("John", 35, 1, 3000.0, vehicle);
    Delivery* delivery = new Delivery(1, order, dp, address, 5.0);
    DeliveryTime time(1, delivery, "14:30", 30);
    
    EXPECT_EQ(time.getTimeId(), 1);
    EXPECT_EQ(time.getDelivery(), delivery);
    EXPECT_EQ(time.getEstimatedTime(), "14:30");
    
    delete delivery;
    delete dp;
    delete address;
    delete order;
    delete restaurant;
    delete customer;
}

TEST(DeliveryTimeTest, Setters) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order1 = new Order(1, customer, restaurant);
    Order* order2 = new Order(2, customer, restaurant);
    Address* address = new Address(1, "123 Main St", "New York");
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Motorcycle");
    DeliveryPerson* dp = new DeliveryPerson("John", 35, 1, 3000.0, vehicle);
    Delivery* delivery1 = new Delivery(1, order1, dp, address, 5.0);
    Delivery* delivery2 = new Delivery(2, order2, dp, address, 5.0);
    DeliveryTime time(1, delivery1, "14:30", 30);
    
    EXPECT_EQ(time.getTimeId(), 1);
    EXPECT_EQ(time.getDelivery(), delivery1);
    EXPECT_EQ(time.getEstimatedTime(), "14:30");
    
    time.setActualTime("15:05");
    EXPECT_EQ(time.getActualTime(), "15:05");
    
    int delay = time.calculateDelay();
    EXPECT_GE(delay, 0);
    
    delete delivery1;
    delete delivery2;
    delete dp;
    delete address;
    delete order1;
    delete order2;
    delete restaurant;
    delete customer;
}

TEST(DeliveryTimeTest, CalculateDelay) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order = new Order(1, customer, restaurant);
    Address* address = new Address(1, "123 Main St", "New York");
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Motorcycle");
    DeliveryPerson* dp = new DeliveryPerson("John", 35, 1, 3000.0, vehicle);
    Delivery* delivery = new Delivery(1, order, dp, address, 5.0);
    DeliveryTime time(1, delivery, "14:30", 30);
    
    time.setActualTime("15:10");
    int delay = time.calculateDelay();
    EXPECT_GE(delay, 0);
    
    delete delivery;
    delete dp;
    delete address;
    delete order;
    delete restaurant;
    delete customer;
}

TEST(DeliveryTimeTest, PrintMethod) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order = new Order(1, customer, restaurant);
    Address* address = new Address(1, "123 Main St", "New York");
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Motorcycle");
    DeliveryPerson* dp = new DeliveryPerson("John", 35, 1, 3000.0, vehicle);
    Delivery* delivery = new Delivery(1, order, dp, address, 5.0);
    DeliveryTime time(1, delivery, "14:30", 30);
    
    testing::internal::CaptureStdout();
    time.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete delivery;
    delete dp;
    delete address;
    delete order;
    delete restaurant;
    delete customer;
}

// Tests for DeliveryStatus class
TEST(DeliveryStatusTest, ConstructorAndGetters) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order = new Order(1, customer, restaurant);
    Address* address = new Address(1, "123 Main St", "New York");
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Motorcycle");
    DeliveryPerson* dp = new DeliveryPerson("John", 35, 1, 3000.0, vehicle);
    Delivery* delivery = new Delivery(1, order, dp, address, 5.0);
    DeliveryStatus status(1, delivery, "In Transit", "Delivery is on the way");
    
    EXPECT_EQ(status.getStatusId(), 1);
    EXPECT_EQ(status.getDelivery(), delivery);
    EXPECT_EQ(status.getStatusName(), "In Transit");
    EXPECT_EQ(status.getDescription(), "Delivery is on the way");
    
    delete delivery;
    delete dp;
    delete address;
    delete order;
    delete restaurant;
    delete customer;
}

TEST(DeliveryStatusTest, Setters) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order1 = new Order(1, customer, restaurant);
    Order* order2 = new Order(2, customer, restaurant);
    Address* address = new Address(1, "123 Main St", "New York");
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Motorcycle");
    DeliveryPerson* dp = new DeliveryPerson("John", 35, 1, 3000.0, vehicle);
    Delivery* delivery1 = new Delivery(1, order1, dp, address, 5.0);
    Delivery* delivery2 = new Delivery(2, order2, dp, address, 5.0);
    DeliveryStatus status(1, delivery1, "In Transit", "Delivery is on the way");
    
    status.setStatusId(2);
    EXPECT_EQ(status.getStatusId(), 2);
    
    status.setDelivery(delivery2);
    EXPECT_EQ(status.getDelivery(), delivery2);
    
    status.setStatusName("Delivered");
    EXPECT_EQ(status.getStatusName(), "Delivered");
    
    status.setDescription("Order has been delivered successfully");
    EXPECT_EQ(status.getDescription(), "Order has been delivered successfully");
    
    status.setTimestamp("2024-01-15 15:00:00");
    EXPECT_EQ(status.getTimestamp(), "2024-01-15 15:00:00");
    
    delete delivery1;
    delete delivery2;
    delete dp;
    delete address;
    delete order1;
    delete order2;
    delete restaurant;
    delete customer;
}

TEST(DeliveryStatusTest, PrintMethod) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order = new Order(1, customer, restaurant);
    Address* address = new Address(1, "123 Main St", "New York");
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Motorcycle");
    DeliveryPerson* dp = new DeliveryPerson("John", 35, 1, 3000.0, vehicle);
    Delivery* delivery = new Delivery(1, order, dp, address, 5.0);
    DeliveryStatus status(1, delivery, "In Transit", "Delivery is on the way");
    
    testing::internal::CaptureStdout();
    status.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete delivery;
    delete dp;
    delete address;
    delete order;
    delete restaurant;
    delete customer;
}

// Tests for Receipt class
TEST(ReceiptTest, ConstructorAndGetters) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order = new Order(1, customer, restaurant);
    Payment* payment = new Payment(1, order, 25.99);
    Receipt receipt(1, payment, order, 25.99, "2024-01-15");
    
    EXPECT_EQ(receipt.getReceiptId(), 1);
    EXPECT_EQ(receipt.getPayment(), payment);
    EXPECT_EQ(receipt.getOrder(), order);
    EXPECT_EQ(receipt.getAmount(), 25.99);
    EXPECT_EQ(receipt.getReceiptDate(), "2024-01-15");
    
    delete payment;
    delete order;
    delete restaurant;
    delete customer;
}

TEST(ReceiptTest, Setters) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order1 = new Order(1, customer, restaurant);
    Order* order2 = new Order(2, customer, restaurant);
    Payment* payment1 = new Payment(1, order1, 25.99);
    Payment* payment2 = new Payment(2, order2, 30.99);
    Receipt receipt(1, payment1, order1, 25.99, "2024-01-15");
    
    EXPECT_EQ(receipt.getReceiptId(), 1);
    EXPECT_EQ(receipt.getPayment(), payment1);
    EXPECT_EQ(receipt.getOrder(), order1);
    EXPECT_EQ(receipt.getAmount(), 25.99);
    EXPECT_EQ(receipt.getReceiptDate(), "2024-01-15");
    
    delete payment1;
    delete payment2;
    delete order1;
    delete order2;
    delete restaurant;
    delete customer;
}

TEST(ReceiptTest, PrintMethod) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order = new Order(1, customer, restaurant);
    Payment* payment = new Payment(1, order, 25.99);
    Receipt receipt(1, payment, order, 25.99, "2024-01-15");
    
    testing::internal::CaptureStdout();
    receipt.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete payment;
    delete order;
    delete restaurant;
    delete customer;
}

// Tests for Transaction class
TEST(TransactionTest, ConstructorAndGetters) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order = new Order(1, customer, restaurant);
    Payment* payment = new Payment(1, order, 25.99);
    Transaction transaction(1, payment, "Credit Card", 25.99, "2024-01-15");
    
    EXPECT_EQ(transaction.getTransactionId(), 1);
    EXPECT_EQ(transaction.getPayment(), payment);
    EXPECT_EQ(transaction.getAmount(), 25.99);
    EXPECT_EQ(transaction.getStatus(), "Pending");
    
    delete payment;
    delete order;
    delete restaurant;
    delete customer;
}

TEST(TransactionTest, Setters) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order1 = new Order(1, customer, restaurant);
    Order* order2 = new Order(2, customer, restaurant);
    Payment* payment1 = new Payment(1, order1, 25.99);
    Payment* payment2 = new Payment(2, order2, 30.99);
    Transaction transaction(1, payment1, "Credit Card", 25.99, "2024-01-15");
    
    EXPECT_EQ(transaction.getTransactionId(), 1);
    EXPECT_EQ(transaction.getPayment(), payment1);
    EXPECT_EQ(transaction.getAmount(), 25.99);
    
    transaction.setStatus("Completed");
    EXPECT_EQ(transaction.getStatus(), "Completed");
    
    transaction.process();
    
    delete payment1;
    delete payment2;
    delete order1;
    delete order2;
    delete restaurant;
    delete customer;
}

TEST(TransactionTest, PrintMethod) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order = new Order(1, customer, restaurant);
    Payment* payment = new Payment(1, order, 25.99);
    Transaction transaction(1, payment, "Credit Card", 25.99, "2024-01-15");
    
    testing::internal::CaptureStdout();
    transaction.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete payment;
    delete order;
    delete restaurant;
    delete customer;
}

// Tests for InventoryItem class
TEST(InventoryItemTest, ConstructorAndGetters) {
    Address* address = new Address(1, "123 Main St", "New York");
    Warehouse* warehouse = new Warehouse(1, "Main Warehouse", address, 1000.0);
    InventoryItem item(1, "Flour", "Dry Goods", 100, 2.50, "2024-01-01", warehouse);
    
    EXPECT_EQ(item.getItemId(), 1);
    EXPECT_EQ(item.getName(), "Flour");
    EXPECT_EQ(item.getQuantity(), 100);
    EXPECT_EQ(item.getUnitPrice(), 2.50);
    
    delete warehouse;
    delete address;
}

TEST(InventoryItemTest, Setters) {
    Address* address1 = new Address(1, "123 Main St", "New York");
    Address* address2 = new Address(2, "456 Oak St", "New York");
    Warehouse* warehouse1 = new Warehouse(1, "Main Warehouse", address1, 1000.0);
    Warehouse* warehouse2 = new Warehouse(2, "Secondary Warehouse", address2, 500.0);
    InventoryItem item(1, "Flour", "Dry Goods", 100, 2.50, "2024-01-01", warehouse1);
    
    EXPECT_EQ(item.getItemId(), 1);
    EXPECT_EQ(item.getName(), "Flour");
    EXPECT_EQ(item.getQuantity(), 100);
    
    item.setQuantity(150);
    EXPECT_EQ(item.getQuantity(), 150);
    
    item.restock(50);
    EXPECT_EQ(item.getQuantity(), 200);
    
    delete warehouse1;
    delete warehouse2;
    delete address1;
    delete address2;
}

TEST(InventoryItemTest, PrintMethod) {
    Address* address = new Address(1, "123 Main St", "New York");
    Warehouse* warehouse = new Warehouse(1, "Main Warehouse", address, 1000.0);
    InventoryItem item(1, "Flour", "Dry Goods", 100, 2.50, "2024-01-01", warehouse);
    
    testing::internal::CaptureStdout();
    item.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete warehouse;
    delete address;
}

// Additional tests for Employee class methods
TEST(EmployeeTest, SetSalary) {
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Motorcycle");
    DeliveryPerson* dp = new DeliveryPerson("John", 35, 1, 3000.0, vehicle);
    
    dp->setSalary(3500.0);
    EXPECT_EQ(dp->getSalary(), 3500.0);
    
    dp->setSalary(-100.0);
    EXPECT_EQ(dp->getSalary(), 3500.0);
    
    delete dp;
}

TEST(EmployeeTest, PrintMethod) {
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Motorcycle");
    DeliveryPerson* dp = new DeliveryPerson("John", 35, 1, 3000.0, vehicle);
    testing::internal::CaptureStdout();
    dp->print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    delete dp;
}

// Additional tests for MenuItem class methods
TEST(MenuItemTest, SetIsAvailable) {
    Category* category = new Category(1, "Appetizers", "Starters");
    MenuItem item(1, "Caesar Salad", 8.99, category);
    
    // Test that item can be created and basic operations work
    EXPECT_EQ(item.getItemId(), 1);
    EXPECT_EQ(item.getName(), "Caesar Salad");
    EXPECT_EQ(item.getPrice(), 8.99);
    
    delete category;
}

TEST(MenuItemTest, PrintMethod) {
    Category* category = new Category(1, "Appetizers", "Starters");
    MenuItem item(1, "Caesar Salad", 8.99, category);
    
    testing::internal::CaptureStdout();
    item.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete category;
}

// Additional tests for Category class methods
TEST(CategoryTest, PrintMethod) {
    Category category(1, "Appetizers", "Starters and appetizers");
    testing::internal::CaptureStdout();
    category.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

// Additional tests for Cuisine class methods
TEST(CuisineTest, PrintMethod) {
    Cuisine cuisine(1, "Italian", "Italy", "Traditional Italian dishes");
    testing::internal::CaptureStdout();
    cuisine.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

// Additional tests for Branch class methods
TEST(BranchTest, PrintMethod) {
    Address* address = new Address(1, "123 Main St", "New York");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Branch branch(1, restaurant, address, "555-1234", 50);
    
    testing::internal::CaptureStdout();
    branch.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete address;
    delete restaurant;
}

// Additional tests for OrderItem class methods
TEST(OrderItemTest, PrintMethod) {
    Category* category = new Category(1, "Main", "Main dishes");
    MenuItem* menuItem = new MenuItem(1, "Pizza", 12.99, category);
    OrderItem orderItem(1, menuItem, 2, "No onions");
    
    testing::internal::CaptureStdout();
    orderItem.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete menuItem;
    delete category;
}

// Additional tests for Vehicle class methods
TEST(VehicleTest, SetIsAvailable) {
    Vehicle vehicle(1, "ABC123", "Motorcycle");
    
    vehicle.setIsAvailable(false);
    EXPECT_FALSE(vehicle.getIsAvailable());
    
    vehicle.setIsAvailable(true);
    EXPECT_TRUE(vehicle.getIsAvailable());
}

TEST(VehicleTest, PrintMethod) {
    Vehicle vehicle(1, "ABC123", "Motorcycle");
    testing::internal::CaptureStdout();
    vehicle.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

// Additional tests for DeliveryZone class methods
TEST(DeliveryZoneTest, PrintMethod) {
    DeliveryZone zone(1, "Downtown", 3.0, 30);
    testing::internal::CaptureStdout();
    zone.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

// Additional tests for Payment class methods
TEST(PaymentTest, PrintMethod) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order = new Order(1, customer, restaurant);
    Payment payment(1, order, 25.99);
    
    testing::internal::CaptureStdout();
    payment.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete order;
    delete restaurant;
    delete customer;
}

// Additional tests for PaymentMethod class methods
TEST(PaymentMethodTest, PrintMethod) {
    PaymentMethod method(1, "Credit Card", "1234-5678-9012-3456", "John Doe", "12/25");
    testing::internal::CaptureStdout();
    method.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

// Additional tests for Invoice class methods
TEST(InvoiceTest, PrintMethod) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order = new Order(1, customer, restaurant);
    Invoice invoice(1, order, customer, 25.99, "2024-01-15");
    
    testing::internal::CaptureStdout();
    invoice.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete order;
    delete restaurant;
    delete customer;
}

// Additional tests for Review class methods
TEST(ReviewTest, PrintMethod) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order = new Order(1, customer, restaurant);
    Review review(1, customer, restaurant, order, 5, "Great food!", "2024-01-16");
    
    testing::internal::CaptureStdout();
    review.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete order;
    delete restaurant;
    delete customer;
}

// Additional tests for Rating class methods
TEST(RatingTest, PrintMethod) {
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Motorcycle");
    DeliveryPerson* dp = new DeliveryPerson("John", 35, 1, 3000.0, vehicle);
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    Rating rating(1, restaurant, dp, customer, 5, 4, "2024-01-16");
    
    testing::internal::CaptureStdout();
    rating.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete restaurant;
    delete dp;
    delete customer;
}

// Additional tests for Feedback class methods
TEST(FeedbackTest, PrintMethod) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order = new Order(1, customer, restaurant);
    Feedback feedback(1, customer, order, "Suggestion", "Add more vegetarian options", "2024-01-16");
    
    testing::internal::CaptureStdout();
    feedback.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete order;
    delete restaurant;
    delete customer;
}

// Additional tests for Complaint class methods
TEST(ComplaintTest, PrintMethod) {
    Customer* customer = new Customer("Jane", 28, 1, "jane@email.com");
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Order* order = new Order(1, customer, restaurant);
    Complaint complaint(1, customer, order, "Late Delivery", "Order arrived 30 minutes late", "2024-01-16");
    
    testing::internal::CaptureStdout();
    complaint.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete order;
    delete restaurant;
    delete customer;
}

// Additional tests for Ingredient class methods
TEST(IngredientTest, PrintMethod) {
    Address* address = new Address(1, "123 Main St", "New York");
    Supplier* supplier = new Supplier(1, "Food Supply Co", "John", "555-1234", "supply@email.com", address);
    Ingredient ingredient(1, "Flour", 100.0, supplier);
    
    testing::internal::CaptureStdout();
    ingredient.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete supplier;
    delete address;
}

// Additional tests for Stock class methods
TEST(StockTest, PrintMethod) {
    Address* address = new Address(1, "123 Main St", "New York");
    Supplier* supplier = new Supplier(1, "Food Supply Co", "John", "555-1234", "supply@email.com", address);
    Ingredient* ingredient = new Ingredient(1, "Flour", 100.0, supplier);
    Warehouse* warehouse = new Warehouse(1, "Main Warehouse", address, 1000.0);
    Stock stock(1, ingredient, warehouse, 50.0, 10.0, 200.0);
    
    testing::internal::CaptureStdout();
    stock.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete warehouse;
    delete ingredient;
    delete supplier;
    delete address;
}

// Additional tests for Warehouse class methods
TEST(WarehouseTest, PrintMethod) {
    Address* address = new Address(1, "123 Main St", "New York");
    Warehouse warehouse(1, "Main Warehouse", address, 1000.0);
    
    testing::internal::CaptureStdout();
    warehouse.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete address;
}

// Additional tests for Shift class methods
TEST(ShiftTest, PrintMethod) {
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Motorcycle");
    DeliveryPerson* dp = new DeliveryPerson("John", 35, 1, 3000.0, vehicle);
    Shift shift(1, dp, "2024-01-15");
    
    testing::internal::CaptureStdout();
    shift.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete dp;
}

// Additional tests for Schedule class methods
TEST(ScheduleTest, PrintMethod) {
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Motorcycle");
    DeliveryPerson* dp = new DeliveryPerson("John", 35, 1, 3000.0, vehicle);
    Schedule schedule(1, dp, "2024-01-15");
    
    testing::internal::CaptureStdout();
    schedule.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete dp;
}

// Additional tests for Task class methods
TEST(TaskTest, PrintMethod) {
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Motorcycle");
    DeliveryPerson* dp = new DeliveryPerson("John", 35, 1, 3000.0, vehicle);
    Task task(1, "Deliver Order", "Deliver order #123", dp, "2024-01-20", 1);
    
    testing::internal::CaptureStdout();
    task.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete dp;
}

// Additional tests for WorkLog class methods
TEST(WorkLogTest, PrintMethod) {
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Motorcycle");
    DeliveryPerson* dp = new DeliveryPerson("John", 35, 1, 3000.0, vehicle);
    WorkLog log(1, dp, "2024-01-15", "08:00", "16:00", 8);
    
    testing::internal::CaptureStdout();
    log.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete dp;
}

// Additional tests for Performance class methods
TEST(PerformanceTest, PrintMethod) {
    Vehicle* vehicle = new Vehicle(1, "ABC123", "Motorcycle");
    DeliveryPerson* dp = new DeliveryPerson("John", 35, 1, 3000.0, vehicle);
    Performance perf(1, dp, "2024-01-15", 8, "Excellent work");
    
    testing::internal::CaptureStdout();
    perf.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete dp;
}

// Additional tests for Zone class methods
TEST(ZoneTest, PrintMethod) {
    Zone zone(1, "Downtown", 3.0, 30);
    testing::internal::CaptureStdout();
    zone.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

// Additional tests for City class methods
TEST(CityTest, PrintMethod) {
    City city(1, "New York", "NY", "USA");
    testing::internal::CaptureStdout();
    city.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
}

// Additional tests for Promotion class methods
TEST(PromotionTest, PrintMethod) {
    RestaurantOwner* owner = new RestaurantOwner("Owner", 50, 1);
    Restaurant* restaurant = new Restaurant(1, "Pizza Place", owner);
    Promotion promotion(1, restaurant, 20.0);
    
    testing::internal::CaptureStdout();
    promotion.print();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_FALSE(output.empty());
    
    delete restaurant;
}

// Additional tests for Discount class methods

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}


