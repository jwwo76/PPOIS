#include "pch.h"
#include "Queue.h"

// ����: ����� ������� �����
TEST(QueueTest, NewQueueIsEmpty) {
    Queue q;
    testing::internal::CaptureStdout();
    q.display();
    std::string output = testing::internal::GetCapturedStdout();
    EXPECT_NE(output.find("������� �����"), std::string::npos);
}

// ����: ���������� ���������
TEST(QueueTest, EnqueueAddsElements) {
    Queue q;
    q.enqueue(10);
    q.enqueue(20);

    testing::internal::CaptureStdout();
    q.display();        
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_NE(output.find("10"), std::string::npos);
    EXPECT_NE(output.find("20"), std::string::npos);
}

// ����: �������� ���������
TEST(QueueTest, DequeueRemovesElements) {
    Queue q;
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);

    q.dequeue(); // ������ ������� 1

    testing::internal::CaptureStdout();
    q.display();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output.find("1"), std::string::npos); // 1 ������ ���
    EXPECT_NE(output.find("2"), std::string::npos);
    EXPECT_NE(output.find("3"), std::string::npos);
}

// ����: dequeue �� ������ �������
TEST(QueueTest, DequeueOnEmptyQueueDoesNothing) {
    Queue q;
    EXPECT_NO_THROW(q.dequeue()); // ������ ��������, ��� �� ������
}

// ����: ��������� enqueue + dequeue
TEST(QueueTest, EnqueueDequeueMixed) {
    Queue q;
    q.enqueue(5);
    q.enqueue(6);
    q.dequeue();  // �������� 5
    q.enqueue(7);

    testing::internal::CaptureStdout();
    q.display();
    std::string output = testing::internal::GetCapturedStdout();

    EXPECT_EQ(output.find("5"), std::string::npos);
    EXPECT_NE(output.find("6"), std::string::npos);
    EXPECT_NE(output.find("7"), std::string::npos);
}
