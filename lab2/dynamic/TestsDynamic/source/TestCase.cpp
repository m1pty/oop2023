#define CATCH_CONFIG_MAIN
#include <catch2/catch_test_macros.hpp>
#include <ResourceDynamic/Resource.h>
#include <HandlersDynamic/Handlers.h>
#include <sstream>

TEST_CASE("Resource Constructors + Getters")
{
    SECTION("Default Constructor")
    {
        RNS::Resource r;
        REQUIRE(r.getName() == "Empty");
        REQUIRE(r.getDC() == 0.0);
        REQUIRE(r.getDP() == 0.0);
        REQUIRE(r.getPrice() == 0.0);
    }

    SECTION("Initializing Constructor")
    {
        RNS::Resource r("coal", 7.8, 10.5, 13.2);
        REQUIRE(r.getName() == "coal");
        REQUIRE(r.getDC() == 10.5);
        REQUIRE(r.getDP() == 13.2);
        REQUIRE(r.getPrice() == 7.8);
    }

    SECTION("Partly Initialized Constructor")
    {
        RNS::Resource r{"gold", 8.9};
        REQUIRE(r.getName() == "gold");
        REQUIRE(r.getPrice() == 8.9);
        REQUIRE(r.getDC() == 0.0);
        REQUIRE(r.getDP() == 0.0);

    }
}

TEST_CASE("Setters")
{
    SECTION("Name Setter")
    {
        RNS::Resource r;
        r.setName("gold");
        REQUIRE(r.getName() == "gold");
    }
    SECTION("DC Setter NoExcept")
    {
        RNS::Resource r;
        r.setDC(13.5);
        REQUIRE(r.getDC() == 13.5); 
    }
    SECTION("DC Setter Except")
    {
        RNS::Resource r;
        REQUIRE_THROWS(r.setDC(-10.5));
    }
    SECTION("DP Setter NoExcept")
    {
        RNS::Resource r;
        r.setDP(13.5);
        REQUIRE(r.getDP() == 13.5); 
    }
    SECTION("DP Setter Except")
    {
        RNS::Resource r;
        REQUIRE_THROWS(r.setDC(-10.5));
    }
    SECTION("Price Setter NoExcept")
    {
        RNS::Resource r;
        r.setDC(13.5);
        REQUIRE(r.getDC() == 13.5); 
    }
    SECTION("Price Setter Except")
    {
        RNS::Resource r;
        REQUIRE_THROWS(r.setDC(-10.5));
    }

    SECTION("Chain Setters")
    {
        RNS::Resource r;
        REQUIRE_NOTHROW(r.setName("Hi!"));
        REQUIRE_THROWS(r.setDC(-13.2));
        REQUIRE_NOTHROW(r.setDP(10.2).setPrice(13.9));
        REQUIRE(r.getName() == "Hi!");
        REQUIRE(r.getDC() == 0.0);
        REQUIRE(r.getDP() == 10.2);
        REQUIRE(r.getPrice() == 13.9);
    }
}

TEST_CASE("Other Methods")
{
    SECTION("Print Method")
    {
        RNS::Resource r{"coal", 8.3, 13.5, 12};
        std::stringstream ss;
        r.print(ss);
        REQUIRE(ss.str() == "coal | 13.5 | 12 | 8.3\n");
    }

    SECTION("Add Method NoExcept")
    {
        RNS::Resource r1{"coal", 7.2, 10.2, 12.5},
                      r2{"coal", 4.3,  4.7,  2.5};
        RNS::Resource &link = r2;
        RNS::Resource r = r1.add(link);
        double eps = 0.000001;
        REQUIRE(r.getName() == "coal");
        REQUIRE(std::abs(r.getDC() - 14.9) < eps);
        REQUIRE(std::abs(r.getDP() - 15.0) < eps);
        REQUIRE(std::abs(r.getPrice() - 4.3) < eps);
    }

    SECTION("Equality Method")
    {
        RNS::Resource r1{"coal", 0.7, 10.0, 13.3}, r2{"coal", 0.7, 10.0, 13.3};
        RNS::Resource &link1 = r1, &link2 = r2;
        REQUIRE(link1.compare_equal(link2) == true);
        REQUIRE(link2.compare_equal(link1) == true);
        RNS::Resource r{"c0al", 0.7, 10.0, 13.3};
        RNS::Resource &link = r;
        REQUIRE(link1.compare_equal(link) == false);
        REQUIRE(link.compare_equal(link1) == false);
    }

    SECTION("Less Method")
    {
        RNS::Resource r1{"coal", 0.7, 10.0, 13.3}, r2{"coal", 0.7, 10.0, 13.3};
        RNS::Resource &link1 = r1, &link2 = r2;
        REQUIRE(link1.compare_less(link2) == false);
        REQUIRE(link2.compare_less(link1) == false);
        RNS::Resource r{"c0al", 0.7, 10.0, 13.3};
        RNS::Resource &link = r;
        REQUIRE(link1.compare_less(link) == false);
        REQUIRE(link.compare_less(link1) == true);
    }

    SECTION("Increasing Turnover Method NoExcept")
    {
        RNS::Resource r;
        double eps = 0.000001;
        REQUIRE_NOTHROW(r.setDC(9));
        REQUIRE_NOTHROW(r.setDP(7));
        REQUIRE_NOTHROW(r.incTurnover(0.6));
        REQUIRE(std::abs(r.getDC() - 5.4) < eps);
        REQUIRE(std::abs(r.getDP() - 4.2) < eps);
    }

    SECTION("Increasing Turnover Method Except")
    {
        RNS::Resource r;
        double eps = 0.000001;
        REQUIRE_NOTHROW(r.setDC(10));
        REQUIRE_NOTHROW(r.setDP(7));
        REQUIRE_THROWS(r.incTurnover(-15));
        REQUIRE(std::abs(r.getDC() - 10.0) < eps);
        REQUIRE(std::abs(r.getDP() -  7.0) < eps);
    }
}