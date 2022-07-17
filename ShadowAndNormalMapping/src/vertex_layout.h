//
// Created by 김동현 on 2022/07/13.
//

#ifndef GRAPHICS_VERTEX_LAYOUT_H
#define GRAPHICS_VERTEX_LAYOUT_H

#include "common.h"

CLASS_PTR(VertexLayout)
class VertexLayout {
public:
    static VertexLayoutUPtr Create();
    ~VertexLayout();

    uint32_t Get() const { return m_vertexArrayObject; }
    void Bind() const;
    void SetAttrib(
            uint32_t attribIndex, int count,
            uint32_t type, bool normalized,
            size_t stride, uint64_t offset) const;
    void DisableAttrib(int attribIndex) const;

private:
    VertexLayout() {}
    void Init();
    uint32_t m_vertexArrayObject { 0 };
};

#endif //GRAPHICS_VERTEX_LAYOUT_H
