#include "Canvas.h"
#include <stdlib.h> 

Canvas::Canvas(int w, int h){
    width_ = w;
    height_ = h;
    data_ = (Color*)calloc(w * h, sizeof(Color));
}

void Canvas::WritePixel(Color color, int xCoord, int yCoord) const {
    if (xCoord < 0 || yCoord < 0 || xCoord >= width_ || yCoord>= height_){
        return;
    }
    data_[xCoord + (width_ * yCoord)] = color;
}

// doesn't check that the coordinates are in bound
Color Canvas::PixelAt(int xCoord, int yCoord) const {
    return data_[xCoord + (width_ * yCoord)];
}

std::string Canvas::CanvasAsPPM() const {
    // std::ostringstream;
    // os << "P3" << std::endl << m_width << " " << m_height << std::endl
    //    << "255" << std::endl;
}