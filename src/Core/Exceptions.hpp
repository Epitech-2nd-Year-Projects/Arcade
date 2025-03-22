#pragma once

#include <exception>
#include <string>

namespace Arcade::Core::Exceptions {
class Exception : public std::exception {
public:
  explicit Exception(std::string message) : m_message(std::move(message)) {}

  [[nodiscard]] const char *what() const noexcept override {
    return m_message.c_str();
  }

private:
  std::string m_message;
};

class LibraryLoaderException : public Exception {
public:
  explicit LibraryLoaderException(std::string message)
      : Exception(std::move(message)) {}
};

class DisplayException : public Exception {
public:
  explicit DisplayException(std::string message)
      : Exception(std::move(message)) {}
};

class GameException : public Exception {
public:
  explicit GameException(std::string message) : Exception(std::move(message)) {}
};
} // namespace Arcade::Core::Exceptions
