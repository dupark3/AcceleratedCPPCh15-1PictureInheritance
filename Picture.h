#include <iostream> 
#include <memory> // shared_ptr
#include <string>
#include <vector>

#include "Ptr.h"

// Private Implementation abstract base class and concrete derived classes
class Pic_base{
    friend std::ostream& operator<<(std::ostream&, const Picture&);
    typedef std::vector<std::string>::size_type height_size;
    typedef std::string::size_type width_size;

    // pure virtual functions, making our Pic_base an abstract base class.
    // Compiler will now ensure that we do not create objects of Pic_base at all
    virtual width_size width() const = 0;
    virtual height_size height() const = 0;
    virtual void display(std::ostream&, height_size, bool) const = 0;

public:
    virtual ~Pic_base() { }
};

class String_Pic : public Pic_base {
    friend class Picture;
    std::vector<std::string> data;
    String_Pic(std::vector<std::string> v) : data(v) { }
    width_size width() const;
    height_size height() const;
    void display(std::ostream&, height_size, bool) const;
};

class Frame_Pic: public Pic_base{
    friend Picture frame(const Picture&);
    Ptr<Pic_base> p;
    Frame_Pic(const Ptr<Pic_base>& pic) : p(pic) { }
    width_size width() const;
    height_size height() const;
    void display(std::ostream&, height_size, bool) const;
};

class HCat_Pic: public Pic_base{
    friend Picture hcat(const Picture&, const Picture&);
    Ptr<Pic_base> left, right;
    HCat_Pic(const Ptr<Pic_base>& leftPic, const Ptr<Pic_base>& rightPic) : 
        top(leftPic), bottom(rightPic) { }
    width_size width() const;
    height_size height() const;
    void display(std::ostream&, height_size, bool) const;
};

class VCat_Pic: public Pic_base{
    friend Picture vcat(const Picture&, const Picture&);
    Ptr<Pic_base> top, bottom;
    VCat_Pic(const Ptr<Pic_base>& topPic, const Ptr<Pic_base>& bottomPic) : 
        top(topPic), bottom(bottomPic) { }
    width_size width() const;
    height_size height() const;
    void display(std::ostream&, height_size, bool) const;
};



// Public interface Picture class
class Picture{
friend std::ostream& operator<<(std::ostream&, const Picture&);
public:
    // implicit conversion of vec to Picture allowed by this constructor
    Picture(const std::vector<std::string>& = std::vector<std::string>()); 
    Picture(Pic_base* ptr) : p(ptr) { }

private:
    // std::shared_ptr<Pic_base> p;
    Ptr<Pic_base> p;
};


// Nonmember functions
Picture frame(const Picture&);
Picture hcat(const Picture&, const Picture&);
Picture vcat(const Picture&, const Picture&);
std::ostream& operator<<(std::ostream&, const Picture&);
