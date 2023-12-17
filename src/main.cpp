#include "generation.h"
#include <thread>

int main() {
  Generation current_generation;
  current_generation.populateRandomly();

  while (true) {
    current_generation.display();
    std::this_thread::sleep_for(
        std::chrono::milliseconds(constants::generation_age));
    Generation next_generation;
    calculateNextGeneration(current_generation, next_generation);
    current_generation.updateToNextGeneration(next_generation);
  }
}
