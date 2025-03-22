#pragma once

#include <string_view>

namespace Arcade::Core {

class LibraryLoader {
public:
  LibraryLoader() = default;
  ~LibraryLoader();

  LibraryLoader(const LibraryLoader &) = delete;
  LibraryLoader &operator=(const LibraryLoader &) = delete;

  LibraryLoader(LibraryLoader &&other) noexcept;
  LibraryLoader &operator=(LibraryLoader &&other) noexcept;

  void loadLibrary(std::string_view path);
  void closeLibrary();
  void *getSymbol(std::string_view symbol);

private:
  void *m_handle = nullptr;
};
} // namespace Arcade::Core
