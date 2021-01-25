// Copyright 2021 Slava-100 <svat.strel.2001@gmail.com>

#include <config.hpp>
#include <experiment.hpp>
#include <scheduler.hpp>
#include <vector>

Scheduler::Scheduler(const std::vector<std::size_t> &cacheSizes) {
  bufferSize = cacheSizes.back() * 3 / 2;
  buffer = new char[bufferSize];
  for (auto size = cacheSizes.front() / 2; size < cacheSizes.back(); size *= 2)
    experiments.emplace_back(buffer, size);
  experiments.emplace_back(buffer, bufferSize);

  for (std::size_t i = 0; i < bufferSize; ++i) buffer[i] = std::rand() % 256;
}

Scheduler::~Scheduler() { delete[] buffer; }

std::size_t Scheduler::ExperimentsCount() const { return experiments.size(); }

void Scheduler::WarnUp() {
  [[maybe_unused]] char k = 0;
  for (std::size_t i = 0; i < bufferSize; i += CacheLineSize) {
    k = buffer[i];
  }
}

void Scheduler::RunAll(Experiment::TravelOrder order) {
  expResults.clear();
  for (auto &experiment : experiments) {
    auto duration = experiment.Run(order);
    expResults.push_back(ExperimentResult{duration, experiment.GetBufferSize(),
                                          experiment.GetTravelOrder()});
  }
}

void Scheduler::PrintResult(std::ostream &out) {
  if (expResults.empty()) {
    out << "No experiments results" << std::endl;
    return;
  }

  out << "investigation:" << std::endl;
  out << "  travel_variant: "
      << "\"" << expResults[0].TravelOrder << "\"" << std::endl
      << std::endl;
  out << "  experiments:" << std::endl;
  for (std::size_t i = 0; i < expResults.size(); ++i) {
    out << "  - experiment:" << std::endl;
    out << "    number: " << i + 1 << std::endl;
    out << "    input_data:" << std::endl;
    out << "      buffer_size: "
        << "\"" << expResults[i].BufferSize / 1024 << "Kb\"" << std::endl;
    out << "    results:" << std::endl;
    out << "      duration: "
        << "\"" << expResults[i].Duration << "ns\"" << std::endl
        << std::endl;
  }
}
