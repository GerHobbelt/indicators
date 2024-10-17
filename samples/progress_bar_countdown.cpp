#include <chrono>
#include <indicators/progress_bar.hpp>
#include <thread>
using namespace indicators;


#if defined(BUILD_MONOLITHIC)
#define main   indicators_progress_bar_countdown_main
#endif

int main(void) {

  ProgressBar bar{option::BarWidth{50},
                  option::ProgressType{ProgressType::decremental},
                  option::Start{"["},
                  option::Fill{"■"},
                  option::Lead{"■"},
                  option::Remainder{"-"},
                  option::End{"]"},
                  option::PostfixText{"Reverting System Restore"},
                  option::ForegroundColor{Color::yellow},
                  option::FontStyles{std::vector<FontStyle>{FontStyle::bold}}};

  // Update bar state
  while (true) {
    bar.tick();
    if (bar.is_completed())
      break;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  std::cout << termcolor::bold << termcolor::white << "Task Failed Successfully\n"
            << termcolor::reset;

  return 0;
}
