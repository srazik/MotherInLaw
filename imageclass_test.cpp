#include "imageclass.h"
#include <catch.hpp>
#include "mathcalculate.h"

TEST_CASE("ImageMap_ok") {
    auto newName = ImageMap::createOutFilename("example_name.jpg");
    REQUIRE(newName == "example_name_target.jpg");
}

TEST_CASE("ImageMap_dot_in_filename") {
    auto newName = ImageMap::createOutFilename("Jebac.PiS.example_name.jpg");
    REQUIRE(newName == "Jebac.PiS.example_name_target.jpg");
}

TEST_CASE("ImageMap_no_dots") {
    auto newName = ImageMap::createOutFilename("JebacPiSexample_namejpg");
    REQUIRE(newName == "JebacPiSexample_namejpg_target");
}

TEST_CASE("Checking_px_to_mm_OK") {
    auto checkedValue = pxToMm(200);
    REQUIRE(checkedValue == 53);
}

TEST_CASE("Checking_convertion_Less_0") {
    auto checkedValue = pxToMm(-200);
    REQUIRE(checkedValue == 0);
}

TEST_CASE("Checking_mm_px_OK") {
    auto checkedValue = mmToPx(200);
    REQUIRE(checkedValue == 756);
}

TEST_CASE("Checking_mm_px_Less_0") {
    auto checkedValue = mmToPx(-200);
    REQUIRE(checkedValue == 0);
}

TEST_CASE("Checking_mm_px_0") {
    auto checkedValue = mmToPx(0);
    REQUIRE(checkedValue == 0);
}