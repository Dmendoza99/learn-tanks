#pragma once
#include <Components.hpp>
#include <ECS.hpp>
#include <Engine.hpp>

namespace Skeleton {
class drawGraphicSystem : public System {
public:
  gameDataRef data;
  drawGraphicSystem(gameDataRef data) { this->data = data; }
  void update(float time) override {
    // Get the entity manager using entities() function
    for (auto entity : entities().with<GraphicComponent>()) {
      entity.get<GraphicComponent>().update(time);
      this->data->window.draw(entity.get<GraphicComponent>().sprite);
    }
  }
};

} // namespace Skeleton