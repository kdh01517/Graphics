//
// Created by 김동현 on 2022/07/13.
//

#ifndef GRAPHICS_BUFFER_H
#define GRAPHICS_BUFFER_H

#include "common.h"

CLASS_PTR(Buffer)
class Buffer {
public:
    static BufferUPtr CreateWithData(uint32_t bufferType, uint32_t usage,
                                     const void* data, size_t stride, size_t count);
    ~Buffer();
    uint32_t Get() const { return m_buffer; }
    size_t GetStride() const { return m_stride; }
    size_t GetCount() const { return m_count; }
    void Bind() const;

private:
    Buffer() {}
    bool Init(uint32_t bufferType, uint32_t usage,
              const void* data, size_t stride, size_t count);
    uint32_t m_buffer { 0 };
    uint32_t m_bufferType { 0 };
    uint32_t m_usage { 0 };
    size_t m_stride { 0 };
    size_t m_count { 0 };
};

#endif //GRAPHICS_BUFFER_H
