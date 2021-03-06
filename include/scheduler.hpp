// Copyright 2021 Slava-100 <svat.strel.2001@gmail.com>

#ifndef INCLUDE_SCHEDULER_HPP_
#define INCLUDE_SCHEDULER_HPP_

#include <experiment.hpp>
#include <ostream>
#include <vector>

struct ExperimentResult {
  std::size_t Duration;
  std::size_t BufferSize;
  std::string TravelOrder;
};

class Scheduler {
 public:
  explicit Scheduler(const std::vector<std::size_t> &cacheSizes);
  ~Scheduler();

  std::size_t ExperimentsCount() const;
  void WarnUp();
  void RunAll(Experiment::TravelOrder order);

  void PrintResult(std::ostream &out);

 private:
  char *buffer;
  std::size_t bufferSize;
  std::vector<Experiment> experiments;
  std::vector<ExperimentResult> expResults;
};
#endif  // INCLUDE_SCHEDULER_HPP_
