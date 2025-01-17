#ifndef RTIAW_hittableobject
#define RTIAW_hittableobject

#include <memory>
#include <optional>
#include <variant>

#include "Materials/Materials.h"
#include "Ray.h"
#include "Shapes/Shapes.h"

namespace RTIAW::Render {
using HitResult = std::pair<std::optional<HitRecord>, std::optional<ScatteringRecord>>;
class HittableObject {

public:
  HittableObject(Shape shape, Material material) : m_shape{shape}, m_material{material} {}
  virtual ~HittableObject() = default;

  [[nodiscard]] HitResult Hit(const Ray &r, float t_min, float t_max) const;

private:
  Shape m_shape;
  Material m_material;

  [[nodiscard]] std::optional<ScatteringRecord> Scatter(const Ray &r_in, const HitRecord &rec) const;
};
} // namespace RTIAW::Render

#endif
