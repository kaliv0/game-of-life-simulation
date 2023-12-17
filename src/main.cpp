#include "Generation.h"
#include <thread>

int main() {
  Generation current_generation;
  current_generation.populate_randomly();

  while (true) {
    current_generation.display();
    std::this_thread::sleep_for(std::chrono::milliseconds(GENERATION_AGE));
    Generation next_generation;
    calculate_next_generation(current_generation, next_generation);
    current_generation.update_to_next_generation(next_generation);
  }
}
