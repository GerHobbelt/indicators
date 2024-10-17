#include <chrono>
#include <indicators/progress_bar.hpp>
#include <sstream>
#include <thread>


#if defined(BUILD_MONOLITHIC)
#define main   indicators_progress_bar_stream_main
#endif

int main(void) {
  using namespace indicators;

  std::stringstream os;

  ProgressBar bar{
      option::BarWidth{50},
      option::Start{"["},
      option::Fill{"="},
      option::Lead{">"},
      option::Remainder{" "},
      option::End{"]"},
      option::PostfixText{"Getting started"},
      option::ForegroundColor{indicators::Color::green},
      option::FontStyles{std::vector<indicators::FontStyle>{indicators::FontStyle::bold}},
      option::Stream{os}};

  // Update bar state
  while (true) {
    bar.tick();
    if (bar.is_completed())
      break;
    std::this_thread::sleep_for(std::chrono::milliseconds(100));
  }

  std::cout << "Stream contents:\n";
  std::cout << os.str() << "\n";

  return 0;
}
