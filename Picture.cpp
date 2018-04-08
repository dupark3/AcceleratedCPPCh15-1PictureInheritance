#include <algorithm> 
#include <iostream>
#include <string>
#include <vector>

#include "Picture.h"

Picture::Picture(const std::vector<std::string>& v) : p(new String_pic(v)) { }

Pic_base::width_size String_Pic::width() const{
    Pic_base::width_size maxLen = 0;
    for (Pic_base::height_size i = 0; i != data.size(); ++i)
        maxLen = std::max(maxLen, data[i].size());
    return maxLen;
}

void String_Pic::display(std::ostream& os, height_size row, bool do_pad) const{
    width_size start = 0;

    // write the row if we're still in range
    if (row < height()){
        os << data[row];
        start = data[row].size();
    }

    if (do_pad)
        pad(os, start, width());
}

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