#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <sstream>

#include <ResourceDynamic/Resource.h>
#include <HandlersDynamic/Handlers.h>
#include <TableDynamic/Table.h>
#include <RDialogueDynamic/RDialogue.h>
#include <TDialogueDynamic/TDialogue.h>

TEST_CASE("Dynamic Table Adding")
{
    SECTION("Adding : NoExcept")
    {
        TNS::Table t;
        RNS::Resource r1{"coal", 0.7, 10.0, 13.3};
        RNS::Resource r2{"gold", 1.3, 23.9, 24.8};
        RNS::Resource r3{"coal", 1.5, 12.3, 10.9};

        REQUIRE_NOTHROW(t.add(r1));
        REQUIRE(t.getCSize() == 1);
        REQUIRE(t.getTablePtr()[0].getName() == "coal");

        REQUIRE_NOTHROW(t.add(r2));
        REQUIRE(t.getCSize() == 2);
        REQUIRE(t.getTablePtr()[0].getName() == "coal");
        REQUIRE(t.getTablePtr()[1].getName() == "gold");

        REQUIRE_NOTHROW(t.add(r3));
        REQUIRE(t.getCSize() == 3);
        REQUIRE(t.getTablePtr()[0].getName() == "coal");
        REQUIRE(t.getTablePtr()[1].getName() == "coal");
        REQUIRE(t.getTablePtr()[2].getName() == "gold");
    }
}
TEST_CASE("Dynamic Table Renaming")
{
    SECTION("Renaming : NoExcept")
    {
        TNS::Table t;
        RNS::Resource r1{"coal", 0.7, 10.0, 13.3};
        RNS::Resource r2{"gold", 1.3, 23.9, 24.8};
        RNS::Resource r3{"coal", 1.5, 12.3, 10.9};
        RNS::Resource r4{"zinc", 4.2, 13.2,  9.8};
        RNS::Resource r5{"zinc", 4.3, 13.1, 11.8};
        
        REQUIRE_NOTHROW(t.add(r1));
        REQUIRE_NOTHROW(t.add(r2));
        REQUIRE_NOTHROW(t.add(r3));
        REQUIRE_NOTHROW(t.add(r4));
        REQUIRE_NOTHROW(t.add(r5));

        REQUIRE_NOTHROW(t.rename("coal", "zinc_new"));
        REQUIRE_NOTHROW(t.rename("diamond", "placeholder"));
        REQUIRE_NOTHROW(t.rename("zinc", "coal_new"));

        REQUIRE(t.getCSize() == 5);
        REQUIRE(t.getTablePtr()[0].getName() == "coal_new");
        REQUIRE(t.getTablePtr()[1].getName() == "coal_new");
        REQUIRE(t.getTablePtr()[2].getName() == "gold");
        REQUIRE(t.getTablePtr()[3].getName() == "zinc_new");
        REQUIRE(t.getTablePtr()[4].getName() == "zinc_new");
    }
}
TEST_CASE("Dynamic Table Deletion")
{
    SECTION("Deletion : Index (NoExcept)")
    {
        TNS::Table t;              
        RNS::Resource r1{"coal",  2.3,  9.5, 11.65};
        RNS::Resource r2{"gold", 33.3, 10.8, 11.91};
        RNS::Resource r3{"coal",  1.7,  2.3,  7.4 };
        
        REQUIRE_NOTHROW(t.add(r1));
        REQUIRE_NOTHROW(t.add(r2));
        REQUIRE_NOTHROW(t.add(r3));

        REQUIRE_NOTHROW(t.deleteByIndex(2));
        REQUIRE(t.getCSize() == 2);

        REQUIRE_NOTHROW(t.deleteByIndex(1));
        REQUIRE(t.getCSize() == 1);

        REQUIRE_NOTHROW(t.deleteByIndex(0));
        REQUIRE(t.getCSize() == 0);
    }

    SECTION("Deletion : Index (Except-1)")
    {
        TNS::Table t;      
        REQUIRE_NOTHROW(t.deleteByIndex(-1));
    }

    SECTION("Deletion : Index (Except-2)")
    {
        TNS::Table t;      
        REQUIRE_NOTHROW(t.deleteByIndex(3));
    }

    SECTION("Deletion : Index (Except-3)")
    {
        TNS::Table t;              
        RNS::Resource r1{"coal",  2.3,  9.5, 11.65};
        RNS::Resource r2{"gold", 33.3, 10.8, 11.91};
        RNS::Resource r3{"coal",  1.7,  2.3,  7.4 };
        
        REQUIRE_NOTHROW(t.add(r1));
        REQUIRE_NOTHROW(t.add(r2));
        REQUIRE_NOTHROW(t.add(r3));

        REQUIRE_NOTHROW(t.deleteByIndex(3));
    }

    SECTION("Deletion : Name-1")
    {
        TNS::Table t;
        RNS::Resource r1{"coal",  2.3,  9.5, 11.65};
        RNS::Resource r2{"gold", 33.3, 10.8, 11.91};
        RNS::Resource r3{"coal",  1.7,  2.3,  7.4 };
        t += r1; t += r2; t += r3;

        REQUIRE_NOTHROW(t.deleteByName("coal"));
        REQUIRE(t.getCSize() == 1);
        REQUIRE(t.getTablePtr()[0].getName() == "gold");
    }

    SECTION("Deletion : Name-2")
    {
        TNS::Table t;
        REQUIRE_NOTHROW(t.deleteByName("coal"));
        REQUIRE(t.getCSize() == 0);
    }
}
TEST_CASE("Dynamic Table Profit")
{
    SECTION("Profit : Positive")
    {
        TNS::Table t;      
        double epsilon = 0.0000000000001;
        RNS::Resource r1{"coal",  2.3,  9.5, 11.65};
        RNS::Resource r2{"gold", 33.3, 10.8, 11.91};
        RNS::Resource r3{"coal",  1.7,  2.3,  7.4 };

        REQUIRE_NOTHROW(t.add(r1));
        REQUIRE_NOTHROW(t.add(r2));
        REQUIRE_NOTHROW(t.add(r3));

        REQUIRE_NOTHROW(t.getProfit());
        REQUIRE(abs(abs(t.getProfit()) - 354.046) <= epsilon);
    }

    SECTION("Profit : Negative")
    {
        TNS::Table t;      
        double epsilon = 0.0000000000001;
        RNS::Resource r1{"coal",  2.3, 11.65,  9.5};
        RNS::Resource r2{"gold", 33.3, 11.91, 10.8};
        RNS::Resource r3{"coal",  1.7,  7.4 ,  2.3};
        
        REQUIRE_NOTHROW(t.add(r1));
        REQUIRE_NOTHROW(t.add(r2));
        REQUIRE_NOTHROW(t.add(r3));

        REQUIRE_NOTHROW(t.getProfit());
        REQUIRE(t.getProfit() < 0.0);
        REQUIRE(abs(abs(t.getProfit()) - 354.046) <= epsilon);
    }
}
TEST_CASE("Dynamic Table Turnover")
{
    SECTION("IncTurnover")
    {
        TNS::Table t;
        RNS::Resource r1{"coal", 0.7, 10.0, 13.3};
        RNS::Resource r2{"gold", 1.3, 23.9, 24.8};
        RNS::Resource r3{"coal", 1.5, 12.3, 10.9};
        t += r1; t += r1; t += r3;

        t.print(std::cout);
        REQUIRE_NOTHROW(t * 1.1);

        double eps = 0.0000000000001;
        REQUIRE(abs(t.getResByIndex(0).getDC() - 13.53) < eps);
        REQUIRE(abs(t.getResByIndex(0).getDP() - 11.99) < eps);

        REQUIRE(abs(t.getResByIndex(1).getDC() - 11.0 ) < eps);
        REQUIRE(abs(t.getResByIndex(1).getDP() - 14.63) < eps);

        REQUIRE(abs(t.getResByIndex(2).getDC() - 26.29) < eps);
        REQUIRE(abs(t.getResByIndex(2).getDP() - 27.28) < eps);
    }
}
TEST_CASE("Dynamic Table Search")
{
    SECTION("Multiple Search")
    {
        TNS::Table t;
        RNS::Resource r1{"coal", 0.7, 10.0, 13.3};
        RNS::Resource r2{"gold :)", 1.3, 23.9, 24.8};
        RNS::Resource r3{"coal", 1.5, 12.3, 10.9};
        t += r1; t += r2; t += r3;

        REQUIRE_NOTHROW(t.searchResult("diamond"));
        REQUIRE_NOTHROW(t.searchResult("coal"));
        TNS::Table search = t.searchResult("coal");

        REQUIRE(search.getCSize() == 2);
        double eps = 0.0000000000001;

        REQUIRE_NOTHROW(search.getResByIndex(-1));

        REQUIRE(search.getResByIndex(0).getName() == "coal");
        REQUIRE(abs(search.getResByIndex(0).getPrice() - 0.7) < eps);

        REQUIRE(search.getResByIndex(1).getName() == "coal");
        REQUIRE(abs(search.getResByIndex(0).getPrice() - 1.5) < eps);
    }

    SECTION("Search Operator")
    {
        TNS::Table t;
        RNS::Resource r1{"coal", 0.7, 10.0, 13.3};
        RNS::Resource r2{"gold", 1.3, 23.9, 24.8};
        RNS::Resource r3{"coal", 1.5, 12.3, 10.9};
        t += r1; t += r2; t += r3;

        double eps = 0.0000000000001;
        const RNS::Resource& found = t["coal"];
        REQUIRE(abs(found.getPrice() - 1.5) < eps);
    }
}
TEST_CASE("Dynamic Table Constructors")
{
    SECTION("Copying")
    {
        // ориганальная таблица, где удаляется 1 эл-т
        TNS::Table t;
        RNS::Resource r1{"coal", 0.7, 10.0, 13.3};
        RNS::Resource r2{"gold", 1.3, 23.9, 24.8};
        RNS::Resource r3{"coal", 1.5, 12.3, 10.9};
        REQUIRE_NOTHROW(t.add(r1));
        REQUIRE_NOTHROW(t.add(r2));
        REQUIRE_NOTHROW(t.add(r3));

        TNS::Table copied = t;

        TNS::Table link = t;
        TNS::Table copied_by_constructor{link};

        REQUIRE_NOTHROW(copied.deleteByIndex(2));
        REQUIRE(copied.getCSize() == 2);

        REQUIRE_NOTHROW(copied_by_constructor.deleteByName("coal"));
        REQUIRE(copied_by_constructor.getCSize() == 1);

        REQUIRE(t.getCSize() == 3);
    }
}
TEST_CASE("Dynamic Table Move/Copy Assignments")
{
    SECTION("Move Assignment")
    {
        TNS::Table table, move;
        RNS::Resource r1{"coal", 1.1, 10.5, 11.5};
        RNS::Resource r2{"diamond", 1.2, 7.5, 8.5};
        REQUIRE_NOTHROW(table += r1);
        REQUIRE_NOTHROW(table += r2);
        move = std::move(table);
        REQUIRE(move.getCSize() == 2);
        REQUIRE(table.getCSize() == 0);
    }

    SECTION("Copy Assignment")
    {
        TNS::Table table, move;
        RNS::Resource r1{"coal", 1.1, 10.5, 11.5};
        RNS::Resource r2{"diamond", 1.2, 7.5, 8.5};
        REQUIRE_NOTHROW(table += r1);
        REQUIRE_NOTHROW(table += r2);
        move = table;
        REQUIRE(move.getCSize() == 2);
        REQUIRE(table.getCSize() == 2);
    }
}
TEST_CASE("Dynamic Table Output")
{
    SECTION("Operator Output")
    {
        TNS::Table t;
        REQUIRE_NOTHROW(t.print(std::cout));
        RNS::Resource r1{"coal", 0.7, 10.0, 13.3};
        RNS::Resource r2{"gold!", 1.3, 23.9, 24.8};
        RNS::Resource r3{"coal", 1.5, 12.3, 10.9};
        t += r1; t += r1; t += r3;

        REQUIRE_NOTHROW(t.prettify());
        std::cout << t["coal"];
        std::cout << t;
    }
}

TEST_CASE("Dynamic Resource")
{
    SECTION("Setters")
    {
        RNS::Resource res;
        double eps = 0.0000000000001;
        REQUIRE(res.getName() == "");
        REQUIRE(abs(res.getDC() - 0.0) <= eps);
        REQUIRE(abs(res.getDP() - 0.0) <= eps);
        REQUIRE(abs(res.getPrice() - 0.0) <= eps);

        REQUIRE_NOTHROW(res.setName("coal"));
        REQUIRE_NOTHROW(res.setPrice(1.3));
        REQUIRE_NOTHROW(res.setDC(9.5));
        REQUIRE_NOTHROW(res.setDP(10));

        REQUIRE(res.getName() == "coal");
        REQUIRE(abs(res.getPrice() - 1.3) <= eps);
        REQUIRE(abs(res.getDC() - 9.5) <= eps);
        REQUIRE(abs(res.getDP() - 10.0) <= eps);

        REQUIRE_NOTHROW(res.setPrice(-1));
        REQUIRE_NOTHROW(res.setDC(-1));
        REQUIRE_NOTHROW(res.setDP(-1));
    }

    SECTION("Chained Setters")
    {
        RNS::Resource res;
        double eps = 0.0000000000001;
        REQUIRE_NOTHROW(res.setName("diamond").setPrice(100.3));
        REQUIRE_NOTHROW(res.setDP(0.7).setDC(0.1));

        REQUIRE(res.getName() == "diamond");
        REQUIRE(abs(res.getPrice() - 100.3) <= eps);
        REQUIRE(abs(res.getDP() - 0.7) <= eps);
        REQUIRE(abs(res.getDC() - 0.1) <= eps);
    }

    SECTION("Adding")
    {
        RNS::Resource r1{"coal", 1.3, 10.5, 13.2};
        RNS::Resource r2{"coal", 1.2, 11.5, 12.8};
        RNS::Resource res, res_op;
        
        REQUIRE_NOTHROW(res = r1 + r2);
        REQUIRE_NOTHROW(res_op = r1);
        REQUIRE_NOTHROW(res_op.add(r1));

        double eps = 0.0000000000001;
        REQUIRE(res.getName() == "coal");
        REQUIRE(abs(res.getPrice() - 1.2) <= eps);
        REQUIRE(abs(res.getDP() - 26.0) <= eps);
        REQUIRE(abs(res.getDC() - 22.0) <= eps);

        REQUIRE(res_op.getName() == "coal");
        REQUIRE(abs(res_op.getPrice() - 1.2) <= eps);
        REQUIRE(abs(res_op.getDP() - 26.4) <= eps);
        REQUIRE(abs(res_op.getDC() - 21.0) <= eps);
    }

    SECTION("Increasing Turnover")
    {
        RNS::Resource r{"coal", 1.2, 11.5, 12.8};
        REQUIRE_NOTHROW(r.incTurnover(10));

        double eps = 0.0000000000001;
        REQUIRE(abs(r.getDP() - 128.0) <= eps);
        REQUIRE(abs(r.getDC() - 115.0) <= eps);
    
        r = r * 1.1;
        REQUIRE(abs(r.getDP() - 128.0 * 1.1) <= eps);
        REQUIRE(abs(r.getDC() - 115.0 * 1.1) <= eps);

        REQUIRE_THROWS(r.incTurnover(-1));
    }

    SECTION("Comparison")
    {
        RNS::Resource r0{"coal", 1.2, 11.5, 12.8};
        RNS::Resource r1{"coal", 1.2, 11.5, 12.8};
        REQUIRE_NOTHROW(r0.compare_equal(r1));
        REQUIRE(r0.compare_equal(r1) == true);
        REQUIRE_NOTHROW(r1.compare_equal(r0));
        REQUIRE(r1.compare_equal(r0) == true);

        REQUIRE_NOTHROW(r0.compare_equal(r0));
        REQUIRE(r0.compare_equal(r0) == true);
        REQUIRE_NOTHROW(r1.compare_equal(r1));
        REQUIRE(r1.compare_equal(r1) == true);

        RNS::Resource r2{"zinc"};
        REQUIRE_NOTHROW(r2.compare_equal(r0));
        REQUIRE(r2.compare_equal(r0) == false);

        REQUIRE_NOTHROW(r2.compare_less(r0));
        REQUIRE(r2.compare_less(r0) == false);
        REQUIRE_NOTHROW(r0.compare_less(r2));
        REQUIRE(r0.compare_less(r2) == true);
    }
}