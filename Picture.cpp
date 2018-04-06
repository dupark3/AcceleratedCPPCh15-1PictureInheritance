#include <algorithm> 
#include <iostream>
#include <string>
#include <vector>

#include "Picture.h"

Picture::Picture(const std::vector<std::string>& v) : p(new String_pic(v)) { }

Picture frame(const Picture& pic){
    return new Frame_Pic(pic.p);
}

Picture hcat(const Picture& pictureLeft, const Picture& pictureRight){
    return new HCat_Pic(pictureRight.p, pictureLeft.p);
}

Picture vcat(const Picture& pictureTop, const Picture& pictureBottom){
    return new VCat_Pic(pictureTop.p, pictureBottom.p);
}

std::ostream& operator<<(std::ostream& os, const Picture& picture){
    const Pic_base::height_size height = picture.p->height();
    for (Pic.base::height_size i = 0; i != height; ++i){
        picture.p->display(os, i, false);
        os << std::endl;
    }
    return os;
}