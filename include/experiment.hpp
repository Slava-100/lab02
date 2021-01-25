// Copyright 2021 Slava-100 <svat.strel.2001@gmail.com>

#ifndef INCLUDE_EXPERIMENT_HPP_
#define INCLUDE_EXPERIMENT_HPP_
#include <string>

class Experiment {
 public:
  enum TravelOrder { Direct, Reverse, Random };
  const std::string TravelOrders[3] = {"direct", "reverse", "random"};

  Experiment(char *buffer, std::size_t bufferSize);
  ~Experiment() = default;

  std::size_t Run(TravelOrder order);
  std::string GetTravelOrder() const;
  std::size_t GetBufferSize() const;

 private:
  char *buffer;
  std::size_t bufferSize;
  std::string travelOrderName;
};

#endif  // INCLUDE_EXPERIMENT_HPP_
