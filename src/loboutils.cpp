#include <boost/python/module.hpp>
#include <boost/python/def.hpp>
#include <boost/python.hpp>

char const* help()
{
   return "This is where the help would go if I wasn't lazy";
}


class Widget {

	public: 
		int x, y, width, height;

		// instance method 
		void move(int dx, int dy) { 
			this->x += dx;
			this->y += dy;
		}

		// getter function accessed via python through @property
		int right(void) {
			return x + width;
		}

		// constructor function (equivalent to __init__ for python classes)
		Widget(int x, int y, int width, int height) {
			this->x = x;
			this->y = y;
			this->width = width;
			this->height = height;
		}

};



// Create a Label class that inheirits from Widget
class Label : public Widget {
	public:
		// In addition to widget's public attributes, define a name for the label
		std::string name;
		// Create a constructor for the Label and inside create an instance of the base class (Widget). 
 		// Creating the base class instance will initialize the base class variables and executes it's constructor. 
		// In addition, we've added an argument for the 'name' attribute
		Label(std::string name, int x, int y, int width, int height): Widget(x, y, width, height) {
			this->name = name;		
		};

};



BOOST_PYTHON_MODULE(loboutils)
{
    using namespace boost::python;
    def("help", help);

	
	// Expose the class by wrapping it with the class_ template. The first argument is the name to expose it as and the second
	// argument is the constructor function
    class_<Widget>("Widget", init<int, int, int, int>())
		
        .def("move", &Widget::move)			// expose the defined a class method
		.def_readwrite("x", &Widget::x)		// expose the class attribute as read-write, other option is def_readonly
		.def_readwrite("y", &Widget::y)
		.def_readwrite("width", &Widget::width)	
		.def_readwrite("height", &Widget::height)

		.add_property("right", &Widget::right) // expose the function as a @property 
    ;

	// Expose the Label class which inheirits from Widget. We do not need to expose functions and variables
	// that have already been exposed in the base class.
    class_<Label, bases<Widget> >("Label", init<std::string, int, int, int, int>())
		.def_readwrite("name", &Label::name)
	;		

}

