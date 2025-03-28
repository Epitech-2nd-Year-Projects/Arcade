#pragma once

#include <cstddef>
#include <filesystem>
#include <string>
#include <utility>
#include "../Resource/ResourceIdentifier.hpp"

namespace Arcade::Shared::Scene {

template <typename T>
concept Positionable = requires(T t, float x, float y) {
  { t.setPosition(x, y) } -> std::same_as<void>;
  { t.getPosition() } -> std::convertible_to<std::pair<float, float>>;
};

class IDrawable {
public:
  virtual ~IDrawable() = default;

  virtual void setPosition(float x, float y) noexcept = 0;
  [[nodiscard]] virtual std::pair<float, float>
  getPosition() const noexcept = 0;
  virtual Resource::ResourceIdentifier getResourceId() const = 0;
};

class Drawable : public IDrawable {
public:
  Drawable() = default;
  ~Drawable() override = default;

  Drawable(const Drawable &) = delete;
  Drawable &operator=(const Drawable &) = delete;

  Drawable(Drawable &&other) noexcept;
  Drawable &operator=(Drawable &&other) noexcept;

  void setPosition(float x, float y) noexcept override;
  [[nodiscard]] std::pair<float, float> getPosition() const noexcept override;

protected:
  std::pair<float, float> m_position{0.0f, 0.0f};
};

class GameText final : public Drawable {
public:
  GameText();
  ~GameText();

  void setText(std::string_view text);
  [[nodiscard]] std::string_view getText() const noexcept;

  void setFontSize(std::size_t fontSize) noexcept;
  [[nodiscard]] std::size_t getFontSize() const noexcept;

  Resource::ResourceIdentifier getResourceId() const override;

private:
  std::string m_text;
  std::size_t m_fontSize = 12;
  static const Resource::ResourceIdentifier TEXT_RESOURCE;
};

class GameSprite final : public Drawable {
<<<<<<< HEAD
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

template <typename T, typename... Args>
  requires std::is_base_of_v<Drawable, T>
[[nodiscard]] std::unique_ptr<T> createDrawable(Args &&...args) {
  return std::make_unique<T>(std::forward<Args>(args)...);
}

} // namespace Arcade::Shared::Scene
