#include "LibraryLoader.hpp"
#include "Exceptions.hpp"

#include <dlfcn.h>
#include <utility>

namespace Arcade::Core {

LibraryLoader::~LibraryLoader() {
  try {
    closeLibrary();
  } catch (...) {
  }
}

LibraryLoader::LibraryLoader(LibraryLoader &&other) noexcept
    : m_handle(std::exchange(other.m_handle, nullptr)) {}

LibraryLoader &LibraryLoader::operator=(LibraryLoader &&other) noexcept {
  if (this != &other) {
    try {
      closeLibrary();
    } catch (...) {
    }

    m_handle = std::exchange(other.m_handle, nullptr);
  }
  return *this;
}

void LibraryLoader::loadLibrary(std::string_view path) {
  closeLibrary();

  m_handle = dlopen(path.data(), RTLD_LAZY);

  const char *error = dlerror();

  if (!m_handle) {
    throw Exceptions::LibraryLoaderException(
        error ? error : "Unknown error loading library");
  }
}

void LibraryLoader::closeLibrary() {
  if (m_handle != nullptr) {
    int result = dlclose(m_handle);

    const char *error = dlerror();

    m_handle = nullptr;

    if (result != 0 || error != nullptr) {
      throw Exceptions::LibraryLoaderException(
          error ? error : "Unknown error closing library");
    }
  }
}

void *LibraryLoader::getSymbol(std::string_view symbol) {
  if (!m_handle) {
    throw Exceptions::LibraryLoaderException(
        "Cannot get symbol: No library loaded");
  }

  void *sym = dlsym(m_handle, symbol.data());

  const char *error = dlerror();

  if (error) {
    throw Exceptions::LibraryLoaderException(error);
  }

  if (sym == nullptr) {
    throw Exceptions::LibraryLoaderException(
        std::string("Symbol not found: ").append(symbol));
  }

  return sym;
}
} // namespace Arcade::Core
