#pragma once

namespace Arcade::Shared {
class IDisplay {
public:
  virtual ~IDisplay() = default;

  virtual void display() = 0;
};
} // namespace Arcade::Shared
