#pragma once

#include <cstddef>
#include <filesystem>
#include <string>
#include <utility>
#include "../Resource/ResourceIdentifier.hpp"

namespace Arcade::Shared::Scene {

class IDrawable {
public:
  virtual ~IDrawable() = default;
  virtual void setPosition(float x, float y) = 0;
  virtual std::pair<float, float> getPosition() const = 0;
  virtual Resource::ResourceIdentifier getResourceId() const = 0;
};

class Drawable : public IDrawable {
public:
  Drawable();
  virtual ~Drawable() = default;

  Drawable(const Drawable &) = delete;
  Drawable &operator=(const Drawable &) = delete;

  Drawable(Drawable &&other) noexcept;
  Drawable &operator=(Drawable &&other) noexcept;

  void setPosition(float x, float y) override;
  std::pair<float, float> getPosition() const override;

protected:
  std::pair<float, float> m_position;
};

class GameText final : public Drawable {
public:
  GameText();
  ~GameText();

  void setText(const std::string &text);
  const std::string &getText() const;

  void setFontSize(std::size_t fontSize);
  std::size_t getFontSize() const;

  Resource::ResourceIdentifier getResourceId() const override;

private:
  std::string m_text;
  std::size_t m_fontSize = 12;
  static const Resource::ResourceIdentifier TEXT_RESOURCE;
};

class GameSprite final : public Drawable {
public:
  GameSprite();
  explicit GameSprite(Resource::ResourceType type,
                      const std::string &state = "default");
  ~GameSprite() override = default;

  void setResourceType(Resource::ResourceType type);
  Resource::ResourceType getResourceType() const;

  void setState(const std::string &state);
  const std::string &getState() const;

  Resource::ResourceIdentifier getResourceId() const override;

private:
  Resource::ResourceType m_resourceType;
  std::string m_state;
};

} // namespace Arcade::Shared::Scene
