#pragma once

#include <chrono>
#include <cstddef>
#include <utility>

namespace Arcade::Shared {
class IGameView {
public:
  virtual ~IGameView() = default;

  virtual int getScore() const = 0;
  virtual void setScore(int score) = 0;

  virtual std::chrono::milliseconds getPartyDuration() const = 0;
  virtual void setPartyDuration(std::chrono::milliseconds duration) = 0;

  virtual std::pair<std::size_t, std::size_t> getMapSize() const = 0;
  virtual void setMapSize(std::size_t width, std::size_t height) = 0;
};
} // namespace Arcade::Shared
