#include "../src/usecase/stack.h"
#include "gtest/gtest.h"

TEST(Ground_Send_Stack_Test, Test1) {
    char command_data[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    Ground_Send_Stack(command_data);
    // TODO: Add your assertions here
}

TEST(Ground_Send_Stack_Test, Test2) {
    char command_data[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    Ground_Send_Stack(command_data);
    // TODO: Add your assertions here
}

TEST(Ground_Send_Stack_Test, Test3) {
    char command_data[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    for (int i = 0; i < 100; i++) {
        Ground_Send_Stack(command_data);
    }
    // TODO: Add your assertions here
}

TEST(Ground_Send_Stack_Test, Test4) {
    char command_data[] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    for (int i = 0; i < 1000; i++) {
        Ground_Send_Stack(command_data);
    }
    // TODO: Add your assertions here
}