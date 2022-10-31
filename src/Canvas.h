#ifndef RT_CANVAS_H
#define RT_CANVAS_H
#include <string>
#include "color.h"
/**
 * @brief canvas object, height and width are 0 indexed i.e. (0 - width-1) 
 * 
 */
class Canvas{
    private:
    int width_, height_;
    Color* data_;
    public:
    Canvas(int width, int height);
    ~Canvas() = default;

    void WritePixel(Color c, int x, int y) const;
    Color PixelAt(int x, int y) const;
    int Width() const { return width_; };
    int Height() const { return height_; };
    std::string CanvasAsPPM() const;
};

#endif //RT_CANVAS_H