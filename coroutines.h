#pragma once
#include "number_generator.h"
#include <memory>
#include <queue>

NumberGenerator random_numbers(std::shared_ptr<std::queue<int>> numbers);