#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>


#include "List.h"

TEST_CASE("PushBack добавляет элементы в конец списка")
{
    List list;

    list.PushBack(10);
    list.PushBack(20);

    REQUIRE(list.Size() == 2);
    REQUIRE(list.PopBack() == 20);
    REQUIRE(list.PopBack() == 10);
}

TEST_CASE("PushFront добавляет элементы в начало списка")
{
    List list;

    list.PushFront(10);
    list.PushFront(20);

    REQUIRE(list.Size() == 2);
    REQUIRE(list.PopFront() == 20);
    REQUIRE(list.PopFront() == 10);
}

TEST_CASE("PopBack для пустого списка выбрасывает исключение")
{
    List list;

    REQUIRE_THROWS_AS(list.PopBack(), std::runtime_error);
}

TEST_CASE("PopFront для пустого списка выбрасывает исключение")
{
    List list;

    REQUIRE_THROWS_AS(list.PopFront(), std::runtime_error);
}

TEST_CASE("Сложный сценарий использования списка")
{
    List list;

    list.PushBack(10);
    list.PushBack(20);
    list.PushFront(5);
    list.PushFront(1);

    REQUIRE(list.Size() == 4);

    REQUIRE(list.PopFront() == 1);
    REQUIRE(list.PopBack() == 20);

    list.PushBack(30);
    list.PushFront(0);

    REQUIRE(list.PopFront() == 0);
    REQUIRE(list.PopFront() == 5);
    REQUIRE(list.PopBack() == 30);
    REQUIRE(list.PopBack() == 10);

    REQUIRE(list.Empty());
    REQUIRE(list.Size() == 0);
}