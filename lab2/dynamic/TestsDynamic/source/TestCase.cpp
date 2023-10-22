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

        t.print(std::cin);
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
        RNS::Resource r2{"gold", 1.3, 23.9, 24.8};
        RNS::Resource r3{"coal", 1.5, 12.3, 10.9};
        t += r1; t += r1; t += r3;

        REQUIRE_NOTHROW(t.searchResult("diamond"));
        REQUIRE_NOTHROW(t.searchResult("coal"));
        TNS::Table search = t.searchResult("coal");

        search.print(std::cout);

        REQUIRE(search.getCSize() == 2);
        double eps = 0.0000000000001;

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
        t += r1; t += r1; t += r3;

        double eps = 0.0000000000001;
        RNS::Resource& found = t["coal"];
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

    // SECTION("Moving")
    // {
    //     TNS::Table t;
    //     RNS::Resource r1{"coal", 0.7, 10.0, 13.3};
    //     RNS::Resource r2{"gold", 1.3, 23.9, 24.8};
    //     RNS::Resource r3{"coal", 1.5, 12.3, 10.9};
    //     REQUIRE_NOTHROW(t.add(r1));
    //     REQUIRE_NOTHROW(t.add(r2));
    //     REQUIRE_NOTHROW(t.add(r3));

    //     TNS::Table moved;
    //     moved = t;
    // }
}