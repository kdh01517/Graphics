//
// Created by 동현 on 2022/07/12.
//

#ifndef GRAPHICS_COMMON_H
#define GRAPHICS_COMMON_H

#include <memory>
#include <string>
#include <optional>
#include "glad.h"
#include "GLFW/glfw3.h"
#include "spdlog/spdlog.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#define CLASS_PTR(klassName) \
class klassName; \
using klassName ## UPtr = std::unique_ptr<klassName>; \
using klassName ## Ptr = std::shared_ptr<klassName>; \
using klassName ## WPtr = std::weak_ptr<klassName>;

std::optional<std::string> LoadTextFile(const std::string& filename);
glm::vec3 GetAttenuationCoeff(float distance);

#endif //GRAPHICS_COMMON_H
