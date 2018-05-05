/* Copyright 2018 TolyaTalamanov */

#include <gtest/gtest.h>
#include <vector>
#include "include/max_binary_heap.hpp"

TEST(MaxBinaryHeapTest, Can_Create_Empty_Heap) {
  // AAA
  ASSERT_NO_THROW(MaxBinaryHeap<int> heap);
}

TEST(MaxBinaryHeapTest, Can_Create_Heap_With_Reserved_Memory) {
  // AAA
  ASSERT_NO_THROW(MaxBinaryHeap<int> heap(100));
}

TEST(MaxBinaryHeapTest, Can_Create_Heap_From_Initializer_List) {
  // AAA
  ASSERT_NO_THROW(MaxBinaryHeap<int> heap{1});
}

TEST(MaxBinaryHeapTest, Can_Create_Heap_From_Vector) {
  // Arrange
  std::vector<int> v {1, 4, -3, 2};

  // Act & Assert
  ASSERT_NO_THROW(MaxBinaryHeap<int> heap(v.begin(), v.end()));
}

TEST(MaxBinaryHeapTest, Check_That_Empty_Heap_Is_Empty) {
  // Arrange
  MaxBinaryHeap<int> heap;

  // Act & Assert
  ASSERT_TRUE(heap.empty());
}

TEST(MaxBinaryHeapTest, Check_Heap_Size) {
  // Arrange
  MaxBinaryHeap<int> heap;

  // Act
  for (int i = 0; i < 100; ++i) {
    heap.push(i);
  }

  // Assert
  EXPECT_EQ(100, heap.size());
}

TEST(MaxBinaryHeapTest, Right_Push_Element) {
  // Arrange
  MaxBinaryHeap<int> heap = {1, 3, 5};

  // Act
  heap.push(1000);

  // Assert
  EXPECT_EQ(1000, heap.top());
}

TEST(MaxBinaryHeapTest, Right_Emplace_Element) {
  // Arrange
  MaxBinaryHeap<int> heap = {1, 3, 5};

  // Act
  heap.emplace(1000);

  // Assert
  EXPECT_EQ(1000, heap.top());
}

TEST(MaxBinaryHeapTest, Throw_When_Get_Top_From_Empty_Heap) {
  // Arrange
  MaxBinaryHeap<int> heap;

  // Act & Assert
  ASSERT_ANY_THROW(heap.top());
}

TEST(MaxBinaryHeapTest, Check_Get_Top) {
  // Arrange
  MaxBinaryHeap<int> heap;

  // Act
  for (int i = 0; i < 4; ++i) {
    heap.push(i);
  }

  // Assert
  EXPECT_EQ(3, heap.top());
}

TEST(MaxBinaryHeapTest, Throw_When_Delete_Top_From_Empty_Heap) {
  // Arrange
  MaxBinaryHeap<int> heap;

  // Act & Assert
  ASSERT_NO_THROW(heap.pop());
}

TEST(MaxBinaryHeapTest, Check_Delete_Top) {
  // Arrange
  MaxBinaryHeap<int> heap = {3, 5, 10, 2, 1};

  // Act
  heap.pop();

  // Assert
  EXPECT_EQ(5, heap.top());
}
