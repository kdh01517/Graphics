//
// Created by 김동현 on 2022/07/17.
//

#ifndef GRAPHICS_SHADOW_MAP_H
#define GRAPHICS_SHADOW_MAP_H

#include "texture.h"

CLASS_PTR(ShadowMap);
class ShadowMap {
public:
    static ShadowMapUPtr Create(int width, int height);
    ~ShadowMap();

    const uint32_t Get() const { return m_framebuffer; }
    void Bind() const;
    const TexturePtr GetShadowMap() const { return m_shadowMap; }

private:
    ShadowMap() {}
    bool Init(int width, int height);

    uint32_t m_framebuffer { 0 };
    TexturePtr m_shadowMap;
};

#endif //GRAPHICS_SHADOW_MAP_H