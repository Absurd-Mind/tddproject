#include <bowling.cpp>
#include <catch2/catch_all.hpp>
#include <vector>

struct TestData {
    int expected;
    std::vector<int> rolls;
    std::string description;
};

TEST_CASE("scoring in bowling") {
    auto testData = GENERATE(
        TestData{0, {0}, "one roll gutter ball"},
        TestData{1, {1}, "one roll one pin"},
        TestData{5, {3, 2}, "two rolls"},
        TestData{10, {5, 5}, "spare without bonus"},
        TestData{16, {5, 5, 3}, "spare with bonus"},
        TestData{20, {5, 5, 3, 4}, "spare with bonus and roll after"},
        TestData{30, {5, 5, 4, 6, 3}, "spare after spare and one roll"},
        TestData{10, {10}, "one strike"},
        TestData{14, {10, 2}, "one strike, one roll"},
        TestData{20, {10, 2, 3}, "one strike, two rolls"},
        TestData{42, {10, 10, 2, 3}, "two strikes, two rolls"},
        TestData{72, {10, 10, 10, 2, 3}, "three strikes, two rolls"},
        TestData{300, {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10}, "perfect game"},
        TestData{133, {1, 4, 4, 5, 6, 4, 5, 5, 10, 0, 1, 7, 3, 6, 4, 10, 2, 8, 6}, "perfect game"},
        TestData{0, {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}, "nearly perfect game"},
        
        TestData{0, {}, "no rolls"}
    );

    SECTION(testData.description) {
        Bowling bowling;
        for (auto pins : testData.rolls) {
            bowling.roll(pins);
        }
        REQUIRE(bowling.score() == testData.expected);
    }
}
