#include <algorithm> // max in width()
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
    
    return os;
}

size_t width(const Picture& picture){
    size_t maxLen = 0;
    for (size_t i = 0; i != vec.size(); ++i){
        maxLen = std::max(maxLen, vec[i].size());    
    }
    return widthSize;
}