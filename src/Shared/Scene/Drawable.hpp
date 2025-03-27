#pragma once

#include <cstddef>
#include <filesystem>
#include <string>

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
  void setText(std::string_view text);
  [[nodiscard]] std::string_view getText() const noexcept;

  void setFontSize(std::size_t fontSize) noexcept;
  [[nodiscard]] std::size_t getFontSize() const noexcept;

private:
  std::string m_text;
  std::size_t m_fontSize = 12;
};

class GameSprite final : public Drawable {
  enum class SpriteType { Player, Enemy, Wall, Floor };

public:
  void setType(SpriteType type) noexcept;
  [[nodiscard]] SpriteType getType() const noexcept;

  void setTexturePath(const std::filesystem::path &path);
  [[nodiscard]] const std::filesystem::path &getTexturePath() const noexcept;

private:
  std::filesystem::path m_texturePath;
  SpriteType m_type;
};

template <typename T, typename... Args>
  requires std::is_base_of_v<Drawable, T>
[[nodiscard]] std::unique_ptr<T> createDrawable(Args &&...args) {
  return std::make_unique<T>(std::forward<Args>(args)...);
}

} // namespace Arcade::Shared::Scene
