#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <boost/python.hpp>

char const* help()
{
   return "This is where the help would go if I wasn't lazy";
}


class Widget {

    std::string msg;

	public: 
		int x, y, width, height;
		void move(int, int);
		int right(void);
		Widget(int, int, int, int);

};


Widget::Widget(int x, int y, int width, int height) {
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
}

// instance method 
void Widget::move(int dx, int dy) { 
	this->x += dx;
	this->y += dy;
}

// getter function
int Widget::right(void) {
	return x + width;
}



BOOST_PYTHON_MODULE(loboutils)
{
    using namespace boost::python;
    def("help", help);

	
    class_<Widget>("Widget", init<int, int, int, int>())
		
        .def("move", &Widget::move)			// expose the defined a class method
		.def_readwrite("x", &Widget::x)		// expose the class attribute as read-write, other option is def_readonly
		.def_readwrite("y", &Widget::y)
		.add_property("right", &Widget::right)
    ;

}

