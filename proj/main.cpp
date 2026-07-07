#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include "List.h"      // Подключите файл, в котором находится класс List

TEST_CASE("Проверка Empty для нового списка", "[Empty]")
{
    List list;

    REQUIRE(list.Empty() == true);
    REQUIRE(list.Size() == 0);
}

TEST_CASE("Проверка Size после добавления элементов", "[Size]")
{
    List list;

    list.PushBack(10);
    REQUIRE(list.Size() == 1);

    list.PushBack(20);
    REQUIRE(list.Size() == 2);

    list.PushFront(5);
    REQUIRE(list.Size() == 3);

    REQUIRE_FALSE(list.Empty());
}

TEST_CASE("Проверка Clear очищает список", "[Clear]")
{
    List list;

    list.PushBack(1);
    list.PushBack(2);
    list.PushFront(0);

    REQUIRE(list.Size() == 3);

    list.Clear();

    REQUIRE(list.Empty());
    REQUIRE(list.Size() == 0);
}

TEST_CASE("Clear для пустого списка", "[Clear]")
{
    List list;

    REQUIRE_NOTHROW(list.Clear());

    REQUIRE(list.Empty());
    REQUIRE(list.Size() == 0);
}

TEST_CASE("После Clear список можно использовать снова", "[Clear]")
{
    List list;

    list.PushBack(10);
    list.PushBack(20);

    list.Clear();

    REQUIRE(list.Empty());
    REQUIRE(list.Size() == 0);

    list.PushFront(5);

    REQUIRE_FALSE(list.Empty());
    REQUIRE(list.Size() == 1);
}