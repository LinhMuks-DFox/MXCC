# MXC::object

The base object of MXC.

An object in MXC, contain 3 method, 1 operator overload, 1 `Type` field.

Struct `Type`, is a RTTI support in MXC, it contains a string type field `type_name` and an uint64 type
field `generation`

### Method

1. `to_string()`
   to convert a MXC::object to string representation.
2. `get_hash()`
   to convert a MXC::object to a hash_code type(uint64_t) representation.
3. `get_type()`
   to get the RTTI of a MXC::object instance.

### Operator overload

1. `std::ostream operator<<(...)`

### Filed

1. `my_type`

We consider an MXC::object to be instantiated when the constructor of a class is called to generate a new object, while
calling the constructor of a publicly inherited object and filling in the type.

Consider the following code.
```CPP
class my_class : public MXC::object{
public:
    my_class(...) : MXC::object("my_type", 1) {}
    my_class(void) {}
    ~my_class() {}
};

int main() {
    my_class foo(...); // foo object is instantiated as a MXC::object;
    my_class bar(); // foo object is not instantiated as a MXC::object;
    return 0;
}
```