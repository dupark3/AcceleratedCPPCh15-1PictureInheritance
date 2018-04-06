#include <string>
#include <vector>

#include "Ptr.h"

class Pic_base{

};

class String_Pic : public Pic_base {

};
class Frame_Pic: public Pic_base{

};
class VCat_Pic: public Pic_base{

};
class HCat_Pic: public Pic_base{

};

// public interface Picture class
class Picture{
public:
    Picture(const std::vector<std::string>& = std::vector<std::string>());
private:
    Ptr<Pic_base> p;
};
