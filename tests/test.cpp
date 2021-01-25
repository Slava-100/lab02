// Copyright 2021 Your Name <your_email>

#include <gtest/gtest.h>

#include <config.hpp>
#include <experiment.hpp>
#include <iostream>
#include <scheduler.hpp>

TEST(Example, EmptyTest) {
  Scheduler scheduler(CacheSizes);

  scheduler.WarnUp();
  scheduler.RunAll(Experiment::TravelOrder::Direct);
  scheduler.PrintResult(std::cout);

  std::cout << std::endl;

  scheduler.WarnUp();
  scheduler.RunAll(Experiment::TravelOrder::Reverse);
  scheduler.PrintResult(std::cout);

  std::cout << std::endl;

  scheduler.WarnUp();
  scheduler.RunAll(Experiment::TravelOrder::Random);
  scheduler.PrintResult(std::cout);
  EXPECT_TRUE(true);
}
