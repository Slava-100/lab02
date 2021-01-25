// Copyright 2021 Your Name <your_email>

#ifndef INCLUDE_CONFIG_HPP_
#define INCLUDE_CONFIG_HPP_

#include <vector>

const std::size_t IterationsCount = 1000;
const std::size_t CacheLineSize = 64;
const std::vector<std::size_t> CacheSizes = {64 * 1024, 512 * 1024,
                                             4 * 1024 * 1024};

#endif  // INCLUDE_CONFIG_HPP_
