//
// Created by 김동현 on 2022/07/16.
//

#ifndef GRAPHICS_FRAMEBUFFER_H
#define GRAPHICS_FRAMEBUFFER_H

#include "texture.h"

CLASS_PTR(Framebuffer);
class Framebuffer {
public:
    static FramebufferUPtr Create(const TexturePtr colorAttachment);
    static void BindToDefault();
    ~Framebuffer();

    const uint32_t Get() const { return m_framebuffer; }
    void Bind() const;
    const TexturePtr GetColorAttachment() const { return m_colorAttachment; }

private:
    Framebuffer() {}
    bool InitWithColorAttachment(const TexturePtr colorAttachment);

    uint32_t m_framebuffer { 0 };
    uint32_t m_depthStencilBuffer { 0 };
    TexturePtr m_colorAttachment;
};

#endif //GRAPHICS_FRAMEBUFFER_H
