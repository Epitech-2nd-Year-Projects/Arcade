#pragma once

#include <SDL2/SDL.h>

#include "ResourceManager.hpp"
#include "../../Shared/IDisplay.hpp"

namespace Arcade::Graphics {
class SDL2 : public Shared::IDisplay {
public:
  SDL2();
  ~SDL2() override;

  void display(Shared::GameView &gameView) override;
  Shared::GameEvent getGameEvent() override;

private:
  void renderDrawable(const Shared::Scene::IDrawable &drawable);

  SDL_Window *m_window;
  SDL_Renderer *m_renderer;
  std::unique_ptr<ResourceManager> m_resourceManager;
};
}

