#pragma once
#include <filesystem>
#include <map>
#include <string>
#include <SDL2/SDL.h>

#include "Shared/ResourceIdentifier.hpp"

namespace Arcade::Graphics {
class ResourceManager {
public:
  ResourceManager(SDL_Renderer *renderer);
  ~ResourceManager();

  SDL_Texture *getTexture(const Shared::ResourceIdentifier &id);

private:
  SDL_Texture *loadTexture(const std::filesystem::path &path);

  SDL_Renderer *m_renderer;
  std::map<std::string, SDL_Texture *> m_textures;
};
}
