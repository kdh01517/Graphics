//
// Created by 동현 on 2022/07/12.
//

#ifndef GRAPHICS_SHADER_H
#define GRAPHICS_SHADER_H

#include "common.h"

CLASS_PTR(Shader);
class Shader {
public:
    static ShaderUPtr CreateFromFile(const std::string& filename,
                                     GLenum shaderType);

    ~Shader();
    uint32_t Get() const { return m_shader; }
private:
    Shader() {}
    bool LoadFile(const std::string& filename, GLenum shaderType);
    uint32_t m_shader { 0 };
};

#endif //GRAPHICS_SHADER_H
