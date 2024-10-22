#include <CppUTest/TestHarness.h>
#include <memory>
#include "LM35IC.h"

using LM35::LM35IC;
using LM35::sensors;

TEST_GROUP(testErrorMethods){

    std::shared_ptr<LM35IC> lm35d;
    std::shared_ptr<LM35IC> lm35;
    std::shared_ptr<LM35IC> lm35a;
    std::shared_ptr<LM35IC> lm35ca;
    std::shared_ptr<LM35IC> lm35c;

    void setup(){

        lm35d = std::make_shared<LM35IC>(1);
        lm35 = std::make_shared<LM35IC>(1, sensors::LM35);
        lm35a = std::make_shared<LM35IC>(1, sensors::LM35A);
        lm35ca = std::make_shared<LM35IC>(1, sensors::LM35CA);
        lm35c = std::make_shared<LM35IC>(1, sensors::LM35C);

    }

    void teardown(){

    }

};

TEST(testErrorMethods, testResolution){

    std::unique_ptr<LM35IC> lm35d_full_range = std::make_unique<LM35IC>(1, sensors::LM35D, 5.0);
    std::unique_ptr<LM35IC> lm35d_high_res = std::make_unique<LM35IC>(1, sensors::LM35D, 1.0, 0.0, 5.0, 12);
    std::unique_ptr<LM35IC> lm35d_low_voltage = std::make_unique<LM35IC>(1, sensors::LM35D, 1.0, 0.0, 3.3);
    std::unique_ptr<LM35IC> lm35_full_range = std::make_unique<LM35IC>(1, sensors::LM35, 5.0/2.05);
    std::unique_ptr<LM35IC> lm35_high_res = std::make_unique<LM35IC>(1, sensors::LM35, 1.0, 0.0, 5.0, 12);
    std::unique_ptr<LM35IC> lm35_low_voltage = std::make_unique<LM35IC>(1, sensors::LM35, 1.0, 0.0, 3.3);
    std::unique_ptr<LM35IC> lm35a_full_range = std::make_unique<LM35IC>(1, sensors::LM35A, 5.0/2.05);
    std::unique_ptr<LM35IC> lm35ca_full_range = std::make_unique<LM35IC>(1, sensors::LM35CA, 5.0/1.5);
    std::unique_ptr<LM35IC> lm35ca_high_res = std::make_unique<LM35IC>(1, sensors::LM35CA, 1.0, 0.0, 5.0, 12);
    std::unique_ptr<LM35IC> lm35ca_low_voltage = std::make_unique<LM35IC>(1, sensors::LM35CA, 1.0, 0.0, 3.3);
    std::unique_ptr<LM35IC> lm35c_full_range = std::make_unique<LM35IC>(1, sensors::LM35C, 5.0/1.5);

    double threshold = 0.001;

    DOUBLES_EQUAL(0.490, lm35d->getResolution(), threshold);
    DOUBLES_EQUAL(0.098, lm35d_full_range->getResolution(), threshold);
    DOUBLES_EQUAL(0.122, lm35d_high_res->getResolution(), threshold);
    DOUBLES_EQUAL(0.323, lm35d_low_voltage->getResolution(), threshold);

    //DOUBLES_EQUAL(0.489, lm35->getResolution(), threshold);
    DOUBLES_EQUAL(0.200, lm35_full_range->getResolution(), threshold);
    DOUBLES_EQUAL(0.122, lm35_high_res->getResolution(), threshold);
    DOUBLES_EQUAL(0.322, lm35_low_voltage->getResolution(), threshold);

    DOUBLES_EQUAL(0.489, lm35a->getResolution(), threshold);

    DOUBLES_EQUAL(0.489, lm35ca->getResolution(), threshold);
    DOUBLES_EQUAL(0.146, lm35ca_full_range->getResolution(), threshold);
    DOUBLES_EQUAL(0.122, lm35ca_high_res->getResolution(), threshold);
    DOUBLES_EQUAL(0.323, lm35ca_low_voltage->getResolution(), threshold);

    DOUBLES_EQUAL(0.489, lm35c->getResolution(), threshold);

};

TEST(testErrorMethods, testAccuracy){



};

TEST(testErrorMethods, testError){



};