#ifndef RT_CANVAS_H
#define RT_CANVAS_H

#include "color.h"
/**
 * @brief canvas object, height and width are 0 indexed i.e. (0 - width-1) 
 * 
 */
class Canvas{
    private:
    int width_, height_;
    public:
    Canvas(int width, int height);
    ~Canvas() = default;

    void WritePixel(Color c, int x, int y);
    Color PixelAt(int x, int y);
    int Width() { return width_; };
    int Height() { return height_; };
};
#endif //RT_CANVAS_H